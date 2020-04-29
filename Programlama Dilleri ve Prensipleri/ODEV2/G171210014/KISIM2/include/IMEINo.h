#ifndef IMEINO_H
#define IMEINO_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Rastgele.h"


// imeino sınıf yapısı ve fonksiyon göstericileri
struct IMEINO{
	char* imeiNo;
	Rastgele r;
	int*(*imeiuret)(struct IMEINO*);
	char*(*imeial)(struct IMEINO*);
	bool(*imeiKontrol)(struct IMEINO*,char*);
	char*(*imeiyaz)(struct IMEINO*);
	void (*imeiYoket)(struct IMEINO*); 
};

typedef struct IMEINO* IMEINo;
IMEINo IMEINoOlustur();
int* IMEIUret(const IMEINo);
char* Alimeino(IMEINo);
bool IMEIKontrolEt(const IMEINo,char*);
char* IMEIYaz(const IMEINo);
void IMEIYoket(IMEINo);
#endif