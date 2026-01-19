namespace lab1
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
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
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            userNameTxt = new TextBox();
            passwordTxt = new TextBox();
            userNameLbl = new Label();
            passwordLbl = new Label();
            showPassChx = new CheckBox();
            loginBtn = new Button();
            missingUsernameLbl = new Label();
            missingPassLbl = new Label();
            incorrectPassLbl = new Label();
            SuspendLayout();
            // 
            // userNameTxt
            // 
            userNameTxt.Location = new Point(291, 103);
            userNameTxt.Name = "userNameTxt";
            userNameTxt.Size = new Size(257, 31);
            userNameTxt.TabIndex = 0;
            userNameTxt.TextAlign = HorizontalAlignment.Right;
            // 
            // passwordTxt
            // 
            passwordTxt.Location = new Point(291, 182);
            passwordTxt.Name = "passwordTxt";
            passwordTxt.PasswordChar = '*';
            passwordTxt.Size = new Size(257, 31);
            passwordTxt.TabIndex = 1;
            passwordTxt.TextAlign = HorizontalAlignment.Right;
            // 
            // userNameLbl
            // 
            userNameLbl.AutoSize = true;
            userNameLbl.Location = new Point(185, 109);
            userNameLbl.Name = "userNameLbl";
            userNameLbl.Size = new Size(91, 25);
            userNameLbl.TabIndex = 2;
            userNameLbl.Text = "Username";
            // 
            // passwordLbl
            // 
            passwordLbl.AutoSize = true;
            passwordLbl.Location = new Point(185, 185);
            passwordLbl.Name = "passwordLbl";
            passwordLbl.Size = new Size(87, 25);
            passwordLbl.TabIndex = 3;
            passwordLbl.Text = "Password";
            // 
            // showPassChx
            // 
            showPassChx.AutoSize = true;
            showPassChx.Location = new Point(185, 265);
            showPassChx.Name = "showPassChx";
            showPassChx.Size = new Size(162, 29);
            showPassChx.TabIndex = 4;
            showPassChx.Text = "Show Password";
            showPassChx.UseVisualStyleBackColor = true;
            showPassChx.CheckedChanged += showPassChx_CheckedChanged;
            // 
            // loginBtn
            // 
            loginBtn.Location = new Point(185, 334);
            loginBtn.Name = "loginBtn";
            loginBtn.Size = new Size(112, 34);
            loginBtn.TabIndex = 5;
            loginBtn.Text = "Login";
            loginBtn.UseVisualStyleBackColor = true;
            loginBtn.Click += loginBtn_Click;
            // 
            // missingUsernameLbl
            // 
            missingUsernameLbl.AutoSize = true;
            missingUsernameLbl.ForeColor = Color.Red;
            missingUsernameLbl.Location = new Point(581, 109);
            missingUsernameLbl.Name = "missingUsernameLbl";
            missingUsernameLbl.Size = new Size(90, 25);
            missingUsernameLbl.TabIndex = 6;
            missingUsernameLbl.Text = "Required*";
            missingUsernameLbl.Visible = false;
            // 
            // missingPassLbl
            // 
            missingPassLbl.AutoSize = true;
            missingPassLbl.ForeColor = Color.Red;
            missingPassLbl.Location = new Point(581, 185);
            missingPassLbl.Name = "missingPassLbl";
            missingPassLbl.Size = new Size(90, 25);
            missingPassLbl.TabIndex = 7;
            missingPassLbl.Text = "Required*";
            missingPassLbl.Visible = false;
            // 
            // incorrectPassLbl
            // 
            incorrectPassLbl.AutoSize = true;
            incorrectPassLbl.ForeColor = Color.Red;
            incorrectPassLbl.Location = new Point(323, 339);
            incorrectPassLbl.Name = "incorrectPassLbl";
            incorrectPassLbl.Size = new Size(174, 25);
            incorrectPassLbl.TabIndex = 8;
            incorrectPassLbl.Text = "Incorrect  Password*";
            incorrectPassLbl.Visible = false;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(10F, 25F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(incorrectPassLbl);
            Controls.Add(missingPassLbl);
            Controls.Add(missingUsernameLbl);
            Controls.Add(loginBtn);
            Controls.Add(showPassChx);
            Controls.Add(passwordLbl);
            Controls.Add(userNameLbl);
            Controls.Add(passwordTxt);
            Controls.Add(userNameTxt);
            Name = "Form1";
            RightToLeft = RightToLeft.Yes;
            Text = "Login Form";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private TextBox userNameTxt;
        private TextBox passwordTxt;
        private Label userNameLbl;
        private Label passwordLbl;
        private CheckBox showPassChx;
        private Button loginBtn;
        private Label missingUsernameLbl;
        private Label missingPassLbl;
        private Label incorrectPassLbl;
    }
}
