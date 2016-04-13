#ifndef _KLIBC_ARCHSTAT_H
#define _KLIBC_ARCHSTAT_H

#include <klibc/stathelp.h>

#define _STATBUF_ST_NSEC

struct stat {
	__stdev64	(st_dev);
	__u64		st_ino;
	__u64		st_nlink;

	__u32		st_mode;
	__u32		st_uid;
	__u32		st_gid;
	__u32		__pad0;
	__stdev64	(st_rdev);
	__s64		st_size;
	__s64		st_blksize;
	__s64		st_blocks;	/* Number 512-byte blocks allocated. */

	struct timespec st_atim;
	struct timespec st_mtim;
	struct timespec st_ctim;
	__u64		__unused[3];
};

#endif
