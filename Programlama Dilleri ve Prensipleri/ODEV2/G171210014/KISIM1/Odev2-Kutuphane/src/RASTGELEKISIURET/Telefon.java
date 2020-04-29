/**
*
* @author Aslıhan Çetiner aslihan.cetiner@ogr.sakarya.edu.tr
* @since 26.04.2020
* <p>
* G171210014 1-C 
* </p>
*/
package RASTGELEKISIURET;

import java.util.Arrays;

/**
 *
 * @author emre
 */
public class Telefon extends Rastgele{
   
    String no;
    String ImeiNosu;
    IMEINo imei;
    public Telefon()
    {
        no=TelYaz();//üretilen tel noyu tutan değişken
        imei=new IMEINo();//imei nesnesi oluşturuyorum
        ImeiNosu=imei.imeiNo;
        
    }
    public int[] TelUret()//tel üretme fonksiyonu
    {
          int[] dizi=new int[11];
        Rastgele r =new Rastgele();
        dizi[0]=0;
        dizi[1]=5;
          for(int i=2;i<11;i++)
        {
            r.bekle();
            int sayi=r.Uret();
            if(i==2)
            {
                 while(!(sayi==0||sayi==3||sayi==4||sayi==5||sayi==6))//telefon operatörlerinin alan koduna göre üretiyorum
                  {
                      r.bekle();
                       sayi=r.Uret();
                  }
                
            }
            if(i==3)
            {
                if(dizi[2]==0)
                {
                      while(!(sayi==1||sayi==5||sayi==6||sayi==7))//telefon operatörlerinin alan koduna göre üretiyorum
                          {
                              r.bekle();
                             sayi=r.Uret();
                          }
                }
                if(dizi[2]==5)
                {
                      while(!(sayi==1||sayi==2||sayi==3||sayi==4||sayi==5||sayi==9))//telefon operatörlerinin alan koduna göre üretiyorum
                          {
                              r.bekle();
                             sayi=r.Uret();
                          }
                }
                if(dizi[2]==6)
                {
                      while(!(sayi==1))//telefon operatörlerinin alan koduna göre üretiyorum
                          {
                              r.bekle();
                             sayi=r.Uret();
                          }
                }
            }
          
           dizi[i]=sayi;
        }
        
        return dizi;
    }
    public String TelYaz()//telefonu yazma metodu
    {
        String duzenle="";
        for(int i : TelUret()) {
            duzenle+=Integer.toString(i);//int diziyi stringe dönüştürüyorum
        }
        return duzenle;
    }
    
    
    
    
    
    
    
    
}
