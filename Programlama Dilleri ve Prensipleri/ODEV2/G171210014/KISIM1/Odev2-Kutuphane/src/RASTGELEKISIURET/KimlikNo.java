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
public class KimlikNo extends Rastgele{
    
    String tc;
    public KimlikNo()
    {
        this.tc=TcYaz();//üretilen tc noyu tutan değişken
    }
    
    
    public int[] TcUret()//tc üretme fonksiyonu
    {
        int[] dizi=new int[11];
        Rastgele r =new Rastgele();
        for(int i=0;i<9;i++)//ilk 9 numarayı rastgele oluşturuyorum.
        {
            r.bekle();
            int sayi=r.Uret();// 0-10 arası rastgele sayı üretiyorum.
            if(i==0)//ilk hanenin 0 olmamasını sağlıyorum.0 sa tekrar üretiyorum.
            {
                while((sayi==0))
                     {
                         r.bekle();
                         sayi=r.Uret();
                     }
            }
            
            dizi[i]=sayi;
            
        }
        //tc algoritmasına göre 10.haneyi ilk 9 haneyi kullanarak hesaplıyorum.
        int toplamOn=((dizi[0]+dizi[2]+dizi[4]+dizi[6]+dizi[8])*7)+((dizi[1]+dizi[3]+dizi[5]+dizi[7])*9);
        toplamOn=toplamOn%10;//birler basamağını buluyorum.
        dizi[9]=toplamOn;//10.haneyi oluşturdum.
        //tc algoritmasına göre 11.haneyi ilk 10 haneyi kullanarak hesaplıyorum.
         int toplamOnBir=(dizi[0]+dizi[1]+dizi[2]+dizi[3]+dizi[4]+dizi[5]+dizi[6]+dizi[7]+dizi[8]+dizi[9])%10;
        dizi[10]=toplamOnBir;//11.haneyi oluşturdum.
        return dizi;
    }
    
    public boolean TcKontrolEt(String al)//tc numarasının doğru olup olmadığını kontrol eden fonksiyon
    {
        int[] dizi=new int[11];
 
       boolean b=true;
       
        for(int i=0;i<11;i++)
        {
             dizi[i]=al.charAt(i)-'0';//parametreden gelen string diziyi int diziye dönüştürüyorum.
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
    
    
    
    
    
    public String TcYaz()//üretilen tc numarasını yazdıran fonksiyon
    {
       String duzenle="";
        for(int i : TcUret()) {
            duzenle+=Integer.toString(i);//int gelen tc numarasını stringe döndürüyorum.
        }
        return duzenle;
        
    }
    
    
    
    
    
}
