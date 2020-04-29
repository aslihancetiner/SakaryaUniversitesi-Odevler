/**
*
* @author Aslıhan Çetiner aslihan.cetiner@ogr.sakarya.edu.tr
* @since 26.04.2020
* <p>
* G171210014 1-C 
* </p>
*/
package RASTGELEKISIURET;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.nio.Buffer;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.lang.String;
import java.util.ArrayList;


public class RastgeleKisi  extends Kisi {
    String saa;
   
     ArrayList<String> cars = new ArrayList<String>();
    FileReader fileReader;
    FileWriter fileWriter;
    BufferedReader bufferedReader;
    BufferedWriter bufferedWriter;
    File file=null;
    int ne;
    
    
    public RastgeleKisi() throws FileNotFoundException {
//        this.fileReader = new FileReader("random_isimler.txt");
//        bufferedReader=new BufferedReader(fileReader);
    }
     public int Oku() throws IOException//random txtsini okuyup her satırı arrayliste atan fonksiyon.
     {
         fileReader = new FileReader("random_isimler.txt");
        bufferedReader=new BufferedReader(fileReader);
         while ((saa = bufferedReader.readLine()) != null)
         {
             cars.add(saa);
         }
         ne=cars.size(); 
         bufferedReader.close();
         return ne;
     }
    
        public void RastgeleKisiUret(int a) throws IOException//rastgele kişi üreten fonksiyon
     {
      
           Kisi[] kisiler=new Kisi[a];

        for(int i=0;i<a;i++)//istenilen sayıda kisi nesnesi tutan dizi oluşturdum.
         {
             kisiler[i]=new Kisi();
         }
         for(int i=0;i<a;i++)
         {

            int ras=RUret(Oku());//rastgele kisi txtsinin boyutu ile 0 arasında rastgele sayı ürettim
            String AdAl=cars.get(ras);//arraylistten satırı aldım.
 
              String Adayir=AdAl.substring(0,AdAl.indexOf(" "));//ismi bulup stringe attım.
              String SoyAdayir=AdAl.substring(AdAl.indexOf(" ")+1,AdAl.length());//soyismi bulup stringe attım.
              //bulduğum ad,soyad,yaş,tel,imei,tc yi oluşan kişiye atıyorum.
              kisiler[i].ad=Adayir;
              kisiler[i].SoyAd=SoyAdayir;
              kisiler[i].yas=kisiler[i].YasUret();
              kisiler[i].tel=new Telefon();
              kisiler[i].Tc=new KimlikNo();
            
         }
          //kişiler txtye yazmak için dosya açıyorum.
               file=new File("Kisiler.txt");
             
           fileWriter=new FileWriter(file); 
           bufferedWriter=new BufferedWriter(fileWriter);
         for(Kisi i:kisiler)//istenilen kişi sayısına göre dosyaya yazıyorum.
         {
             bufferedWriter.write(i.Tc.tc+" ");
             bufferedWriter.write(i.ad+" ");
             bufferedWriter.write(i.SoyAd+" ");
             bufferedWriter.write(i.yas+" ");
             bufferedWriter.write(i.tel.no+" (");
             bufferedWriter.write(i.tel.ImeiNosu+")");
            bufferedWriter.newLine();
           
         }
 bufferedWriter.flush();
             bufferedWriter.close();
          
         
     }
     public void UretilmisKontrol() throws FileNotFoundException, IOException//üretilen tc ve imeiyi kontrol eden foksiyon
     {
         //satır satır okumak için dosyayı açıyorum.
        FileReader fileReader2 = new FileReader("Kisiler.txt");
        BufferedReader bufferedReader2=new BufferedReader(fileReader2);
         String metin;
          int total=0;
           int ImeiGecerli=0;
            int ImeiGecersiz=0;
             int gecerli=0;
        int gecersiz=0;
        boolean Tcbak;
         boolean ImeiKontrol;
          ArrayList<String> cars2 = new ArrayList<String>();
          KimlikNo k=new KimlikNo();
          IMEINo imei=new IMEINo();
          while ((metin = bufferedReader2.readLine()) != null)
         {
             cars2.add(metin);  // dosyayı okuyup arrayliste atıyorum.          
         }
         total=cars2.size();
         
          for(int i=0;i<total;i++)//arraylistin boyutu kadar yani dosyadaki satır kadar işlem yapıyorum.
         {
               String AdAl=cars2.get(i);
                String Tcayir=AdAl.substring(0,11);//txtdeki tcyi buluyorum.
                String Imeiayir=AdAl.substring(AdAl.indexOf('(')+1,AdAl.indexOf(')'));//txtdeki imeiyi buluyorum.
                   Tcbak=k.TcKontrolEt(Tcayir);//tc kontrol fonksiyona gönderip kontrol ediyorum.
                    if(Tcbak==true)//true dönerse geçerli false dönerse gecersiz değeri arttırıyorum.
                  {
                      gecerli++;
                  }
                  else
                  {
                      gecersiz++;
                  }                              
                   
                  ImeiKontrol=imei.IMEIKontrolEt(Imeiayir);//imei kontrol fonksiyona gönderip kontrol ediyorum.
                 
                  if(ImeiKontrol==true)//true dönerse imeigecerli false dönerse imeigecersiz değeri arttırıyorum.
                  {
                      ImeiGecerli++;
                  }
                   else
                  {
                      ImeiGecersiz++;
                  }
                  
              
         }
         //ekrana geçerli geçersiz durumu yazdırıyorum.
         System.out.println("T.C. Kimlik Kontrol");
         System.out.println(gecerli+"     "+"Geçerli");
         System.out.println(gecersiz+"    "+"Geçersiz\n\n");       
          System.out.println("IMEI Kontrol");
         System.out.println(ImeiGecerli+"     "+"Geçerli");
         System.out.println(ImeiGecersiz+"    "+"Geçersiz\n");
       
     }

    
    
}
