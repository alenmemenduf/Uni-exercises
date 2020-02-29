.data
v: .byte 10,20,'+',10,15,'+','-',4,3,'-','-',0 
.text
main:
a: #initializez i=0
	addi $t0,$zero,0
b: #t1 = v[i]
	lb $t1,v($t0)
	beq $t1,0,f #daca v[i]=0 sari la f
c: #daca v[i] = '+' -> pop1,daca v[i] = '-' ->pop2
	beq $t1,43,pop1
	beq $t1,45,pop2
	j push
e: #i++
	addi $t0,$t0,1
	j b
f:#t1 devine elementul din varful stivei
	lb $t1,0($sp)
	#addi $sp,$sp,4

li $v0,1
move $a0,$t1
syscall

li $v0,10
syscall


push: #push la valoarea din t1
	addi $sp,$sp,-4
	sb $t1,0($sp)
	j e
pop1: #pop la 2 valori,suma + push la suma inapoi
	lb $t2,4($sp) #x =penultimul element
	lb $t3,0($sp) #y =ultimul
	add $t3,$t2,$t3	#x=x+y
	addi $sp,$sp,8
	move $t1,$t3
	j push
	
pop2: #pop la 2 valori,fac scadere + push la diferenta
	
	lb $t2,4($sp) #x =penultimul element
	lb $t3,0($sp) #y =ultimul
	sub $t3,$t2,$t3	#x=x-y
	addi $sp,$sp,8 #ultim element aruncat la gunoi
	move $t1,$t3
	j push
