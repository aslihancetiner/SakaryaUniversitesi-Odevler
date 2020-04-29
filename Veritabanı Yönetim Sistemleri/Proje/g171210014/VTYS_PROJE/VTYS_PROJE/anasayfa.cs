using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace VTYS_PROJE
{
    public partial class anasayfa : Form
    {
        public anasayfa()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Category formac = new Category();
            formac.Show();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Native formac = new Native();
            formac.Show();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            Country formac = new Country();
            formac.Show();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Yönetmen formac = new Yönetmen();
            formac.Show();
        }

        private void anasayfa_Load(object sender, EventArgs e)
        {

        }

        private void button5_Click(object sender, EventArgs e)
        {
            Oyuncular formac = new Oyuncular();
            formac.Show();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            Film formac = new Film();
            formac.Show();
        }

        private void button7_Click(object sender, EventArgs e)
        {

        }

        private void button7_Click_1(object sender, EventArgs e)
        {

            Cinema formac = new Cinema();
            formac.Show();
        }
    }
}
