#include "Stack.h"
#include <iomanip>
#include <iostream>
using namespace std;

Stack::Stack()
{
}

void Stack::StackElemanEkle(int sayi)
{
	Dizi[top] = sayi;
	top++;
}

void Stack::StackYazdir()
{
	for (int i = top-1; i >= 0; i--)
	{
		cout << setw(6) << Dizi[i] << setw(6);
	}
	cout << endl;
}

