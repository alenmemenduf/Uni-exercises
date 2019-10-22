.data
string: .asciiz "-123"

.text
main:
	add $s0,$s0,$zero

	lb $t1,string($s0)
	add $s0,$s0,4

	jal atoi

	beq $tq,'-',minus

	
	
atoi:
	lb $t0,string($s0)	
	beqz $t0,exit 		 	
	mul $v0,$v0,10
	add $v0,$v0,$t0
	
	
	addi $sp,$sp,-8
	sw $ra,0($sp)
	sw $v0,4($sp)
	 
	addi $s0,$s0,1 		
	jal atoi
minus:
	muli $v0,$v0,-1
	move $a0,$v0
	
	li $v0,1
	syscall
	
	li $v0,10
	syscall


exit:	
	lw $ra,0($sp)
	addi $sp,$sp,8
	jr $ra

	
