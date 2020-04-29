#ifndef KIMLIKNO_H
#define KIMLIKNO_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Rastgele.h"


// kimlikno sınıf yapısı ve fonksiyon göstericileri
struct KIMLIKNO{
	char* tc;
	Rastgele r;
	int*(*tcuret)(struct KIMLIKNO*);
	char*(*kimlikal)(struct KIMLIKNO*);
	bool(*tcKontrol)(struct KIMLIKNO*,char*);
	char*(*tcyaz)(struct KIMLIKNO*);
	void (*tcYoket)(struct KIMLIKNO*); 
};

typedef struct KIMLIKNO* KimlikNo;
KimlikNo KimlikNoOlustur();
int* TcUret(const KimlikNo);
char* AlKimlikno(KimlikNo);
bool TcKontrolEt(KimlikNo,char*);
char* TcYaz(const KimlikNo);
void TcYoket(KimlikNo);
#endif