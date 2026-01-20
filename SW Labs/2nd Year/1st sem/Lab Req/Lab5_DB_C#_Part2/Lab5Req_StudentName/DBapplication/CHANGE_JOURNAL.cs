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
    public partial class CHANGE_JOURNAL : Form
    {
        Controller controllerObj;
        public CHANGE_JOURNAL()
        {
            InitializeComponent();
            controllerObj = new Controller();
            DataTable dt = controllerObj.papers();
            papers.DataSource = dt;
            papers.DisplayMember = "ATitle";
            papers.ValueMember = "PID";
            papers.SelectedIndex = -1;
            papers.DropDownStyle = ComboBoxStyle.DropDownList;

            lbl.Visible = false;
            Jtitle.Visible = false;
        }

        private void CHANGE_JOURNAL_Load(object sender, EventArgs e)
        {
            controllerObj.Updatepaper(Convert.ToInt32(papers.SelectedValue), Convert.ToInt32(Jtitle.SelectedValue));
        }

        private void ChangeJ_Click(object sender, EventArgs e)
        {
            int rows = controllerObj.Updatepaper(Convert.ToInt32(PID.Text), Convert.ToInt32(Jtitle.SelectedValue));
            if (rows == 1)
                MessageBox.Show("Done!");
            else
                MessageBox.Show("mhmm no rows affected...sad");
        }

        private void choosepaper_Click(object sender, EventArgs e)
        {

        }

        private void papers_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (papers.SelectedIndex != -1)
            {

                lbl.Visible = true;
                Jtitle.Visible = true;
                int pid = Convert.ToInt32(papers.SelectedValue);

                DataTable dt = controllerObj.journal();
                Jtitle.DataSource = dt;
                Jtitle.DisplayMember = "JTitle";
                Jtitle.ValueMember = "JID";
                Jtitle.SelectedValue = controllerObj.journalid(pid);
                Jtitle.DropDownStyle = ComboBoxStyle.DropDownList;

                PID.Text = pid.ToString();
            }
        }
    }
}
