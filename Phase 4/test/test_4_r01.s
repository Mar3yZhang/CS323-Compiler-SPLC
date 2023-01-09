.data
_prompt: .asciiz "Please enter an integer: "
_ret: .asciiz "\n"

_v15: .word 0
_v14: .word 0
_v11: .word 0
_v12: .word 0
_v9: .word 0
_v7: .word 0
_v5: .word 0
_v3: .word 0
_n: .word 0

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

    addi $sp, $sp, -8 ### push stack to store $ra
    sw   $a0,  0($sp) ## store $a0
    sw   $ra,  4($sp) ### store $ra
    jal  read ### invoke read
    lw   $a0,  0($sp) ## store $a0
    lw   $ra,  4($sp) ## read $ra
    addi $sp, $sp, 8
    move $t0,$v0
    sw   $t0,_v3

    li   $t0,0
    sw   $t0,_v5

    lw   $t0,_v3
    lw   $t1,_v5
    bgt  $t0,$t1,label1

    j label2

label1:
    li   $t0,1
    sw   $t0,_v7

    addi $sp, $sp, -8 ### push stack to store $ra
    sw   $a0,  0($sp) ## store $a0
    sw   $ra,  4($sp) ### store $ra
    lw   $t0,_v7
    move $a0,  $t0
    jal  write ### invoke write
    lw   $ra,  4($sp) ## read $ra
    lw   $a0,  0($sp) ## store $a0
    addi $sp, $sp, 8

    j label6

label2:
    li   $t0,0
    sw   $t0,_v9

    lw   $t0,_v3
    lw   $t1,_v9
    blt  $t0,$t1,label4

    j label5

label4:
    li   $t0,1
    sw   $t0,_v12

    move $t0,$zero
    lw   $t1,_v12
    sub  $t2,$t0,$t1
    sw   $t2,_v11

    addi $sp, $sp, -8 ### push stack to store $ra
    sw   $a0,  0($sp) ## store $a0
    sw   $ra,  4($sp) ### store $ra
    lw   $t0,_v11
    move $a0,  $t0
    jal  write ### invoke write
    lw   $ra,  4($sp) ## read $ra
    lw   $a0,  0($sp) ## store $a0
    addi $sp, $sp, 8

    j label6

label5:
    li   $t0,0
    sw   $t0,_v14

    addi $sp, $sp, -8 ### push stack to store $ra
    sw   $a0,  0($sp) ## store $a0
    sw   $ra,  4($sp) ### store $ra
    lw   $t0,_v14
    move $a0,  $t0
    jal  write ### invoke write
    lw   $ra,  4($sp) ## read $ra
    lw   $a0,  0($sp) ## store $a0
    addi $sp, $sp, 8

label6:
    li   $t0,0
    sw   $t0,_v15

    lw $s7,28($sp)
    lw $s6,24($sp)
    lw $s5,20($sp)
    lw $s4,16($sp)
    lw $s3,12($sp)
    lw $s2,8($sp)
    lw $s1,4($sp)
    lw $s0,0($sp)
    addi $sp,$sp,32
    lw   $t0,_v15
    move $v0,$t0
    jr $ra