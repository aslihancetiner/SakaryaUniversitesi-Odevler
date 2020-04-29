/**        
* @file  OGRENCI.h
* @description  OGRENCI.cpp nin h dosyasi  
* @course  Veri Yapilari 2. Ogretim C Grubu
* @assignment  1. Odev  
* @date  30.03.2018
* @author  Aslihan Cetiner aslihancetiner@hotmail.com
  */
#ifndef OGRENCI_H
#define OGRENCI_H
class OGRENCI
{
private:
	char OgrAdi;
public:
	OGRENCI();
	OGRENCI(char);
	char OgrenciAdiGETIR();
	
};
#endif