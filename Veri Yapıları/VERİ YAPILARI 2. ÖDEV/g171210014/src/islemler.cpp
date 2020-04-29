#include "islemler.h"
#include "Dugum.h"
#include <iomanip>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

islemler::islemler()
{
	ifstream Oku("sayilar.txt");
	string Satir;
	string Deger;
	int AtamaMiktari = 0;

	while (getline(Oku, Satir))
	{
		for (int i = 0; i <= Satir.size(); i++)
		{
			if (Satir[i] == ' ')
			{
				if (AtamaMiktari == 0)
				{
					ilk = new Dugum(stoi(Deger));
					ilk->next = ilk;
					ilk->prev = ilk;
					Deger = "";
					AtamaMiktari++;
				}
				else
				{
					yedek = ilk;
					while (yedek->next != ilk)
					{
						yedek = yedek->next;
					}
					yedek->next = new Dugum(stoi(Deger));
					yedek->next->prev = yedek;
					yedek->next->next = ilk;
					ilk->prev = yedek->next;
					Deger = "";
				}
			}
			else
			{
				Deger += Satir[i];
			}
		}
	}

	yedek = ilk;
	while (yedek->next != ilk)
	{
		yedek = yedek->next;
	}
	yedek->next = new Dugum(stoi(Deger));
	yedek->next->prev = yedek;
	yedek->next->next = ilk;
	ilk->prev = yedek->next;


}

void islemler::SolaKaydir(Dugum* ilkAdres)
{
	Dugum* Yedek;
	Yedek = ilkAdres;
	int yedeksayi;
	yedeksayi = Yedek->VeriMetot();
	while (Yedek->next != ilkAdres)
	{
		Yedek->VeriDuzelt(Yedek->next->VeriMetot());
		Yedek = Yedek->next;
	}
	Yedek->VeriDuzelt(yedeksayi);
}

void islemler::SagaKaydir(Dugum * ilkAdres)
{
	Dugum* Yedek;
	Yedek = ilkAdres;
	int yedeksayi;
	yedeksayi = Yedek->VeriMetot();
	while (Yedek->prev != ilkAdres)
	{
		Yedek->VeriDuzelt(Yedek->prev->VeriMetot());
		Yedek = Yedek->prev;
	}
	Yedek->VeriDuzelt(yedeksayi);
}

void islemler::Bulma(Dugum *ilkAdres,int sayi)
{
	int sayac = 1;
	Dugum*yedek;
	yedek = ilkAdres;
	while (yedek->next != ilkAdres)
	{
		if (sayac == sayi)
		{
			break;
		}
		sayac++;
		yedek = yedek->next;

		

	}

	cout << setw(6) << yedek->VeriMetot() << setw(6) << ":" << setw(6);
	yedek->StackleriYazdir();
}

void islemler::HepsiniYazdir(Dugum * ilkAdres)
{
	Dugum* yedek=ilkAdres;
	while (yedek->next != ilkAdres)
	{
		cout << setw(6) << yedek->VeriMetot() << setw(6) << ":" << setw(6);
		yedek->StackleriYazdir();
		yedek = yedek->next;
	}
	cout << setw(6) << yedek->VeriMetot() << setw(6) << ":" << setw(6);
	yedek->StackleriYazdir();
}

