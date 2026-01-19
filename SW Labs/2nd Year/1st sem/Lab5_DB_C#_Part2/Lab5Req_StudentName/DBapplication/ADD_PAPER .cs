using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace DBapplication
{
    public partial class ADD_PAPER : Form
    {
        Controller controllerObj;
        public ADD_PAPER()
        {
            InitializeComponent();
        }

        private void ADD_PAPER_Load(object sender, EventArgs e)
        {
            controllerObj = new Controller();
            LoadCombo();
        }

        private void LoadCombo()
        {
            Jtitle.Items.Clear();

            DataTable dt = controllerObj.SelectJinfo();

            Jtitle.DataSource = dt;
            Jtitle.DisplayMember = "JTitle";
            Jtitle.ValueMember = "JID";
        }

        private void inspaper_Click(object sender, EventArgs e)
        {
            if (papertitle.Text != "")
            {
                if (controllerObj.InsertPaper(papertitle.Text.ToString(), Convert.ToInt32(Jtitle.SelectedValue)) == 1)
                    MessageBox.Show("Done!");
                else
                    MessageBox.Show("undone sad no rows affected...");

            }
            else
                MessageBox.Show("Please, insert all values");
        }
    }
}
