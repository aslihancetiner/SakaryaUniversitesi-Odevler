using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp3
{
    class Forvet:Futbolcu
    {
        public int Bitiricilik;
        public int IlkDokunus;
        public int Kafa;
        public int OzelYetenek;
        public int Sogukkanlilik;

        public Forvet(string isim, int forma)
        {
            AdSoyad = isim;
            FormaNo = forma;
            Random rastgele = new Random();
            Bitiricilik = rastgele.Next(70, 100);
            IlkDokunus = rastgele.Next(70, 100);
            Kafa = rastgele.Next(70, 100);
            OzelYetenek = rastgele.Next(70, 100);
            Sogukkanlilik = rastgele.Next(70, 100);
        }

        public override bool PasVer()
        {
            double PasSkor;
            PasSkor = Pas * 0.3 + Yetenek * 0.2 + OzelYetenek * 0.2 + Dayaniklilik * 0.1 + DogalForm * 0.1 + Sans * 0.1;
            if (PasSkor >= 60)
                return true;
            else
                return false;
        }
        public override bool GolVurusu()
        {
           double GolSkor = Yetenek * 0.2 + OzelYetenek * 0.2 + Sut * 0.1 + Kafa * 0.1 + IlkDokunus * 0.1 + Bitiricilik * 0.1 + Sogukkanlilik * 0.1 + Kararlilik * 0.1 + DogalForm * 0.1 + Sans * 0.1;
            if (GolSkor >= 70)
                return true;
            else
                return false;
        }


    }
}
