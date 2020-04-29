/****************************************************************************
**					SAKARYA �N�VERS�TES�
**			         B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**				    B�LG�SAYAR M�HEND�SL��� B�L�M�
**				          PROGRAMLAMAYA G�R��� DERS�
**
**				�DEV NUMARASI�...: 3
**				��RENC� ADI...............: ASLIHAN �ET�NER
**				��RENC� NUMARASI.: G171210014
**				DERS GRUBU����: 1B
****************************************************************************/

#include <iostream>
using namespace std;

struct Islem
{
	int Dizi[5][5] = { 1,2,3,4,5,
		6,7,8,9,10,
		11,12,13,14,15,
		16,17,18,19,20,
		21,22,23,24,25 };

	int kayma_miktari;
	int cekirdek_boyutu;
	int son_boyut;
	int DiziBoyut = sizeof(Dizi) / sizeof(Dizi[0]);
}Matris;
void atama(Islem Matrisim, int **cekirdek, int **sonuc) //�ekirdek �er�eveyi olu�turan fonksiyon
{
	int a = 0, b = 0, x = 0, y = 0;
	for (int i = 0; i < Matris.son_boyut; i++)
	{

		for (int j = 0; j < Matris.son_boyut; j++)
		{

			for (int t = 0; t < Matrisim.cekirdek_boyutu*Matrisim.cekirdek_boyutu; t++)
			{
				sonuc[i][j] += Matrisim.Dizi[a][b] * cekirdek[x][y]; // giri� matrisi elemanlar�yla, �ekirdek matrisin elemanlar�n�n toplan�p sonu� matrisine atanmas�.
				if (y < Matrisim.cekirdek_boyutu - 1) 
				{
					y++;
					b++;
				}
				else if (y == Matrisim.cekirdek_boyutu - 1)
				{
					y = 0;
					x++;
					b = b - (Matrisim.cekirdek_boyutu - 1);
					a++;
				}
			}
			x = 0;
			y = 0;
			b += Matrisim.kayma_miktari;
			a -= Matrisim.cekirdek_boyutu;
		}

		a += Matrisim.kayma_miktari;
		b = 0;
	}
}
int main()
{
	int **cekirdek; 
	cout << "Cekirdek Boyutunu Giriniz: ";
	cin >> Matris.cekirdek_boyutu;
	cout << "Kayma Miktarini Giriniz: ";
	cin >> Matris.kayma_miktari;
	Matris.son_boyut = ((Matris.DiziBoyut - Matris.cekirdek_boyutu) / Matris.kayma_miktari) + 1;
	if (((Matris.DiziBoyut - Matris.cekirdek_boyutu) % Matris.kayma_miktari) != 0)
	{
		cout << "Bu islem yapilamaz.." << endl;
		system("PAUSE");
		return 0;
	}
	cekirdek = new int *[Matris.cekirdek_boyutu]; 
	for (int i = 0; i < Matris.cekirdek_boyutu; i++) //kullan�c�dan girilen �ekirdek matrisi boyutu ile �ekirdek matris olu�turan d�ng�
	{
		cekirdek[i] = new int[Matris.cekirdek_boyutu];
	}
	for (int i = 0; i < Matris.cekirdek_boyutu; i++)
	{
		for (int j = 0; j < Matris.cekirdek_boyutu; j++)
		{
			cout << "Cekirdek[" << i + 1 << "][" << j + 1 << "]:";
			cin >> cekirdek[i][j]; //�ekirdek matrisin elemanlar� kullan�c�dan isteniyor.
		}
	}
	int **sonuc;
	sonuc = new int *[Matris.son_boyut];
	for (int i = 0; i < Matris.son_boyut; i++) //sonu� matrisi olu�turuluyor.
	{
		sonuc[i] = new int[Matris.son_boyut];
	}
	for (int i = 0; i < Matris.son_boyut; i++)
	{
		for (int j = 0; j < Matris.son_boyut; j++)
		{
			sonuc[i][j] = 0;
		}
	}

	atama(Matris, cekirdek, sonuc); 

	for (int i = 0; i < Matris.son_boyut; i++) //sonu� matrisini ekrana yazd�ran for d�ng�s�
	{
		for (int j = 0; j < Matris.son_boyut; j++)
		{
			cout << sonuc[i][j] << " ";
		}
		cout << endl;
	}





	system("PAUSE");
	return 0;
}