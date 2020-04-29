#ifndef RASTGELEKISI_H
#define RASTGELEKISI_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Kisi.h"
#include "Rastgele.h"
#include "Telefon.h"
#include "IMEINo.h"
// Rastgelekişi sınıf yapısı ve fonksiyon göstericileri
struct RASTGELEKISI{
	Kisi kisiler;
	Rastgele r;
	Telefon t;
	KimlikNo k;
	IMEINo im;
	void(*rastgelekisiuret)(struct RASTGELEKISI*,int);
	void(*uretilmiskontrol)(struct RASTGELEKISI*);
	char* (*oku)(struct RASTGELEKISI*);
	void (*rastgelekisiYoket)(struct RASTGELEKISI*); 
};

typedef struct RASTGELEKISI* RastgeleKisi;
RastgeleKisi RastgeleKisiOlustur();
void RastgeleKisiUret(const RastgeleKisi,int);
void UretilmisKontrol(RastgeleKisi);
char* Oku(RastgeleKisi);
void RastgeleKisiYoket(RastgeleKisi);
#endif