using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace WindowsFormsApplication2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox1.Checked == true)
            {
                textBox2.ReadOnly = false;
            }
            else {
                textBox2.ReadOnly = true;
            }
        }

        private void textBox1_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter) {
                MessageBox.Show("Hello " + textBox1.Text);
            }
        }

        private void textBox1_Move(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (SunnyButton.Checked){
                MessageBox.Show("You can go");
            }
            if (RainyButton.Checked) {
                MessageBox.Show("Stay at home");
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Form f2 = new Form2();
            f2.Show();
        }

        private void textBox1_MouseHover(object sender, EventArgs e)
        {

        }

    }
}
