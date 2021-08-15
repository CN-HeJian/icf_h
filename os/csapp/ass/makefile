CC = D:/gcc/bin/gcc
CFLAGS = -Wall -g -O2 -Werror -Wformat=0 -std=gnu99

EXE = csapp

SRC = ./src

CODE = ./src/memory/instruction.c ./src/disk/code.c ./src/memory/dram.c ./src/cpu/mmu.c  ./src/main.c ./src/cpu/register.c

.PHONY: csapp

csapp:
	$(CC) $(CFLAGS) -I$(SRC) $(CODE) -o $(EXE)
	./$(EXE)
#D:/gcc/bin/gcc -Wall -g -O2 -Werror -std=gnu99 -I./src ./src/memory/instruction.c ./src/disk/code.c ./src/main.c -o program

clean:
	rm -f *.o *~$(EXE)