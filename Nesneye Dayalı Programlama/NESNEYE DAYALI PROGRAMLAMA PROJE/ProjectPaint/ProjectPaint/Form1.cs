using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Drawing.Imaging;
using System.Runtime.InteropServices;
using System.IO;

namespace ProjectPaint
{
    public partial class Form1 : Form
    {
        bool paint = false; //ekrana bir şeyler çizilip çizilmediğini kontrol etmek için
        Pen pen = new Pen(Color.Black, 2); //kalem nesnesi
        int x, y, lx, ly = 0; //mouse'un tıklandığı kordinatlar ve bırakıldığı kordinatlar

        private void pictureBox2_Click(object sender, EventArgs e)
        {
            pen.Color = pictureBox2.BackColor; //kalem rengini tıklandığı rengin arkaplanından alıyor.
        }

        private void pictureBox3_Click(object sender, EventArgs e)
        {
            pen.Color = pictureBox3.BackColor; //kalem rengini tıklandığı rengin arkaplanından alıyor.
        }

        private void pictureBox4_Click(object sender, EventArgs e)
        {
            pen.Color = pictureBox4.BackColor; //kalem rengini tıklandığı rengin arkaplanından alıyor.
        }

        private void pictureBox5_Click(object sender, EventArgs e)
        {
            pen.Color = pictureBox5.BackColor; //kalem rengini tıklandığı rengin arkaplanından alıyor.
        }

        private void pictureBox6_Click(object sender, EventArgs e)
        {
            pen.Color = pictureBox6.BackColor; //kalem rengini tıklandığı rengin arkaplanından alıyor.
        }

        private void pictureBox7_Click(object sender, EventArgs e)
        {
            pen.Color = pictureBox7.BackColor; //kalem rengini tıklandığı rengin arkaplanından alıyor.
        }

        private void pictureBox8_Click(object sender, EventArgs e)
        {
            currItem = Item.Rectangle; //şekillerin tıklanmalarını yakalamak için (kare)
        }

        private void pictureBox9_Click(object sender, EventArgs e)
        {
            currItem = Item.Pollygon; //şekillerin tıklanmalarını yakalamak için (üçgen)
        }

        private void pictureBox10_Click(object sender, EventArgs e)
        {
            currItem = Item.Ellipse; //şekillerin tıklanmalarını yakalamak için (daire)
        }

        
        private void pictureBox1_MouseDown(object sender, MouseEventArgs e)//mouse'un ilk tıklandığı nokta
        {
            paint = true;
            x = e.X;
            y = e.Y;
        }

        private void pictureBox1_MouseMove(object sender, MouseEventArgs e) //mouse basılıyken hareket
        {
            if (paint)//paint == true; çizilebiliyorsa
            {
                Graphics g = pictureBox1.CreateGraphics(); //çizim yapılacak alanın belirlenmesi (picturebox1)
                if (currItem == Item.Rectangle) //eğer kare item'ı seçildiyse
                {
                    g.FillRectangle(new SolidBrush(pen.Color), x, y, e.X - x, e.Y - y); //fillrectangle kodu içinin tamemen boyanması için. Rengini kalem nesnesinden alıyor sonrası x,y koordinatlarına göre çiziliyor.
                }  
            }
        }

        private void pictureBox1_MouseUp(object sender, MouseEventArgs e) //mouse'un bırakıldığı nokta
        {
            paint = false; //çizimi durdur
            lx = e.X; //mouse'un bırakıldığı noktanın x koordinatındaki yeri
            ly = e.Y; //mouse'un bırakıldığı noktanın y koordinatındaki yeri
            if (currItem == Item.Pollygon) // üçgen
            {
                int fp = (x + e.X) / 2; //üçgenin tepe noktası
                Point pt1 = new Point(fp, y); // ilk nokta
                Point pt2 = new Point(e.X, e.Y); // ikinci nokta
                Point pt3 = new Point(x, e.Y); // üçüncü nokta
                Graphics g = pictureBox1.CreateGraphics();
                g.FillPolygon(new SolidBrush(pen.Color), new PointF[] { pt1, pt2, pt3 });
            }
            else if (currItem == Item.Pollygonn) //eşkenar dörtgen
            {
                Graphics g = pictureBox1.CreateGraphics();
                int fp = (x + e.X) / 2; //ilk noktanın yerinin belirlenmesi
                int sp = (y + e.Y) / 2; //sağdaki noktanın yerinin belirlenmesi
                int tp = (x + e.X) / 2; //alttaki noktanın yerinin belirlenmesi
                int fthp = (y + e.Y) / 2; //soldaki noktanın yerinin belirlenmesi
                Point pn1 = new Point(fp, y); 
                Point pn2 = new Point(e.X, sp);
                Point pn3 = new Point(tp, e.Y);
                Point pn4 = new Point(x, fthp);
                g.FillPolygon(new SolidBrush(pen.Color), new PointF[] { pn1, pn2, pn3, pn4 });
            }
            else if (currItem == Item.Ellipse) //daire
            {
                Graphics g = pictureBox1.CreateGraphics();
                g.FillEllipse(new SolidBrush(pen.Color), x, y, e.X - x, e.Y - y);
            }
        }

        
        private void pictureBox12_Click(object sender, EventArgs e) //open butonu kodları
        {
            OpenFileDialog o = new OpenFileDialog(); //butona tıklayınca açılacak dialogun belirllenmesi
            o.Filter = "png files|*.png|jpeg files|*jpg|bitmaps|*.bmp"; //seçilebilecek dosya formatları
            if (o.ShowDialog() == System.Windows.Forms.DialogResult.OK) //eğer dialog açıldıysa
            {
                pictureBox1.Image = (Image)Image.FromFile(o.FileName).Clone(); //ekrana (picturebox1'e) seçilen resim dosyasını kopyala
            }   
        }

        private void pictureBox13_Click(object sender, EventArgs e) //kadet butonu kodları
        {
            Bitmap bmp = new Bitmap(pictureBox1.Width, pictureBox1.Height); //kaydedilen resmin yüksekliği ve genişliği
            Graphics g = Graphics.FromImage(bmp);
            Rectangle rect = pictureBox1.RectangleToScreen(pictureBox1.ClientRectangle); //ekrandaki şekiller
            g.CopyFromScreen(rect.Location, Point.Empty, pictureBox1.Size); //ekrandan kaydet
            g.Dispose(); 
            SaveFileDialog s = new SaveFileDialog(); //butona tıklayınca bu diyalog açılacak
            s.Filter = "png files|*.png|jpeg files|*jpg|bitmaps|*.bmp"; //sadece bu formatlarda kaydedilebilir.
            if (s.ShowDialog() == System.Windows.Forms.DialogResult.OK) //eğer diyalog açıldıysa
            {
                if (File.Exists(s.FileName)) //eğer aynı isimde dosya varsa
                {
                    File.Delete(s.FileName);
                }
                if (s.FileName.Contains(".jpg")) //.jpg formatı seçildiyse
                {
                    bmp.Save(s.FileName, ImageFormat.Jpeg);
                }
                else if (s.FileName.Contains(".png")) //.png formatı seçildiyse
                {
                    bmp.Save(s.FileName, ImageFormat.Png);
                }
                else if (s.FileName.Contains(".bmp")) //.bmp formatı seçildiyse
                {
                    bmp.Save(s.FileName, ImageFormat.Bmp);
                }
            }
        }

        private void pictureBox11_Click(object sender, EventArgs e) 
        {
            currItem = Item.Pollygonn; //üçgenin tıklanmasını yakalamak için
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        Item currItem;
        public Form1()
        {
            InitializeComponent();
        }
        public enum Item
        {
            Rectangle, Pollygon, Ellipse, Pollygonn //şekiller
        }
    }
}
