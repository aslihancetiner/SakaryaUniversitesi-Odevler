using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace WindowsFormsApp4
{
    public partial class Form3 : Form
    {
        public Form3()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            
            StreamReader sr  = new StreamReader("bos.txt");
            string Ad_Renk, SoyAD_Renk, Numara_Renk;
            Ad_Renk = "aasd";
            SoyAD_Renk = "sasdas";
            Numara_Renk = "nasdasd";
            string Adim1OkunanDeger;
            Adim1OkunanDeger = "kym";
            int Adim1OkunanAdim = 1;
            int OkunanaKacinciKelime = 1;
            while (!sr.EndOfStream)
            {
                var OkunanCumle = sr.ReadLine();

                foreach (var BosluktanOncekiKelime in OkunanCumle.Split(' '))
                {
                    if (OkunanaKacinciKelime == 1)
                    {
                        Adim1OkunanDeger = BosluktanOncekiKelime;
                        foreach (char harfharf in Adim1OkunanDeger)
                        {
                            if (Adim1OkunanAdim == 1)
                            {
                                if (harfharf == 'k')
                                {
                                    Ad_Renk = "kirmizi";
                                }
                                if (harfharf == 'y')
                                {
                                    Ad_Renk = "yesil";
                                }
                                if (harfharf == 'm')
                                {
                                    Ad_Renk = "mavi";
                                }
                            }

                            if (Adim1OkunanAdim == 2)
                            {
                                if (harfharf == 'k')
                                {
                                    SoyAD_Renk = "kirmizi";
                                }
                                if (harfharf == 'y')
                                {
                                    SoyAD_Renk = "yesil";
                                }
                                if (harfharf == 'm')
                                {
                                    SoyAD_Renk = "mavi";
                                }
                            }
                            if (Adim1OkunanAdim == 3)
                            {
                                if (harfharf == 'k')
                                {
                                    Numara_Renk = "kirmizi";
                                }
                                if (harfharf == 'y')
                                {
                                    Numara_Renk = "yesil";
                                }
                                if (harfharf == 'm')
                                {
                                    Numara_Renk = "mavi";
                                }
                            }
                            Adim1OkunanAdim += 1;
                            if (Adim1OkunanAdim == 4)
                            {
                                Adim1OkunanAdim = 1;
                            }

                        }

                    }
                    if (OkunanaKacinciKelime == 2)
                    {
                        if (Ad_Renk == "kirmizi")
                        {
                            richTextBox1.ForeColor = Color.Red;
                            richTextBox1.AppendText(BosluktanOncekiKelime + " ");
                        }
                        else if (Ad_Renk == "yesil")
                        {
                            richTextBox1.ForeColor = Color.Green;
                            richTextBox1.AppendText(BosluktanOncekiKelime + " ");
                        }
                        else if (Ad_Renk == "mavi")
                        {
                            richTextBox1.ForeColor = Color.Blue;
                            richTextBox1.AppendText(BosluktanOncekiKelime + " ");
                        }
                    }
                    if (OkunanaKacinciKelime == 3)
                    {
                        if (SoyAD_Renk == "kirmizi")
                        {
                            richTextBox1.ForeColor = Color.Red;
                            richTextBox1.AppendText(BosluktanOncekiKelime + " ");
                        }
                        else if (SoyAD_Renk == "yesil")
                        {
                            richTextBox1.ForeColor = Color.Green;
                            richTextBox1.AppendText(BosluktanOncekiKelime + " ");

                        }
                        else if (SoyAD_Renk == "mavi")
                        {
                            richTextBox1.ForeColor = Color.Blue;
                            richTextBox1.AppendText(BosluktanOncekiKelime + " ");
                        }
                    }
                    if (OkunanaKacinciKelime == 4 || OkunanaKacinciKelime == 5)
                    {
                        if (Numara_Renk == "kirmizi")
                        {
                            richTextBox1.ForeColor = Color.Red;
                            richTextBox1.AppendText(BosluktanOncekiKelime + " ");
                        }
                        else if (Numara_Renk == "yesil")
                        {
                            richTextBox1.ForeColor = Color.Green;
                            richTextBox1.AppendText(BosluktanOncekiKelime + " ");
                        }
                        else if (Numara_Renk == "mavi")
                        {
                            richTextBox1.ForeColor = Color.Blue;
                            richTextBox1.AppendText(BosluktanOncekiKelime + " ");
                        }
                    }
                    OkunanaKacinciKelime++;
                    if (OkunanaKacinciKelime == 6)
                    {
                        OkunanaKacinciKelime = 1;
                        richTextBox1.Text += "\n";
                    }
                }
            }
            sr.Close(); 


        
        }
    }
}
