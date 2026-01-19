namespace DBapplication
{
    partial class Products
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.allproducts = new System.Windows.Forms.DataGridView();
            this.label1 = new System.Windows.Forms.Label();
            this.productsname = new System.Windows.Forms.ComboBox();
            this.order = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.qty = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.orderid = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.address = new System.Windows.Forms.TextBox();
            this.userid = new System.Windows.Forms.TextBox();
            this.firstname = new System.Windows.Forms.TextBox();
            this.email = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.allproducts)).BeginInit();
            this.SuspendLayout();
            // 
            // allproducts
            // 
            this.allproducts.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.allproducts.Location = new System.Drawing.Point(12, 365);
            this.allproducts.Name = "allproducts";
            this.allproducts.RowHeadersWidth = 62;
            this.allproducts.RowTemplate.Height = 28;
            this.allproducts.Size = new System.Drawing.Size(776, 279);
            this.allproducts.TabIndex = 0;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(24, 327);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(98, 20);
            this.label1.TabIndex = 1;
            this.label1.Text = "PRODUCTS";
            // 
            // productsname
            // 
            this.productsname.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.productsname.FormattingEnabled = true;
            this.productsname.Location = new System.Drawing.Point(143, 42);
            this.productsname.Name = "productsname";
            this.productsname.Size = new System.Drawing.Size(184, 28);
            this.productsname.TabIndex = 2;
            // 
            // order
            // 
            this.order.Location = new System.Drawing.Point(247, 319);
            this.order.Name = "order";
            this.order.Size = new System.Drawing.Size(296, 37);
            this.order.TabIndex = 3;
            this.order.Text = "Place Order";
            this.order.UseVisualStyleBackColor = true;
            this.order.Click += new System.EventHandler(this.order_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(12, 48);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(98, 20);
            this.label2.TabIndex = 4;
            this.label2.Text = "PRODUCTS";
            // 
            // qty
            // 
            this.qty.Location = new System.Drawing.Point(522, 42);
            this.qty.Name = "qty";
            this.qty.Size = new System.Drawing.Size(231, 26);
            this.qty.TabIndex = 5;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(427, 42);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(41, 20);
            this.label3.TabIndex = 6;
            this.label3.Text = "QTY";
            // 
            // orderid
            // 
            this.orderid.Location = new System.Drawing.Point(120, 105);
            this.orderid.Name = "orderid";
            this.orderid.Size = new System.Drawing.Size(231, 26);
            this.orderid.TabIndex = 7;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(12, 108);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(70, 20);
            this.label4.TabIndex = 8;
            this.label4.Text = "Order ID";
            // 
            // address
            // 
            this.address.Location = new System.Drawing.Point(522, 260);
            this.address.Name = "address";
            this.address.Size = new System.Drawing.Size(231, 26);
            this.address.TabIndex = 9;
            // 
            // userid
            // 
            this.userid.Location = new System.Drawing.Point(120, 187);
            this.userid.Name = "userid";
            this.userid.Size = new System.Drawing.Size(231, 26);
            this.userid.TabIndex = 10;
            // 
            // firstname
            // 
            this.firstname.Location = new System.Drawing.Point(522, 184);
            this.firstname.Name = "firstname";
            this.firstname.Size = new System.Drawing.Size(231, 26);
            this.firstname.TabIndex = 11;
            // 
            // email
            // 
            this.email.Location = new System.Drawing.Point(120, 260);
            this.email.Name = "email";
            this.email.Size = new System.Drawing.Size(231, 26);
            this.email.TabIndex = 12;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(395, 266);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(66, 20);
            this.label5.TabIndex = 13;
            this.label5.Text = "address";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(8, 266);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(46, 20);
            this.label6.TabIndex = 14;
            this.label6.Text = "email";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(395, 190);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(79, 20);
            this.label7.TabIndex = 15;
            this.label7.Text = "first name";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(8, 190);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(56, 20);
            this.label8.TabIndex = 16;
            this.label8.Text = "user id";
            // 
            // Products
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 656);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.email);
            this.Controls.Add(this.firstname);
            this.Controls.Add(this.userid);
            this.Controls.Add(this.address);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.orderid);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.qty);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.order);
            this.Controls.Add(this.productsname);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.allproducts);
            this.Name = "Products";
            this.Text = "Products";
            this.Load += new System.EventHandler(this.Products_Load);
            ((System.ComponentModel.ISupportInitialize)(this.allproducts)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView allproducts;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ComboBox productsname;
        private System.Windows.Forms.Button order;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox qty;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox orderid;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox address;
        private System.Windows.Forms.TextBox userid;
        private System.Windows.Forms.TextBox firstname;
        private System.Windows.Forms.TextBox email;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8;
    }
}