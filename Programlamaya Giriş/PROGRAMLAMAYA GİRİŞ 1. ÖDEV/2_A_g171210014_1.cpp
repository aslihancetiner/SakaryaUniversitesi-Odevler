
/****************************************************************************
**					SAKARYA �N�VERS�TES�
**			         B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**				    B�LG�SAYAR M�HEND�SL��� B�L�M�
**				          PROGRAMLAMAYA G�R��� DERS�
**
**				�DEV NUMARASI�...: 1
**				��RENC� ADI...............: Asl�han �etiner
**				��RENC� NUMARASI.: g171210014
**				DERS GRUBU����: A
****************************************************************************/



#include <iostream> // K�t�phane belirtildi.
using namespace std; // Standart ad uzay� kullan�ld�.

int main() // Ana fonksiyon tan�mland�.
{
	for (int y = 0; y < 24; y++) // Her seferinde bir y�ld�z daha eklenmesi i�in d�ng� tan�mland�.
	{
		cout << "* ";
	}
	cout << endl;
	for (int y = 0; y <= 17; y++) // Sat�r�n ba��na ve sonuna y�ld�z konuldu ve y==1 iken sau bilgisayar bas�ld�.
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
	for (d = 1; d <= p; d++) {          //Sat�r say� belirtildi.
		{
			cout << "* ";
		}
		for (u = (p - 1); u >= d; u--) {   // Y�ld�zlardan �nceki bo�lu�u i�in n-1 bo�luk b�rak�ld�.  

			cout << "  ";
		}

		for (g = 1; g <= (2 * d - 1); g++) {  //Y�ld�z say�s� yazd�r�ld�.
											      
			cout << "* ";

		}
		for (u = (p - 1); u >= d; u--) {   // Y�ld�zlardan �nceki bo�luk i�in n-1 bo�luk b�rak�ld�. 

			cout << "    ";
		}
		for (g = 1; g <= (2 * d - 1); g++) {  // Y�ld�z say�s� yazd�r�ld�.      
			cout << "* ";

		}
		for (u = (p - 1); u >= d; u--) {   // Y�ld�zlardan �nceki bo�luk i�in n-1 bo�luk b�rak�ld�. 

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
	for (q = 1; q <= p; q++) {          //Sat�r say� belirtildi.
		{
			cout << "* ";
		}
		for (e = (r - 1); e >= q; e--) {   // Y�ld�zlardan �nceki bo�lu�u i�i n-1 bo�luk b�rak�ld�  

			cout << "  ";
		}

		for (w = 1; w <= (2 * q - 1); w++) {  // Y�ld�z say�s� yazd�r�ld�.       
			cout << "* ";

		}
		for (e = (r - 1); e >= q; e--) {   // Y�ld�zlardan �nceki bo�luk i�in n-1 bo�luk b�rak�ld�  

			cout << "    ";
		}
		for (w = 1; w <= (2 * q - 1); w++) {  // Y�ld�z say�s� yazd�r�ld�       
			cout << "* ";

		}
		for (e = (r - 1); e >= q; e--) {   // Y�ld�zlardan �nceki bo�luk i�in n-1 bo�luk b�rak�ld�  

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
