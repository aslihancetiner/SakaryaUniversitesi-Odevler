/**       
* @file  kaynak.cpp 
* @description Programýn akýþ sýrasýnýn belirlendiði dosya. 
* @course  2. öðretim C grubu 
* @assignment  3. ödev  
* @date  19.12.2018
* @author  Aslýhan Çetiner aslihancetiner@hotmail.com
*/
#include <iostream>
#include <string>
#include "agac.h"
#include "kok.h"
using namespace std;

int main()
{
	string basamak;
	cout << "Derinlikleri Giriniz: ";
	cin >> basamak;
	agac* anaAgac = NULL;
	agac* temp;
	for (int i = 0; i < basamak.size(); i++)
	{
		if (i == 0)
		{
			anaAgac = new agac((int)basamak[i] - 48);
		}
		else
		{
			temp = anaAgac;
			while (temp->altagacGet() != NULL)
			{
				temp = temp->altagacGet();
			}
			temp->altagacSet(new agac((int)basamak[i] - 48));
		}
	}
	cout << endl;
	int secim;

	do
	{
		cout << "1-Agaclardan maximum degeri cikar" << endl;
		cout << "2-Agaclardan minimum degeri cikar" << endl;
		cout << "3-Tum agaclari levelorder yazdir" << endl;
		cout << "4-Cikis" << endl;
		cout << "Secim Giriniz: ";
		cin >> secim;
		if (secim == 1)
		{
			temp = anaAgac;
			while (temp->altagacGet() != NULL)
			{
				temp->KokMaxSil();
				temp = temp->altagacGet();
			}
			temp->KokMaxSil();
			temp = anaAgac;
			while (temp->altagacGet() != NULL)
			{
				if (temp->rootGet() == NULL)
				{
					agac*temp2 = anaAgac;
					while (temp2->altagacGet() != temp && temp != temp2)
					{
						temp2 = temp2->altagacGet();
					}
					if (temp->altagacGet() != NULL)
					{
						temp2->altagacSet (temp->altagacGet());
					}
					else
					{
						temp2->altagacSet(NULL);
					}
					if (anaAgac==temp)
					{
						anaAgac=(temp->altagacGet());
					}
					else
					{
						delete temp;
					}
					temp = temp2->altagacGet();
					continue;
				}
				temp = temp->altagacGet();
			}
			if (temp->rootGet() == NULL)
			{
				agac*temp2 = anaAgac;
				while (temp2->altagacGet() != temp && temp != temp2)
				{
					temp2 = temp2->altagacGet();
				}
				if (temp->altagacGet() != NULL)
				{
					temp2 = temp->altagacGet();
				}
				else
				{
					temp2->altagacSet(NULL);
				}
				delete temp;
			}
		}
		if (secim == 2)
		{
			temp = anaAgac;
			while (temp->altagacGet() != NULL)
			{
				temp->KokMinSil();
				temp = temp->altagacGet();
			}
			temp->KokMinSil();
			temp = anaAgac;
			while (temp->altagacGet() != NULL)
			{
				if (temp->rootGet() == NULL)
				{
					agac*temp2 = anaAgac;
					while (temp2->altagacGet() != temp && temp != temp2)
					{
						temp2 = temp2->altagacGet();
					}
					if (temp->altagacGet() != NULL)
					{
						temp2->altagacSet(temp->altagacGet());
					}
					else
					{
						temp2->altagacSet(NULL);
					}
					if (anaAgac == temp)
					{
						anaAgac = (temp->altagacGet());
					}
					else
					{
						delete temp;
					}
					temp = temp2->altagacGet();
					continue;
				}
				temp = temp->altagacGet();
			}
			if (temp->rootGet() == NULL)
			{
				agac*temp2 = anaAgac;
				while (temp2->altagacGet() != temp && temp != temp2)
				{
					temp2 = temp2->altagacGet();
				}
				if (temp->altagacGet() != NULL)
				{
					temp2 = temp->altagacGet();
				}
				else
				{
					temp2->altagacSet(NULL);
				}
				delete temp;
			}
		}
		if (secim == 3)
		{
			temp = anaAgac;
			while (temp->altagacGet() != NULL)
			{
				temp->Levelorder();
				temp = temp->altagacGet();
			}
			temp->Levelorder();
			
		}
		
	} while (secim!=4);




	system("PAUSE");
	return 0;
	
}