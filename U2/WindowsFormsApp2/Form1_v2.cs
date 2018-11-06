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
        public float[,] FA;
        public Form1v2()
        {
            InitializeComponent();
            AsignarDatosTabla();
            //inic_FA();
        }
        public void inic_FA()
        {
            FA = new float[4,8]; 
            object valorCelda;
            int index,num,den;
            for (int i = 0; i <= 3; i++)
            {
                for(int j = 1; j <= 6; j++)
                {
                    valorCelda= dataGridView1.Rows[i].Cells[j].Value;
                    index = valorCelda.ToString().IndexOf("/");
                    num = Convert.ToInt32(valorCelda.ToString().Substring(0, index));
                    den = Convert.ToInt32(valorCelda.ToString().Substring(index + 1));
                    FA[i,j] = (float)num / (float)den;
                }
            }
        }//end inic_FA()
        private void inic1_FA()
        {
            FA = new float[4, 7];
            object valorCelda;
            for (int i = 0; i <= 3; i++)
            {
                for (int j = 1; j <= 6; j++)
                {
                    valorCelda = dataGridView1.Rows[i].Cells[j].Value;
                    FA[i, j] = (float)Convert.ToDouble(valorCelda.ToString());
                }
            }
        }

        private void AsignarDatosTabla()
        {
            //object[] fila0 = { "1/1", "-3/1", "-5/1", "0/1", "0/1", "0/1", "0/1",""};
            //object[] fila1 = { "x3", "1/1", "0/1", "1/1", "0/1", "0/1", "4/1","" };
            //object[] fila2 = { "x4", "0/1", "2/1", "0/1", "1/1", "0/1", "12/1","" };
            //object[] fila3 = { "x5", "3/1", "2/1", "0/1", "0/1", "1/1", "18/1","" };
            object[] fila0 = { "1.0", "-3.0", "-5.0", "0.0", "0.0", "0.0", "0.0", "" };
            object[] fila1 = { "x3", "1.0", "0.0", "1.0", "0.0", "0.0", "4.0", "" };
            object[] fila2 = { "x4", "0.0", "2.0", "0.0", "1.0", "0.0", "12.0", "" };
            object[] fila3 = { "x5", "3.0", "2.0", "0.0", "0.0", "1.0", "18.0", "" };
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
            ////////////////////////////////////////////////////////////////
            //Rac RacNum=new Rac(), RacDen=new Rac(),RacQ=new Rac();
            //float q;
            //for (int i = 1; i <= 3; i++)
            //{
            //    valorCelda = dataGridView1.Rows[i].Cells[colDisponibilidad].Value;
            //    index = valorCelda.ToString().IndexOf("/");
            //    num = Convert.ToInt32(valorCelda.ToString().Substring(0, index));
            //    den = Convert.ToInt32(valorCelda.ToString().Substring(index + 1));
            //    RacNum.set_n(num);
            //    RacNum.set_d(den);
            //    valorCelda = dataGridView1.Rows[i].Cells[colPivote].Value;
            //    index = valorCelda.ToString().IndexOf("/");
            //    num = Convert.ToInt32(valorCelda.ToString().Substring(0, index));
            //    den = Convert.ToInt32(valorCelda.ToString().Substring(index + 1));
            //    RacDen.set_n(num);
            //    RacDen.set_d(den);
            //    if ((RacDen.get_n() != 0) && (RacDen.get_d() != 0))
            //    {
            //        RacQ = RacNum / RacDen;
            //        num = RacQ.get_n();den = RacQ.get_d();
            //        q = (float)num / (float)den;
            //        dataGridView1.Rows[i].Cells[colDisponibilidad + 1].Value = q.ToString();
            //    }
            //}
            /////////////////////////////////////////////////////////////////
            float q,Num,Den;
            for (int i = 0; i <= 3; i++)
            {
                dataGridView1.Rows[i].Cells[6 + 1].Value = "";
            }
            for (int i = 1; i <= 3; i++)
            {
                valorCelda = dataGridView1.Rows[i].Cells[colDisponibilidad].Value;
                Num = (float)Convert.ToDouble(valorCelda.ToString());
                valorCelda = dataGridView1.Rows[i].Cells[colPivote].Value;
                Den=(float)Convert.ToDouble(valorCelda.ToString());
                if (Den != 0)
                {
                    q = Num / Den;
                    dataGridView1.Rows[i].Cells[colDisponibilidad + 1].Value = q.ToString();
                }
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            int colPivote = Convert.ToInt32(textBox1.Text);
            String[] headers = {"z","x1","x2","x3","x4","x5",};
            textBox4.Text = headers[colPivote];
            textBox3.Text = dataGridView1.Rows[Convert.ToInt32(textBox2.Text)].Cells[0].Value.ToString();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            int fp, cp;     //fila pivote, columna pivote
            float factor;
            String[] headers = { "z", "x1", "x2", "x3", "x4", "x5", };
            fp = Convert.ToInt32(textBox2.Text);
            cp = Convert.ToInt32(textBox1.Text);
            dataGridView1.Rows[fp].Cells[0].Value = headers[cp];
            inic1_FA();
            factor = 1/FA[fp,cp];
            for(int j = 1; j <= 6; j++)
            {
                FA[fp, j] = factor * FA[fp, j];
                dataGridView1.Rows[fp].Cells[j].Value = FA[fp, j].ToString();
            }
            for(int i = 0; i <= 3; i++)
            {
                if (i != fp)
                {
                    factor = -FA[i, cp];
                    for(int j = 1; j <= 6; j++)
                    {
                        FA[i, j] = FA[i, j] + factor * FA[fp, j];
                        dataGridView1.Rows[i].Cells[j].Value = FA[i, j].ToString();
                    }
                }
            }
            for(int i = 0; i <= 3; i++)
            {
                dataGridView1.Rows[i].Cells[6 + 1].Value = "";
            }
            textBox1.Text = "";
            textBox2.Text = "";
            textBox3.Text = "";
            textBox4.Text = "";
        }//end button3_Click(object sender, EventArgs e)
    }//end class Form1v2
}//end namespace WindowsFormsApp2
