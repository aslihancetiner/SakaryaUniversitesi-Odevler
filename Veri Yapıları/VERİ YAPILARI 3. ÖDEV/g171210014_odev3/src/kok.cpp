/**
* @file  kok.cpp
* @description kok s�n�f�ndaki fonksiyonlar�n olu�turuldu�u dosya.
* @course  2. ��retim C grubu
* @assignment  3. �dev
* @date  19.12.2018
* @author  Asl�han �etiner aslihancetiner@hotmail.com
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

