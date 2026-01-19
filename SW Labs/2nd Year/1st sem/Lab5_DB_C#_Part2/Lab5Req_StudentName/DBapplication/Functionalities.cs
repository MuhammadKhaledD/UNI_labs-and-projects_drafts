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

        private void form1btn_Click(object sender, EventArgs e)
        {
            ADD_PAPER f = new ADD_PAPER();
            f.Show();
        }

        private void form2btn_Click(object sender, EventArgs e)
        {
            AUTHOR_PAPERS f = new AUTHOR_PAPERS();
            f.Show();
        }

        private void form3btn_Click(object sender, EventArgs e)
        {
            CHANGE_JOURNAL f = new CHANGE_JOURNAL();
            f.Show();
        }
    }
}
