/**
* @file  agac.cpp
* @description agac sýnýfýndaki fonksiyonlarn oluþturulduðu dosya.
* @course  2. öðretim C grubu
* @assignment  3. ödev
* @date  19.12.2018
* @author  Aslýhan Çetiner aslihancetiner@hotmail.com
*/
#include "agac.h"
#include "kok.h"
using namespace std;


void agac::KokOlustur(int deger, kok**ptr)
{
	if (*ptr == NULL)
	{
		*ptr = new kok(deger);
	}
	else
	{
		if ((*ptr)->veriGet()< deger)
		{
			KokOlustur(deger, (*ptr)->sagGet2Pointer());
		}
		if ((*ptr)->veriGet() > deger)
		{
			KokOlustur(deger,(*ptr)->solGet2Pointer());
		}
	}
}

int agac::yukseklik(kok *root)
{

	if (root == NULL)
		return -1;
	int sagsayac, solsayac;
	solsayac = yukseklik(root->solGet());
	sagsayac = yukseklik(root->sagGet());
	if (sagsayac > solsayac)
	{
		return sagsayac + 1;
	}
	else
	{
		return solsayac + 1;
	}

}

agac::agac(int derinlik)
{
	while (yukseklik(root)<derinlik)
	{
		KokOlustur(rand() % 800, &root);
	}
}

agac * agac::altagacGet()
{
	return altAgac;
}

agac** agac::altagac2PGet()
{
	return &altAgac;
}

kok * agac::rootGet()
{
	return root;
}

void agac::altagacSet(agac*ptr)
{
	altAgac = ptr;
}

void agac::rootSet(kok * ptr)
{
	root = ptr;
}

void agac::Levelorder()
{
	int h = yukseklik(root);
	for (int level = 0; level <= h; level++)
		SeviyeyiYazdir(root, level);
	cout << endl;
}
void agac::SeviyeyiYazdir(kok *alt_Dugum, int seviye)
{
	if (alt_Dugum == NULL) return;
	if (seviye == 0) 
		cout << alt_Dugum->veriGet() << " ";
	else {
		SeviyeyiYazdir(alt_Dugum->solGet(), seviye - 1);
		SeviyeyiYazdir(alt_Dugum->sagGet(), seviye - 1);
	}
}

void agac::KokMaxSil()
{
	kok* temp=root;
	kok*temp2=root;
	while (temp->sagGet() != NULL)
	{
		temp = temp->sagGet();
	}
	while (temp2->sagGet() != temp && temp2 != temp)
	{
		temp2 = temp2->sagGet();
	}
	if (temp == root&&temp->solGet()!=NULL)
	{
		root = temp->solGet();
	}
	if (temp->solGet() != NULL)
	{
		temp2->sagSet(temp->solGet());
	}
	else
	{
		temp2->sagSet(NULL);
	}
	if (root==temp&&temp->solGet()==NULL)
	{
		delete root;
		root = NULL;
	}
	else
	{
		delete temp;
	}

	
}

void agac::KokMinSil()
{
	kok*temp = root;
	kok*temp2 = root;
	while (temp->solGet() != NULL)
	{
		temp = temp->solGet();
	}
	while (temp2->solGet() != temp && temp != root)
	{
		temp2 = temp2->solGet();
	}
	if (temp == root && temp->sagGet() != NULL)
	{
		root = temp->sagGet();
	}
	if (temp->sagGet() != NULL)
	{
		temp2->solSet(temp->sagGet());
	}
	else
	{
		temp2->solSet(NULL);
	}
	if (root == temp && temp->sagGet() == NULL)
	{
		delete root;
		root = NULL;
	}
	else
	{
		delete temp;
	}
}
