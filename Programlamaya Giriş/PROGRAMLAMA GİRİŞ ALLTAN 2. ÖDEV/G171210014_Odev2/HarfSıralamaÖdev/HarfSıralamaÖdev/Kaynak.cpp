/****************************************************************************
**					SAKARYA �N�VERS�TES�
**			         B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**				    B�LG�SAYAR M�HEND�SL��� B�L�M�
**				          PROGRAMLAMAYA G�R��� DERS�
**
**				�DEV NUMARASI�...: 2
**				��RENC� ADI...............: ASLIHAN �ET�NER
**				��RENC� NUMARASI.: G171210014
**				DERS GRUBU����: B
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

	char Harf[5][10]; //5x10 boyutlu bir matris tan�mland�
	int nokta = 0;

	srand(time(0));
	for (int i = 0; i < 5; i++) // matrisi olu�turdu�um for d�ng�s�
	{
		for( int j = 0; j<10; j++)
		{
			nokta = 0;
			if (j % 2 == 0)
			{
				Harf[i][j] = char(65 + rand() % 26); // rastgele b�y�k harf atamas�
			}
			else
			{
				Harf[i][j] = char(97 + rand() % 26); // rastgele k���k harf atamas�
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
					if (Harf[satir][sutun] == Harf[i][j]) // atanan harfin bir daha atanmamas� kontrol ediliyor
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

	for (int i = 0; i < 5; i++) // olu�an matrisi ekrana yazd�ran for d�ng�s�
	{
		for (int j = 0;  j < 10;  j++)
		{
			cout << setw(4) << Harf[i][j];
		}	
		cout << endl;
	}
	cout << endl;
	cout << endl;


	for (int i = 0; i < 5; i++) //matristeki harfleri b�y�kten k����e s�ralatan for d�ng�s�
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
	for (int i = 0; i < 5; i++) //b�y�kten k����e do�ru s�ralanan harflerin ekrana yazd�r�ld��� d�ng�
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

