#ifndef agac_HPP
#define agac_HPP


#include <iostream>
#include "kok.h"
class agac
{
private:
	agac* altAgac = NULL;
	kok* root = NULL;
	void KokOlustur(int,kok**);
	int yukseklik(kok*);
public:
	agac(int );
	agac* altagacGet();
	agac** altagac2PGet();
	kok* rootGet();
	void altagacSet(agac*ptr);
	void rootSet(kok*ptr);
	void Levelorder();
	void SeviyeyiYazdir(kok *alt_Dugum, int seviye);
	void KokMaxSil();
	void KokMinSil();

};

#endif 