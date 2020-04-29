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
using namespace std;
int main()
{

	for (int i = 1; i <= 5; i++) // 5 Kez iþlemleri tekrar et
	{
		for (int yildiz = 1; yildiz <= 5 - i + 1; yildiz++) // yildiz sayisi (5-i+1)'den küçük olduðu sürece ekrana yýldýz bas ve  yildiz sayýsýný 1 arttýr
	{
		cout << "* ";
	}
	for (int bosluk = 1; bosluk < i; bosluk++) // bosluk sayýsý i'den küçük olduðu sürece ekrana bosluk yazdýr ve bosluk sayýsýný  arttýr.
	{
		cout << "  ";
	}
	cout << " "; // ekrana bosluk bas
	for (int bosluk = 1; bosluk < i; bosluk++) // bosluk sayýsý i'den küçük olduðu sürece ekrana bosluk yazdýr ve bosluk sayýsýný  arttýr.
	{
		cout << "  ";
	}
	for (int yildiz = 1; yildiz <= 5 - i + 1; yildiz++) // yildiz sayisi (5-i+1)'den küçük olduðu sürece ekrana yýldýz bas ve  yildiz sayýsýný 1 arttýr
	{
		cout << "* ";
	}
	cout << endl; // bir alt satýra geç.
}
cout << endl; // bir alt satýra geç.
for (int i = 1; i <= 5; i++) // 5 Kez iþlemleri tekrar et
{
	for (int yildiz = 1; yildiz <= i; yildiz++) // yildiz sayisi i'den küçük olduðu sürece ekrana yildiz bas ve  arttýr.
	{
		cout << "* ";
	}
	for (int bosluk = 1; bosluk < 5 - i + 1; bosluk++) //bosluk sayisi (5-i+1)den küçük olduðu sürece ekrana boþluk bas ve 1 arttýr.
	{
		cout << "  ";
	}
	cout << " "; // ekrana boþluk bas
	for (int bosluk = 1; bosluk <= 5 - (i); bosluk++) //bosluk sayisi (5-i+1)den küçük olduðu sürece ekrana boþluk bas ve 1 arttýr.
	{
		cout << "  ";
	}
	for (int yildiz = 1; yildiz <= i; yildiz++)// yildiz sayisi i'den küçük olduðu sürece ekrana yildiz bas ve  arttýr.
	{
		cout << "* ";
	}
	cout << endl; // bir alt satýra geç.
}
system("PAUSE");
return 0;
}