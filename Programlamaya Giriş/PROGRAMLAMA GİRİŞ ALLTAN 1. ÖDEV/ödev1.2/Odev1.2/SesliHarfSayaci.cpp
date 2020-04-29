
/****************************************************************************
**					SAKARYA ÜNÝVERSÝTESÝ
**			         BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**				    BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**				          PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**				ÖDEV NUMARASI…...: 1
**				ÖÐRENCÝ ADI...............: ASLIHAN ÇETÝNER
**				ÖÐRENCÝ NUMARASI.: G171210014
**				DERS GRUBU…………: 1. ÖÐRETÝM B GRUBU
****************************************************************************/

#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <iomanip> 
#include<locale.h>

using namespace std;

int main(int argc, char*argv[])
{
	setlocale(LC_ALL, "Turkish");

	char harf = 'b';
	int sayac = 0;
	int asayac = 0;
	int esayac = 0;
	int ýsayac = 0;
	int ý_sayac = 0; //i sayacý
	int osayac = 0;
	int o_sayac = 0; //ö sayacý
	int usayac = 0;
	int u_sayac = 0; //ü sayacý
	int max = 0;
	cout << "kelime gir:" << endl;

	while (harf != '\r') //okunan harf enter olana kadar döngüye devam et.
	{
		harf = _getche();

		if (harf == 'a' || harf == 'A')
		{
			asayac++;
		}
		if (harf == 'e' || harf == 'E')
		{
			esayac++;
		}
		if (harf == 'ý' || harf == 'I')
		{
			ýsayac++;
		}
		if (harf == 'i' || harf == 'Ý')
		{
			ý_sayac++;
		}
		if (harf == 'o' || harf == 'O')
		{
			osayac++;
		}
		if (harf == 'ö' || harf == 'Ö')
		{
			o_sayac++;
		}
		if (harf == 'u' || harf == 'U')
		{
			usayac++;
		}
		if (harf == 'ü' || harf == 'Ü')
		{
			u_sayac++;
		}

	}
	sayac = asayac + esayac + ýsayac + ý_sayac + osayac + o_sayac + usayac + u_sayac;
	if (asayac>max)
	{
		max = asayac;
	}
	if (esayac>max)
	{
		max = esayac;
	}
	if (ýsayac>max)
	{
		max = ýsayac;
	}
	if (ý_sayac>max)
	{
		max = ý_sayac;
	}
	if (osayac>max)
	{
		max = osayac;
	}
	if (o_sayac>max)
	{
		max = o_sayac;
	}
	if (usayac>max)
	{
		max = usayac;
	}
	if (u_sayac>max)
	{
		max = u_sayac;
	}

	cout << "" << endl;
	cout << setw(4) << "Harf" << setw(4) << "TS" << setw(4);
	for (int i = 1; i <= max; i++)
	{
		cout << i << setw(4);
	}
	cout << endl;
	cout << setw(4) << "A" << setw(4) << asayac << setw(4);
	for (int i = 1; i <= asayac; i++)
	{
		cout << "a" << setw(4);
	}
	cout << endl;

	cout << setw(4) << "E" << setw(4) << esayac << setw(4);
	for (int i = 1; i <= esayac; i++)
	{
		cout << "e" << setw(4);
	}
	cout << endl;

	cout << setw(4) << "I" << setw(4) << ýsayac << setw(4);
	for (int i = 1; i <= ýsayac; i++)
	{
		cout << "ý" << setw(4);
	}
	cout << endl;

	cout << setw(4) << "Ý" << setw(4) << ý_sayac << setw(4);
	for (int i = 1; i <= ý_sayac; i++)
	{
		cout << "i" << setw(4);
	}
	cout << endl;

	cout << setw(4) << "O" << setw(4) << osayac << setw(4);
	for (int i = 1; i <= osayac; i++)
	{
		cout << "o" << setw(4);
	}
	cout << endl;
	cout << setw(4) << "Ö" << setw(4) << o_sayac << setw(4);
	for (int i = 1; i <= o_sayac; i++)
	{
		cout << "ö" << setw(4);
	}
	cout << endl;
	cout << setw(4) << "U" << setw(4) << usayac << setw(4);
	for (int i = 1; i <= usayac; i++)
	{
		cout << "u" << setw(4);
	}
	cout << endl;

	cout << setw(4) << "Ü" << setw(4) << u_sayac << setw(4);
	for (int i = 1; i <= u_sayac; i++)
	{
		cout << "ü" << setw(4);
	}
	cout << endl;

	system("PAUSE");
	return 0;


}
