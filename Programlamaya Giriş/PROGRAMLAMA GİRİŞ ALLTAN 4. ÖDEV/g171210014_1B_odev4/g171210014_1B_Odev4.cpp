/****************************************************************************
**					SAKARYA ÜNÝVERSÝTESÝ
**			         BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**				    BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**				          PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**				ÖDEV NUMARASI…...: 4
**				ÖÐRENCÝ ADI...............: ASLIHAN ÇETÝNER
**				ÖÐRENCÝ NUMARASI.: G171210014
**				DERS GRUBU…………: 1. ÖÐRETÝM B GRUBU
****************************************************************************/
#include <iostream>
using namespace std;

class Sifre
{
public:
	Sifre(char*alfabe, char*sifre);
	Sifre();
	char* sifrele(char*metin);
	char* sifrecoz(char*sifremetin);
	void sifrekelimesiata();
private:
	char*alfabe;
	char*sifrekelimesi;
};
int main()
{
	char SIFRE[10];
	char ALFABE[40];
	char METIN[80];
	char SIFRECOZMETIN[80];
	cout << "ALFABE:";
	cin >> ALFABE;
	cout << "SIFRE:";
	cin >> SIFRE;
	Sifre nesne(ALFABE, SIFRE);
	int secim;
	do
	{
		cout << "1-METIN SIFRELEME ISLEMI" << endl;
		cout << "2-METIN DESIFRELEME ISLEMI" << endl;
		cout << "3-SIFRE DEGISTIRME ISLEMI\n4-CIKIS\nSECIM:";
		cin >> secim;
		if (secim == 1)
		{
			cout << "METIN:";
			cin >> METIN;
			cout << "SIFRELENMIS METIN:" << nesne.sifrele(METIN) << endl;

		}
		if (secim == 2)
		{
			cout << "DESIFRELENECEK METIN:";
			cin >> SIFRECOZMETIN;
			cout << "DESIFRELENMIS METIN:" << nesne.sifrecoz(SIFRECOZMETIN) << endl;
		}
		if (secim == 3)
		{
			nesne.sifrekelimesiata();
		}
	} while (secim != 4);



	system("pause");
	return 0;

}
Sifre::Sifre(char * alfabe, char * sifre)
{
	this->alfabe = alfabe;
	sifrekelimesi = sifre;
}

Sifre::Sifre()
{
}

char * Sifre::sifrele(char *metin)
{
	int x = 0;
	int a = 0, b = 0;
	char* sifremetin = new char[strlen(metin)];
	char**vigenere = new char*[strlen(alfabe)];
	for (int i = 0; i < strlen(alfabe); i++)
	{
		vigenere[i] = new char[strlen(alfabe)];
	}
	for (int i = 0; i < strlen(alfabe); i++)
	{
		for (int j = 0; j < strlen(alfabe) + 1; j++)
		{
			if (x == strlen(alfabe))
				x = 0;
			if (i == 0 && j == 0)
				vigenere[i][j] = 0;
			else
			{
				vigenere[i][j] = alfabe[x];
				x++;
			}

		}
	}

	for (int i = 0; i < strlen(metin); i++)
	{
		for (a = 0; a < strlen(alfabe) + 1; a++)
		{
			if (metin[i] == vigenere[a][0])
			{
				break;
			}
		}
		for (b = 0; b < strlen(alfabe); b++)
		{
			if (sifrekelimesi[i%strlen(sifrekelimesi)] == vigenere[0][b])
			{
				break;
			}
		}
		sifremetin[i] = vigenere[a][b];
	}
	sifremetin[strlen(metin)] = '\0';
	return sifremetin;
}

char * Sifre::sifrecoz(char *sifremetin)
{
	char* cozulmusmetin = new char[strlen(sifremetin)];
	int a, b, x = 0;
	char**vigenere = new char*[strlen(alfabe)];
	for (int i = 0; i < strlen(alfabe); i++)
	{
		vigenere[i] = new char[strlen(alfabe)];
	}
	for (int i = 0; i < strlen(alfabe); i++)
	{
		for (int j = 0; j < strlen(alfabe) + 1; j++)
		{
			if (x == strlen(alfabe))
				x = 0;
			if (i == 0 && j == 0)
				vigenere[i][j] = 0;
			else
			{
				vigenere[i][j] = alfabe[x];
				x++;
			}

		}
	}
	for (int i = 0; i < strlen(sifremetin); i++)
	{
		for (b = 0; b < strlen(alfabe); b++)
		{
			if (sifrekelimesi[i%strlen(sifrekelimesi)] == vigenere[0][b])
			{
				break;
			}
		}
		for (a = 0; a < strlen(alfabe) + 1; a++)
		{
			if (sifremetin[i] == vigenere[a][b])
			{
				break;
			}
		}

		cozulmusmetin[i] = vigenere[a][0];
	}
	cozulmusmetin[strlen(sifremetin)] = '\0';
	return cozulmusmetin;
}

void Sifre::sifrekelimesiata()
{
	cout << "YENI SIFRE KELIME:";
	cin >> sifrekelimesi;
}