/**
*
* @author Aslıhan Çetiner aslihan.cetiner@ogr.sakarya.edu.tr
* @since 26.04.2020
* <p>
* G171210014 1-C 
* </p>
*/
#include "Telefon.h"


Telefon TelefonOlustur(){
	Telefon this;
	this = (Telefon)malloc(sizeof(struct TELEFON));
	this->telyaz=&TelYaz;
	this->teluret=&TelUret;
	this->telal=&Alno;
	this->telYoket=&TelefonYoket;
	
	return this;
}
//rastgeliliği arttıran fonksiyon
void teldelay(int number_of_seconds) 
{ 
    int milli_seconds = 100 * number_of_seconds; 
    clock_t start_time = clock(); 
    while (clock() < start_time + milli_seconds) 
        ; 
}
int* TelUret(const Telefon this)//telefon no üreten fonksiyon
{
	  int* dizi=malloc(sizeof(int)*11);
	  int i;
	   int sayi;
        this->r=RastgeleOlustur();
        dizi[0]=0;
        dizi[1]=5;
	  for(i=2;i<11;i++)//11haneli telefon no üretiyorum.
        {
           teldelay(1);
              sayi=this->r->randomuret(this->r);// 0-10 arası rastgele sayı üretiyorum.
            if(i==2)
            {
                 while(!(sayi==0||sayi==3||sayi==4||sayi==5||sayi==6))//telefon operatorlerin alan kodunu sağlamak için döngüyle kontrol ediyorum.
                  {
                      teldelay(1);
                       sayi=this->r->randomuret(this->r);
                  }
                
            }
            if(i==3)
            {
                if(dizi[2]==0)
                {
                      while(!(sayi==1||sayi==5||sayi==6||sayi==7))//telefon operatorlerin alan kodunu sağlamak için döngüyle kontrol ediyorum.
                          {
                              teldelay(1);
                             sayi=this->r->randomuret(this->r);
                          }
                }
                if(dizi[2]==5)
                {
                      while(!(sayi==1||sayi==2||sayi==3||sayi==4||sayi==5||sayi==9))//telefon operatorlerin alan kodunu sağlamak için döngüyle kontrol ediyorum.
                          {
                             teldelay(1);
                             sayi=this->r->randomuret(this->r);
                          }
                }
                if(dizi[2]==6)
                {
                      while(!(sayi==1))//telefon operatorlerin alan kodunu sağlamak için döngüyle kontrol ediyorum.
                          {
                              teldelay(1);
                              sayi=this->r->randomuret(this->r);
                          }
                }
            }
          
           dizi[i]=sayi;
        }
        
        return dizi;
}

char* TelYaz(const Telefon this)//üretilen telefon numarasını yazdıran fonksiyon
{
		char* duzenle = malloc(sizeof(char)*11);
		int i;
		int* al=malloc(sizeof(int)*11);
		al=this->teluret(this);
		
        for(i=0;i<11;i++) {
            duzenle[i]=al[i]+ '0';//int gelen telefon numarasını chara döndürüyorum.
        }
        return duzenle;
		
}
char* Alno(Telefon te){//telefon numarasını döndürüyorum.
	char* duzenle = malloc(sizeof(char)*11);
	
	te->no=te->telyaz(te);
	te->no[11]='\0';
	return te->no;
}
void TelefonYoket(Telefon this){//yoket metodu
	
	if(this == NULL) return;
	this->r->Yoket(this->r);
	free(this);
	this=NULL;
}