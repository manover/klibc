/*
 * arch/x32/include/klibc/archsetjmp.h
 */

#ifndef _KLIBC_ARCHSETJMP_H
#define _KLIBC_ARCHSETJMP_H

struct __jmp_buf {
	__u64 __rbx;
	__u64 __rsp;
	__u64 __rbp;
	__u64 __r12;
	__u64 __r13;
	__u64 __r14;
	__u64 __r15;
	__u64 __rip;
};

typedef struct __jmp_buf jmp_buf[1];

#endif				/* _SETJMP_H */
