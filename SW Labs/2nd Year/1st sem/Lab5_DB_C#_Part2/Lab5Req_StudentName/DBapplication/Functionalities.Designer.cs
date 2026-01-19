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
            this.form1btn = new System.Windows.Forms.Button();
            this.form2btn = new System.Windows.Forms.Button();
            this.form3btn = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // form1btn
            // 
            this.form1btn.Location = new System.Drawing.Point(36, 48);
            this.form1btn.Name = "form1btn";
            this.form1btn.Size = new System.Drawing.Size(354, 40);
            this.form1btn.TabIndex = 0;
            this.form1btn.Text = "ADD_PAPER";
            this.form1btn.UseVisualStyleBackColor = true;
            this.form1btn.Click += new System.EventHandler(this.form1btn_Click);
            // 
            // form2btn
            // 
            this.form2btn.Location = new System.Drawing.Point(36, 181);
            this.form2btn.Name = "form2btn";
            this.form2btn.Size = new System.Drawing.Size(354, 40);
            this.form2btn.TabIndex = 1;
            this.form2btn.Text = " AUTHOR_PAPERS";
            this.form2btn.UseVisualStyleBackColor = true;
            this.form2btn.Click += new System.EventHandler(this.form2btn_Click);
            // 
            // form3btn
            // 
            this.form3btn.Location = new System.Drawing.Point(36, 307);
            this.form3btn.Name = "form3btn";
            this.form3btn.Size = new System.Drawing.Size(354, 40);
            this.form3btn.TabIndex = 2;
            this.form3btn.Text = " CHANGE_JOURNAL";
            this.form3btn.UseVisualStyleBackColor = true;
            this.form3btn.Click += new System.EventHandler(this.form3btn_Click);
            // 
            // Functionalities
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(426, 402);
            this.Controls.Add(this.form3btn);
            this.Controls.Add(this.form2btn);
            this.Controls.Add(this.form1btn);
            this.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.Name = "Functionalities";
            this.Text = "Welcome";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button form1btn;
        private System.Windows.Forms.Button form2btn;
        private System.Windows.Forms.Button form3btn;
    }
}