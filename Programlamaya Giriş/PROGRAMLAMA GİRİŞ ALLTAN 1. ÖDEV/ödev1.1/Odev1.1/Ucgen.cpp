/****************************************************************************
**					SAKARYA �N�VERS�TES�
**			         B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**				    B�LG�SAYAR M�HEND�SL��� B�L�M�
**				          PROGRAMLAMAYA G�R��� DERS�
**
**				�DEV NUMARASI�...: 1
**				��RENC� ADI...............: ASLIHAN �ET�NER
**				��RENC� NUMARASI.: G171210014
**				DERS GRUBU����: 1. ��RET�M B GRUBU
****************************************************************************/

#include <iostream>
using namespace std;
int main()
{

	for (int i = 1; i <= 5; i++) // 5 Kez i�lemleri tekrar et
	{
		for (int yildiz = 1; yildiz <= 5 - i + 1; yildiz++) // yildiz sayisi (5-i+1)'den k���k oldu�u s�rece ekrana y�ld�z bas ve  yildiz say�s�n� 1 artt�r
	{
		cout << "* ";
	}
	for (int bosluk = 1; bosluk < i; bosluk++) // bosluk say�s� i'den k���k oldu�u s�rece ekrana bosluk yazd�r ve bosluk say�s�n�  artt�r.
	{
		cout << "  ";
	}
	cout << " "; // ekrana bosluk bas
	for (int bosluk = 1; bosluk < i; bosluk++) // bosluk say�s� i'den k���k oldu�u s�rece ekrana bosluk yazd�r ve bosluk say�s�n�  artt�r.
	{
		cout << "  ";
	}
	for (int yildiz = 1; yildiz <= 5 - i + 1; yildiz++) // yildiz sayisi (5-i+1)'den k���k oldu�u s�rece ekrana y�ld�z bas ve  yildiz say�s�n� 1 artt�r
	{
		cout << "* ";
	}
	cout << endl; // bir alt sat�ra ge�.
}
cout << endl; // bir alt sat�ra ge�.
for (int i = 1; i <= 5; i++) // 5 Kez i�lemleri tekrar et
{
	for (int yildiz = 1; yildiz <= i; yildiz++) // yildiz sayisi i'den k���k oldu�u s�rece ekrana yildiz bas ve  artt�r.
	{
		cout << "* ";
	}
	for (int bosluk = 1; bosluk < 5 - i + 1; bosluk++) //bosluk sayisi (5-i+1)den k���k oldu�u s�rece ekrana bo�luk bas ve 1 artt�r.
	{
		cout << "  ";
	}
	cout << " "; // ekrana bo�luk bas
	for (int bosluk = 1; bosluk <= 5 - (i); bosluk++) //bosluk sayisi (5-i+1)den k���k oldu�u s�rece ekrana bo�luk bas ve 1 artt�r.
	{
		cout << "  ";
	}
	for (int yildiz = 1; yildiz <= i; yildiz++)// yildiz sayisi i'den k���k oldu�u s�rece ekrana yildiz bas ve  artt�r.
	{
		cout << "* ";
	}
	cout << endl; // bir alt sat�ra ge�.
}
system("PAUSE");
return 0;
}