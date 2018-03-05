	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 13
	.globl	_ft_strlen
	.p2align	4, 0x90
_ft_strlen:                             ## @ft_strlen
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi0:
	.cfi_def_cfa_offset 16
Lcfi1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi2:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movl	$0, -12(%rbp)
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	movq	-8(%rbp), %rax
	movslq	-12(%rbp), %rcx
	movsbl	(%rax,%rcx), %edx
	cmpl	$0, %edx
	je	LBB0_3
## BB#2:                                ##   in Loop: Header=BB0_1 Depth=1
	movl	-12(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -12(%rbp)
	jmp	LBB0_1
LBB0_3:
	movl	-12(%rbp), %eax
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_ft_memset
	.p2align	4, 0x90
_ft_memset:                             ## @ft_memset
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi3:
	.cfi_def_cfa_offset 16
Lcfi4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi5:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-8(%rbp), %rdx
	movq	%rdx, -32(%rbp)
	movq	$0, -40(%rbp)
LBB1_1:                                 ## =>This Inner Loop Header: Depth=1
	movq	-40(%rbp), %rax
	cmpq	-24(%rbp), %rax
	jae	LBB1_3
## BB#2:                                ##   in Loop: Header=BB1_1 Depth=1
	movl	-12(%rbp), %eax
	movb	%al, %cl
	movq	-32(%rbp), %rdx
	movq	-40(%rbp), %rsi
	movq	%rsi, %rdi
	addq	$1, %rdi
	movq	%rdi, -40(%rbp)
	movb	%cl, (%rdx,%rsi)
	jmp	LBB1_1
LBB1_3:
	movq	-8(%rbp), %rax
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_ft_strnew
	.p2align	4, 0x90
_ft_strnew:                             ## @ft_strnew
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi6:
	.cfi_def_cfa_offset 16
Lcfi7:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi8:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -16(%rbp)
	movq	-16(%rbp), %rdi
	addq	$1, %rdi
	callq	_malloc
	movq	%rax, -24(%rbp)
	cmpq	$0, %rax
	jne	LBB2_2
## BB#1:
	movq	$0, -8(%rbp)
	jmp	LBB2_3
LBB2_2:
	xorl	%esi, %esi
	movq	-24(%rbp), %rdi
	movq	-16(%rbp), %rax
	addq	$1, %rax
	movq	%rax, %rdx
	callq	_ft_memset
	movq	-24(%rbp), %rdx
	movq	%rdx, -8(%rbp)
	movq	%rax, -32(%rbp)         ## 8-byte Spill
LBB2_3:
	movq	-8(%rbp), %rax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_ft_strjoin
	.p2align	4, 0x90
_ft_strjoin:                            ## @ft_strjoin
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi9:
	.cfi_def_cfa_offset 16
Lcfi10:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi11:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	cmpq	$0, -16(%rbp)
	je	LBB3_2
## BB#1:
	cmpq	$0, -24(%rbp)
	jne	LBB3_3
LBB3_2:
	movq	$0, -8(%rbp)
	jmp	LBB3_12
LBB3_3:
	movl	$0, -36(%rbp)
	movq	-16(%rbp), %rdi
	callq	_ft_strlen
	movq	-24(%rbp), %rdi
	movl	%eax, -40(%rbp)         ## 4-byte Spill
	callq	_ft_strlen
	movl	-40(%rbp), %ecx         ## 4-byte Reload
	addl	%eax, %ecx
	addl	$1, %ecx
	movslq	%ecx, %rdi
	callq	_malloc
	movq	%rax, -32(%rbp)
	cmpq	$0, %rax
	jne	LBB3_5
## BB#4:
	movq	$0, -8(%rbp)
	jmp	LBB3_12
LBB3_5:
	jmp	LBB3_6
LBB3_6:                                 ## =>This Inner Loop Header: Depth=1
	movq	-16(%rbp), %rax
	movslq	-36(%rbp), %rcx
	cmpb	$0, (%rax,%rcx)
	je	LBB3_8
## BB#7:                                ##   in Loop: Header=BB3_6 Depth=1
	movq	-16(%rbp), %rax
	movslq	-36(%rbp), %rcx
	movb	(%rax,%rcx), %dl
	movq	-32(%rbp), %rax
	movslq	-36(%rbp), %rcx
	movb	%dl, (%rax,%rcx)
	movl	-36(%rbp), %esi
	addl	$1, %esi
	movl	%esi, -36(%rbp)
	jmp	LBB3_6
LBB3_8:
	jmp	LBB3_9
LBB3_9:                                 ## =>This Inner Loop Header: Depth=1
	movq	-24(%rbp), %rax
	cmpb	$0, (%rax)
	je	LBB3_11
## BB#10:                               ##   in Loop: Header=BB3_9 Depth=1
	movq	-24(%rbp), %rax
	movq	%rax, %rcx
	addq	$1, %rcx
	movq	%rcx, -24(%rbp)
	movb	(%rax), %dl
	movq	-32(%rbp), %rax
	movslq	-36(%rbp), %rcx
	movb	%dl, (%rax,%rcx)
	movl	-36(%rbp), %esi
	addl	$1, %esi
	movl	%esi, -36(%rbp)
	jmp	LBB3_9
LBB3_11:
	movq	-32(%rbp), %rax
	movslq	-36(%rbp), %rcx
	movb	$0, (%rax,%rcx)
	movq	-32(%rbp), %rax
	movq	%rax, -8(%rbp)
LBB3_12:
	movq	-8(%rbp), %rax
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc


.subsections_via_symbols
