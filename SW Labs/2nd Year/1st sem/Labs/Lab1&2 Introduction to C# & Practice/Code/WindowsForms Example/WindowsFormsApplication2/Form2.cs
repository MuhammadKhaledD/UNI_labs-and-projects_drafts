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
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
            dataGridView1.Columns.Add("Sport", "Sport");
            dataGridView1.Columns.Add("DM", "Day/Month");
            /*comboBox2.Items.Add("Sunday");
              comboBox2.Items.Add("Monday ");*/

        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (comboBox1.SelectedItem.ToString() == "Day")
            {
                
                comboBox2.DataSource = new string[] { "Sunday ", "Monday" };


            }
            if (comboBox1.SelectedItem.ToString() == "Month")
            {
                comboBox2.DataSource = new string[] { "feb ", "jan" };

            }


        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                if (checkBox1.Checked)
                {
                    string[] row = new string[] { "Tennis", comboBox2.SelectedItem.ToString() };
                    dataGridView1.Rows.Add(row);
                }
                if (checkBox2.Checked)
                {
                    string[] row = new string[] { "Football", comboBox2.SelectedItem.ToString() };
                    dataGridView1.Rows.Add(row);
                }
                if (checkBox3.Checked)
                {
                    string[] row = new string[] { "Basketball", comboBox2.SelectedItem.ToString() };
                    dataGridView1.Rows.Add(row);
                }
            }
            catch (Exception ex) {
                System.Console.WriteLine(ex);
            }

        }

        private void dataGridView1_CellContentDoubleClick(object sender, DataGridViewCellEventArgs e)
        {
            dataGridView1.Rows.RemoveAt(e.RowIndex);
        }

    }
}
