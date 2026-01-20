namespace DBapplication
{
    partial class CHANGE_JOURNAL
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
            this.Jtitle = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.lbl = new System.Windows.Forms.Label();
            this.PID = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.ChangeJ = new System.Windows.Forms.Button();
            this.papers = new System.Windows.Forms.ComboBox();
            this.SuspendLayout();
            // 
            // Jtitle
            // 
            this.Jtitle.FormattingEnabled = true;
            this.Jtitle.Location = new System.Drawing.Point(628, 74);
            this.Jtitle.Name = "Jtitle";
            this.Jtitle.Size = new System.Drawing.Size(160, 28);
            this.Jtitle.TabIndex = 1;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 77);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(84, 20);
            this.label1.TabIndex = 2;
            this.label1.Text = "Paper Title";
            // 
            // lbl
            // 
            this.lbl.AutoSize = true;
            this.lbl.Location = new System.Drawing.Point(499, 79);
            this.lbl.Name = "lbl";
            this.lbl.Size = new System.Drawing.Size(110, 20);
            this.lbl.TabIndex = 3;
            this.lbl.Text = "Jounrals Titles";
            // 
            // PID
            // 
            this.PID.Location = new System.Drawing.Point(375, 76);
            this.PID.Name = "PID";
            this.PID.ReadOnly = true;
            this.PID.Size = new System.Drawing.Size(100, 26);
            this.PID.TabIndex = 4;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(288, 82);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(36, 20);
            this.label3.TabIndex = 5;
            this.label3.Text = "PID";
            // 
            // ChangeJ
            // 
            this.ChangeJ.Location = new System.Drawing.Point(238, 171);
            this.ChangeJ.Name = "ChangeJ";
            this.ChangeJ.Size = new System.Drawing.Size(285, 92);
            this.ChangeJ.TabIndex = 6;
            this.ChangeJ.Text = "Change";
            this.ChangeJ.UseVisualStyleBackColor = true;
            this.ChangeJ.Click += new System.EventHandler(this.ChangeJ_Click);
            // 
            // papers
            // 
            this.papers.FormattingEnabled = true;
            this.papers.Location = new System.Drawing.Point(114, 79);
            this.papers.Name = "papers";
            this.papers.Size = new System.Drawing.Size(121, 28);
            this.papers.TabIndex = 7;
            this.papers.SelectedIndexChanged += new System.EventHandler(this.papers_SelectedIndexChanged);
            // 
            // CHANGE_JOURNAL
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.papers);
            this.Controls.Add(this.ChangeJ);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.PID);
            this.Controls.Add(this.lbl);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.Jtitle);
            this.Name = "CHANGE_JOURNAL";
            this.Text = "CHANGE_JOURNAL";
            this.Load += new System.EventHandler(this.CHANGE_JOURNAL_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.ComboBox Jtitle;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label lbl;
        private System.Windows.Forms.TextBox PID;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button ChangeJ;
        private System.Windows.Forms.ComboBox papers;
    }
}