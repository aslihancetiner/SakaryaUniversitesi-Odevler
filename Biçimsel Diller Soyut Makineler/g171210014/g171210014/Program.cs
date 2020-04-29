using System;

namespace g171210014
{
    class Program
    {
        static void Main(string[] args)
        {
            int count;
            string ifade;
            int[,] Matris = new int[4, 2]
            {
            { 1, 2 },
            { 3, 0 },
            { 2, 0},
            { 1, 3 },
            };


            int B_Durumu = 0;
            int Durum;
            int Kabul_Durum = 0;
            int Kabul_Durumu1 = 3; ;

            Durum = B_Durumu;


           
               
                Console.WriteLine("Reguler İfadeyi Giriniz:  ");
                ifade = Console.ReadLine();
                


                for (count = 0; count < ifade.Length; count++)
                {
                    if (ifade[count] == 'a')
                    {
                        Durum = Matris[Durum, 0];

                    }
                    if (ifade[count] == 'b')
                    {
                        Durum = Matris[Durum, 1];

                    }
                
                }


                if (Durum == Kabul_Durum || Durum == Kabul_Durumu1)
                {
                    Console.WriteLine("İfade kabul edildi.");
                }
                else
                {
                    Console.WriteLine("İfade reddedildi.");
                }
               
            


            Console.ReadKey();


        }
    }
}
