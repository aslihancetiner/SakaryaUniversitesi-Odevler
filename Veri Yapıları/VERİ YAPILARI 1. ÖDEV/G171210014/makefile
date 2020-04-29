VPATH= ./src
CXXFLAGS= -I "./include"

all: PROGRAM Calis

PROGRAM:TEST.o  OGRENCI.o Okul.o SINIF.o  YonetimSinifi.o
	g++ TEST.o OGRENCI.o Okul.o SINIF.o  YonetimSinifi.o -o PROGRAM

OGRENCI.o:OGRENCI.cpp
	g++ -c $(CXXFLAGS) $<
Okul.o:Okul.cpp
	g++ -c $(CXXFLAGS) $<
SINIF.o:SINIF.cpp
	g++ -c $(CXXFLAGS) $<
TEST.o:TEST.cpp
	g++ -c $(CXXFLAGS) $<
YonetimSinifi.o:YonetimSinifi.cpp
	g++ -c $(CXXFLAGS) $<

Calis:PROGRAM.exe
	./PROGRAM.exe