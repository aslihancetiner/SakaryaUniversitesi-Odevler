#ifndef KISI_H
#define KISI_H

#include <stdio.h>
#include <stdlib.h>
#include "Rastgele.h"
#include "KimlikNo.h"
#include "Telefon.h"
// kişi sınıf yapısı
struct KISI{
	int yas;
	char* ad;
	char* soyad;
	Telefon tel;
	KimlikNo tc;
	char* telno;
	char* imeino;
	char* kimlikno;
};

typedef struct KISI* Kisi;



#endif