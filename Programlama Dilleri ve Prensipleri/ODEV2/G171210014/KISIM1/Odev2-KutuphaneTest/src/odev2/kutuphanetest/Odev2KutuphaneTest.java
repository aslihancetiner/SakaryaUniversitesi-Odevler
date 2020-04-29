/**
*
* @author Aslıhan Çetiner aslihan.cetiner@ogr.sakarya.edu.tr
* @since 26.04.2020
* <p>
* G171210014 1-C 
* </p>
*/
package odev2.kutuphanetest;
import RASTGELEKISIURET.*;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Scanner;
/**
 *
 * @author emre
 */
public class Odev2KutuphaneTest {

    /**
     * @param args the command line arguments
     * @throws java.io.FileNotFoundException
     */
    public static void main(String[] args) throws FileNotFoundException, IOException {
        // TODO code application logic here
        

        RastgeleKisi r=new RastgeleKisi();

       int x=0;
       int kisiSayisi=0;
        Scanner sc=new Scanner(System.in);
        
        while(x!=3)
        {   
            
            System.out.println("1-  Rastgele Kişi Üret");
           System.out.println("2-  Üretilmiş Dosya Kontrol Et");
           System.out.println("3-  Çıkış"); 
            System.out.println("İşlem seçiniz...");
            x=sc.nextInt();
            switch (x)
            {
                case 1:
                {   
                    
                     System.out.println("1-  Rastgele Kişi Üret\n");
                      System.out.println("Kişi sayısı giriniz");
                       kisiSayisi=sc.nextInt();
                      r.RastgeleKisiUret(kisiSayisi);
                       System.out.println("Rastgele Kisi Uretildi\n");
                    break;
                }
                case 2:
                { 
                   
                      r.UretilmisKontrol();

                    break;
                }

                case 3: 
                {
                    System.out.println("Çıkış yaptınız.....");
                    break;
                }
                default:
                {
                    System.out.println("yanlış tuşa  bastiniz. Tekrar seçim yapınız.");
                    break;
                }

            }

        }
        
   }
    
}
