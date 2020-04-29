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
    public partial class Native : Form
    {
        SqlConnection baglanti;
        SqlCommand komut;
        SqlDataAdapter da;

        void DilGetir()
        {
            baglanti = new SqlConnection("server=(localdb)\\mssqllocaldb; Initial Catalog=03.12.2019; Integrated Security=SSPI");
            baglanti.Open();
            da = new SqlDataAdapter("SELECT * FROM Native", baglanti);
            DataTable tablo = new DataTable();
            da.Fill(tablo);
            dataGridView1.DataSource = tablo;
            baglanti.Close();
        }

        public Native()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            string sorgu = "DELETE FROM Native WHERE ID=@ID";
            komut = new SqlCommand(sorgu, baglanti);
            komut.Parameters.AddWithValue("@ID", Convert.ToInt32(textBox3.Text));
            baglanti.Open();
            komut.ExecuteNonQuery();
            baglanti.Close();
            DilGetir();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string sorgu = "INSERT INTO Native (Name, DisplayOrder) VALUES (@Name, @DisplayOrder)";
            komut = new SqlCommand(sorgu, baglanti);
            komut.Parameters.AddWithValue("@Name", textBox1.Text);
            komut.Parameters.AddWithValue("@DisplayOrder", textBox2.Text);
            baglanti.Open();
            komut.ExecuteNonQuery();
            baglanti.Close();
            DilGetir();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            string sorgu = "UPDATE Native SET Name=@Name, DisplayOrder=@DisplayOrder WHERE ID=@ID";
            komut = new SqlCommand(sorgu, baglanti);
            komut.Parameters.AddWithValue("@ID", Convert.ToInt32(textBox3.Text));
            komut.Parameters.AddWithValue("@Name", textBox1.Text);
            komut.Parameters.AddWithValue("@DisplayOrder", textBox2.Text);
            baglanti.Open();
            komut.ExecuteNonQuery();
            baglanti.Close();
            DilGetir();
        }

        private void Form2_Load(object sender, EventArgs e)
        {
            DilGetir();
        }
       

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void dataGridView1_CellEnter_1(object sender, DataGridViewCellEventArgs e)
        {
            textBox1.Text = dataGridView1.CurrentRow.Cells[1].Value.ToString();
            textBox2.Text = dataGridView1.CurrentRow.Cells[2].Value.ToString();
            textBox3.Text = dataGridView1.CurrentRow.Cells[0].Value.ToString();
        }
    }
}
