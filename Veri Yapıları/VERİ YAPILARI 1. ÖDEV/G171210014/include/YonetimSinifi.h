/**        
* @file  YonetimSinifi.h
* @description YonetimSinifi.cpp nin h dosyasi 
* @course  Veri Yapilari 2. Ogretim C Grubu
* @assignment  1. Odev  
* @date  30.03.2018
* @author  Aslihan Cetiner aslihancetiner@hotmail.com
  */
#ifndef YonetimSinifi_H
#define YonetimSinifi_H
#include"Okul.h"
#include"SINIF.h"
#include "OGRENCI.h"
class YonetimSinifi
{
private:
	
public:
	YonetimSinifi();
	void SinifDegistir(char,char,Okul*);
	void OgrenciDegistir(char,char,Okul*);
};
#endif