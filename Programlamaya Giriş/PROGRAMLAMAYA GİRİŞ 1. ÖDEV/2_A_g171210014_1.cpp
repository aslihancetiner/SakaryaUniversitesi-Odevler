
/****************************************************************************
**					SAKARYA ÜNÝVERSÝTESÝ
**			         BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**				    BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**				          PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**				ÖDEV NUMARASI…...: 1
**				ÖÐRENCÝ ADI...............: Aslýhan Çetiner
**				ÖÐRENCÝ NUMARASI.: g171210014
**				DERS GRUBU…………: A
****************************************************************************/



#include <iostream> // Kütüphane belirtildi.
using namespace std; // Standart ad uzayý kullanýldý.

int main() // Ana fonksiyon tanýmlandý.
{
	for (int y = 0; y < 24; y++) // Her seferinde bir yýldýz daha eklenmesi için döngü tanýmlandý.
	{
		cout << "* ";
	}
	cout << endl;
	for (int y = 0; y <= 17; y++) // Satýrýn baþýna ve sonuna yýldýz konuldu ve y==1 iken sau bilgisayar basýldý.
		if (y == 0 || y == 17)
		{
			cout << "* ";

		}
		else if (y == 1)
		{
			cout << "SAU BILGISAYAR";

		}
		else
		{
			cout << "  ";
		}

	cout << endl;

	int d, g, u, p;
	p = 6;
	for (d = 1; d <= p; d++) {          //Satýr sayý belirtildi.
		{
			cout << "* ";
		}
		for (u = (p - 1); u >= d; u--) {   // Yýldýzlardan önceki boþluðu için n-1 boþluk býrakýldý.  

			cout << "  ";
		}

		for (g = 1; g <= (2 * d - 1); g++) {  //Yýldýz sayýsý yazdýrýldý.
											      
			cout << "* ";

		}
		for (u = (p - 1); u >= d; u--) {   // Yýldýzlardan önceki boþluk için n-1 boþluk býrakýldý. 

			cout << "    ";
		}
		for (g = 1; g <= (2 * d - 1); g++) {  // Yýldýz sayýsý yazdýrýldý.      
			cout << "* ";

		}
		for (u = (p - 1); u >= d; u--) {   // Yýldýzlardan önceki boþluk için n-1 boþluk býrakýldý. 

			cout << "  ";
		}
		{
			cout << "* ";
		}


		cout << endl;    
	}
	for (int m = 0; m <= 15; m++)
		if (m == 0 || m == 15)
		{
			cout << "*";

		}
		else if (m == 1)
		{
			cout << "MUHENDISLIGI BOLUMU";

		}
		else
		{
			cout << "  ";
		}
	cout << endl;
	int q, w, e, r;
	r = 6;
	for (q = 1; q <= p; q++) {          //Satýr sayý belirtildi.
		{
			cout << "* ";
		}
		for (e = (r - 1); e >= q; e--) {   // Yýldýzlardan önceki boþluðu içi n-1 boþluk býrakýldý  

			cout << "  ";
		}

		for (w = 1; w <= (2 * q - 1); w++) {  // Yýldýz sayýsý yazdýrýldý.       
			cout << "* ";

		}
		for (e = (r - 1); e >= q; e--) {   // Yýldýzlardan önceki boþluk için n-1 boþluk býrakýldý  

			cout << "    ";
		}
		for (w = 1; w <= (2 * q - 1); w++) {  // Yýldýz sayýsý yazdýrýldý       
			cout << "* ";

		}
		for (e = (r - 1); e >= q; e--) {   // Yýldýzlardan önceki boþluk için n-1 boþluk býrakýldý  

			cout << "  ";
		}
		{
			cout << "* ";
		}


		cout << endl;   
	}
	for (int v = 0; v < 24; v++)
		if (v == 0 || v == 23)
		{
			cout << "* ";
		}
		else
		{
			cout << "  ";
		}
	cout << endl;
	for (int s = 0; s < 24; s++)
	{
		cout << "* ";
	}
	cout << endl;


	system("pause");
	return 0;
}
