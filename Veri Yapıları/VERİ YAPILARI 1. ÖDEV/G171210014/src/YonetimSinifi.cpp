/**        
* @file  YonetimSinifi.cpp
* @description Degisim Islemlerinin Bulundugu cpp  
* @course  Veri Yapilari 2. Ogretim C Grubu
* @assignment  1. Odev  
* @date  30.03.2018
* @author  Aslihan Cetiner aslihancetiner@hotmail.com
  */
#include "YonetimSinifi.h"
#include "Okul.h"
#include "SINIF.h"
#include "OGRENCI.h"
YonetimSinifi::YonetimSinifi()
{

}

void YonetimSinifi::SinifDegistir(char A, char B,Okul* Okul1)
{
	for (int i = 0; i <= Okul1->ATAMA; i++)
	{
		if (Okul1->SinifDizi[i]->SinifAdiGetir() == A)
		{
			for (int y = 0; y <= Okul1->ATAMA; y++)
			{
				if (Okul1->SinifDizi[y]->SinifAdiGetir() == B)
				{
					SINIF* temp = Okul1->SinifDizi[i];
					Okul1->SinifDizi[i] = Okul1->SinifDizi[y];
					Okul1->SinifDizi[y] = temp;
					i = Okul1->ATAMA;
					break;
				}
			}
		}
	}
	Okul1->SinifiYaz();
}
void YonetimSinifi::OgrenciDegistir(char A,char B,Okul* Okul1)
{
	int x1;
	int y1;
	int x2;
	int y2;
	for (int i = 0; i <Okul1->ATAMA; i++)
	{

		for (int y = 0; y <= Okul1->ATAMA; y++)
		{
			if (Okul1->SinifDizi[i]->ATA<= y)
			{
				break;
			}
			if (Okul1->SinifDizi[i]->ogrdizisi[y]->OgrenciAdiGETIR() == A)
			{
				x1 = i;
				y1 = y;
			}
			if (Okul1->SinifDizi[i]->ogrdizisi[y]->OgrenciAdiGETIR() == B)
			{
				x2 = i;
				y2 = y;
			}
		}
	}
	OGRENCI* OGRENCIM = Okul1->SinifDizi[x1]->ogrdizisi[y1];
	Okul1->SinifDizi[x1]->ogrdizisi[y1] = Okul1->SinifDizi[x2]->ogrdizisi[y2];
	Okul1->SinifDizi[x2]->ogrdizisi[y2] = OGRENCIM;
	Okul1->SinifiYaz();
}
