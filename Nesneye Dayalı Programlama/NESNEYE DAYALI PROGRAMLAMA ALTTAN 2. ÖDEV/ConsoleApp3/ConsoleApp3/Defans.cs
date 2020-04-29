using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp3
{
    class Defans:Futbolcu
    {
        public int PozisyonAlma;
        public int Kafa;
        public int Sicrama;

        public Defans(string isim, int forma)
        {
            AdSoyad = isim;
            FormaNo = forma;
            Random rastgele = new Random();
            PozisyonAlma = rastgele.Next(50, 90);
            Kafa = rastgele.Next(50, 90);
            Sicrama = rastgele.Next(50, 90);    
        }

        public override bool PasVer()
        {
            double PasSkor = Pas * 0.3 + Yetenek * 0.3 + Dayaniklilik * 0.1 + DogalForm * 0.1 + PozisyonAlma * 0.1 + Sans * 0.2;
            if (PasSkor >= 60)
                return true;
            else
                return false;
        }
        public override bool GolVurusu()
        {
           double GolSkor = Yetenek * 0.3 + Sut * 0.2 + Kararlilik * 0.1 + DogalForm * 0.1 + Kafa * 0.1 + Sicrama * 0.1 + Sans * 0.1;
            if (GolSkor >= 70)
                return true;
            else
                return false;
        }
       


    }
}
