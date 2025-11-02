/* SPDX-License-Identifier: MIT */

#include <xboot.h>
#include <xboot/uimage.h>
#include <command/command.h>

static void usage(void)
{
	printf("usage:\n");
	printf("    bootu <path>\n");
}

static int do_bootu(int argc, char ** argv)
{
	uint32_t entry, load, size;

	if (argc != 2) {
		usage();
		return -1;
	}

	if (uimage_load(argv[1], &entry, &load, &size) != 0) {
		printf("Error: Failed to load uImage '%s'\n", argv[1]);
		return -1;
	}

	printf("Booting kernel at 0x%08x, entry point 0x%08x, size %d bytes\n", load, entry, size);
	machine_smpboot((void (*)(void))entry);

	return 0;
}

static struct command_t cmd_bootu = {
	.name	= "bootu",
	.desc	= "boot uImage",
	.usage	= usage,
	.exec	= do_bootu,
};

static __init void bootu_cmd_init(void)
{
	register_command(&cmd_bootu);
}

static __exit void bootu_cmd_exit(void)
{
	unregister_command(&cmd_bootu);
}

command_initcall(bootu_cmd_init);
command_exitcall(bootu_cmd_exit);
