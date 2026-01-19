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
    public partial class Functionalities : Form
    {
        public Functionalities()
        {
            InitializeComponent();
        }

        private void Functionalities_Load(object sender, EventArgs e)
        {

        }

        private void create_Click(object sender, EventArgs e)
        {
            Products form = new Products();
            form.Show();
        }

        private void show_Click(object sender, EventArgs e)
        {
            ShowOrder form = new ShowOrder();
            form.Show();
        }

        private void show2_Click(object sender, EventArgs e)
        {
            Spendings form = new Spendings();
            form.Show();
        }
    }
}
