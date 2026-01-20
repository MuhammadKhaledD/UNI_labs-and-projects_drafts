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
    public partial class AUTHOR_PAPERS : Form
    {
        Controller controllerObj;
        public AUTHOR_PAPERS()
        {
            InitializeComponent();
        }

        private void AUTHOR_PAPERS_Load(object sender, EventArgs e)
        {
            controllerObj = new Controller();
            DataTable dt = controllerObj.SelectAllAuthors();
            authorpapers.DataSource = dt;
            authorpapers.Refresh();
        }

        private void authorpapers_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }
    }
}
