#ifndef RASTGELE_H
#define RASTGELE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Rastgele sınıf yapısı ve fonksiyon göstericileri
struct RASTGELE{
	unsigned previous;
	unsigned short lfsr;
	unsigned bit;
	int(*randomuret)(struct RASTGELE*);
	unsigned(*randomruret)(struct RASTGELE*);
	unsigned(*randomyasuret)(struct RASTGELE*);
	void (*Yoket)(struct RASTGELE*); 
};

typedef struct RASTGELE* Rastgele;

// Fonksiyon prototipleri yazildi.
Rastgele RastgeleOlustur();

int system_clock();
int RandomUret(const Rastgele);
int RandomRUret(const Rastgele);
unsigned RandomYasUret(const Rastgele);
void RastgeleYoket(Rastgele);

#endif