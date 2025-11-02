/* SPDX-License-Identifier: MIT */

#include <xboot.h>
#include <xboot/uimage.h>
#include <vfs.h>
#include <crc32.h>

#define UIMAGE_MAGIC	0x27051956

int uimage_load(const char * path, uint32_t * entry, uint32_t * load, uint32_t * size)
{
	struct uimage_header_t header;
	uint32_t hcrc, dcrc;
	char * buf;
	int fd;

	fd = vfs_open(path, O_RDONLY, 0);
	if (fd < 0)
		return -1;

	if (vfs_read(fd, &header, sizeof(header)) != sizeof(header)) {
		vfs_close(fd);
		return -1;
	}

	if (be32_to_cpu(header.ih_magic) != UIMAGE_MAGIC) {
		vfs_close(fd);
		return -1;
	}

	hcrc = be32_to_cpu(header.ih_hcrc);
	header.ih_hcrc = 0;
	if (crc32(0, (const uint8_t *)&header, sizeof(header)) != hcrc) {
		vfs_close(fd);
		return -1;
	}

	*size = be32_to_cpu(header.ih_size);
	buf = malloc(*size);
	if (!buf) {
		vfs_close(fd);
		return -1;
	}

	if (vfs_read(fd, buf, *size) != *size) {
		free(buf);
		vfs_close(fd);
		return -1;
	}

	dcrc = be32_to_cpu(header.ih_dcrc);
	if (crc32(0, (const uint8_t *)buf, *size) != dcrc) {
		free(buf);
		vfs_close(fd);
		return -1;
	}

	/*
	 * TODO: Add support for compressed images.
	 */
	if (header.ih_comp != 0) {
		printf("uimage: compressed images are not supported yet\n");
		free(buf);
		vfs_close(fd);
		return -1;
	}

	*entry = be32_to_cpu(header.ih_ep);
	*load = be32_to_cpu(header.ih_load);

	memcpy((void *)(*load), buf, *size);

	free(buf);
	vfs_close(fd);

	return 0;
}
