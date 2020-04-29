#ifndef  Dugum_H
#define Dugum_H
#include<iostream>
#include"Stack.h"
class Dugum
{
private:
	int veri;
	Stack yigit;
public:
	Dugum * prev = NULL;
	Dugum* next = NULL;
	Dugum(int);
	int VeriMetot();
	void VeriDuzelt(int);
	void StackleriYazdir();
};

#endif // ! Dugum_H



