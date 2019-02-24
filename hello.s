	.data

srt:
	.ascii	"Hello world\000"

prn:
	.ascii	"%s %d %d \n\000"
	.align 2

a:
	.word 45, 65

	.text
	.global main

main:
	push {fp,lr}
	add fp,sp,#4
	ldr r0,.L0
	ldr r1,.L0+4
	ldr r2,.L0+8
	ldr r2,[r2]
	ldr r3,.L0+8
	ldr r3,[r3,#4]
	bl printf
	mov r0,#0
	pop {fp,pc}

.L0:
	.word	prn
	.word	srt
	.word 	a
