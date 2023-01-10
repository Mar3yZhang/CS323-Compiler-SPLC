.data
_prompt: .asciiz "Please enter an integer: "
_ret: .asciiz "\n"

_v40: .word 0
_v41: .word 0
_v39: .word 0
_v38: .word 0
_v33: .word 0
_v29: .word 0
_v21: .word 0
_v13: .word 0
_v35: .word 0
_v25: .word 0
_v14: .word 0
_v16: .word 0
_v36: .word 0
_sum: .word 0
_v26: .word 0
_v27: .word 0
_v2: .word 0
_p3: .word 0
_v12: .word 0
_p2: .word 0
_p1: .word 0
_n: .word 0
_v4: .word 0
_v1: .word 0
_v3: .word 0
_v6: .word 0
_v22: .word 0
_v8: .word 0
_v9: .word 0

.globl main
.text
read:
    li $v0, 4
    la $a0, _prompt
    syscall
    li $v0, 5
    syscall
    jr $ra
write:
    li $v0, 1
    syscall
    li $v0, 4
    la $a0, _ret
    syscall
    move $v0, $0
    jr $ra

hanoi:
    addi $sp,$sp,-32
    sw $s0,0($sp)
    sw $s1,4($sp)
    sw $s2,8($sp)
    sw $s3,12($sp)
    sw $s4,16($sp)
    sw $s5,20($sp)
    sw $s6,24($sp)
    sw $s7,28($sp)

    li   $t0,1
    sw   $t0,_v6

    move $t0,$a0
    lw   $t1,_v6
    beq  $t0,$t1,label1

    j label2

label1:
    li   $t0,10000
    sw   $t0,_v12

    move $t0,$a1
    lw   $t1,_v12
    mul  $t2,$t0,$t1
    sw   $t2,_v9

    lw   $t0,_v9
    move $t1,$a3
    add  $t2,$t0,$t1
    sw   $t2,_v8

    addi $sp, $sp, -8 ### push stack to store $ra
    sw   $a0,  0($sp) ## store $a0
    sw   $ra,  4($sp) ### store $ra
    lw   $t0,_v8
    move $a0,  $t0
    jal  write ### invoke write
    lw   $ra,  4($sp) ## read $ra
    lw   $a0,  0($sp) ## store $a0
    addi $sp, $sp, 8

    j label3

label2:
    li   $t0,1
    sw   $t0,_v16

    move $t0,$a0
    lw   $t1,_v16
    sub  $t2,$t0,$t1
    sw   $t2,_v14

    addi $sp, $sp, -136
    sw $a0,  0($sp) ## store $a0
    sw $a1,  4($sp) ## store $a1
    sw $a2,  8($sp) ## store $a2
    sw $a3,  12($sp) ## store $a3
    lw $t0,_v40
    sw $t0, 16($sp)
    lw $t0,_v41
    sw $t0, 20($sp)
    lw $t0,_v39
    sw $t0, 24($sp)
    lw $t0,_v38
    sw $t0, 28($sp)
    lw $t0,_v33
    sw $t0, 32($sp)
    lw $t0,_v29
    sw $t0, 36($sp)
    lw $t0,_v21
    sw $t0, 40($sp)
    lw $t0,_v13
    sw $t0, 44($sp)
    lw $t0,_v35
    sw $t0, 48($sp)
    lw $t0,_v25
    sw $t0, 52($sp)
    lw $t0,_v14
    sw $t0, 56($sp)
    lw $t0,_v16
    sw $t0, 60($sp)
    lw $t0,_v36
    sw $t0, 64($sp)
    lw $t0,_sum
    sw $t0, 68($sp)
    lw $t0,_v26
    sw $t0, 72($sp)
    lw $t0,_v27
    sw $t0, 76($sp)
    lw $t0,_v2
    sw $t0, 80($sp)
    lw $t0,_p3
    sw $t0, 84($sp)
    lw $t0,_v12
    sw $t0, 88($sp)
    lw $t0,_p2
    sw $t0, 92($sp)
    lw $t0,_p1
    sw $t0, 96($sp)
    lw $t0,_n
    sw $t0, 100($sp)
    lw $t0,_v4
    sw $t0, 104($sp)
    lw $t0,_v1
    sw $t0, 108($sp)
    lw $t0,_v3
    sw $t0, 112($sp)
    lw $t0,_v6
    sw $t0, 116($sp)
    lw $t0,_v22
    sw $t0, 120($sp)
    lw $t0,_v8
    sw $t0, 124($sp)
    lw $t0,_v9
    sw $t0, 128($sp)
    sw $ra, 132($sp)
    lw $a3,8($sp)
    lw $a2,12($sp)
    lw $a1,4($sp)
    lw $a0,56($sp)
    jal hanoi
    lw $a0,  0($sp) ## store $a0
    lw $a1,  4($sp) ## store $a1
    lw $a2,  8($sp) ## store $a2
    lw $a3,  12($sp) ## store $a3
    lw $t0,16($sp)
    sw $t0,_v40
    lw $t0,20($sp)
    sw $t0,_v41
    lw $t0,24($sp)
    sw $t0,_v39
    lw $t0,28($sp)
    sw $t0,_v38
    lw $t0,32($sp)
    sw $t0,_v33
    lw $t0,36($sp)
    sw $t0,_v29
    lw $t0,40($sp)
    sw $t0,_v21
    lw $t0,44($sp)
    sw $t0,_v13
    lw $t0,48($sp)
    sw $t0,_v35
    lw $t0,52($sp)
    sw $t0,_v25
    lw $t0,56($sp)
    sw $t0,_v14
    lw $t0,60($sp)
    sw $t0,_v16
    lw $t0,64($sp)
    sw $t0,_v36
    lw $t0,68($sp)
    sw $t0,_sum
    lw $t0,72($sp)
    sw $t0,_v26
    lw $t0,76($sp)
    sw $t0,_v27
    lw $t0,80($sp)
    sw $t0,_v2
    lw $t0,84($sp)
    sw $t0,_p3
    lw $t0,88($sp)
    sw $t0,_v12
    lw $t0,92($sp)
    sw $t0,_p2
    lw $t0,96($sp)
    sw $t0,_p1
    lw $t0,100($sp)
    sw $t0,_n
    lw $t0,104($sp)
    sw $t0,_v4
    lw $t0,108($sp)
    sw $t0,_v1
    lw $t0,112($sp)
    sw $t0,_v3
    lw $t0,116($sp)
    sw $t0,_v6
    lw $t0,120($sp)
    sw $t0,_v22
    lw $t0,124($sp)
    sw $t0,_v8
    lw $t0,128($sp)
    sw $t0,_v9
    lw $ra, 132($sp)
    addi $sp, $sp, 136
    sw $v0,_v13

    li   $t0,10000
    sw   $t0,_v25

    move $t0,$a1
    lw   $t1,_v25
    mul  $t2,$t0,$t1
    sw   $t2,_v22

    lw   $t0,_v22
    move $t1,$a3
    add  $t2,$t0,$t1
    sw   $t2,_v21

    addi $sp, $sp, -8 ### push stack to store $ra
    sw   $a0,  0($sp) ## store $a0
    sw   $ra,  4($sp) ### store $ra
    lw   $t0,_v21
    move $a0,  $t0
    jal  write ### invoke write
    lw   $ra,  4($sp) ## read $ra
    lw   $a0,  0($sp) ## store $a0
    addi $sp, $sp, 8

    li   $t0,1
    sw   $t0,_v29

    move $t0,$a0
    lw   $t1,_v29
    sub  $t2,$t0,$t1
    sw   $t2,_v27

    addi $sp, $sp, -136
    sw $a0,  0($sp) ## store $a0
    sw $a1,  4($sp) ## store $a1
    sw $a2,  8($sp) ## store $a2
    sw $a3,  12($sp) ## store $a3
    lw $t0,_v40
    sw $t0, 16($sp)
    lw $t0,_v41
    sw $t0, 20($sp)
    lw $t0,_v39
    sw $t0, 24($sp)
    lw $t0,_v38
    sw $t0, 28($sp)
    lw $t0,_v33
    sw $t0, 32($sp)
    lw $t0,_v29
    sw $t0, 36($sp)
    lw $t0,_v21
    sw $t0, 40($sp)
    lw $t0,_v13
    sw $t0, 44($sp)
    lw $t0,_v35
    sw $t0, 48($sp)
    lw $t0,_v25
    sw $t0, 52($sp)
    lw $t0,_v14
    sw $t0, 56($sp)
    lw $t0,_v16
    sw $t0, 60($sp)
    lw $t0,_v36
    sw $t0, 64($sp)
    lw $t0,_sum
    sw $t0, 68($sp)
    lw $t0,_v26
    sw $t0, 72($sp)
    lw $t0,_v27
    sw $t0, 76($sp)
    lw $t0,_v2
    sw $t0, 80($sp)
    lw $t0,_p3
    sw $t0, 84($sp)
    lw $t0,_v12
    sw $t0, 88($sp)
    lw $t0,_p2
    sw $t0, 92($sp)
    lw $t0,_p1
    sw $t0, 96($sp)
    lw $t0,_n
    sw $t0, 100($sp)
    lw $t0,_v4
    sw $t0, 104($sp)
    lw $t0,_v1
    sw $t0, 108($sp)
    lw $t0,_v3
    sw $t0, 112($sp)
    lw $t0,_v6
    sw $t0, 116($sp)
    lw $t0,_v22
    sw $t0, 120($sp)
    lw $t0,_v8
    sw $t0, 124($sp)
    lw $t0,_v9
    sw $t0, 128($sp)
    sw $ra, 132($sp)
    lw $a3,12($sp)
    lw $a2,4($sp)
    lw $a1,8($sp)
    lw $a0,76($sp)
    jal hanoi
    lw $a0,  0($sp) ## store $a0
    lw $a1,  4($sp) ## store $a1
    lw $a2,  8($sp) ## store $a2
    lw $a3,  12($sp) ## store $a3
    lw $t0,16($sp)
    sw $t0,_v40
    lw $t0,20($sp)
    sw $t0,_v41
    lw $t0,24($sp)
    sw $t0,_v39
    lw $t0,28($sp)
    sw $t0,_v38
    lw $t0,32($sp)
    sw $t0,_v33
    lw $t0,36($sp)
    sw $t0,_v29
    lw $t0,40($sp)
    sw $t0,_v21
    lw $t0,44($sp)
    sw $t0,_v13
    lw $t0,48($sp)
    sw $t0,_v35
    lw $t0,52($sp)
    sw $t0,_v25
    lw $t0,56($sp)
    sw $t0,_v14
    lw $t0,60($sp)
    sw $t0,_v16
    lw $t0,64($sp)
    sw $t0,_v36
    lw $t0,68($sp)
    sw $t0,_sum
    lw $t0,72($sp)
    sw $t0,_v26
    lw $t0,76($sp)
    sw $t0,_v27
    lw $t0,80($sp)
    sw $t0,_v2
    lw $t0,84($sp)
    sw $t0,_p3
    lw $t0,88($sp)
    sw $t0,_v12
    lw $t0,92($sp)
    sw $t0,_p2
    lw $t0,96($sp)
    sw $t0,_p1
    lw $t0,100($sp)
    sw $t0,_n
    lw $t0,104($sp)
    sw $t0,_v4
    lw $t0,108($sp)
    sw $t0,_v1
    lw $t0,112($sp)
    sw $t0,_v3
    lw $t0,116($sp)
    sw $t0,_v6
    lw $t0,120($sp)
    sw $t0,_v22
    lw $t0,124($sp)
    sw $t0,_v8
    lw $t0,128($sp)
    sw $t0,_v9
    lw $ra, 132($sp)
    addi $sp, $sp, 136
    sw $v0,_v26

label3:
    li   $t0,0
    sw   $t0,_v33

    lw $s7,28($sp)
    lw $s6,24($sp)
    lw $s5,20($sp)
    lw $s4,16($sp)
    lw $s3,12($sp)
    lw $s2,8($sp)
    lw $s1,4($sp)
    lw $s0,0($sp)
    addi $sp,$sp,32
    lw   $t0,_v33
    move $v0,$t0
    jr $ra

main:
    addi $sp,$sp,-32
    sw $s0,0($sp)
    sw $s1,4($sp)
    sw $s2,8($sp)
    sw $s3,12($sp)
    sw $s4,16($sp)
    sw $s5,20($sp)
    sw $s6,24($sp)
    sw $s7,28($sp)

    li   $t0,3
    sw   $t0,_v35

    li   $t0,1
    sw   $t0,_v38

    li   $t0,2
    sw   $t0,_v39

    li   $t0,3
    sw   $t0,_v40

    addi $sp, $sp, -136
    sw $a0,  0($sp) ## store $a0
    sw $a1,  4($sp) ## store $a1
    sw $a2,  8($sp) ## store $a2
    sw $a3,  12($sp) ## store $a3
    lw $t0,_v40
    sw $t0, 16($sp)
    lw $t0,_v41
    sw $t0, 20($sp)
    lw $t0,_v39
    sw $t0, 24($sp)
    lw $t0,_v38
    sw $t0, 28($sp)
    lw $t0,_v33
    sw $t0, 32($sp)
    lw $t0,_v29
    sw $t0, 36($sp)
    lw $t0,_v21
    sw $t0, 40($sp)
    lw $t0,_v13
    sw $t0, 44($sp)
    lw $t0,_v35
    sw $t0, 48($sp)
    lw $t0,_v25
    sw $t0, 52($sp)
    lw $t0,_v14
    sw $t0, 56($sp)
    lw $t0,_v16
    sw $t0, 60($sp)
    lw $t0,_v36
    sw $t0, 64($sp)
    lw $t0,_sum
    sw $t0, 68($sp)
    lw $t0,_v26
    sw $t0, 72($sp)
    lw $t0,_v27
    sw $t0, 76($sp)
    lw $t0,_v2
    sw $t0, 80($sp)
    lw $t0,_p3
    sw $t0, 84($sp)
    lw $t0,_v12
    sw $t0, 88($sp)
    lw $t0,_p2
    sw $t0, 92($sp)
    lw $t0,_p1
    sw $t0, 96($sp)
    lw $t0,_n
    sw $t0, 100($sp)
    lw $t0,_v4
    sw $t0, 104($sp)
    lw $t0,_v1
    sw $t0, 108($sp)
    lw $t0,_v3
    sw $t0, 112($sp)
    lw $t0,_v6
    sw $t0, 116($sp)
    lw $t0,_v22
    sw $t0, 120($sp)
    lw $t0,_v8
    sw $t0, 124($sp)
    lw $t0,_v9
    sw $t0, 128($sp)
    sw $ra, 132($sp)
    lw $a3,16($sp)
    lw $a2,24($sp)
    lw $a1,28($sp)
    lw $a0,48($sp)
    jal hanoi
    lw $a0,  0($sp) ## store $a0
    lw $a1,  4($sp) ## store $a1
    lw $a2,  8($sp) ## store $a2
    lw $a3,  12($sp) ## store $a3
    lw $t0,16($sp)
    sw $t0,_v40
    lw $t0,20($sp)
    sw $t0,_v41
    lw $t0,24($sp)
    sw $t0,_v39
    lw $t0,28($sp)
    sw $t0,_v38
    lw $t0,32($sp)
    sw $t0,_v33
    lw $t0,36($sp)
    sw $t0,_v29
    lw $t0,40($sp)
    sw $t0,_v21
    lw $t0,44($sp)
    sw $t0,_v13
    lw $t0,48($sp)
    sw $t0,_v35
    lw $t0,52($sp)
    sw $t0,_v25
    lw $t0,56($sp)
    sw $t0,_v14
    lw $t0,60($sp)
    sw $t0,_v16
    lw $t0,64($sp)
    sw $t0,_v36
    lw $t0,68($sp)
    sw $t0,_sum
    lw $t0,72($sp)
    sw $t0,_v26
    lw $t0,76($sp)
    sw $t0,_v27
    lw $t0,80($sp)
    sw $t0,_v2
    lw $t0,84($sp)
    sw $t0,_p3
    lw $t0,88($sp)
    sw $t0,_v12
    lw $t0,92($sp)
    sw $t0,_p2
    lw $t0,96($sp)
    sw $t0,_p1
    lw $t0,100($sp)
    sw $t0,_n
    lw $t0,104($sp)
    sw $t0,_v4
    lw $t0,108($sp)
    sw $t0,_v1
    lw $t0,112($sp)
    sw $t0,_v3
    lw $t0,116($sp)
    sw $t0,_v6
    lw $t0,120($sp)
    sw $t0,_v22
    lw $t0,124($sp)
    sw $t0,_v8
    lw $t0,128($sp)
    sw $t0,_v9
    lw $ra, 132($sp)
    addi $sp, $sp, 136
    sw $v0,_v36

    li   $t0,0
    sw   $t0,_v41

    lw $s7,28($sp)
    lw $s6,24($sp)
    lw $s5,20($sp)
    lw $s4,16($sp)
    lw $s3,12($sp)
    lw $s2,8($sp)
    lw $s1,4($sp)
    lw $s0,0($sp)
    addi $sp,$sp,32
    lw   $t0,_v41
    move $v0,$t0
    jr $ra

