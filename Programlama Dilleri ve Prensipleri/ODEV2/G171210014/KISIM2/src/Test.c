/**
*
* @author Aslıhan Çetiner aslihan.cetiner@ogr.sakarya.edu.tr
* @since 26.04.2020
* <p>
* G171210014 1-C 
* </p>
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Rastgele.h"
#include "Telefon.h"
#include "KimlikNo.h"
#include "IMEINo.h"
#include "RastgeleKisi.h"


int main(){
	int x=0;
	int KisiSayisi=0;
	RastgeleKisi rast=RastgeleKisiOlustur();
	
 	        while(x!=3)
        {   
            printf("1-  Rastgele Kisi Uret\n");
           printf("2-  Uretilmis Dosya Kontrol Et\n");
           printf("3-  Cikis\n"); 
            printf("Islem seciniz...\n");
           scanf ("%d",&x);
            switch (x)
            {
                case 1:
                {   
                    
                     printf("1-  Rastgele Kisi Uret\n");
					   printf("Kisi Sayisi Giriniz\n");
					   scanf ("%d",&KisiSayisi);
                      rast->rastgelekisiuret(rast,KisiSayisi);
					   printf(" Rastgele Kisi Uretildi\n\n");
                    break;
                }
                case 2:
                { 

                    rast->uretilmiskontrol(rast);
   
                    break;
                }

                case 3: 
                {
                    printf("Cikis yaptiniz.....\n");
                    break;
                }
                default:
                {
                   printf("yanlis tusa  bastiniz. Tekrar secim yapiniz.\n");
                    break;
                }

            }

        } 
		rast->rastgelekisiYoket(rast);
	getchar();
	return 0;
}
 