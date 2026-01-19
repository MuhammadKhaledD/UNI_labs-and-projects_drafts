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
    public partial class Welcome : Form
    {
        public Welcome()
        {
            InitializeComponent();
        }

        // TODO: it is good practice, to rename the controls with meaningful names before accessing them

        private void button1_Click(object sender, EventArgs e)
        {
            AdminLogin a = new AdminLogin();
            a.Show();
             
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Provided_Functionalities f = new Provided_Functionalities(0);  // 0 for non-admin
            f.Show();
        }
    }
}
