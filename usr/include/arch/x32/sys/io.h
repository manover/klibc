/* ----------------------------------------------------------------------- *
 *
 *   Copyright 2004 H. Peter Anvin - All Rights Reserved
 *
 *   Permission is hereby granted, free of charge, to any person
 *   obtaining a copy of this software and associated documentation
 *   files (the "Software"), to deal in the Software without
 *   restriction, including without limitation the rights to use,
 *   copy, modify, merge, publish, distribute, sublicense, and/or
 *   sell copies of the Software, and to permit persons to whom
 *   the Software is furnished to do so, subject to the following
 *   conditions:
 *
 *   The above copyright notice and this permission notice shall
 *   be included in all copies or substantial portions of the Software.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 *   OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 *   HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 *   WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 *   OTHER DEALINGS IN THE SOFTWARE.
 *
 * ----------------------------------------------------------------------- */

/*
 * sys/io.h for the x32 architecture
 *
 * Basic I/O macros
 */

#ifndef _SYS_IO_H
#define _SYS_IO_H 1

/* I/O-related system calls */

int iopl(int);
int ioperm(__u64, __u64, int);

/* Basic I/O macros */

static __inline__ void outb(__u8 __v, __u16 __p)
{
	asm volatile ("outb %0,%1" : : "a" (__v), "dN"(__p));
}

static __inline__ void outw(__u16 __v, __u16 __p)
{
	asm volatile ("outw %0,%1" : : "a" (__v), "dN"(__p));
}

static __inline__ void outl(__u32 __v, __u16 __p)
{
	asm volatile ("outl %0,%1" : : "a" (__v), "dN"(__p));
}

static __inline__ __u8 inb(__u16 __p)
{
	__u8 __v;
	asm volatile ("inb %1,%0" : "=a" (__v) : "dN"(__p));
	return __v;
}

static __inline__ __u16 inw(__u16 __p)
{
	__u16 __v;
	asm volatile ("inw %1,%0" : "=a" (__v) : "dN"(__p));
	return __v;
}

static __inline__ __u32 inl(__u16 __p)
{
	__u32 __v;
	asm volatile ("inl %1,%0" : "=a" (__v) : "dN"(__p));
	return __v;
}

/* String I/O macros */

static __inline__ void outsb(__u16 __p, const void *__d, __u64 __n)
{
	asm volatile ("cld; rep; outsb"
		      : "+S" (__d), "+c"(__n)
		      : "d"(__p));
}

static __inline__ void outsw(__u16 __p, const void *__d, __u64 __n)
{
	asm volatile ("cld; rep; outsw"
		      : "+S" (__d), "+c"(__n)
		      : "d"(__p));
}

static __inline__ void outsl(__u16 __p, const void *__d, __u64 __n)
{
	asm volatile ("cld; rep; outsl"
		      : "+S" (__d), "+c"(__n)
		      : "d"(__p));
}

static __inline__ void insb(__u16 __p, void *__d, __u64 __n)
{
	asm volatile ("cld; rep; insb"
		      : "+D" (__d), "+c"(__n)
		      : "d"(__p));
}

static __inline__ void insw(__u16 __p, void *__d, __u64 __n)
{
	asm volatile ("cld; rep; insw"
		      : "+D" (__d), "+c"(__n)
		      : "d"(__p));
}

static __inline__ void insl(__u16 __p, void *__d, __u64 __n)
{
	asm volatile ("cld; rep; insl"
		      : "+D" (__d), "+c"(__n)
		      : "d"(__p));
}

#endif				/* _SYS_IO_H */
