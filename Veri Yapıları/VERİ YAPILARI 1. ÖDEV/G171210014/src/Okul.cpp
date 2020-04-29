/**        
* @file  Okul.cpp
* @description Sinif Dizisinin bulundugu ve sinifin Olusturuldugu cpp  
* @course  Veri Yapilari 2. Ogretim C Grubu
* @assignment  1. Odev  
* @date  30.03.2018
* @author  Aslihan Cetiner aslihancetiner@hotmail.com
  */
#include "Okul.h"
#include "SINIF.h"
#include <iostream>
#include<fstream>
#include <string>
using namespace std;
Okul::Okul()
{

}
void Okul::SinifEKLE() 
{
	ifstream Dosya("Okul.txt");
	string SATIR;
	char OkunanDeger;
	while (getline(Dosya,SATIR))
	{
		for (int i = 0; i < SATIR.size(); i++)
		{
			OkunanDeger = SATIR[i];
			if (i==0)
			{
				SinifDizi[ATAMA] = new SINIF(OkunanDeger);
				SinifDizi[ATAMA]->OgrenciEkle();
				ATAMA++;
			}
		}
	}
}
void Okul::SinifiYaz()
{
	int A=0;
	for (int i = 0; i <ATAMA ; i++)
	{
		cout <<"Sinif Adi  : "<< SinifDizi[i]->SinifAdiGetir()<<"   ";
	}
	cout << endl;
	for (int i = 0; i < ATAMA; i++)
	{
		if (SinifDizi[i]->ATA > A-1)
		{
			A = SinifDizi[i]->ATA;
		}
	}
	for (int y = 0; y < A-1; y++)
	{
		for (int i = 0; i <= ATAMA-1; i++)
		{
			if (SinifDizi[i]->ATA-1 <= y)
			{
				cout << "                 ";
				continue;
			}
			cout << SinifDizi[i]->ogrdizisi[y]->OgrenciAdiGETIR() << "    " << SinifDizi[i]->ogrdizisi[y] << "    ";
		}
		cout << endl;
	}


}