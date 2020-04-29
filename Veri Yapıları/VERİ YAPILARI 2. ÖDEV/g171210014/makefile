VPATH= ./src
CXXFLAGS= -I "./include"

all: PROGRAM Calis

PROGRAM:Dugum.o  islemler.o Kaynak.o Stack.o  
	g++ Dugum.o islemler.o Kaynak.o Stack.o  -o PROGRAM

Dugum.o:Dugum.cpp
	g++ -c $(CXXFLAGS) $<
islemler.o:islemler.cpp
	g++ -c $(CXXFLAGS) $<
Kaynak.o:Kaynak.cpp
	g++ -c $(CXXFLAGS) $<
Stack.o:Stack.cpp
	g++ -c $(CXXFLAGS) $<

Calis:PROGRAM.exe
	./PROGRAM.exe