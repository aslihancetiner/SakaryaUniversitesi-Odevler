#ifndef TELEFON_H
#define TELEFON_H

#include <stdio.h>
#include <stdlib.h>
#include "Rastgele.h"
#include "IMEINo.h"

// telefon sınıf yapısı ve fonksiyon göstericileri
struct TELEFON{
	char* no;
	Rastgele r;
	IMEINo im;
	int*(*teluret)(struct TELEFON*);
	char*(*telal)(struct TELEFON*);
	char*(*telyaz)(struct TELEFON*);
	void (*telYoket)(struct TELEFON*); 
};

typedef struct TELEFON* Telefon;
Telefon TelefonOlustur();
int* TelUret(const Telefon);
char* Alno(Telefon);
char* TelYaz(const Telefon);
void TelefonYoket(Telefon);
#endif