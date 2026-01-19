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

namespace lab1
{
    public partial class Form2 : Form
    {
        public Form2(string name)
        {
            InitializeComponent();
            statusCmbx.DataSource = new string[] { "To Do ", " In Progress", "Done " };
            statusCmbx.SelectedIndex = -1;
            TodoGrid.Columns.Add("Name", "Task");
            inprogGrid.Columns.Add("Name", "Task");
            doneGrid.Columns.Add("Name", "Task");
            this.Text = name;
        }

        private void addTaskBtn_Click(object sender, EventArgs e)
        {
            missingTasklbl.Visible = false;
            missingStatusLbl.Visible = false;

            if (taskTxt.Text == "" || statusCmbx.SelectedIndex == -1)
            {
                if (taskTxt.Text == "")
                {
                    missingTasklbl.Visible = true;
                }
                if (statusCmbx.SelectedIndex == -1)
                {
                    missingStatusLbl.Visible = true;
                }
            }
            else
            {
                if (statusCmbx.SelectedIndex == 0)
                {
                    TodoGrid.Rows.Add(taskTxt.Text);
                }
                else if (statusCmbx.SelectedIndex == 1)
                {
                    inprogGrid.Rows.Add(taskTxt.Text);
                }
                else
                {
                    doneGrid.Rows.Add(taskTxt.Text);
                }
            }
        }

        private void clearInBtn_Click(object sender, EventArgs e)
        {
            statusCmbx.SelectedIndex = -1;
            taskTxt.Text = "";
        }

        private void TodoGrid_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            statusCmbx.SelectedIndex = 0;
            int r = e.RowIndex;
            taskTxt.Text = TodoGrid.Rows[r].Cells[0].Value.ToString();
            TodoGrid.Rows.RemoveAt(r);
        }

        private void inprogGrid_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            statusCmbx.SelectedIndex = 1;
            int r = e.RowIndex;
            taskTxt.Text = inprogGrid.Rows[r].Cells.ToString();
            inprogGrid.Rows.RemoveAt(r);
        }

        private void doneGrid_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            statusCmbx.SelectedIndex = 2;
            int r = e.RowIndex;
            taskTxt.Text = doneGrid.Rows[r].Cells.ToString();
            doneGrid.Rows.RemoveAt(r);
        }
    }
}
