#ifndef islemler_H
#define islemler_H

#include "Dugum.h"
class islemler
{
public:
	Dugum* ilk = NULL;
	Dugum* yedek;
	islemler();
	void SolaKaydir(Dugum*);
	void SagaKaydir(Dugum*);
	void HepsiniYazdir(Dugum*);
	void Bulma(Dugum*,int);
};
#endif
