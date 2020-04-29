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
    public partial class Yorumlar : Form
    {

        SqlConnection baglanti;
        SqlCommand komut;
        SqlDataAdapter da;
        void YorumGetir()
        {
            baglanti = new SqlConnection("server=(localdb)\\mssqllocaldb; Initial Catalog=03.12.2019; Integrated Security=SSPI");
            baglanti.Open();
            da = new SqlDataAdapter("SELECT * FROM Comment", baglanti);
            DataTable tablo = new DataTable();
            da.Fill(tablo);
            dataGridView1.DataSource = tablo;
            baglanti.Close();
        }
        public Yorumlar()
        {
            InitializeComponent();
        }

        private void Yorumlar_Load(object sender, EventArgs e)
        {
            YorumGetir();
        }

        private void dataGridView1_CellEnter(object sender, DataGridViewCellEventArgs e)
        {
            textBox1.Text = dataGridView1.CurrentRow.Cells[0].Value.ToString();
            textBox2.Text = dataGridView1.CurrentRow.Cells[1].Value.ToString();
            textBox3.Text = dataGridView1.CurrentRow.Cells[2].Value.ToString();
            dateTimePicker1.Text = dataGridView1.CurrentRow.Cells[3].Value.ToString();
            textBox4.Text = dataGridView1.CurrentRow.Cells[4].Value.ToString();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            string sorgu = "INSERT INTO Comment ( FilmID, Content ,CommentTime, Rating)  VALUES ( @FilmID, @Content,@CommentTime, @Rating)";
            komut = new SqlCommand(sorgu, baglanti);
            //komut.Parameters.AddWithValue("@ID", Convert.ToInt32(textBox1.Text));
            komut.Parameters.AddWithValue("@FilmID", Convert.ToInt32(textBox2.Text));
            komut.Parameters.AddWithValue("@Content", Convert.ToString(textBox3.Text));
            komut.Parameters.AddWithValue("@CommentTime", Convert.ToDateTime(dateTimePicker1.Text));
            komut.Parameters.AddWithValue("@Rating", Convert.ToSingle(textBox4.Text));
            baglanti.Open();
            komut.ExecuteNonQuery();
            baglanti.Close();
            YorumGetir();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            string sorgu = "DELETE FROM Comment WHERE ID=@ID";
            komut = new SqlCommand(sorgu, baglanti);
            komut.Parameters.AddWithValue("@ID", Convert.ToInt32(textBox1.Text));
            komut.Parameters.AddWithValue("@FilmID", Convert.ToInt32(textBox2.Text));
            komut.Parameters.AddWithValue("@Content", Convert.ToString(textBox3.Text));
            komut.Parameters.AddWithValue("@CommentTime", Convert.ToDateTime(dateTimePicker1.Text));
            komut.Parameters.AddWithValue("@Rating", Convert.ToSingle(textBox4.Text));
            baglanti.Open();
            komut.ExecuteNonQuery();
            baglanti.Close();
            YorumGetir();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            string sorgu = "UPDATE Comment SET FilmID=@FilmID, Content=@Content,CommentTime=@CommentTime, Rating=@Rating WHERE ID=@ID";
            komut = new SqlCommand(sorgu, baglanti);
            komut.Parameters.AddWithValue("@ID", Convert.ToInt32(textBox1.Text));
            komut.Parameters.AddWithValue("@FilmID", Convert.ToInt32(textBox2.Text));
            komut.Parameters.AddWithValue("@Content", Convert.ToString(textBox3.Text));
            komut.Parameters.AddWithValue("@CommentTime", Convert.ToDateTime(dateTimePicker1.Text));
            komut.Parameters.AddWithValue("@Rating", Convert.ToSingle(textBox4.Text));
            baglanti.Open();
            komut.ExecuteNonQuery();
            baglanti.Close();
            YorumGetir();
        }
    }
}