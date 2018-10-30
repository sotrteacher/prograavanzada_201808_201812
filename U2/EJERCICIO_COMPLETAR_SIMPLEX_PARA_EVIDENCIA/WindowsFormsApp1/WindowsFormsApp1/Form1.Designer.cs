namespace WindowsFormsApp1
{
    partial class Form1
    {
        /// <summary>
        /// Variable del diseñador necesaria.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpiar los recursos que se estén usando.
        /// </summary>
        /// <param name="disposing">true si los recursos administrados se deben desechar; false en caso contrario.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código generado por el Diseñador de Windows Forms

        /// <summary>
        /// Método necesario para admitir el Diseñador. No se puede modificar
        /// el contenido de este método con el editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.col_z = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.col_x1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.col_x2 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.col_x3 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.col_x4 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.col_x5 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.col_b = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.button1 = new System.Windows.Forms.Button();
            this.textBox1 = new System.Windows.Forms.TextBox();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.SuspendLayout();
            // 
            // dataGridView1
            // 
            this.dataGridView1.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.dataGridView1.AutoSizeRowsMode = System.Windows.Forms.DataGridViewAutoSizeRowsMode.DisplayedCells;
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.col_z,
            this.col_x1,
            this.col_x2,
            this.col_x3,
            this.col_x4,
            this.col_x5,
            this.col_b});
            this.dataGridView1.Location = new System.Drawing.Point(0, 0);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.RowHeadersWidthSizeMode = System.Windows.Forms.DataGridViewRowHeadersWidthSizeMode.AutoSizeToAllHeaders;
            this.dataGridView1.Size = new System.Drawing.Size(584, 250);
            this.dataGridView1.TabIndex = 0;
            // 
            // col_z
            // 
            this.col_z.HeaderText = "z";
            this.col_z.Name = "col_z";
            // 
            // col_x1
            // 
            this.col_x1.HeaderText = "x1";
            this.col_x1.Name = "col_x1";
            // 
            // col_x2
            // 
            this.col_x2.HeaderText = "x2";
            this.col_x2.Name = "col_x2";
            // 
            // col_x3
            // 
            this.col_x3.HeaderText = "x3";
            this.col_x3.Name = "col_x3";
            // 
            // col_x4
            // 
            this.col_x4.HeaderText = "x4";
            this.col_x4.Name = "col_x4";
            // 
            // col_x5
            // 
            this.col_x5.HeaderText = "x5";
            this.col_x5.Name = "col_x5";
            // 
            // col_b
            // 
            this.col_b.HeaderText = "";
            this.col_b.Name = "col_b";
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(25, 271);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 1;
            this.button1.Text = "Fila pivote";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(25, 310);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(75, 20);
            this.textBox1.TabIndex = 2;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(584, 361);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.dataGridView1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.DataGridViewTextBoxColumn col_z;
        private System.Windows.Forms.DataGridViewTextBoxColumn col_x1;
        private System.Windows.Forms.DataGridViewTextBoxColumn col_x2;
        private System.Windows.Forms.DataGridViewTextBoxColumn col_x3;
        private System.Windows.Forms.DataGridViewTextBoxColumn col_x4;
        private System.Windows.Forms.DataGridViewTextBoxColumn col_x5;
        private System.Windows.Forms.DataGridViewTextBoxColumn col_b;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.TextBox textBox1;
    }
}

