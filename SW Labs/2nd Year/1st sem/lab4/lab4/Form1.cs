using System;
using System.Data;
using System.Windows.Forms;

namespace lab4
{
    public partial class Form1 : Form
    {
        Controller controllerObj;

        public Form1()
        {
            InitializeComponent();
            controllerObj = new Controller();
        }

        private void insert_new_employee_Click(object sender, EventArgs e)
        {
            if (string.IsNullOrWhiteSpace(fname.Text) || string.IsNullOrWhiteSpace(lname.Text) ||
                string.IsNullOrWhiteSpace(address.Text) || string.IsNullOrWhiteSpace(ssn.Text) ||
                string.IsNullOrWhiteSpace(dno.Text))
            {
                MessageBox.Show("Please fill in all fields.");
                return;
            }

            if (!int.TryParse(dno.Text, out int deptNo))
            {
                MessageBox.Show("Department number must be numeric.");
                return;
            }

            int result = controllerObj.InsertEmp(fname.Text, lname.Text, address.Text, ssn.Text, deptNo);
            MessageBox.Show(result == 0 ? "The insertion of a new Employee failed" : "The row is inserted successfully!");
        }

        private void update_Click(object sender, EventArgs e)
        {
            if (string.IsNullOrWhiteSpace(emp_ssn.Text) || string.IsNullOrWhiteSpace(adjprojnum.Text) ||
                string.IsNullOrWhiteSpace(hoursbox.Text))
            {
                MessageBox.Show("Please fill in all fields.");
                return;
            }

            if (!int.TryParse(hoursbox.Text, out int hours))
            {
                MessageBox.Show("Hours must be numeric.");
                return;
            }

            int result = controllerObj.UpdateHours(emp_ssn.Text, adjprojnum.Text, hours);
            MessageBox.Show(result == 0 ? "No rows are updated" : "The row is updated successfully");
        }

        private void delete_Click(object sender, EventArgs e)
        {
            if (string.IsNullOrWhiteSpace(deletemp.Text))
            {
                MessageBox.Show("Please enter the SSN to delete.");
                return;
            }

            int result = controllerObj.DeleteEmp(deletemp.Text);
            MessageBox.Show(result == 0 ? "No rows are deleted" : "The row is deleted successfully!");
        }

        private void display_sum_Click(object sender, EventArgs e)
        {
            if (projNumber.SelectedItem == null)
            {
                MessageBox.Show("Please select a project number.");
                return;
            }

            if (!int.TryParse(projNumber.SelectedItem.ToString(), out int selected))
                return;

            sumbox.Text = controllerObj.Counthours(selected).ToString();
        }

        private void display_all_Click(object sender, EventArgs e)
        {
            DataTable dt = controllerObj.SelectAllEmployee();
            empgrid.DataSource = dt;
            empgrid.Refresh();
        }

        private void LoadNumbersToCombo()
        {
            projNumber.Items.Clear();

            int[] numbers = controllerObj.GetIntArrayFromDB();

            foreach (int n in numbers)
                projNumber.Items.Add(n);
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            LoadNumbersToCombo();
        }
    }
}
