/* SPDX-License-Identifier: MIT */

#ifndef __UIMAGE_H__
#define __UIMAGE_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <xboot.h>

struct uimage_header_t {
	uint32_t	ih_magic;	/* Image Header Magic Number	*/
	uint32_t	ih_hcrc;	/* Image Header CRC Checksum	*/
	uint32_t	ih_time;	/* Image Creation Timestamp	*/
	uint32_t	ih_size;	/* Image Data Size		*/
	uint32_t	ih_load;	/* Data	Load  Address		*/
	uint32_t	ih_ep;		/* Entry Point Address		*/
	uint32_t	ih_dcrc;	/* Image Data CRC Checksum	*/
	uint8_t		ih_os;		/* Operating System		*/
	uint8_t		ih_arch;	/* CPU architecture		*/
	uint8_t		ih_type;	/* Image Type			*/
	uint8_t		ih_comp;	/* Compression Type		*/
	uint8_t		ih_name[32];	/* Image Name		*/
};

int uimage_load(const char * path, uint32_t * entry, uint32_t * load, uint32_t * size);

#ifdef __cplusplus
}
#endif

#endif /* __UIMAGE_H__ */
