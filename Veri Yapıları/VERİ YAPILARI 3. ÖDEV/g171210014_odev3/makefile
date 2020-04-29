VPATH= ./src
CXXFLAGS= -I "./include"

all: PROGRAM Calis

PROGRAM:agac.o  Kaynak.o kok.o
	g++ agac.o  Kaynak.o kok.o   -o PROGRAM

agac.o:agac.cpp
	g++ -c $(CXXFLAGS) $<
Kaynak.o:Kaynak.cpp
	g++ -c $(CXXFLAGS) $<
kok.o:kok.cpp
	g++ -c $(CXXFLAGS) $<


Calis:PROGRAM.exe
	./PROGRAM.exe