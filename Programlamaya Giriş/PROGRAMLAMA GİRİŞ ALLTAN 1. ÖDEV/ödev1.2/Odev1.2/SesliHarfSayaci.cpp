
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
	int �sayac = 0;
	int �_sayac = 0; //i sayac�
	int osayac = 0;
	int o_sayac = 0; //� sayac�
	int usayac = 0;
	int u_sayac = 0; //� sayac�
	int max = 0;
	cout << "kelime gir:" << endl;

	while (harf != '\r') //okunan harf enter olana kadar d�ng�ye devam et.
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
		if (harf == '�' || harf == 'I')
		{
			�sayac++;
		}
		if (harf == 'i' || harf == '�')
		{
			�_sayac++;
		}
		if (harf == 'o' || harf == 'O')
		{
			osayac++;
		}
		if (harf == '�' || harf == '�')
		{
			o_sayac++;
		}
		if (harf == 'u' || harf == 'U')
		{
			usayac++;
		}
		if (harf == '�' || harf == '�')
		{
			u_sayac++;
		}

	}
	sayac = asayac + esayac + �sayac + �_sayac + osayac + o_sayac + usayac + u_sayac;
	if (asayac>max)
	{
		max = asayac;
	}
	if (esayac>max)
	{
		max = esayac;
	}
	if (�sayac>max)
	{
		max = �sayac;
	}
	if (�_sayac>max)
	{
		max = �_sayac;
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

	cout << setw(4) << "I" << setw(4) << �sayac << setw(4);
	for (int i = 1; i <= �sayac; i++)
	{
		cout << "�" << setw(4);
	}
	cout << endl;

	cout << setw(4) << "�" << setw(4) << �_sayac << setw(4);
	for (int i = 1; i <= �_sayac; i++)
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
	cout << setw(4) << "�" << setw(4) << o_sayac << setw(4);
	for (int i = 1; i <= o_sayac; i++)
	{
		cout << "�" << setw(4);
	}
	cout << endl;
	cout << setw(4) << "U" << setw(4) << usayac << setw(4);
	for (int i = 1; i <= usayac; i++)
	{
		cout << "u" << setw(4);
	}
	cout << endl;

	cout << setw(4) << "�" << setw(4) << u_sayac << setw(4);
	for (int i = 1; i <= u_sayac; i++)
	{
		cout << "�" << setw(4);
	}
	cout << endl;

	system("PAUSE");
	return 0;


}
