using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp3
{
    class Ortasaha:Futbolcu
    {
        public int UzunTop;
        public int IlkDokunus;
        public int Uretkenlik;
        public int TopSurme;
        public int OzelYetenek;

        public Ortasaha(string isim, int forma)
        {
            AdSoyad = isim;
            FormaNo = forma;
            Random rastgele = new Random();
            UzunTop = rastgele.Next(60, 100);
            IlkDokunus = rastgele.Next(60, 100);
            Uretkenlik = rastgele.Next(60, 100);
            TopSurme = rastgele.Next(60, 100);
            OzelYetenek = rastgele.Next(60, 100);
        }

        public override bool PasVer()
        {
            double PasSkor;
            PasSkor = Pas * 0.3 + Yetenek * 0.2 + OzelYetenek * 0.2 + Dayaniklilik * 0.1 + DogalForm * 0.1 + UzunTop * 0.1 + TopSurme * 0.1 + Sans * 0.1;
            if (PasSkor >= 60)
                return true;
            else
                return false;
        }
        public override bool GolVurusu()
        {
           double GolSkor = Yetenek * 0.3 + OzelYetenek * 0.2 + Sut * 0.2 + IlkDokunus * 0.1 + Kararlilik * 0.1 + DogalForm * 0.1 + Sans * 0.1;
            if (GolSkor >= 70)
                return true;
            else
                return false;
        }

    }
}
