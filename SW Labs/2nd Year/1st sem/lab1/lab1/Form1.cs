namespace lab1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void showPassChx_CheckedChanged(object sender, EventArgs e)
        {
            passwordTxt.PasswordChar = '\0';
        }

        private void loginBtn_Click(object sender, EventArgs e)
        {
            missingUsernameLbl.Visible = false;
            missingPassLbl.Visible = false;
            incorrectPassLbl.Visible = false;

            if (userNameTxt.Text == "")
            {
                missingUsernameLbl.Visible = true;

                if(passwordTxt.Text == "")
                {
                    missingPassLbl.Visible = true;
                }
            }
            else if (passwordTxt.Text != "123")
            {
                incorrectPassLbl.Visible = true;
            }
            else
            {
                Form f2 = new Form2(userNameTxt.Text);
                f2.Show();
            }
        }
    }
}