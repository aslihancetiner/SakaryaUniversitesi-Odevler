/****************************************************************************
**					SAKARYA ÜNİVERSİTESİ
**				BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				   NESNEYE DAYALI PROGRAMLAMA DERSİ
**					2018-2019 BAHAR DÖNEMİ
**	
**				ÖDEV NUMARASI..........: 3
**				ÖĞRENCİ ADI............: ASLIHAN ÇETİNER
**				ÖĞRENCİ NUMARASI.......: G171210014
**              DERSİN ALINDIĞI GRUP...: 2-C 
****************************************************************************/


using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WindowsFormsApp2
{
    public class Islem

    {

       
        public double deger(char[] sonra, ref int sonuc)  // textbox a yazılan  ifadenin içindeki rakamları bulan fonksiyon.
        {
            string islem = "";
            while ((int)sonra[sonuc] >= 48 && (int)sonra[sonuc] <= 57)
            {
                islem = islem + sonra[sonuc].ToString();
                sonuc++;
                if (sonuc == sonra.Length)
                {
                    sonuc--;
                    break;

                }

            }
            return double.Parse(islem);
        }


        
        public double Toplama_Cikarma(char[] sonra, int sonuc) //Çarpma_Bolme fonksiyonundan gelen sonuclarla stringteki  + ve - işaretlerini bulup işlem yapılıyor.
                                                             
        {

            double a = Carpma_Bolme(sonra, ref sonuc);
            while (true)
            {
                char isaret = sonra[sonuc];
                if (isaret != '+' && isaret != '-')
                    return a;
                sonuc++;
                double b = Carpma_Bolme(sonra, ref sonuc);
                if (isaret == '+')
                    a += b;
                else
                    a -= b;

            }
        }

       
      
        public double Carpma_Bolme(char[] sonra, ref int sonuc) //stringteki * ve / işaretleri bulup işlem yapılıyor.  ilk bu fonksiyon çalışır.
        {
            double a = deger(sonra, ref sonuc);
            while (true)
            {
                char isaret = sonra[sonuc];
                if (isaret != '/' && isaret != '*')
                    return a;
                sonuc++;
                double b = deger(sonra, ref sonuc);
                if (isaret == '/')
                    a /= b;
                else
                    a *= b;

            }
        }


        
        public double SonucHesapla(char[] sonra) //bütün işlemleri yapan fonksiyon
        {
            return Toplama_Cikarma(sonra, 0);
        }

    }
}
