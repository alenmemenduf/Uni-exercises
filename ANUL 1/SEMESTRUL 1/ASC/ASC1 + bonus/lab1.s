.data
	var1: .word 9
	var2: .word 10
	var3: .word 11
.text

main:
	lw $t0,var1     #$t0 = 9
	lw $t1,var2     #$t1 = 10
	lw $t2,var3     #$t2 = 11
	
	bgt $t1,$t0,IF1      #daca $t1>$t0   salt la IF1
	j exit1              #daca $t1<=$t0   salt la exit1

IF1:
	move $t0,$t1     #$t0=$t1

	
exit1:	
	bgt $t2,$t1,IF2    #daca $t2>$t1 salt la IF2
	j exit2            #daca $t2<=$t1 salt la exit2


IF2:
	move $t0,$t2       #$t0=$t2


exit2:	
	li $v0,1      #
	la  $a0,($t0) # afiseaza valoarea din $t0
	syscall       #
	
	li $v0,10
	syscall
