#include "Dugum.h"
#include "Stack.h"


Dugum::Dugum(int sayi)
{
	veri = sayi;
	yigit.StackElemanEkle(sayi);
}

int Dugum::VeriMetot()
{
	return veri;
}

void Dugum::VeriDuzelt(int sayi)
{
	veri = sayi;
	yigit.StackElemanEkle(sayi);
}

void Dugum::StackleriYazdir()
{
	yigit.StackYazdir();
}
