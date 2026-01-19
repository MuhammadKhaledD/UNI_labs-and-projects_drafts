namespace DBapplication
{
    partial class AUTHOR_PAPERS
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
            this.authorpapers = new System.Windows.Forms.DataGridView();
            ((System.ComponentModel.ISupportInitialize)(this.authorpapers)).BeginInit();
            this.SuspendLayout();
            // 
            // authorpapers
            // 
            this.authorpapers.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.authorpapers.Location = new System.Drawing.Point(32, 31);
            this.authorpapers.Name = "authorpapers";
            this.authorpapers.RowHeadersWidth = 62;
            this.authorpapers.RowTemplate.Height = 28;
            this.authorpapers.Size = new System.Drawing.Size(744, 394);
            this.authorpapers.TabIndex = 0;
            this.authorpapers.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.authorpapers_CellContentClick);
            // 
            // AUTHOR_PAPERS
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.authorpapers);
            this.Name = "AUTHOR_PAPERS";
            this.Text = "AUTHOR_PAPERS";
            this.Load += new System.EventHandler(this.AUTHOR_PAPERS_Load);
            ((System.ComponentModel.ISupportInitialize)(this.authorpapers)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.DataGridView authorpapers;
    }
}