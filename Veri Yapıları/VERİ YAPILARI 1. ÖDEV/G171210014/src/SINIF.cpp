/**        
* @file  SINIF.cpp
* @description Sinif Classi Ogrenci Dizisinin ve Sinif adinin  bulundugu cpp  
* @course  Veri Yapilari 2. Ogretim C Grubu
* @assignment  1. Odev  
* @date  30.03.2018
* @author  Aslihan Cetiner aslihancetiner@hotmail.com
  */
#include "SINIF.h"
#include "OGRENCI.h"
#include <iostream>
#include <fstream>
#include<string>
using namespace std;
SINIF::SINIF()
{

}
SINIF::SINIF(char i)
{
	SinifAdi = i;
}

char SINIF::SinifAdiGetir()
{
	return SinifAdi;
}

void SINIF::OgrenciEkle()
{ 
	ifstream DosyaOku("Okul.txt");
	string satir;
	char SatirAdi;
	char harf;
	while (getline(DosyaOku,satir))
	{
		for (char i = 0; i <= satir.size(); i++)
		{
			harf = satir[i];
			if (i==0)
			{
				SatirAdi=harf;
			}
			else if (SatirAdi==SinifAdi)
			{
				if (harf == ' ')
				{
					continue;
				}
				else
				{
					ogrdizisi[ATA] = new OGRENCI(harf);
					ATA++;
				}
			}

		}
	}
}

void SINIF::SinifiEkranaYaz()
{
	for (int i = 0; i < ATA; i++)
	{
		cout << ogrdizisi[i]->OgrenciAdiGETIR()<<" ";
	}
}
