#include <iostream>
#include <fstream>
#include <string>
#include "Dugum.h"
#include "islemler.h"
using namespace std;
int main()
{
	islemler islem;
	int secim;
	int sirasecim;
	do
	{
		cout << "1- Sola Hareket" << endl;
		cout << "2- Saga Hareket" << endl;
		cout << "3- Bir Dugumun Tum Durumlarini Yazdir" << endl;
		cout << "4- Tum Durumlari Yazdir" << endl;
		cout << "5- Cikis" << endl;
		cin >> secim;
		if (secim == 1)
		{
			islem.SolaKaydir(islem.ilk);
		}
		if (secim == 2)
		{
			islem.SagaKaydir(islem.ilk);
		}
		if (secim==3)
		{
			cout << "Dugum Konumu:";
			cin >> sirasecim;
			islem.Bulma(islem.ilk, sirasecim);
			
		}
		if (secim == 4)
		{
			islem.HepsiniYazdir(islem.ilk);
		}

	} while (secim!=5);
	Dugum* yedek1;
	islem.yedek = islem.ilk->next;
	yedek1 = islem.ilk->prev;
	while (islem.yedek->next!=yedek1)
	{
		delete islem.ilk;
		islem.ilk = islem.yedek;
		islem.yedek = islem.yedek->next;
	}
	delete yedek1;
	delete islem.ilk;
	delete islem.yedek;
	system("PAUSE");
	return 0;

}