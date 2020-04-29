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
    public partial class Salon : Form
    {
        SqlConnection baglanti;
        SqlCommand komut;
        SqlDataAdapter da;
        void SalonGetir()
        {
            baglanti = new SqlConnection("server=(localdb)\\mssqllocaldb; Initial Catalog=03.12.2019; Integrated Security=SSPI");
            baglanti.Open();
            da = new SqlDataAdapter("SELECT * FROM Salon", baglanti);
            DataTable tablo = new DataTable();
            da.Fill(tablo);
            dataGridView1.DataSource = tablo;
            baglanti.Close();
        }
        public Salon()
        {
            InitializeComponent();
        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void Salon_Load(object sender, EventArgs e)
        {
            SalonGetir();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string sorgu = "INSERT INTO Salon (Name,Capacity,CinemaID) VALUES (@Name,@Capacity,@CinemaID)";
            komut = new SqlCommand(sorgu, baglanti);
            komut.Parameters.AddWithValue("@Name", Convert.ToInt32 (textBox2.Text));
            komut.Parameters.AddWithValue("@Capacity", Convert.ToInt32(textBox3.Text));
            komut.Parameters.AddWithValue("@CinemaID", Convert.ToInt32(textBox4.Text));
            baglanti.Open();
            komut.ExecuteNonQuery();
            baglanti.Close();
            SalonGetir();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            string sorgu = "DELETE FROM Salon WHERE ID=@ID";
            komut = new SqlCommand(sorgu, baglanti);
            komut.Parameters.AddWithValue("@ID", Convert.ToInt32(textBox1.Text));
            baglanti.Open();
            komut.ExecuteNonQuery();
            baglanti.Close();
            SalonGetir();
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void dataGridView1_CellEnter(object sender, DataGridViewCellEventArgs e)
        {
            textBox1.Text = dataGridView1.CurrentRow.Cells[0].Value.ToString();
            textBox2.Text = dataGridView1.CurrentRow.Cells[1].Value.ToString();
            textBox3.Text = dataGridView1.CurrentRow.Cells[2].Value.ToString();
            textBox4.Text = dataGridView1.CurrentRow.Cells[3].Value.ToString();

        }

        private void button3_Click(object sender, EventArgs e)
        {
            string sorgu = "UPDATE Salon SET Name=@Name, Capacity=@Capacity, CinemaID=@CinemaID WHERE ID=@ID";
            komut = new SqlCommand(sorgu, baglanti);
            komut.Parameters.AddWithValue("@ID", Convert.ToInt32(textBox1.Text));
            komut.Parameters.AddWithValue("@Name", Convert.ToInt32(textBox2.Text));
            komut.Parameters.AddWithValue("@Capacity", Convert.ToInt32(textBox3.Text));
            komut.Parameters.AddWithValue("@CinemaID", Convert.ToInt32(textBox4.Text));
            baglanti.Open();
            komut.ExecuteNonQuery();
            baglanti.Close();
            SalonGetir();
        }
    }
}
