/**
* @file  kok.cpp
* @description kok sýnýfýndaki fonksiyonlarýn oluþturulduðu dosya.
* @course  2. öðretim C grubu
* @assignment  3. ödev
* @date  19.12.2018
* @author  Aslýhan Çetiner aslihancetiner@hotmail.com
*/
#include "kok.h"

kok::kok(int veri)
{
	this->veri = veri;
}

kok * kok::sagGet()
{
	return sag;
}

kok ** kok::sagGet2Pointer()
{
	return &sag;
}

kok * kok::solGet()
{
	return sol;
}

kok ** kok::solGet2Pointer()
{
	return &sol;
}

int kok::veriGet()
{
	return veri;
}

void kok::sagSet(kok*ptr)
{
	sag = ptr;
}

void kok::solSet(kok*ptr)
{
	sol = ptr;
}

