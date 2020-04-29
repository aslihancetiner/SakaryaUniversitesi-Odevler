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
        bool paint = false;
        Pen pen = new Pen(Color.Black, 2);
        int x, y, lx, ly = 0;

        private void pictureBox2_Click(object sender, EventArgs e)
        {
            pen.Color = pictureBox2.BackColor;
        }

        private void pictureBox3_Click(object sender, EventArgs e)
        {
            pen.Color = pictureBox3.BackColor;
        }

        private void pictureBox4_Click(object sender, EventArgs e)
        {
            pen.Color = pictureBox4.BackColor;
        }

        private void pictureBox5_Click(object sender, EventArgs e)
        {
            pen.Color = pictureBox5.BackColor;
        }

        private void pictureBox6_Click(object sender, EventArgs e)
        {
            pen.Color = pictureBox6.BackColor;
        }

        private void pictureBox7_Click(object sender, EventArgs e)
        {
            pen.Color = pictureBox7.BackColor;
        }

        private void pictureBox8_Click(object sender, EventArgs e)
        {
            currItem = Item.Rectangle;
        }

        private void pictureBox9_Click(object sender, EventArgs e)
        {
            currItem = Item.Pollygon;
        }

        private void pictureBox10_Click(object sender, EventArgs e)
        {
            currItem = Item.Ellipse;
        }

        private void pictureBox1_MouseDown(object sender, MouseEventArgs e)
        {
            paint = true;
            x = e.X;
            y = e.Y;
        }

        private void pictureBox1_MouseMove(object sender, MouseEventArgs e)
        {
            if (paint)
            {
                Graphics g = pictureBox1.CreateGraphics();
                if (currItem == Item.Rectangle)
                {
                    g.FillRectangle(new SolidBrush(pen.Color), x, y, e.X - x, e.Y - y);
                }  
            }
        }

        private void pictureBox1_MouseUp(object sender, MouseEventArgs e)
        {
            paint = false;
            lx = e.X;
            ly = e.Y;
            if (currItem == Item.Pollygon)
            {
                int fp = (x + e.X) / 2;
                Point pt1 = new Point(fp, y);
                Point pt2 = new Point(e.X, e.Y);
                Point pt3 = new Point(x, e.Y);
                Graphics g = pictureBox1.CreateGraphics();
                g.FillPolygon(new SolidBrush(pen.Color), new PointF[] { pt1, pt2, pt3 });
            }
            else if (currItem == Item.Pollygonn)
            {
                Graphics g = pictureBox1.CreateGraphics();
                int fp = (x + e.X) / 2;
                int sp = (y + e.Y) / 2;
                int tp = (x + e.X) / 2;
                int fthp = (y + e.Y) / 2;
                Point pn1 = new Point(fp, y);
                Point pn2 = new Point(e.X, sp);
                Point pn3 = new Point(tp, e.Y);
                Point pn4 = new Point(x, fthp);
                g.FillPolygon(new SolidBrush(pen.Color), new PointF[] { pn1, pn2, pn3, pn4 });
            }
            else if (currItem == Item.Ellipse)
            {
                Graphics g = pictureBox1.CreateGraphics();
                g.FillEllipse(new SolidBrush(pen.Color), x, y, e.X - x, e.Y - y);
            }
        }

        private void pictureBox12_Click(object sender, EventArgs e)
        {
            OpenFileDialog o = new OpenFileDialog();
            o.Filter = "png files|*.png|jpeg files|*jpg|bitmaps|*.bmp";
            if (o.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                pictureBox1.Image = (Image)Image.FromFile(o.FileName).Clone();
            }   
        }

        private void pictureBox13_Click(object sender, EventArgs e)
        {
            Bitmap bmp = new Bitmap(pictureBox1.Width, pictureBox1.Height);
            Graphics g = Graphics.FromImage(bmp);
            Rectangle rect = pictureBox1.RectangleToScreen(pictureBox1.ClientRectangle);
            g.CopyFromScreen(rect.Location, Point.Empty, pictureBox1.Size);
            g.Dispose();
            SaveFileDialog s = new SaveFileDialog();
            s.Filter = "png files|*.png|jpeg files|*jpg|bitmaps|*.bmp";
            if (s.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                if (File.Exists(s.FileName))
                {
                    File.Delete(s.FileName);
                }
                if (s.FileName.Contains(".jpg"))
                {
                    bmp.Save(s.FileName, ImageFormat.Jpeg);
                }
                else if (s.FileName.Contains(".png"))
                {
                    bmp.Save(s.FileName, ImageFormat.Png);
                }
                else if (s.FileName.Contains(".bmp"))
                {
                    bmp.Save(s.FileName, ImageFormat.Bmp);
                }
            }
        }

        private void pictureBox11_Click(object sender, EventArgs e)
        {
            currItem = Item.Pollygonn;
        }

        Item currItem;
        public Form1()
        {
            InitializeComponent();
        }
        public enum Item
        {
            Rectangle, Pollygon, Ellipse, Pollygonn
        }
    }
}
