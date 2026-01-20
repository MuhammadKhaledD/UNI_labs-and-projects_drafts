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
    public partial class RetrieveProjects : Form
    {
        Controller controllerObj;
        public RetrieveProjects()
        {
            InitializeComponent();
            controllerObj = new Controller();

            DataTable dt = controllerObj.SelectDepLoc();  // Retrieves only the locations
            comboBox1.DataSource = dt;
            comboBox1.DisplayMember = "Dlocation";  // NOTE: we used only the display member here        
        }

        private void Execute_Click(object sender, EventArgs e)
        {
            // Note: we used comboBox1.Text to access the display member
            DataTable dt = controllerObj.SelectProject(comboBox1.Text); 
            dataGridView1.DataSource = dt;
            dataGridView1.Refresh();
        }
    }
}
