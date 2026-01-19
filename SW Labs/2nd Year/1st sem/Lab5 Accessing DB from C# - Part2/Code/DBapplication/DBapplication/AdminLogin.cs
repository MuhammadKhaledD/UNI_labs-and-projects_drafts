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
    public partial class AdminLogin : Form
    {
        public AdminLogin()
        {
            InitializeComponent();
        }

        // TODO: it is good practice, to rename the controls with meaningful names before accessing them
        // TODO: Don't forget to add any needed validations (the empty fields, int.TryParse, etc.)
        // We omitted the TryParse here, but you MUST use it in any assessment

        private void button1_Click(object sender, EventArgs e)
        {
            // Password can be saved in the DB encrypted rather than being hardcoded.
            if (textBox1.Text.ToString() == "1234")  
            {
                // Login successful
                Provided_Functionalities f = new Provided_Functionalities(1);  // 1 means admin
                f.Show();
            }
            else
            {
                MessageBox.Show("Password isn't correct");
            }
            this.Close();
        }

      
    }
}
