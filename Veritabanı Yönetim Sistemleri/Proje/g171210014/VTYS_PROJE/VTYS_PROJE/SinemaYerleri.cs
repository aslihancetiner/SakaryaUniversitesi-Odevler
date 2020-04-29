using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;

namespace VTYS_PROJE
{

    public partial class SinemaYerleri : Form
    {
        SqlConnection baglanti;
        SqlCommand komut;
        SqlDataAdapter da;
        void CinemaGetir()
        {
            baglanti = new SqlConnection("server=(localdb)\\mssqllocaldb; Initial Catalog=03.12.2019; Integrated Security=SSPI");
            baglanti.Open();
            da = new SqlDataAdapter("SELECT * FROM Cinema", baglanti);
            DataTable tablo = new DataTable();
            da.Fill(tablo);
            dataGridView1.DataSource = tablo;
            baglanti.Close();
        }
        public SinemaYerleri()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void SinemaYerleri_Load(object sender, EventArgs e)
        {
            CinemaGetir();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string sorgu = "INSERT INTO Cinema (Name,Phone,EMail,Address,TownID) VALUES (@Name,@Phone,@EMail,@Address,@TownID)";
            komut = new SqlCommand(sorgu, baglanti);
            komut.Parameters.AddWithValue("@Name", textBox2.Text);
            komut.Parameters.AddWithValue("@Phone", textBox3.Text);
            komut.Parameters.AddWithValue("@EMail", textBox4.Text);
            komut.Parameters.AddWithValue("@Address", textBox5.Text);
            komut.Parameters.AddWithValue("@TownID", Convert.ToInt32(textBox6.Text));
            baglanti.Open();
            komut.ExecuteNonQuery();
            baglanti.Close();
            CinemaGetir();
        }

        private void dataGridView1_CellEnter(object sender, DataGridViewCellEventArgs e)
        {
            textBox1.Text = dataGridView1.CurrentRow.Cells[0].Value.ToString();
            textBox2.Text = dataGridView1.CurrentRow.Cells[1].Value.ToString();
            textBox3.Text = dataGridView1.CurrentRow.Cells[2].Value.ToString();
            textBox4.Text = dataGridView1.CurrentRow.Cells[3].Value.ToString();
            textBox5.Text = dataGridView1.CurrentRow.Cells[4].Value.ToString();
            textBox6.Text = dataGridView1.CurrentRow.Cells[5].Value.ToString();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            string sorgu = "DELETE FROM Cinema WHERE ID=@ID";
            komut = new SqlCommand(sorgu, baglanti);
            komut.Parameters.AddWithValue("@ID", Convert.ToInt32(textBox1.Text));
            baglanti.Open();
            komut.ExecuteNonQuery();
            baglanti.Close();
            CinemaGetir();
        }
    }
}
