namespace DBapplication
{
    partial class Functionalities
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
            this.show = new System.Windows.Forms.Button();
            this.create = new System.Windows.Forms.Button();
            this.show2 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // show
            // 
            this.show.Location = new System.Drawing.Point(34, 233);
            this.show.Name = "show";
            this.show.Size = new System.Drawing.Size(840, 185);
            this.show.TabIndex = 0;
            this.show.Text = "Show User’s Orders";
            this.show.UseVisualStyleBackColor = true;
            this.show.Click += new System.EventHandler(this.show_Click);
            // 
            // create
            // 
            this.create.Location = new System.Drawing.Point(41, 47);
            this.create.Name = "create";
            this.create.Size = new System.Drawing.Size(833, 164);
            this.create.TabIndex = 1;
            this.create.Text = "Create New Order";
            this.create.UseVisualStyleBackColor = true;
            this.create.Click += new System.EventHandler(this.create_Click);
            // 
            // show2
            // 
            this.show2.Location = new System.Drawing.Point(34, 438);
            this.show2.Name = "show2";
            this.show2.Size = new System.Drawing.Size(840, 188);
            this.show2.TabIndex = 2;
            this.show2.Text = "Show Spendings";
            this.show2.UseVisualStyleBackColor = true;
            this.show2.Click += new System.EventHandler(this.show2_Click);
            // 
            // Functionalities
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(903, 649);
            this.Controls.Add(this.show2);
            this.Controls.Add(this.create);
            this.Controls.Add(this.show);
            this.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.Name = "Functionalities";
            this.Text = "Welcome";
            this.Load += new System.EventHandler(this.Functionalities_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button show;
        private System.Windows.Forms.Button create;
        private System.Windows.Forms.Button show2;
    }
}