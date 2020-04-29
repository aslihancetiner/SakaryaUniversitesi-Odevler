/**
*
* @author Aslıhan Çetiner aslihan.cetiner@ogr.sakarya.edu.tr
* @since 26.04.2020
* <p>
* G171210014 1-C 
* </p>
*/
#include "IMEINo.h"
#include <string.h>
#include <time.h>
#include <windows.h>
IMEINo IMEINoOlustur(){
	IMEINo this;
	this = (IMEINo)malloc(sizeof(struct IMEINO));
	this->imeiuret=&IMEIUret;
	this->imeial=&Alimeino;
	this->imeiKontrol=&IMEIKontrolEt;
	this->imeiyaz=&IMEIYaz;
	this->imeiYoket=&IMEIYoket;
	return this;
}
void imeidelay(int number_of_seconds) //rastgeliliği arttıran fonksiyon
{ 
    int milli_seconds = 100 * number_of_seconds; 
    clock_t start_time = clock(); 
    while (clock() < start_time + milli_seconds) 
        ; 
} 
int* IMEIUret(const IMEINo this){//imei no üreten fonksiyon
	  int ToplamOnBes=0;
          int* dizi=malloc(sizeof(int)*15);	  
         this->r=RastgeleOlustur();
	   int i,j,k,l,m,o;
	   int sayi;
         for(i=0;i<14;i++)//ilk 14 numarasını rastgele üretiyorum.
        {
			imeidelay(1);
            sayi=this->r->randomuret(this->r);      
            dizi[i]=sayi;
            
        }
		
	     for(j=1;j<14;j=j+2)//son hanesini gerekli kuralları uygulayarak oluşturuyorum.15numaralı imeinin tek indekslerini topluyorum.
        {
            if(dizi[j]*2<10)
            {
                 ToplamOnBes+=dizi[j]*2;
            }
             else
            {
                int al=dizi[j]*2; 
					
				 char* hesap=malloc(sizeof(char)*2);
				sprintf(hesap, "%d",al);//int değeri chara döndürüyorum.
						int uzunluk=(int)( sizeof(hesap) / sizeof(hesap[0]) );//char dizinin uzunluğunu buluyorum.
			  char* diz=malloc(sizeof(char)*uzunluk);
                for(k=0;k<uzunluk;k++)
                {
				  diz[k]=hesap[k];
                }
				ToplamOnBes+=(diz[0]-'0');//char değeri int değere döndürüyorum ve topluyorum.
				ToplamOnBes+=(diz[1]-'0');
            }      
        }
         for(l=0;l<14;l=l+2)//15numaralı imeinin çift indekslerini topluyorum.
        {
            ToplamOnBes+=dizi[l];
        }
         for(m=10;m<=200;m=m+10)//imei numarasının son hanesini buluyorum.
        {
            if(m>= ToplamOnBes)//ilk 14 değerin toplamı 10un katlarından birinden küçükse çıkarıyorum ve son haneyi bulmuş oluyorum.
            {
                dizi[14]=(m- ToplamOnBes);
                break;
            }
            
        }   
        
        return dizi;
}
bool IMEIKontrolEt(const IMEINo this,char* al){//imei numarasının doğru olup olmadığını kontrol eden fonksiyon
	  int* dizi=malloc(sizeof(int)*15);	 
        int ToplamOnBes=0;
        int SonSayiKontrol=0;
       bool b=true;
       int i,j,k,l,m;
        for(i=0;i<15;i++)
        {
			 dizi[i]=al[i]-'0';//parametreden gelen char diziyi int diziye dönüştürüyorum.
        }
        for(j=1;j<14;j=j+2)//son hanesini gerekli kuralları uygulayarak oluşturuyorum.15numaralı imeinin tek indekslerini topluyorum.
        {
            if(dizi[j]*2<10)
            {
                 ToplamOnBes+=dizi[j]*2;
            }
             else
            {
                int all=dizi[j]*2;              
                char* hesap=malloc(sizeof(char)*2);
				sprintf(hesap, "%d",all);//int değeri chara döndürüyorum.
						int uzunluk=(int)( sizeof(hesap) / sizeof(hesap[0]) );//char dizinin uzunluğunu buluyorum.
			  char* diz=malloc(sizeof(char)*uzunluk);
                for(k=0;k<uzunluk;k++)
                {
				  diz[k]=hesap[k];
                }
				ToplamOnBes+=(diz[0]-'0');//char değeri int değere döndürüyorum ve topluyorum.
				ToplamOnBes+=(diz[1]-'0');
            }      
        }
         for(l=0;l<14;l=l+2)//son hanesini gerekli kuralları uygulayarak oluşturuyorum.15numaralı imeinin çift indekslerini topluyorum.
        {
            ToplamOnBes+=dizi[l];
        }
         for(m=10;m<=200;m=m+10)
        {
            if(m>= ToplamOnBes)//ilk 14 değerin toplamı 10un katlarından birinden küçükse çıkarıyorum ve son haneyi bulmuş oluyorum.
            {
                 SonSayiKontrol=(m- ToplamOnBes);
                break;
            }
            
        }
    if(SonSayiKontrol!=dizi[14])//parametreden gelen numaranın son hanesi kontrolde oluşan son haneye eşitmi değilmi bakıyorum.
        {
            b=false; //eşit değilse fonksiyon false döndürüyor.
        }
        
       
        return b;
}
char* IMEIYaz(const IMEINo this){//üretilen imei numarasını yazdıran fonksiyon
	char* duzenle = malloc(sizeof(char)*15);
	int i;
		int* al=malloc(sizeof(int)*15);
		al=this->imeiuret(this);
        for(i=0;i<15;i++) {
            duzenle[i]=al[i]+ '0';//int gelen imei numarasını chara döndürüyorum.
        }
        return duzenle;
}
char* Alimeino(IMEINo im){//imei numarasını döndürüyorum.
	char* duzenle = malloc(sizeof(char)*15);
	
	im->imeiNo=im->imeiyaz(im);
	return im->imeiNo;
}
void IMEIYoket(IMEINo this){//yoket metodu
	if(this == NULL) return;
	this->r->Yoket(this->r);
	free(this);
	this=NULL;
}