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
    public partial class Town : Form
    {
        SqlConnection baglanti;
        SqlCommand komut;
        SqlDataAdapter da;
        void TownGetir()
        {
            baglanti = new SqlConnection("server=(localdb)\\mssqllocaldb; Initial Catalog=03.12.2019; Integrated Security=SSPI");
            baglanti.Open();
            da = new SqlDataAdapter("SELECT * FROM Town", baglanti);
            DataTable tablo = new DataTable();
            da.Fill(tablo);
            dataGridView1.DataSource = tablo;
            baglanti.Close();
        }
        public Town()
        {
            InitializeComponent();
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void Town_Load(object sender, EventArgs e)
        {
            TownGetir();
        }

        private void dataGridView1_CellEnter(object sender, DataGridViewCellEventArgs e)
        {
            textBox1.Text = dataGridView1.CurrentRow.Cells[0].Value.ToString();
            textBox2.Text = dataGridView1.CurrentRow.Cells[1].Value.ToString();
            textBox3.Text = dataGridView1.CurrentRow.Cells[2].Value.ToString();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string sorgu = "INSERT INTO Town (Name,CityID) VALUES (@Name, @CityID)";
            komut = new SqlCommand(sorgu, baglanti);
            komut.Parameters.AddWithValue("@Name", textBox2.Text);
            komut.Parameters.AddWithValue("@CityID", Convert.ToInt32(textBox3.Text));
            baglanti.Open();
            komut.ExecuteNonQuery();
            baglanti.Close();
            TownGetir();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            string sorgu = "DELETE FROM Town WHERE ID=@ID";
            komut = new SqlCommand(sorgu, baglanti);
            komut.Parameters.AddWithValue("@ID", Convert.ToInt32(textBox1.Text));
            baglanti.Open();
            komut.ExecuteNonQuery();
            baglanti.Close();
            TownGetir();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            string sorgu = "UPDATE Town SET Name=@Name, CityID=@CityID WHERE ID=@ID";
            komut = new SqlCommand(sorgu, baglanti);
            komut.Parameters.AddWithValue("@ID", Convert.ToInt32(textBox1.Text));
            komut.Parameters.AddWithValue("@Name", textBox2.Text);
            komut.Parameters.AddWithValue("@CityID", Convert.ToInt32(textBox3.Text));
            baglanti.Open();
            komut.ExecuteNonQuery();
            baglanti.Close();
            TownGetir();
        }
    }
}
