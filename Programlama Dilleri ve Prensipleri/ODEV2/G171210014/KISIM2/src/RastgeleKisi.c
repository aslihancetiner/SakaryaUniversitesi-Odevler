/**
*
* @author Aslıhan Çetiner aslihan.cetiner@ogr.sakarya.edu.tr
* @since 26.04.2020
* <p>
* G171210014 1-C 
* </p>
*/
#include "Kisi.h"
#include "RastgeleKisi.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


RastgeleKisi RastgeleKisiOlustur(){
	RastgeleKisi this;
	this = (RastgeleKisi)malloc(sizeof(struct RASTGELEKISI));
	this->rastgelekisiuret=&RastgeleKisiUret;
	this->uretilmiskontrol=&UretilmisKontrol;
	this->oku=&Oku;
	this->rastgelekisiYoket=&RastgeleKisiYoket;
	return this;
}
void rastdelay(int number_of_seconds) //rastgeliliği arttıran fonksiyon
{ 
    int milli_seconds = 2 * number_of_seconds;  
    clock_t start_time = clock(); 
    while (clock() < start_time + milli_seconds) 
        ; 
} 
    void bekle()//çalışmayı geciktiren fonksiyon.
  {
      const long interval=3;
      long SayiyiAl=clock();
      long son=0;
      do
      {
          son=clock();
      }while(SayiyiAl+interval>=son);
  } 
char* Oku(RastgeleKisi this){//random txtsini okuyup herhangi bir satırı döndüren fonksiyon.
	 FILE *inFile;

	  this->r=RastgeleOlustur();
	  char* str = malloc(sizeof(char)*25);
	  char* str2 = malloc(sizeof(char)*25);
	  char* filename = "./random_isimler.txt";
	int sayac=0;
	int total=0;
	int sayi;


	  inFile = fopen(filename, "r");//dosyayı okumak için açıyorum.
	  bekle(1);
	  sayi=this->r->randomruret(this->r);//rastgele satır almak için sayı üretiyorum.
	  while(fgets(str,25,inFile)!=NULL)
	  {
	  
		if(sayac==sayi)//istenilen satırdaysa döndüden çıkıyorum.
		{
			str[strlen(str)-1]='\0';
			return str;
			break;
		}
		sayac++;
	  }
	
	  fclose(inFile);  
	
	  return str;
}
void RastgeleKisiUret(const RastgeleKisi this,int a){//rastgele kişi üreten fonksiyon
	 char* al = malloc(sizeof(char)*25);
	  char* Adal = malloc(sizeof(char)*25);
	   char* SoyAdal = malloc(sizeof(char)*25);
	   char* hesapla=malloc(sizeof(char)*2);
	    char* hesapla2=malloc(sizeof(char)*11);
	   int sayac=0;
	struct KISI kisiler[a];
	
	   
	   char *ch;
	   
		
		 for(int i=0;i<a;i++)//istenilen kişi sayısına göre kişi üretiyorum.
		 {	
		 al=this->oku(this);
			ch = strtok(al, " ");//txtden rastgele aldığımız satırı isim ve soyismi bulmak için parçalıyorum.
		while (ch != NULL) {
			if(sayac==0)
			{
				Adal=ch;//ismi bulup diziye atıyorum.
				Adal[strlen(Adal)-1]='\0';
			}
			else
			{
				SoyAdal=ch;//soyismi bulup diziye atıyorum.
			}
			ch = strtok(NULL, " ");
			sayac++;
		}
		 sayac=0;
		  this->t=TelefonOlustur();
	  this->k=KimlikNoOlustur();
	  this->im=IMEINoOlustur();
	  //bulduğum ad,soyad,yaş,tel,imei,tc yi oluşan kişiye atıyorum.
			 kisiler[i].ad=Adal;
			 kisiler[i].soyad=SoyAdal;
			 rastdelay(1);
			 kisiler[i].yas=this->r->randomyasuret(this->r);			
			  kisiler[i].telno=this->t->telal(this->t);			
			  kisiler[i].kimlikno=this->k->kimlikal(this->k);
			   kisiler[i].imeino=this->im->imeial(this->im);
			
		 }
		 //ch=NULL;
		// free(al);
			//al=NULL;
			// free(Adal);
			//Adal=NULL;
			 //free(SoyAdal);
			//SoyAdal=NULL;
		  FILE * fp;
		  char* filename = "./Kisiler.txt";
		 fp = fopen (filename,"w");//kişiler txtye yazmak için açıyorum.
		    for(int l = 0; l < a;l++){//istenilen kişi sayısına göre dosyaya yazıyorum.
				sprintf(hesapla, "%d",kisiler[l].yas);//yaş değerini char diziye dönüştürüyorum.
				//sprintf(hesapla2, "%d",kisiler[l].telno);
				 fprintf (fp,kisiler[l].kimlikno,l + 1);
				 fprintf (fp," ",l + 1);
				 fprintf (fp,kisiler[l].ad,l + 1);
				 fprintf (fp," ",l + 1);
				 fprintf (fp,kisiler[l].soyad,l + 1);
				 fprintf (fp," ",l + 1);
				 fprintf (fp,hesapla,l + 1);
				 fprintf (fp," ",l + 1);
				 fprintf (fp,kisiler[l].telno,l + 1);
				 fprintf (fp," (",l + 1);
				 fprintf (fp,kisiler[l].imeino,l + 1);
				 fprintf (fp,")",l + 1);
				 fprintf (fp,"\n",l + 1);
			}
		 fclose (fp);
}
void UretilmisKontrol(RastgeleKisi this){//üretilen tc ve imeiyi kontrol eden foksiyon
	FILE *oku;
	char* filename = "./Kisiler.txt";
	char* str = malloc(sizeof(char)*80);
	this->k=KimlikNoOlustur();
	this->im=IMEINoOlustur();
	int sayac=0;
	int tcgecerli=0;
	int tcgecersiz=0;
	int imeigecerli=0;
	int imeigecersiz=0;
	char *ch;
	 char* Tcal = malloc(sizeof(char)*11);
	   char* Imeial = malloc(sizeof(char)*16);
	   char* Imeial2 = malloc(sizeof(char)*15);
	   bool tcbak;
	   bool imeibak;
	oku = fopen(filename, "r");//satır satır okumak için dosyayı açıyorum.
	while(fgets(str,80,oku)!=NULL)
	  {
		  ch = strtok(str, " ");
		  while (ch != NULL) {
			if(sayac==0)
			{
				Tcal=ch;//txtdeki tcyi buluyorum.
				tcbak=this->k->tcKontrol(this->k,Tcal);//tc kontrol fonksiyona gönderip kontrol ediyorum.
				if(tcbak==true)//true dönerse geçerli false dönerse gecersiz değeri arttırıyorum.
				{
					tcgecerli++;
				}
				else
				{
					tcgecersiz++;
				}
				
			}
 			if(sayac==5)
			{
				Imeial=ch;//txtdeki imeiyi buluyorum.
 				for(int b=0;b<15;b++)
				{
					Imeial2[b]=Imeial[b+1];//dosyadan okunan imeyi değerini parantez kısmından kurtarıyorum.
				} 
				
				imeibak=this->im->imeiKontrol(this->im,Imeial2);//imei kontrol fonksiyona gönderip kontrol ediyorum.
 				if(imeibak==true)//true dönerse imeigecerli false dönerse imeigecersiz değeri arttırıyorum.
				{
					imeigecerli++;
				}
				else
				{
					imeigecersiz++;
				} 
			} 
			ch = strtok(NULL, " ");
			sayac++;
		  }
		sayac=0;
	  }
	  fclose(oku);
		 printf("T.C. Kimlik Kontrol\n");//ekrana geçerli geçersiz durumu yazdırıyorum.
		 printf("%d",tcgecerli);
		 printf("     Gecerli\n");
		 printf("%d",tcgecersiz);
		 printf("     Gecersiz\n\n");
		 printf("IMEI Kontrol\n");
		 printf("%d",imeigecerli);
		 printf("     Gecerli\n");
		 printf("%d",imeigecersiz);
		printf("     Gecersiz\n\n");
	    
	  
}
void RastgeleKisiYoket(RastgeleKisi this){//yoket metodu
	if(this == NULL) return;
	this->r->Yoket(this->r);
	this->k->tcYoket(this->k);
	this->im->imeiYoket(this->im);
	this->t->telYoket(this->t);
	free(this);
	this=NULL;
}