# 28-02-2022
# alex

EXE = prova # Executable
OBJ = bchc.o prova.o recur.o # Objectes
COM = gcc # Compilador
LIB = -lm # Llibreries (-l*, -L*, -I*)
MAC = -D_GNU_SOURCE # Macros (-D*)
AVS = -W -Wall -Wextra -ansi -pedantic # Avisos
OPT = -march=native -O2 -pipe # Optimitzacio
DEP = -g -DDEBUG # Depuracio, no recomanable junt amb $(OPT)
OPC = $(DEP) $(AVS) $(MAC) -std=c11 # Opcions
DIR = /usr/local/bin # Directori per a instalar

all: $(EXE)

$(EXE): $(OBJ)
	@echo Enllaçant $(OBJ) per a crear $(EXE)
	$(COM) $(LIB) $(OBJ) -o $@

bchc.o: bchc.c bchc.h recur.h
	@echo Compilant $<
	$(COM) $(LIB) $(OPC) -c $<

prova.o: prova.c bchc.h recur.h
	@echo Compilant $<
	$(COM) $(LIB) $(OPC) -c $<

recur.o: recur.c recur.h
	@echo Compilant $<
	$(COM) $(LIB) $(OPC) -c $<

exe: all
	./$(EXE)

install: all
	mkdir -p $(DIR)
	cp $(EXE) $(DIR)
	chown root:staff $(EXE)

clean:
	@echo Netejant...
	rm -rf $(EXE) $(OBJ) *~
