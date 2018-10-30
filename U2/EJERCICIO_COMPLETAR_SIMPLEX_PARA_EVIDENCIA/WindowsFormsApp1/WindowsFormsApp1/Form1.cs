using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            AsignarDatosTabla();
        }

        private void AsignarDatosTabla()
        {
            object[] fila0 = {"1/1","-3/1","-5/1","0/1","0/1","0/1","0/1"};
            object[] fila1 = {"x3","1/1","0/1","1/1","0/1","0/1","4/1"};
            object[] fila2 = { "x4", "0/1", "2/1", "0/1", "1/1", "0/1", "12/1" };
            object[] fila3 = { "x5", "3/1", "2/1", "0/1", "0/1", "1/1", "18/1" };
            dataGridView1.Rows.Add(fila0);
            dataGridView1.Rows.Add(fila1);
            dataGridView1.Rows.Add(fila2);
            dataGridView1.Rows.Add(fila3);
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            object valorCelda = dataGridView1.Rows[2].Cells[2].Value;
            //textBox1.Text = valorCelda.ToString();
            int f = dataGridView1.CurrentCellAddress.Y;
            int c = dataGridView1.CurrentCellAddress.X;
            valorCelda= dataGridView1.Rows[f].Cells[c].Value;
            textBox1.Text = valorCelda.ToString();
        }
    }//end class Form1
}//end namespace WindowsFormsApp1
