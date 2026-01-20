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
    public partial class Supplier : Form
    {
        Controller controllerObj;
        public Supplier()
        {
            InitializeComponent();
        }

        private void Supplier_Load(object sender, EventArgs e)
        {
            controllerObj = new Controller();
        }

        private void insertButton_Click(object sender, EventArgs e)
        {
            // It is good to use Int16.TryParse first to check if the entered 'status' is a number
            // You should valaidate from the beginning that entered value to be integer.
            int result = controllerObj.InsertSupplier(sNumTextBox.Text, sNameTextBox.Text, cityTextBox.Text, Int16.Parse(statusTextBox.Text));
            if (result == 0)
            {
                MessageBox.Show("The insertion of a new Supplier failed");
            }
            else
            {
                MessageBox.Show("The row is inserted successfully!");
            }
        }

        private void deleteButton_Click(object sender, EventArgs e)
        {
            int result = controllerObj.DeleteSupplier(sNumDelTextBox.Text);
            if (result == 0)
            {
                MessageBox.Show("No rows are deleted");
            }
            else
            {
                MessageBox.Show("The row is deleted successfully!");
            }
        }

        private void updateButton_Click(object sender, EventArgs e)
        {
            int result = controllerObj.UpdateSupplier(sNumUpdateTextBox.Text, cityUpdateTextBox.Text);
            if (result == 0)
            {
                MessageBox.Show("No rows are updated");
            }
            else
            {
                MessageBox.Show("The row is updated successfully");
            }
        }

        private void closeButton_Click(object sender, EventArgs e)
        {
            controllerObj.TerminateConnection();
            this.Close();
        }

        private void selectAllButton_Click(object sender, EventArgs e)
        {
            DataTable dt = controllerObj.SelectAllSuppliers();
            suppliersDataGrid.DataSource = dt;
            suppliersDataGrid.Refresh();


        }

        private void countButton_Click(object sender, EventArgs e)
        {
            countTextBox.Text = controllerObj.CountSuppliers().ToString();
        }
    }
}
