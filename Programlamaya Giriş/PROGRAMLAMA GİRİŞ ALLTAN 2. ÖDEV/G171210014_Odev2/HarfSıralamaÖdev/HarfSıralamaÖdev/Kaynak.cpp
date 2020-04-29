/****************************************************************************
**					SAKARYA ÜNÝVERSÝTESÝ
**			         BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**				    BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**				          PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**				ÖDEV NUMARASI…...: 2
**				ÖÐRENCÝ ADI...............: ASLIHAN ÇETÝNER
**				ÖÐRENCÝ NUMARASI.: G171210014
**				DERS GRUBU…………: B
****************************************************************************/

#include <iostream> 
#include <iomanip> 
#include <stdlib.h>
#include <ctime>	
#include <cstdlib>
#include <locale.h>	
using namespace std;


int main()
{

	char Harf[5][10]; //5x10 boyutlu bir matris tanýmlandý
	int nokta = 0;

	srand(time(0));
	for (int i = 0; i < 5; i++) // matrisi oluþturduðum for döngüsü
	{
		for( int j = 0; j<10; j++)
		{
			nokta = 0;
			if (j % 2 == 0)
			{
				Harf[i][j] = char(65 + rand() % 26); // rastgele büyük harf atamasý
			}
			else
			{
				Harf[i][j] = char(97 + rand() % 26); // rastgele küçük harf atamasý
			}

			for (int satir = 0; satir <= i; satir++) 
			{
				for (int sutun = 0; sutun < 10; sutun++)
				{
					if (satir == i && sutun == j)
					{
						nokta = 1;
						break;
					}
					if (Harf[satir][sutun] == Harf[i][j]) // atanan harfin bir daha atanmamasý kontrol ediliyor
					{
						j--;
						nokta = 1;
						break;
					}
				}
				if (nokta == 1)
				{
					break;
				}
			}
		}

		
	}

	for (int i = 0; i < 5; i++) // oluþan matrisi ekrana yazdýran for döngüsü
	{
		for (int j = 0;  j < 10;  j++)
		{
			cout << setw(4) << Harf[i][j];
		}	
		cout << endl;
	}
	cout << endl;
	cout << endl;


	for (int i = 0; i < 5; i++) //matristeki harfleri büyükten küçüðe sýralatan for döngüsü
	{
		for (int j = 0; j < 10; j++)
		{
			for (int a =0; a < 5; a++)
			{ 
				for (int b = 0; b < 10; b++)
			{
			if (Harf[i][j]<Harf[a][b])
			{
				int x = Harf[i][j];
				Harf[i][j] = Harf[a][b];
				Harf[a][b] = x;
			}
			}
			}
		}
		
	}
	for (int i = 0; i < 5; i++) //büyükten küçüðe doðru sýralanan harflerin ekrana yazdýrýldýðý döngü
	{
		for (int j = 0; j < 10; j++)
		{
			cout << setw(4) << Harf[i][j];
		}

		cout << endl;
	}
	cout << endl;


	system("PAUSE");
	return 0;
}

