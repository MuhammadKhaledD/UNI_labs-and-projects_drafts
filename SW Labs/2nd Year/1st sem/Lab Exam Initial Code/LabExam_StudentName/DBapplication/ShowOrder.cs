using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DBapplication
{
    public partial class ShowOrder : Form
    {
        Controller c;
        public ShowOrder()
        {
            InitializeComponent();
        }

        private void ShowOrder_Load(object sender, EventArgs e)
        {
            c = new Controller();
        }

        private void entermail_Click(object sender, EventArgs e)
        {
            if(!string.IsNullOrWhiteSpace(email.Text))
            {
                DataTable dt = c.email(email.Text);
                orders.DataSource = dt;
            }
            else
            {
                MessageBox.Show("Please enter Email...");
            }
        }
    }
}
