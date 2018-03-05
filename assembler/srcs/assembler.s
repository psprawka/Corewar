	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 13
	.globl	_readandstore
	.p2align	4, 0x90
_readandstore:                          ## @readandstore
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
	subq	$32, %rsp
	movl	$1, %esi
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	movb	$0, %al
	callq	_open
	movl	$100, %esi
	movl	%esi, %edi
	leaq	l_.str(%rip), %rcx
	movl	%eax, -12(%rbp)
	movq	%rcx, -32(%rbp)
	callq	_ft_strnew
	movq	%rax, -24(%rbp)
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	movl	$99, %eax
	movl	%eax, %edx
	movl	-12(%rbp), %edi
	movq	-24(%rbp), %rsi
	callq	_read
	cmpq	$0, %rax
	je	LBB0_3
## BB#2:                                ##   in Loop: Header=BB0_1 Depth=1
	movq	-32(%rbp), %rdi
	movq	-24(%rbp), %rsi
	callq	_ft_strjoin
	movq	%rax, -32(%rbp)
	jmp	LBB0_1
LBB0_3:
	movq	-32(%rbp), %rax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_handle_header
	.p2align	4, 0x90
_handle_header:                         ## @handle_header
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
	subq	$48, %rsp
	movl	$129, %eax
	movl	%eax, %ecx
	movq	%rdi, -8(%rbp)
	movq	%rcx, %rdi
	callq	_ft_strnew
	movl	$2049, %edx             ## imm = 0x801
	movl	%edx, %edi
	movq	%rax, -24(%rbp)
	callq	_ft_strnew
	movl	$2192, %edx             ## imm = 0x890
	movl	%edx, %edi
	movq	%rax, -16(%rbp)
	callq	_malloc
	movq	-8(%rbp), %rcx
	movq	%rax, 8(%rcx)
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movl	$15369203, (%rax)       ## imm = 0xEA83F3
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movl	$0, 136(%rax)
LBB1_1:                                 ## =>This Inner Loop Header: Depth=1
	movq	-8(%rbp), %rax
	movq	16(%rax), %rax
	movq	-8(%rbp), %rcx
	movl	24(%rcx), %edx
	movl	%edx, %esi
	addl	$1, %esi
	movl	%esi, 24(%rcx)
	movslq	%edx, %rcx
	movsbl	(%rax,%rcx), %edx
	cmpl	$34, %edx
	je	LBB1_3
## BB#2:                                ##   in Loop: Header=BB1_1 Depth=1
	jmp	LBB1_1
LBB1_3:
	jmp	LBB1_4
LBB1_4:                                 ## =>This Inner Loop Header: Depth=1
	movq	-8(%rbp), %rax
	movq	16(%rax), %rax
	movq	-8(%rbp), %rcx
	movslq	24(%rcx), %rcx
	movsbl	(%rax,%rcx), %edx
	cmpl	$34, %edx
	je	LBB1_6
## BB#5:                                ##   in Loop: Header=BB1_4 Depth=1
	movq	-8(%rbp), %rax
	movq	16(%rax), %rax
	movq	-8(%rbp), %rcx
	movl	24(%rcx), %edx
	movl	%edx, %esi
	addl	$1, %esi
	movl	%esi, 24(%rcx)
	movslq	%edx, %rcx
	movb	(%rax,%rcx), %dil
	movq	-24(%rbp), %rax
	movl	_handle_header.i(%rip), %edx
	movl	%edx, %esi
	addl	$1, %esi
	movl	%esi, _handle_header.i(%rip)
	movslq	%edx, %rcx
	movb	%dil, (%rax,%rcx)
	jmp	LBB1_4
LBB1_6:
	movl	$0, _handle_header.i(%rip)
LBB1_7:                                 ## =>This Inner Loop Header: Depth=1
	movq	-8(%rbp), %rax
	movq	16(%rax), %rax
	movq	-8(%rbp), %rcx
	movl	24(%rcx), %edx
	movl	%edx, %esi
	addl	$1, %esi
	movl	%esi, 24(%rcx)
	movslq	%edx, %rcx
	movsbl	(%rax,%rcx), %edx
	cmpl	$34, %edx
	je	LBB1_9
## BB#8:                                ##   in Loop: Header=BB1_7 Depth=1
	jmp	LBB1_7
LBB1_9:
	jmp	LBB1_10
LBB1_10:                                ## =>This Inner Loop Header: Depth=1
	movq	-8(%rbp), %rax
	movq	16(%rax), %rax
	movq	-8(%rbp), %rcx
	movslq	24(%rcx), %rcx
	movsbl	(%rax,%rcx), %edx
	cmpl	$34, %edx
	je	LBB1_12
## BB#11:                               ##   in Loop: Header=BB1_10 Depth=1
	movq	-8(%rbp), %rax
	movq	16(%rax), %rax
	movq	-8(%rbp), %rcx
	movl	24(%rcx), %edx
	movl	%edx, %esi
	addl	$1, %esi
	movl	%esi, 24(%rcx)
	movslq	%edx, %rcx
	movb	(%rax,%rcx), %dil
	movq	-16(%rbp), %rax
	movl	_handle_header.i(%rip), %edx
	movl	%edx, %esi
	addl	$1, %esi
	movl	%esi, _handle_header.i(%rip)
	movslq	%edx, %rcx
	movb	%dil, (%rax,%rcx)
	jmp	LBB1_10
LBB1_12:
	movl	$129, %eax
	movl	%eax, %edx
	movq	-8(%rbp), %rcx
	movq	8(%rcx), %rcx
	addq	$4, %rcx
	movq	-24(%rbp), %rsi
	movq	%rcx, %rdi
	callq	___strcpy_chk
	movq	$-1, %rdx
	movq	-8(%rbp), %rcx
	movq	8(%rcx), %rcx
	addq	$140, %rcx
	movq	-16(%rbp), %rsi
	movq	%rcx, %rdi
	movq	%rax, -32(%rbp)         ## 8-byte Spill
	callq	___strcpy_chk
	movq	%rax, -40(%rbp)         ## 8-byte Spill
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_write_header
	.p2align	4, 0x90
_write_header:                          ## @write_header
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
	subq	$16, %rsp
	movl	$128, %eax
	movl	%eax, %edx
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	movl	(%rdi), %edi
	movq	-8(%rbp), %rcx
	movq	8(%rcx), %rcx
	addq	$4, %rcx
	movq	%rcx, %rsi
	callq	_write
	movq	%rax, -16(%rbp)         ## 8-byte Spill
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_assembler
	.p2align	4, 0x90
_assembler:                             ## @assembler
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
	subq	$16, %rsp
	movl	$32, %eax
	movl	%eax, %ecx
	movq	%rdi, -8(%rbp)
	movq	%rcx, %rdi
	callq	_malloc
	movq	%rax, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rcx
	movq	%rax, 16(%rcx)
	movq	-16(%rbp), %rax
	movl	$0, 24(%rax)
	movq	-16(%rbp), %rdi
	callq	_handle_header
	leaq	L_.str.1(%rip), %rsi
	movq	-16(%rbp), %rax
	movq	8(%rax), %rax
	addq	$4, %rax
	movq	%rax, %rdi
	callq	_ft_strjoin
	movl	$513, %esi              ## imm = 0x201
	movq	%rax, %rdi
	movb	$0, %al
	callq	_open
	movq	-16(%rbp), %rcx
	movl	%eax, (%rcx)
	movq	-16(%rbp), %rdi
	callq	_write_header
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi12:
	.cfi_def_cfa_offset 16
Lcfi13:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi14:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movl	$0, -4(%rbp)
	movl	%edi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	cmpl	$1, -8(%rbp)
	jne	LBB4_2
## BB#1:
	leaq	L_.str.2(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	$1, -4(%rbp)
	movl	%eax, -28(%rbp)         ## 4-byte Spill
	jmp	LBB4_4
LBB4_2:
	movq	-16(%rbp), %rax
	movq	8(%rax), %rdi
	callq	_readandstore
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rdi
	callq	_assembler
## BB#3:
	movl	$0, -4(%rbp)
LBB4_4:
	movl	-4(%rbp), %eax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__const
l_.str:                                 ## @.str
	.space	2

.zerofill __DATA,__bss,_handle_header.i,4,2 ## @handle_header.i
	.section	__TEXT,__cstring,cstring_literals
L_.str.1:                               ## @.str.1
	.asciz	".cor"

L_.str.2:                               ## @.str.2
	.asciz	"Usage: ./asm [-a] <sourcefile.s>"


.subsections_via_symbols
