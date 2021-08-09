CC = D:/gcc/bin/gcc
CFLAGS = -Wall -g -O2 -Werror -std=gnu99

EXE = program

SRC = ./src

CODE = ./src/memory/instruction.c ./src/memory/dram.c\
 	   ./src/disk/code.c\
       ./src/cpu/mmu.c\
       ./src/main.c\


.PHONY: program

main:
	$(CC) $(CFLAGS) -I$(SRC) $(CODE) -o $(EXE)
#D:/gcc/bin/gcc -Wall -g -O2 -Werror -std=gnu99 -I./src ./src/memory/instruction.c ./src/disk/code.c ./src/main.c -o program

run:
	./$(EXE)