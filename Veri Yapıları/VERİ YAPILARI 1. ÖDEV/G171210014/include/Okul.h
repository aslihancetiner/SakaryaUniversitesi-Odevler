/**        
* @file  Okul.h
* @description Okul.cpp nin h dosyasi 
* @course  Veri Yapilari 2. Ogretim C Grubu
* @assignment  1. Odev  
* @date  30.03.2018
* @author  Aslihan Cetiner aslihancetiner@hotmail.com
  */
#ifndef Okul_H
#define Okul_H
#include "SINIF.h"
class Okul
{
public:
	Okul();
	void SinifEKLE();
	void SinifiYaz();
	int ATAMA = 0;
	SINIF* SinifDizi[4];
};
#endif
