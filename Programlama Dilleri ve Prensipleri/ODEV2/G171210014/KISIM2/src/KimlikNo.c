/**
*
* @author Aslıhan Çetiner aslihan.cetiner@ogr.sakarya.edu.tr
* @since 26.04.2020
* <p>
* G171210014 1-C 
* </p>
*/
#include "KimlikNo.h"


KimlikNo KimlikNoOlustur(){
	KimlikNo this;
	this = (KimlikNo)malloc(sizeof(struct KIMLIKNO));
	this->tcuret=&TcUret;
	this->tcKontrol=&TcKontrolEt;
	this->tcyaz=&TcYaz;
	this->kimlikal=&AlKimlikno;
	this->tcYoket=&TcYoket;
	return this;
	
}
void kimlikdelay(int number_of_seconds) //rastgeliliği arttıran fonksiyon
{ 
    int milli_seconds = 100 * number_of_seconds; 
    clock_t start_time = clock(); 
    while (clock() < start_time + milli_seconds) 
        ; 
}
int* TcUret(const KimlikNo this){//kimlik no üreten fonksiyon
	 int* dizi=malloc(sizeof(int)*11);	  
       this->r=RastgeleOlustur();
	   int i;
	   int sayi;
        for(i=0;i<9;i++)//ilk 9 numarayı rastgele oluşturuyorum.
        {
            kimlikdelay(1);
               sayi=this->r->randomuret(this->r);// 0-10 arası rastgele sayı üretiyorum.
            if(i==0)//ilk hanenin 0 olmamasını sağlıyorum.0 sa tekrar üretiyorum.
            {
                while((sayi==0))
                     {
                        kimlikdelay(1);
                          sayi=this->r->randomuret(this->r);
                     }
            }
            
            dizi[i]=sayi;
            
        }
        
        int toplamOn=((dizi[0]+dizi[2]+dizi[4]+dizi[6]+dizi[8])*7)+((dizi[1]+dizi[3]+dizi[5]+dizi[7])*9);//tc algoritmasına göre 10.haneyi ilk 9 haneyi kullanarak hesaplıyorum.
        toplamOn=toplamOn%10;//birler basamağını buluyorum.
        dizi[9]=toplamOn;//10.haneyi oluşturdum.
         int toplamOnBir=(dizi[0]+dizi[1]+dizi[2]+dizi[3]+dizi[4]+dizi[5]+dizi[6]+dizi[7]+dizi[8]+dizi[9])%10;//tc algoritmasına göre 11.haneyi ilk 10 haneyi kullanarak hesaplıyorum.
        dizi[10]=toplamOnBir;//11.haneyi oluşturdum.
        return dizi;
}
bool TcKontrolEt(KimlikNo this,char* al){//tc numarasının doğru olup olmadığını kontrol eden fonksiyon
	
	     int* dizi=malloc(sizeof(int)*11);	 
       bool b=true;
       char* duzenle = malloc(sizeof(char)*11);
        for(int i=0;i<11;i++)
        {
			 dizi[i]=al[i]-'0';//parametreden gelen char diziyi int diziye dönüştürüyorum.
        }
		//parametreden gelen numarayı tc algoritmasına göre kontrol ediyorum.
        int toplamOnKontrol=((dizi[0]+dizi[2]+dizi[4]+dizi[6]+dizi[8])*7)+((dizi[1]+dizi[3]+dizi[5]+dizi[7])*9);
        toplamOnKontrol=toplamOnKontrol%10;
        int toplamOnBirKontrol=(dizi[0]+dizi[1]+dizi[2]+dizi[3]+dizi[4]+dizi[5]+dizi[6]+dizi[7]+dizi[8]+dizi[9])%10;
    
        
        if(toplamOnKontrol!=dizi[9]||toplamOnBirKontrol!=dizi[10])//kontrolden oluşan 10 ve 11.haneler parametreden geleninkine eşitmi değilmi bakıyorum.
        {
            b=false;//eşit değilse fonksiyon false döndürüyor.
        }
        return b;
}
char* TcYaz(const KimlikNo this){//üretilen tc numarasını yazdıran fonksiyon
	char* duzenle = malloc(sizeof(char)*11);
	int i;
		int* al=malloc(sizeof(int)*11);
		al=this->tcuret(this);
        for(i=0;i<11;i++) {
            duzenle[i]=al[i]+ '0';//int gelen tc numarasını chara döndürüyorum.
        }
        return duzenle;
}
char* AlKimlikno(KimlikNo ki){//tc numarasını döndürüyorum.
	char* duzenle = malloc(sizeof(char)*11);
	
	ki->tc=ki->tcyaz(ki);
	
	return ki->tc;
	
}
void TcYoket(KimlikNo this){//yoket metodu
	if(this == NULL) return;
	this->r->Yoket(this->r);
	free(this);
	this=NULL;
}