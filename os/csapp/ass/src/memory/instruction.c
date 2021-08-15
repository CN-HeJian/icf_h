#include "instruction.h"
#include "cpu/mmu.h"
#include "cpu/register.h"
#include "dram.h"
#include <stdio.h>
handler_t handler_table[NUM_INSTRTYPE];

extern reg_t reg;
extern handler_t handler_table[NUM_INSTRTYPE];

static uint64_t decode_od(od_t od){
    if(od.type == IMM){
        return *((uint64_t *)&od.imm);
    }else if(od.type == REG){
        return (uint64_t)od.reg1; //返回的是虚拟地址
    }else{
        uint64_t vaddr = 0;
        if(od.type == MM_IMM){
            vaddr = *((uint64_t*)&od.imm);
        }else if(od.type == MM_REG){
            vaddr = *(od.reg1);//virtual address
        }else if(od.type == MM_IMM_REG){
            vaddr = od.imm + *(od.reg1);
        }else if(od.type == MM_REG1_REG2){
            vaddr = *(od.reg1) + *(od.reg2);
        }else if(od.type == MM_IMM_REG1_REG2){
            vaddr = od.imm + *(od.reg1) + *(od.reg2);
        }else if(od.type == MM_REG2_S){
            vaddr = (*(od.reg2)) * od.scal;
        }else if(od.type == MM_IMM_REG2_S){
            vaddr = od.imm + (*(od.reg2)) * od.scal;
        }else if(od.type == MM_REG1_REG2_S){
            vaddr = *(od.reg1) + (*(od.reg2)) * od.scal;
        }else if(od.type == MM_IMM_REG1_REGS_S){
            vaddr = od.imm + *(od.reg1) + (*(od.reg2)) * od.scal;
        }
        return vaddr;
    }
}

void instruction_cycle(){
    inst_t *instr = (inst_t *)reg.rip;
    //imm:imm
    //reg:value
    //mm：paddr
    uint64_t src = decode_od(instr->src);
    uint64_t dst = decode_od(instr->dst);

    //fuction_table
    handler_t  handler  = handler_table[instr->op];
   
    // src = &rax  dst = &rbx
    handler(src, dst);

    //print instruction 
    printf("    %s\n", instr->code);
}

void init_handler_table(){
    handler_table[mov_reg_reg] = &mov_reg_reg_handler;
    handler_table[call] = &call_handler;
    handler_table[add_reg_reg] = &add_reg_reg_handler;
    handler_table[push_reg] = &push_reg_handler;
    handler_table[pop_reg] = &pop_reg_handler;
    handler_table[mov_reg_mem] = &mov_reg_mem_handler;
    handler_table[mov_mem_reg] = &mov_mem_reg_handler;
    handler_table[ret] = &ret_handler;
}

void mov_reg_reg_handler(uint64_t src, uint64_t dst){
    *(uint64_t *)dst = *(uint64_t *)src;
    reg.rip = reg.rip + sizeof(inst_t);
}

void mov_reg_mem_handler(uint64_t src, uint64_t dst){
    write64Bits_ram(
        va2pa(dst),
        *(uint64_t*)src
    );
    reg.rip = reg.rip + sizeof(inst_t);
}

void mov_mem_reg_handler(uint64_t src, uint64_t dst){
    *(uint64_t *)dst = read64Bits_ram(va2pa(src));
    reg.rip = reg.rip + sizeof(inst_t);
}

void push_reg_handler(uint64_t src,uint64_t dst){
    reg.rsp = reg.rsp - 0x8;
    write64Bits_ram(
        va2pa(reg.rsp),
        *(uint64_t *)src
    );
    reg.rip = reg.rip + sizeof(inst_t);
}

void pop_reg_handler(uint64_t src,uint64_t dst){
    *(uint64_t*)src  = read64Bits_ram(va2pa(reg.rsp));
    reg.rsp = reg.rsp + 8;
    reg.rip = reg.rip + sizeof(inst_t);
}

void ret_handler(uint64_t src,uint64_t dst){
    uint64_t ret_addr = read64Bits_ram(va2pa(reg.rsp));
    reg.rsp += 8;
    reg.rip = ret_addr;
}

void call_handler(uint64_t src,uint64_t dst){
    reg.rsp = reg.rsp - 8;
    write64Bits_ram(
        va2pa(reg.rsp),
        reg.rip + sizeof(inst_t)  //call instruction size
    );
    reg.rip = src;
}

void add_reg_reg_handler(uint64_t src,uint64_t dst){
    *(uint64_t *)dst = *(uint64_t *)dst + *(uint64_t *)src;
    reg.rip = reg.rip + sizeof(inst_t);
}