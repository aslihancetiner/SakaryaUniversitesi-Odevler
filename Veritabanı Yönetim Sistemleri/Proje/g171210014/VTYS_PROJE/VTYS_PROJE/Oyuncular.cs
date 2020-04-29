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

    public partial class Oyuncular : Form
    {
        SqlConnection baglanti;
        SqlCommand komut;
        SqlDataAdapter da;
        void OyuncuGetir()
        {
            baglanti = new SqlConnection("server=(localdb)\\mssqllocaldb; Initial Catalog=03.12.2019; Integrated Security=SSPI");
            baglanti.Open();
            da = new SqlDataAdapter("SELECT * FROM Actor", baglanti);
            DataTable tablo = new DataTable();
            da.Fill(tablo);
            dataGridView1.DataSource = tablo;
            baglanti.Close();
        }
        public Oyuncular()
        {
            InitializeComponent();
        }

        private void Oyuncular_Load(object sender, EventArgs e)
        {
            OyuncuGetir();
        }

        private void dataGridView1_CellEnter(object sender, DataGridViewCellEventArgs e)
        {
            textBox1.Text = dataGridView1.CurrentRow.Cells[0].Value.ToString();
            textBox2.Text = dataGridView1.CurrentRow.Cells[1].Value.ToString();
            textBox3.Text = dataGridView1.CurrentRow.Cells[2].Value.ToString();
            dateTimePicker1.Text = dataGridView1.CurrentRow.Cells[3].Value.ToString();
            textBox4.Text = dataGridView1.CurrentRow.Cells[4].Value.ToString();
            textBox5.Text = dataGridView1.CurrentRow.Cells[5].Value.ToString();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string sorgu = "INSERT INTO Actor (FirstName, LastName, BirthDate, Gender, CountryID) VALUES (@FirstName, @LastName, @BirthDate, @Gender, @CountryID)";
            komut = new SqlCommand(sorgu, baglanti);
            komut.Parameters.AddWithValue("@FirstName", textBox2.Text);
            komut.Parameters.AddWithValue("@LastName", textBox3.Text);
            komut.Parameters.AddWithValue("@BirthDate", Convert.ToDateTime(dateTimePicker1.Text));
            komut.Parameters.AddWithValue("@Gender", Convert.ToInt32(textBox4.Text));
            komut.Parameters.AddWithValue("@CountryID", Convert.ToInt32(textBox5.Text));
            baglanti.Open();
            komut.ExecuteNonQuery();
            baglanti.Close();
            OyuncuGetir();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            string sorgu = "DELETE FROM Actor WHERE ID=@ID";
            komut = new SqlCommand(sorgu, baglanti);
            komut.Parameters.AddWithValue("@ID", Convert.ToInt32(textBox1.Text));
            baglanti.Open();
            komut.ExecuteNonQuery();
            baglanti.Close();
            OyuncuGetir();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            string sorgu = "UPDATE Actor SET FirstName=@FirstName, LastName=@LastName,  BirthDate=@BirthDate, Gender=@Gender, CountryID=@CountryID WHERE ID=@ID";
            komut = new SqlCommand(sorgu, baglanti);
            komut.Parameters.AddWithValue("@ID", Convert.ToInt32(textBox1.Text));
            komut.Parameters.AddWithValue("@FirstName", textBox2.Text);
            komut.Parameters.AddWithValue("@LastName", textBox3.Text);
            komut.Parameters.AddWithValue("@BirthDate", Convert.ToDateTime(dateTimePicker1.Text));
            komut.Parameters.AddWithValue("@Gender", Convert.ToInt32(textBox4.Text));
            komut.Parameters.AddWithValue("@CountryID", Convert.ToInt32(textBox5.Text));
            baglanti.Open();
            komut.ExecuteNonQuery();
            baglanti.Close();
            OyuncuGetir();
        }
    }
    }

