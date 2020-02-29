.data
	var1: .word 3
	var2: .word 20
	var3: .word 15
.text

main:
	lw $t1,var1    #x
	lw $t2,var2    #y
	lw $t3,var3    #z
	
	bgt $t1,$t2,xy2    # daca x>y sare la xy2,daca nu,ramane la xy

	blt $t2,$t3,exit1    #daca y<x sare la exit1
	blt $t3,$t1,exit2    #daca x<y sare la exit 2
	move $t0,$t3
	j sfarsit
xy2:
	blt $t3,$t2,exit1    #daca z<y sare la exit1
	blt $t1,$t3,exit2    #daca x<z sare la exit2
	
	move $t0,$t3
	j sfarsit

	
exit1:
	move $t0,$t2	
	j sfarsit		
exit2:
	move $t0,$t1
	j sfarsit
sfarsit:
	li $v0,1
	la  $a0,($t0)
	syscall
	
	li $v0,10
	syscall
