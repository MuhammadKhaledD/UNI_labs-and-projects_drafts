using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace DBapplication
{
    public partial class AddProject : Form
    {
        Controller controllerObj;
        public AddProject()
        {
            InitializeComponent();
            controllerObj = new Controller();

            // WRONG: DataTable dt = controllerObj.SelectDepNum(); XXXXXXXXXXX
            
            DataTable dt = controllerObj.SelectDepInfo();   // Here is the correct way
            // Note: make sure of the query to select at least the (Dname and Dnumber)
            // not only the Dname, to be able to use them in (.DisplayMember) and (.ValueMember) of combobox

            comboBox1.DataSource = dt;
            comboBox1.DisplayMember = "Dname";  // Here
            comboBox1.ValueMember = "Dnumber";  // Here
        }

        // TODO: it is good practice, to rename the controls with meaningful names before accessing them
        // TODO: Don't forget to add any needed validations (the empty fields, int.TryParse, etc.)
        // We omitted the TryParse here, but you MUST use it in any assessment

        private void button1_Click(object sender, EventArgs e)
        {            
            if (textBox1.Text=="" || textBox2.Text=="" || textBox3.Text=="")  // Validation part
            {
                MessageBox.Show("Please, insert all values");
            }
            else
            {
                // WRONG: 
                // int r = controllerObj.InsertProject(textBox1.Text.ToString(), Convert.ToInt32(textBox2.Text),
                //              textBox3.Text.ToString(), Convert.ToInt32(comboBox1.Text)); XXXXXXXXXXXXX

                // Here: should use int.TryParse in a condition
                int r = controllerObj.InsertProject(textBox1.Text.ToString(), Convert.ToInt32(textBox2.Text), 
                                textBox3.Text.ToString(), Convert.ToInt32(comboBox1.SelectedValue));  
                // NOTE: we used comboBox1.SelectedValue to access the dnumber (not the displayed dname)
                // and we needed to convert it to int because SelectedValue returns type "object"
                
                if (r != 0)  // r contains the number of affected rows (r should be = 1 if inserted 1 row)
                    MessageBox.Show("Project is inserted successfully");
                else
                    MessageBox.Show("Project is NOT inserted. Failure.");
            }
        }
    }
}
