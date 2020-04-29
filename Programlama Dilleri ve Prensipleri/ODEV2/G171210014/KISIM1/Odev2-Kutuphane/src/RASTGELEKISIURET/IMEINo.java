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
public class IMEINo extends Rastgele{
    
    String imeiNo;
    public IMEINo()
    {
        this.imeiNo=IMEIYaz();//üretilen imei noyu tutan değişken
    }
     public int[] IMEIUret()//imei üreten fonksiyon
    {
         int ToplamOnBes=0;
         int[] dizi=new int[15];
        Rastgele r =new Rastgele();
         for(int i=0;i<14;i++)//ilk 14 haneyi rastgele üretiyorum.
        {
            r.bekle();
            int sayi=r.Uret();        
            dizi[i]=sayi;
            
        }
        for(int i=1;i<14;i=i+2)//tek indeklere göre işlem yapıyorum.imei algoritmasına göre
        {
            if(dizi[i]*2<10)
            {
                 ToplamOnBes+=dizi[i]*2;
            }
             else
            {
                int al=dizi[i]*2;              
                String hesap=Integer.toString(al);//inti stringe dönüştürüyorum
                String diz[]=new String[hesap.length()];
                for(int j=0;j<hesap.length();j++)
                {
                    String duzen=hesap.substring(j,j+1);//stringi parçalara ayırıyorum.
                    diz[j]=duzen;
                }
               ToplamOnBes+=Integer.parseInt(diz[0])+Integer.parseInt(diz[1]);//stringi inte dönüştürüyorum.
               
            }      
        }
         for(int i=0;i<14;i=i+2)//15numaralı imeinin çift indekslerini topluyorum.
        {
            ToplamOnBes+=dizi[i];
        }
         for(int i=10;i<=200;i=i+10)//imei numarasının son hanesini buluyorum.
        {
            if(i>= ToplamOnBes)//ilk 14 değerin toplamı 10un katlarından birinden küçükse çıkarıyorum ve son haneyi bulmuş oluyorum.
            {
                dizi[14]=(i- ToplamOnBes);
                break;
            }
            
        }
        
        return dizi;
    }
     
      public boolean IMEIKontrolEt(String al)//imei numarasının doğru olup olmadığını kontrol eden fonksiyon
    {
        int[] dizi=new int[15];
        int ToplamOnBes=0;
        int SonSayiKontrol=0;
     
       boolean b=true;
       
        for(int i=0;i<15;i++)
        {
             dizi[i]=al.charAt(i)-'0';//parametreden gelen string diziyi int diziye dönüştürüyorum.
        }
        for(int i=1;i<14;i=i+2)//son hanesini gerekli kuralları uygulayarak oluşturuyorum.15numaralı imeinin tek indekslerini topluyorum.
        {
            if(dizi[i]*2<10)
            {
                 ToplamOnBes+=dizi[i]*2;
            }
             else
            {
                int all=dizi[i]*2;              
                String hesap=Integer.toString(all);
                String diz[]=new String[hesap.length()];
                for(int j=0;j<hesap.length();j++)
                {
                    String duzen=hesap.substring(j,j+1);//stringi parçalara ayırıyorum.
                    diz[j]=duzen;
                }
               ToplamOnBes+=Integer.parseInt(diz[0])+Integer.parseInt(diz[1]);//stringi int değere döndürüyorum ve topluyorum.
               
            }      
        }
         for(int i=0;i<14;i=i+2)//son hanesini gerekli kuralları uygulayarak oluşturuyorum.15numaralı imeinin çift indekslerini topluyorum.
        {
            ToplamOnBes+=dizi[i];
        }
         for(int i=10;i<=200;i=i+10)
        {
            if(i>= ToplamOnBes)//ilk 14 değerin toplamı 10un katlarından birinden küçükse çıkarıyorum ve son haneyi bulmuş oluyorum.
            {
                 SonSayiKontrol=(i- ToplamOnBes);
                break;
            }
            
        }
    if(SonSayiKontrol!=dizi[14])//parametreden gelen numaranın son hanesi kontrolde oluşan son haneye eşitmi değilmi bakıyorum.
        {
            b=false;//eşit değilse fonksiyon false döndürüyor.
        }
        
       
        return b;
    }
     
     
     
     
     
     
     
     
     
     
    public String IMEIYaz()//üretilen imei numarasını yazdıran fonksiyon
    {
        String duzenle="";
        for(int i :IMEIUret()) {
            duzenle+=Integer.toString(i);//int gelen imei numarasını stringe döndürüyorum.
        }
        return duzenle;
    }
    
}
