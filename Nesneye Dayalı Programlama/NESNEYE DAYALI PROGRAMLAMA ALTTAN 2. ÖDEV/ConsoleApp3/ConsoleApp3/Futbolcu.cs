using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp3
{
    class Futbolcu
    {
        public string AdSoyad;
        public int FormaNo;
        public int Hiz;
        public int Dayaniklilik;
        public int Pas;
        public int Sut;
        public int Yetenek;
        public int Kararlilik;
        public int DogalForm;
        public int Sans;

        public Futbolcu()
        {
            Random rastgele = new Random();
            Hiz = rastgele.Next(50, 100);
            Dayaniklilik = rastgele.Next(50, 100);
            Pas = rastgele.Next(50, 100);
            Sut = rastgele.Next(50, 100);
            Yetenek = rastgele.Next(50, 100);
            Kararlilik = rastgele.Next(50, 100);
            DogalForm = rastgele.Next(50, 100);
            Sans = rastgele.Next(50, 100);
        }

        public virtual bool PasVer()
        {
            return true;  
        }
        public virtual bool GolVurusu()
        {
            return true;
        }




    }
}
