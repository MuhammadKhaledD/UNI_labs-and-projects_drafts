namespace DBapplication
{
    partial class ShowOrder
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
            this.email = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.entermail = new System.Windows.Forms.Button();
            this.orders = new System.Windows.Forms.DataGridView();
            ((System.ComponentModel.ISupportInitialize)(this.orders)).BeginInit();
            this.SuspendLayout();
            // 
            // email
            // 
            this.email.Location = new System.Drawing.Point(134, 52);
            this.email.Name = "email";
            this.email.Size = new System.Drawing.Size(292, 26);
            this.email.TabIndex = 0;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(25, 55);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(53, 20);
            this.label1.TabIndex = 1;
            this.label1.Text = "E-mail";
            // 
            // entermail
            // 
            this.entermail.Location = new System.Drawing.Point(483, 43);
            this.entermail.Name = "entermail";
            this.entermail.Size = new System.Drawing.Size(139, 44);
            this.entermail.TabIndex = 2;
            this.entermail.Text = "Display ";
            this.entermail.UseVisualStyleBackColor = true;
            this.entermail.Click += new System.EventHandler(this.entermail_Click);
            // 
            // orders
            // 
            this.orders.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.orders.Location = new System.Drawing.Point(12, 170);
            this.orders.Name = "orders";
            this.orders.RowHeadersWidth = 62;
            this.orders.RowTemplate.Height = 28;
            this.orders.Size = new System.Drawing.Size(628, 268);
            this.orders.TabIndex = 3;
            // 
            // ShowOrder
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(652, 450);
            this.Controls.Add(this.orders);
            this.Controls.Add(this.entermail);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.email);
            this.Name = "ShowOrder";
            this.Text = "ShowOrder";
            this.Load += new System.EventHandler(this.ShowOrder_Load);
            ((System.ComponentModel.ISupportInitialize)(this.orders)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox email;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button entermail;
        private System.Windows.Forms.DataGridView orders;
    }
}