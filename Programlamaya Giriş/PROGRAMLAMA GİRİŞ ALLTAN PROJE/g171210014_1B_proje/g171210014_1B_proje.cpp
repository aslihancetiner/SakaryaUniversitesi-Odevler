/****************************************************************************
**					SAKARYA ÜNİVERSİTESİ
**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				          PROGRAMLAMAYA GİRİŞİ DERSİ
**
**				ÖDEV NUMARASI…...: PROJE
**				ÖĞRENCİ ADI...............: ASLIHAN ÇETİNER
**				ÖĞRENCİ NUMARASI.: G171210014
**				DERS GRUBU…………: 1. ÖĞRETİM B GRUBU
****************************************************************************/

#include "pch.h"
#include <Windows.h>
#include <iostream>
#include <time.h>
using namespace std;
const double NUM_SECONDS = 1.8;
const int Haritax = 80;
const int Haritay = 20;
char Harita[Haritay][Haritax] = { ' ' };
void EkranaCiz();
void Cerceve();
void gotoxy(int x, int y);
void ucakolustur();
void klavyeoku(char tuslar[]);
char tuslar[256];
void ucaksil();
void mermiolustur();
void mermiilerlet();
void dusmanolustur();
void dusmanilerlet();
void ShowConsoleCursor(bool showFlag);
double zaman_sayac = 0;
clock_t simdiki_zaman = clock();
clock_t son = simdiki_zaman;
struct Ucak
{
	int konum[5][2] = { {8,1},{9,2},{10,3},{11,2},{12,1} };
} ucak;
int main()
{
	ShowConsoleCursor(false);
	while (true)
	{	
		simdiki_zaman = clock();
		zaman_sayac += (double)(simdiki_zaman - son);
		son = simdiki_zaman;
		gotoxy(0,0);
		Cerceve();
		ucakolustur();
		EkranaCiz();
		mermiilerlet();
		dusmanilerlet();
		ucaksil();
		klavyeoku(tuslar);
		if (tuslar['W'] != 0)
		{
			if (Harita[ucak.konum[0][0]-1][ucak.konum[0][1]]!=char(219))
			{
				for (int i = 0; i < 5; i++)
				{
					ucak.konum[i][0]--;
				}
			}
		}
		if (tuslar['S'] != 0)
		{
			if (Harita[ucak.konum[4][0] + 1][ucak.konum[4][1]] != char(219))
			{
				for (int i = 0; i < 5; i++)
				{
					ucak.konum[i][0]++;
				}	
			}
		}
		if (tuslar['F'] != 0)
		{
			mermiolustur();
		}
		if (zaman_sayac > (double)(NUM_SECONDS * CLOCKS_PER_SEC))
		{
			zaman_sayac = 0;
			dusmanolustur();	
		}
	}
	
	system("pause");
	
}
void EkranaCiz()
{
	for (int y = 0; y < Haritay; y++)
	{
		for (int x = 0; x < Haritax; x++)
		{
			cout << Harita[y][x];
		}
		cout << endl;
	}
}
void Cerceve()
{
	for (int i = 0; i < Haritax; i++)
	{
		Harita[0][i] = 219;
		Harita[Haritay - 1][i] = 219;
	}
	for (int i = 0; i < Haritay; i++)
	{
		Harita[i][0] = 219;
		Harita[i][Haritax - 1] = 219;
	}
}
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void ucakolustur()
{
	for (int i = 0; i < 5; i++)
	{
		Harita[ucak.konum[i][0]][ucak.konum[i][1]] = 177;
	}

}
void klavyeoku(char tuslar[])
{
	for (int i = 0; i < 256; i++)
	{
		tuslar[i] = (char)(GetAsyncKeyState(i) >> 8);
	}
}
void ucaksil()
{
	for (int i = 0; i < 5; i++)
	{
		Harita[ucak.konum[i][0]][ucak.konum[i][1]] = ' ';
	}	
}
void mermiolustur()
{
	Harita[ucak.konum[2][0]][ucak.konum[2][1]+1]= 178;
}
void mermiilerlet()
{
	for (int i = 0; i < Haritay; i++)
	{
		for (int j = 0; j < Haritax; j++)
		{
			if (Harita[i][j] == char(178))
			{
				if (Harita[i][j + 1] == char(176)|| Harita[i][j + 2] == char(176))
				{
					Harita[i - 2][j+1] = ' ';
					Harita[i - 2][j+2] = ' ';
					Harita[i - 2][j+3] = ' ';
					Harita[i - 1][j+1] = ' ';
					Harita[i - 1][j+2] = ' ';
					Harita[i - 1][j+3] = ' ';
					Harita[i ][j+1] = ' ';
					Harita[i ][j+2] = ' ';
					Harita[i ][j+3] = ' ';
					Harita[i +1][j+1] = ' ';
					Harita[i +1][j+2] = ' ';
					Harita[i +1][j+3] = ' ';
					Harita[i +2][j+1] = ' ';
					Harita[i +2][j+2] = ' ';
					Harita[i +2][j+3] = ' ';

				}
				Harita[i][j] = ' ';
				Harita[i][j+1] = 178;
				j++;
			}
		}
	}
}
void dusmanolustur()
{
	int rastgele = 2 + rand() % 16;
	Harita[rastgele][Haritax-2] = 176;
	Harita[rastgele][Haritax - 4] = 176;
	Harita[rastgele-1][Haritax - 2] = 176;
	Harita[rastgele-1][Haritax - 4] = 176;
	Harita[rastgele+1][Haritax - 2] = 176;
	Harita[rastgele+1][Haritax - 4] = 176;
	Harita[rastgele-1][Haritax - 3] = 176;
	Harita[rastgele+1][Haritax - 3] = 176;
}
void dusmanilerlet()
{
	for (int i = 0; i < Haritay; i++)
	{
		for (int j = 0; j < Haritax; j++)
		{
			if (Harita[i][j] == char(176))
			{
				Harita[i][j] = ' ';
				Harita[i][j - 1] = 176;
				
			}
		}
	}
}
void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; 
	SetConsoleCursorInfo(out, &cursorInfo);
}
