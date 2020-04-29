INCLUDE = include/
SRC = src/


EX = libfdr.a chain_heal
all: $(EX) 


fields.o: $(SRC)fields.c $(INCLUDE)fields.h
	gcc -c $(SRC)fields.c
	
libfdr.a: fields.o
	ar ru libfdr.a fields.o
	ranlib libfdr.a 

chain_heal: $(SRC)chain_heal.c $(INCLUDE)chain_heal.h $(INCLUDE)fields.h
	gcc -o chain_heal $(SRC)chain_heal.c libfdr.a -lm


.SUFFIXES: .c .o

clean: 
	rm -f $(EX) 
