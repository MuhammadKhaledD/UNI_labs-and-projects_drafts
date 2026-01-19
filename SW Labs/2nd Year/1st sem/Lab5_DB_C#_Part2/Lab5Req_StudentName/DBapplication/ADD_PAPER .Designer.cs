namespace DBapplication
{
    partial class ADD_PAPER
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
            this.papertitle = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.Jtitle = new System.Windows.Forms.ComboBox();
            this.inspaper = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // papertitle
            // 
            this.papertitle.Location = new System.Drawing.Point(187, 159);
            this.papertitle.Name = "papertitle";
            this.papertitle.Size = new System.Drawing.Size(230, 26);
            this.papertitle.TabIndex = 0;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(55, 162);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(84, 20);
            this.label1.TabIndex = 1;
            this.label1.Text = "Paper Title";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(55, 227);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(94, 20);
            this.label2.TabIndex = 2;
            this.label2.Text = "Journal Title";
            // 
            // Jtitle
            // 
            this.Jtitle.FormattingEnabled = true;
            this.Jtitle.Location = new System.Drawing.Point(187, 224);
            this.Jtitle.Name = "Jtitle";
            this.Jtitle.Size = new System.Drawing.Size(230, 28);
            this.Jtitle.TabIndex = 3;
            // 
            // inspaper
            // 
            this.inspaper.Location = new System.Drawing.Point(187, 305);
            this.inspaper.Name = "inspaper";
            this.inspaper.Size = new System.Drawing.Size(230, 45);
            this.inspaper.TabIndex = 4;
            this.inspaper.Text = "Insert";
            this.inspaper.UseVisualStyleBackColor = true;
            this.inspaper.Click += new System.EventHandler(this.inspaper_Click);
            // 
            // ADD_PAPER
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.inspaper);
            this.Controls.Add(this.Jtitle);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.papertitle);
            this.Name = "ADD_PAPER";
            this.Text = "ADD_PAPER";
            this.Load += new System.EventHandler(this.ADD_PAPER_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox papertitle;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.ComboBox Jtitle;
        private System.Windows.Forms.Button inspaper;
    }
}