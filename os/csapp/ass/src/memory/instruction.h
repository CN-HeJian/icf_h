#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MM_LEN 1000
uint8_t mm[MM_LEN];//memory

typedef enum OP {
    MOV,  //0
    PUSH, //1
    CALL  //2
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
    uint64_t reg1;
    uint64_t reg2;
    uint64_t scal;
    char code[100];
}od_t;

typedef struct INSTRUCT_STRUCT
{
    op_t op;//mov,push
    od_t src;
    od_t dst;
} inst_t;

#define INST_LEN 100

inst_t prgram[INST_LEN];

uint64_t decode_od(od_t od);