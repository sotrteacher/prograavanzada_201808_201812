using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp2
{
    public partial class Form1v2 : Form
    {
        public Form1v2()
        {
            InitializeComponent();
            AsignarDatosTabla();
        }

        private void AsignarDatosTabla()
        {
            object[] fila0 = { "1/1", "-3/1", "-5/1", "0/1", "0/1", "0/1", "0/1",""};
            object[] fila1 = { "x3", "1/1", "0/1", "1/1", "0/1", "0/1", "4/1","" };
            object[] fila2 = { "x4", "0/1", "2/1", "0/1", "1/1", "0/1", "12/1","" };
            object[] fila3 = { "x5", "3/1", "2/1", "0/1", "0/1", "1/1", "18/1","" };
            dataGridView1.Rows.Add(fila0);
            dataGridView1.Rows.Add(fila1);
            dataGridView1.Rows.Add(fila2);
            dataGridView1.Rows.Add(fila3);
        }

        private void Form1v2_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            //int f = dataGridView1.CurrentCellAddress.Y;
            //int c = dataGridView1.CurrentCellAddress.X;
            //textBox1.Text = c.ToString();
            //textBox2.Text = f.ToString();
            //object valorCelda = dataGridView1.Rows[ Convert.ToInt32(textBox2.Text)].Cells[Convert.ToInt32(textBox1.Text)].Value;
            //textBox3.Text = valorCelda.ToString();
            //String cad= valorCelda.ToString();
            /*int index = cad.IndexOf("/");
            int num = Convert.ToInt32(cad.Substring(0,index));
            int den = Convert.ToInt32(cad.Substring(index+1));
            textBox3.Text = den.ToString();
            */
            //int index, num, den;
            //Rac[] R = new Rac[6];
            //for(int j = 1; j <= 6; j++)
            //{
            //    valorCelda = dataGridView1.Rows[Convert.ToInt32(textBox2.Text)].Cells[j].Value;
            //    cad = valorCelda.ToString();
            //    index = cad.IndexOf("/");
            //    num = Convert.ToInt32(cad.Substring(0, index));
            //    den = Convert.ToInt32(cad.Substring(index + 1));
            //    R[j - 1] = new Rac(num,den);
            //}
            int colPivote = Convert.ToInt32(textBox1.Text);
            int colDisponibilidad = 6;
            int num, den, index;
            object valorCelda;
            Rac RacNum=new Rac(), RacDen=new Rac(),RacQ=new Rac();
            float q;
            for (int i = 1; i <= 3; i++)
            {
                valorCelda = dataGridView1.Rows[i].Cells[colDisponibilidad].Value;
                index = valorCelda.ToString().IndexOf("/");
                num = Convert.ToInt32(valorCelda.ToString().Substring(0, index));
                den = Convert.ToInt32(valorCelda.ToString().Substring(index + 1));
                RacNum.set_n(num);
                RacNum.set_d(den);
                valorCelda = dataGridView1.Rows[i].Cells[colPivote].Value;
                index = valorCelda.ToString().IndexOf("/");
                num = Convert.ToInt32(valorCelda.ToString().Substring(0, index));
                den = Convert.ToInt32(valorCelda.ToString().Substring(index + 1));
                RacDen.set_n(num);
                RacDen.set_d(den);
                if ((RacDen.get_n() != 0) && (RacDen.get_d() != 0))
                {
                    RacQ = RacNum / RacDen;
                    num = RacQ.get_n();den = RacQ.get_d();
                    q = (float)num / (float)den;
                    dataGridView1.Rows[i].Cells[colDisponibilidad + 1].Value = q.ToString();
                }
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            int colPivote = Convert.ToInt32(textBox1.Text);
            String[] headers = {"z","x1","x2","x3","x4","x5",};
            //dataGridView1.Rows[0].Cells[colPivote].
            textBox4.Text = headers[colPivote];
            textBox3.Text = dataGridView1.Rows[Convert.ToInt32(textBox2.Text)].Cells[0].Value.ToString();
        }
    }//end class
}//end namespace
