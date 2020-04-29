/**        
* @file  OGRENCI.cpp
* @description Ogrenci nesnesinin bulundugu cpp  
* @course  Veri Yapilari 2. Ogretim C Grubu
* @assignment  1. Odev  
* @date  30.03.2018
* @author  Aslihan Cetiner aslihancetiner@hotmail.com
  */
#include "OGRENCI.h"
OGRENCI::OGRENCI()
{

}

OGRENCI::OGRENCI(char a)
{
	OgrAdi = a;
}

char OGRENCI::OgrenciAdiGETIR()
{
	return OgrAdi;
}

