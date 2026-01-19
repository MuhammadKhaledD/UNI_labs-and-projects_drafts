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
    public partial class Products : Form
    {
        Controller c;
        public Products()
        {
            InitializeComponent();
        }

        private void Products_Load(object sender, EventArgs e)
        {
            c = new Controller();
            allproducts.DataSource = c.products();

            productsname.DataSource = c.productscombo();

            productsname.DisplayMember = "name";
            productsname.ValueMember = "id";
            productsname.SelectedIndex = -1;
            
        }

        private void order_Click(object sender, EventArgs e)
        {
            int qty_, user_id, order_id;
            if(string.IsNullOrWhiteSpace(qty.Text) || string.IsNullOrWhiteSpace(orderid.Text) || string.IsNullOrWhiteSpace(userid.Text) || string.IsNullOrWhiteSpace(firstname.Text) || string.IsNullOrWhiteSpace(address.Text) || string.IsNullOrWhiteSpace(email.Text))
            {
                MessageBox.Show("cant be empty..");
            }
            else if (int.TryParse(qty.Text, out qty_) && int.TryParse(orderid.Text, out order_id) && int.TryParse(userid.Text, out user_id) && user_id > 0 && qty_ > 0 && order_id > 0)
            {
                int u = c.InsertU(user_id, firstname.Text, email.Text, address.Text);
                int o = c.InsertO(order_id, user_id, (int)productsname.SelectedValue, qty_, qty_* c.Select((int)productsname.SelectedValue));
                if(o > 0 && u > 0)
                {
                    MessageBox.Show("done");
                }
                else
                {
                    MessageBox.Show("mhmm error 8erb");
                }
            }
            else
            {
                MessageBox.Show("must be +ve int");
            }
        }
    }
}
