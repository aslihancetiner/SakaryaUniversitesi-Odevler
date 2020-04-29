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
    public partial class Cinema : Form
    {
        public Cinema()
        {
            InitializeComponent();
        }

        private void Cinema_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            City formac = new City();
            formac.Show();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Town formac = new Town();
            formac.Show();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            SinemaYerleri formac = new SinemaYerleri();
            formac.Show();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            Salon formac = new Salon();
            formac.Show();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            Ticket formac = new Ticket();
            formac.Show();
        }
    }
    }
