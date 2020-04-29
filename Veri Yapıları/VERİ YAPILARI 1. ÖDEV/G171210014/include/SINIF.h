/**        
* @file  SINIF.h
* @description SINIF.cpp nin h dosyasi 
* @course  Veri Yapilari 2. Ogretim C Grubu
* @assignment  1. Odev  
* @date  30.03.2018
* @author  Aslihan Cetiner aslihancetiner@hotmail.com
  */
#ifndef SINIF_H
#define SINIF_H
#include "OGRENCI.h"
class SINIF
{
private:
	char SinifAdi;


public:
	SINIF();
	SINIF(char);
	char ATA = 0;
	char SinifAdiGetir();
	void OgrenciEkle();
	void SinifiEkranaYaz();
	OGRENCI *ogrdizisi[10];
};
#endif
