#ifndef INSTRUCTION   
#define INSTRUCTION


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define NUM_INSTRTYPE 30  //MOV PUSH CALL the num of op type

typedef enum OP {
    MOV,  //0
    PUSH, //1
    CALL,  //2
    add_reg_reg //3
} op_t;

typedef enum OD_TYPE
{
    IMM, REG, MM_IMM, 
    MM_REG, MM_IMM_REG, MM_REG1_REG2,
    MM_IMM_REG1_REG2, MM_REG2_S, MM_IMM_REG2_S, 
    MM_REG1_REG2_S, MM_IMM_REG1_REGS_S
}od_type_t;

typedef struct OD
{
    od_type_t type;
    int64_t imm;
    uint64_t scal;
    uint64_t *reg1;
    uint64_t *reg2;
    char code[100];
}od_t;

typedef struct INSTRUCT_STRUCT
{
    op_t op;//mov,push
    od_t src;
    od_t dst;
} inst_t;

typedef void (*handler_t)(uint64_t, uint64_t);//函数类型
handler_t handler_table[NUM_INSTRTYPE];//函数数组

void instruction_cycle();
void add_reg_reg_handler(uint64_t src, uint64_t dst);

#endif