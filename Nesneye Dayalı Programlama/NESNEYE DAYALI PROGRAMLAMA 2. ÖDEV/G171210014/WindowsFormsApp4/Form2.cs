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
    public partial class Form2 : Form

    {
        string list1;
        string list2;
        string list3;
        public Form2()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }
        private void label3_Click(object sender, EventArgs e)
        {

        }
        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {

            listBox1.Items.Add(textBox1.Text + " " + textBox2.Text + " " + maskedTextBox1.Text);


            if ((listBox2.SelectedIndex == 0 || listBox2.SelectedIndex == 1 || listBox2.SelectedIndex == 2) && (listBox3.SelectedIndex == 0 || listBox3.SelectedIndex == 1 || listBox3.SelectedIndex == 2) && (listBox4.SelectedIndex == 0 || listBox4.SelectedIndex == 1 || listBox4.SelectedIndex == 2))
            {
                if (listBox2.SelectedIndex == 0)
                {
                    list1 = "k";
                }
                else if (listBox2.SelectedIndex == 1)
                {
                    list1 = "y";
                }
                else if (listBox2.SelectedIndex == 2)
                {
                    list1 = "m";
                }

                if (listBox3.SelectedIndex == 0)
                {
                    list2 = "k";
                }
                else if (listBox3.SelectedIndex == 1)
                {
                    list2 = "y";
                }
                else if (listBox3.SelectedIndex == 2)
                {
                    list2 = "m";
                }

                if (listBox4.SelectedIndex == 0)
                {
                    list3 = "k";
                }
                else if (listBox4.SelectedIndex == 1)
                {
                    list3 = "y";
                }
                else if (listBox4.SelectedIndex == 2)
                {
                    list3 = "m";
                }
                StreamWriter sw = new StreamWriter("bos.txt", true);
                sw.Write(list1 + list2 + list3 + " " + textBox1.Text + " " + textBox2.Text + " " + maskedTextBox1.Text + Environment.NewLine);
                sw.Close();



            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            listBox1.Items.RemoveAt(listBox1.SelectedIndex);
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void listBox2_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void listBox3_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void Form2_Load(object sender, EventArgs e)
        {

        }
    }
}
