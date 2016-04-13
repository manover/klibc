#
# usr/klibc/arch/x32/vfork.S
#
# vfork is nasty - there must be nothing at all on the stack above
# the stack frame of the enclosing function.
#

#include <asm/unistd.h>

	.text
	.align	4
	.globl	vfork
	.type	vfork, @function
vfork:
	mov		(%rsp),%edx		/* Return address */
	add		$8,%rsp			/* pop rdx and clear bits 63-32 */
	mov		$__NR_vfork,%eax
	syscall
	push	%rdx			/* Push the return address back */
	cmp		$-4095, %rax
	jae		1f
	ret
1:
	negl	%eax
	movl	%eax, errno(%rip)
	or	$-1,%rax
	ret
