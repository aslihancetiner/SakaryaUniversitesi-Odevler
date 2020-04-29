/****************************************************************************
**					SAKARYA ÜNİVERSİTESİ
**				BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				   NESNEYE DAYALI PROGRAMLAMA DERSİ
**					2018-2019 BAHAR DÖNEMİ
**	
**				ÖDEV NUMARASI..........: 2
**				ÖĞRENCİ ADI............: ASLIHAN ÇETİNER
**				ÖĞRENCİ NUMARASI.......: G171210014
**              DERSİN ALINDIĞI GRUP...: 2C
****************************************************************************/


using System;
using System.Collections.Generic;
namespace ConsoleApp3
{
    class Program
    {
        static void Main(string[] args)
        {

        List<Futbolcu> takim = new List<Futbolcu>();
            takim.Add(new Defans("Zeki Çelik", 2));
            takim.Add(new Defans("İsmail Kartal", 4));
            takim.Add(new Defans("Erhan Onal", 5));
            takim.Add(new Defans("Semih Yuvakuran", 3));

            takim.Add(new Ortasaha("Uğur Tutuneker", 7));
            takim.Add(new Ortasaha("Tugay Kerimoğlu", 6));
            takim.Add(new Ortasaha("Rıdvan Dilmen", 8));
            takim.Add(new Ortasaha("Metin Tekin", 11));

            takim.Add(new Forvet("Furkan Kuzu", 9));
            takim.Add(new Forvet("Metin Oktay", 10));

            int FormaNo;
            Boolean gololabilir = true;
            Random RastgeleSayi = new Random();
            int[] tut = new int[10]; 
            for (int i = 2; i <= 4; i++) // 3 Kere pas atma işlemini yapan döngü
            {
                
                
                FormaNo = RastgeleSayi.Next(2, 9);
                tut[i] = FormaNo;


                if (tut[i] != tut[i - 1] && tut[i] != tut[i - 2]) //ard arda random pas atacak oyuncunun aynı olmamasını  kontrol eden döngü.
                {
                    if (!takim[FormaNo].PasVer()) //PasVer() fonksiyonunun istenilen şekilde kontol edip, başarılı pas vuruşlarını ekrana yazdıran döngü.
                    {

                        gololabilir = false;
                        break;

                    }
                    Console.WriteLine(i - 1 + ".Pası Atan: " + FormaNo + " numaralı " + takim[FormaNo].AdSoyad);

                }
                else
                {
                    Console.WriteLine(FormaNo + " Numaralı "+takim[FormaNo].AdSoyad+ " Oyununcunun Pası Başarısız.");
                    gololabilir = false;
                    break;
                }     
          
            }
         
            if (gololabilir) // Başarılı ya da başarısız gol vuruşlarını kontrol edip ekrana yazdıran döngü.
            {
                FormaNo = RastgeleSayi.Next(2, 9);
                if (takim[FormaNo].GolVurusu())
                {
                    Console.WriteLine("GOOOOLLL!");
                    Console.WriteLine(FormaNo + " numaralı " + takim[FormaNo].AdSoyad + " Oyuncunun Gol Vuruşu Başarılı.");
                }
                else
                {
                    Console.WriteLine("GOL VURUŞU BAŞARISIZ!");
                    Console.WriteLine(FormaNo + " numaralı " + takim[FormaNo].AdSoyad + " Oyuncunun Gol Vuruşu Başarısız. ");
                }
                
            }
            Console.ReadLine();
        }
        
    }
}
