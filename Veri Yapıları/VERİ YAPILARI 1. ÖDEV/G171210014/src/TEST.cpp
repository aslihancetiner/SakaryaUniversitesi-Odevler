/**        
* @file  Test.cpp
* @description Main in bulundugu cpp  
* @course  Veri Yapilari 2. Ogretim C Grubu
* @assignment  1. Odev  
* @date  30.03.2018
* @author  Aslihan Cetiner aslihancetiner@hotmail.com
  */
#include "SINIF.h"
#include"Okul.h"
#include"YonetimSinifi.h"
#include <iostream>
using namespace std;
int main()
{
	Okul* Okul1 = new Okul();
	YonetimSinifi Yonetim;
	char Veri1, Veri2;
	int Secim=0;
	Okul1->SinifEKLE();
	Okul1->SinifiYaz();
	do
	{
		cout << "1-Sinif Degistir \n";
		cout << "2-Ogrenci Degistir \n";
		cout << "3-Cikis\n";
		cout << "SECIMINIZ :  ";
		cin >> Secim;
		switch (Secim)
		{
		case 1:
			cout << "Degistirilcek ilk sinifi Giriniz : ";
			cin >> Veri1;
			cout << "Degistirilcek ikinci sinifi Giriniz : ";
			cin >> Veri2;
			
			Yonetim.SinifDegistir(Veri1, Veri2,Okul1);
			break;
		case 2:
			cout<< "Degistirilcek ilk Ogrenciyi Giriniz : ";
			cin >> Veri1;
			cout<< "Degistirilcek ikinci Ogrenciyi Giriniz : ";
			cin >> Veri2;
			Yonetim.OgrenciDegistir(Veri1, Veri2,Okul1);
			break;
		}
	} while (Secim != 3);
	delete Okul1;
	system("PAUSE");
	return 0;
}