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
    public partial class Film : Form
    {

        SqlConnection baglanti;
        SqlCommand komut;
        SqlDataAdapter da;
        void FilmGetir()
        {
            baglanti = new SqlConnection("server=(localdb)\\mssqllocaldb; Initial Catalog=03.12.2019; Integrated Security=SSPI");
            baglanti.Open();
            da = new SqlDataAdapter("SELECT * FROM Film", baglanti);
            DataTable tablo = new DataTable();
            da.Fill(tablo);
            dataGridView1.DataSource = tablo;
            baglanti.Close();
        }
        public Film()
        {
            InitializeComponent();
        }

        private void Film_Load(object sender, EventArgs e)
        {
            FilmGetir();
        }

        private void dataGridView1_CellEnter(object sender, DataGridViewCellEventArgs e)
        {
            textBox1.Text = dataGridView1.CurrentRow.Cells[0].Value.ToString();
            textBox13.Text = dataGridView1.CurrentRow.Cells[1].Value.ToString();
            textBox2.Text = dataGridView1.CurrentRow.Cells[2].Value.ToString();
            textBox3.Text = dataGridView1.CurrentRow.Cells[3].Value.ToString();
            dateTimePicker1.Text = dataGridView1.CurrentRow.Cells[4].Value.ToString();
            textBox5.Text = dataGridView1.CurrentRow.Cells[5].Value.ToString();
            textBox6.Text = dataGridView1.CurrentRow.Cells[6].Value.ToString();
            textBox7.Text = dataGridView1.CurrentRow.Cells[7].Value.ToString();
            textBox8.Text = dataGridView1.CurrentRow.Cells[8].Value.ToString();
            textBox9.Text = dataGridView1.CurrentRow.Cells[9].Value.ToString();
            dateTimePicker2.Text = dataGridView1.CurrentRow.Cells[10].Value.ToString();
            dateTimePicker3.Text = dataGridView1.CurrentRow.Cells[11].Value.ToString();
            textBox12.Text = dataGridView1.CurrentRow.Cells[12].Value.ToString();

        }

        private void button1_Click(object sender, EventArgs e)
        {
            string sorgu = "INSERT INTO Film (CategoryID, NativeID, Name, ReleaseDate, Duration,IMDBRating,Description,Banner,Trailer,StartDate,EndDate,DirectorID)  VALUES (@CategoryID, @NativeID, @Name, @ReleaseDate, @Duration,@IMDBRating,@Description,@Banner,@Trailer,@StartDate,@EndDate,@DirectorID)";
            komut = new SqlCommand(sorgu, baglanti);
            komut.Parameters.AddWithValue("@CategoryID", Convert.ToInt32(textBox13.Text));
            komut.Parameters.AddWithValue("@NativeID", Convert.ToInt32(textBox2.Text));
            komut.Parameters.AddWithValue("@Name", textBox3.Text);
            komut.Parameters.AddWithValue("@ReleaseDate", Convert.ToDateTime(dateTimePicker1.Text));
            komut.Parameters.AddWithValue("@Duration", Convert.ToInt32(textBox5.Text));
            komut.Parameters.AddWithValue("@IMDBRating", Convert.ToSingle(textBox6.Text));
            komut.Parameters.AddWithValue("@Description", textBox7.Text);
            komut.Parameters.AddWithValue("@Banner", textBox8.Text);
            komut.Parameters.AddWithValue("@Trailer", textBox9.Text);
            komut.Parameters.AddWithValue("@StartDate", Convert.ToDateTime(dateTimePicker2.Text));
            komut.Parameters.AddWithValue("@EndDate", Convert.ToDateTime(dateTimePicker3.Text));
            komut.Parameters.AddWithValue("@DirectorID", Convert.ToInt32(textBox12.Text));
            baglanti.Open();
            komut.ExecuteNonQuery();
            baglanti.Close();
            FilmGetir();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            string sorgu = "DELETE FROM Film WHERE ID=@ID";
            komut = new SqlCommand(sorgu, baglanti);
            komut.Parameters.AddWithValue("@ID", Convert.ToInt32(textBox1.Text));
            komut.Parameters.AddWithValue("@CategoryID", Convert.ToInt32(textBox13.Text));
            komut.Parameters.AddWithValue("@NativeID", Convert.ToInt32(textBox2.Text));
            komut.Parameters.AddWithValue("@Name", textBox3.Text);
            komut.Parameters.AddWithValue("@ReleaseDate", Convert.ToDateTime(dateTimePicker1.Text));
            komut.Parameters.AddWithValue("@Duration", Convert.ToInt32(textBox5.Text));
            komut.Parameters.AddWithValue("@IMDBRating", Convert.ToSingle(textBox6.Text));
            komut.Parameters.AddWithValue("@Description", textBox7.Text);
            komut.Parameters.AddWithValue("@Banner", textBox8.Text);
            komut.Parameters.AddWithValue("@Trailer", textBox9.Text);
            komut.Parameters.AddWithValue("@StartDate", Convert.ToDateTime(dateTimePicker2.Text));
            komut.Parameters.AddWithValue("@EndDate", Convert.ToDateTime(dateTimePicker3.Text));
            komut.Parameters.AddWithValue("@DirectorID", Convert.ToInt32(textBox12.Text));
            baglanti.Open();
            komut.ExecuteNonQuery();
            baglanti.Close();
            FilmGetir();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            string sorgu = "UPDATE Film SET CategoryID=@CategoryID, NativeID=@NativeID, Name=@Name, ReleaseDate=@ReleaseDate, Duration=@Duration,IMDBRating=@IMDBRating,Description=@Description,Banner=@Banner,Trailer=@Trailer, StartDate=@StartDate,EndDate=@EndDate,DirectorID=@DirectorID WHERE ID=@ID";
            komut = new SqlCommand(sorgu, baglanti);
            komut.Parameters.AddWithValue("@ID", Convert.ToInt32(textBox1.Text));
            komut.Parameters.AddWithValue("@CategoryID", Convert.ToInt32(textBox13.Text));
            komut.Parameters.AddWithValue("@NativeID", Convert.ToInt32(textBox2.Text));
            komut.Parameters.AddWithValue("@Name", textBox3.Text);
            komut.Parameters.AddWithValue("@ReleaseDate", Convert.ToDateTime(dateTimePicker1.Text));
            komut.Parameters.AddWithValue("@Duration", Convert.ToInt32(textBox5.Text));
            komut.Parameters.AddWithValue("@IMDBRating", Convert.ToSingle(textBox6.Text));
            komut.Parameters.AddWithValue("@Description", textBox7.Text);
            komut.Parameters.AddWithValue("@Banner", textBox8.Text);
            komut.Parameters.AddWithValue("@Trailer", textBox9.Text);
            komut.Parameters.AddWithValue("@StartDate", Convert.ToDateTime(dateTimePicker2.Text));
            komut.Parameters.AddWithValue("@EndDate", Convert.ToDateTime(dateTimePicker3.Text));
            komut.Parameters.AddWithValue("@DirectorID", Convert.ToInt32(textBox12.Text));
            baglanti.Open();
            komut.ExecuteNonQuery();
            baglanti.Close();
            FilmGetir();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            Yorumlar formac = new Yorumlar();
            formac.Show();
        }
    }
}
