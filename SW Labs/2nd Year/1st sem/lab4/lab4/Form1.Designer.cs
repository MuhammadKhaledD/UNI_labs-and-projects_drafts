namespace lab4
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
            fname = new TextBox();
            lname = new TextBox();
            ssn = new TextBox();
            address = new TextBox();
            dno = new TextBox();
            insert_new_employee = new Button();
            update = new Button();
            delete = new Button();
            display_sum = new Button();
            display_all = new Button();
            emp_ssn = new TextBox();
            adjssn = new Label();
            newaddress = new Label();
            newdno = new Label();
            newlname = new Label();
            newfname = new Label();
            newssn = new Label();
            adjprojnum = new TextBox();
            adjprojnumber = new Label();
            deletemp = new TextBox();
            label1 = new Label();
            sumbox = new TextBox();
            empgrid = new DataGridView();
            label2 = new Label();
            projNumber = new ComboBox();
            hoursbox = new TextBox();
            hours = new Label();
            ((System.ComponentModel.ISupportInitialize)empgrid).BeginInit();
            SuspendLayout();
            // 
            // fname
            // 
            fname.Location = new Point(141, 51);
            fname.Name = "fname";
            fname.Size = new Size(150, 31);
            fname.TabIndex = 0;
            // 
            // lname
            // 
            lname.Location = new Point(466, 51);
            lname.Name = "lname";
            lname.Size = new Size(150, 31);
            lname.TabIndex = 1;
            // 
            // ssn
            // 
            ssn.Location = new Point(732, 51);
            ssn.Name = "ssn";
            ssn.Size = new Size(150, 31);
            ssn.TabIndex = 2;
            // 
            // address
            // 
            address.Location = new Point(141, 146);
            address.Name = "address";
            address.Size = new Size(150, 31);
            address.TabIndex = 3;
            // 
            // dno
            // 
            dno.Location = new Point(466, 146);
            dno.Name = "dno";
            dno.Size = new Size(150, 31);
            dno.TabIndex = 4;
            // 
            // insert_new_employee
            // 
            insert_new_employee.Location = new Point(668, 146);
            insert_new_employee.Name = "insert_new_employee";
            insert_new_employee.Size = new Size(112, 34);
            insert_new_employee.TabIndex = 5;
            insert_new_employee.Text = "Insert";
            insert_new_employee.UseVisualStyleBackColor = true;
            insert_new_employee.Click += insert_new_employee_Click;
            // 
            // update
            // 
            update.Location = new Point(800, 241);
            update.Name = "update";
            update.Size = new Size(112, 34);
            update.TabIndex = 6;
            update.Text = "Update";
            update.UseVisualStyleBackColor = true;
            update.Click += update_Click;
            // 
            // delete
            // 
            delete.Location = new Point(342, 324);
            delete.Name = "delete";
            delete.Size = new Size(112, 34);
            delete.TabIndex = 7;
            delete.Text = "Delete";
            delete.UseVisualStyleBackColor = true;
            delete.Click += delete_Click;
            // 
            // display_sum
            // 
            display_sum.Location = new Point(536, 426);
            display_sum.Name = "display_sum";
            display_sum.Size = new Size(150, 34);
            display_sum.TabIndex = 8;
            display_sum.Text = "Display sum";
            display_sum.UseVisualStyleBackColor = true;
            display_sum.Click += display_sum_Click;
            // 
            // display_all
            // 
            display_all.Location = new Point(770, 426);
            display_all.Name = "display_all";
            display_all.Size = new Size(112, 34);
            display_all.TabIndex = 9;
            display_all.Text = "Display all";
            display_all.UseVisualStyleBackColor = true;
            display_all.Click += display_all_Click;
            // 
            // emp_ssn
            // 
            emp_ssn.Location = new Point(141, 243);
            emp_ssn.Name = "emp_ssn";
            emp_ssn.Size = new Size(150, 31);
            emp_ssn.TabIndex = 10;
            // 
            // adjssn
            // 
            adjssn.AutoSize = true;
            adjssn.Location = new Point(21, 248);
            adjssn.Name = "adjssn";
            adjssn.Size = new Size(45, 25);
            adjssn.TabIndex = 11;
            adjssn.Text = "SSN";
            // 
            // newaddress
            // 
            newaddress.AutoSize = true;
            newaddress.Location = new Point(21, 152);
            newaddress.Name = "newaddress";
            newaddress.Size = new Size(74, 25);
            newaddress.TabIndex = 12;
            newaddress.Text = "address";
            // 
            // newdno
            // 
            newdno.AutoSize = true;
            newdno.Location = new Point(342, 149);
            newdno.Name = "newdno";
            newdno.Size = new Size(52, 25);
            newdno.TabIndex = 13;
            newdno.Text = "DNO";
            // 
            // newlname
            // 
            newlname.AutoSize = true;
            newlname.Location = new Point(342, 57);
            newlname.Name = "newlname";
            newlname.Size = new Size(88, 25);
            newlname.TabIndex = 14;
            newlname.Text = "last name";
            // 
            // newfname
            // 
            newfname.AutoSize = true;
            newfname.Location = new Point(21, 57);
            newfname.Name = "newfname";
            newfname.Size = new Size(85, 25);
            newfname.TabIndex = 15;
            newfname.Text = "1st name";
            // 
            // newssn
            // 
            newssn.AutoSize = true;
            newssn.Location = new Point(668, 51);
            newssn.Name = "newssn";
            newssn.Size = new Size(45, 25);
            newssn.TabIndex = 16;
            newssn.Text = "SSN";
            // 
            // adjprojnum
            // 
            adjprojnum.Location = new Point(466, 242);
            adjprojnum.Name = "adjprojnum";
            adjprojnum.Size = new Size(150, 31);
            adjprojnum.TabIndex = 17;
            // 
            // adjprojnumber
            // 
            adjprojnumber.AutoSize = true;
            adjprojnumber.Location = new Point(342, 248);
            adjprojnumber.Name = "adjprojnumber";
            adjprojnumber.Size = new Size(106, 25);
            adjprojnumber.TabIndex = 18;
            adjprojnumber.Text = "projnumber";
            // 
            // deletemp
            // 
            deletemp.Location = new Point(141, 326);
            deletemp.Name = "deletemp";
            deletemp.Size = new Size(150, 31);
            deletemp.TabIndex = 19;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(21, 332);
            label1.Name = "label1";
            label1.Size = new Size(45, 25);
            label1.TabIndex = 20;
            label1.Text = "SSN";
            // 
            // sumbox
            // 
            sumbox.Location = new Point(319, 428);
            sumbox.Name = "sumbox";
            sumbox.Size = new Size(150, 31);
            sumbox.TabIndex = 21;
            // 
            // empgrid
            // 
            empgrid.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            empgrid.Location = new Point(21, 483);
            empgrid.Name = "empgrid";
            empgrid.RowHeadersWidth = 62;
            empgrid.Size = new Size(861, 365);
            empgrid.TabIndex = 22;
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(21, 431);
            label2.Name = "label2";
            label2.Size = new Size(85, 25);
            label2.TabIndex = 24;
            label2.Text = "proj num";
            // 
            // projNumber
            // 
            projNumber.FormattingEnabled = true;
            projNumber.Location = new Point(141, 428);
            projNumber.Name = "projNumber";
            projNumber.Size = new Size(150, 33);
            projNumber.TabIndex = 25;
            // 
            // hoursbox
            // 
            hoursbox.Location = new Point(708, 243);
            hoursbox.Name = "hoursbox";
            hoursbox.Size = new Size(56, 31);
            hoursbox.TabIndex = 26;
            // 
            // hours
            // 
            hours.AutoSize = true;
            hours.Location = new Point(627, 248);
            hours.Name = "hours";
            hours.Size = new Size(57, 25);
            hours.TabIndex = 27;
            hours.Text = "hours";
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(10F, 25F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(924, 860);
            Controls.Add(hours);
            Controls.Add(hoursbox);
            Controls.Add(projNumber);
            Controls.Add(label2);
            Controls.Add(empgrid);
            Controls.Add(sumbox);
            Controls.Add(label1);
            Controls.Add(deletemp);
            Controls.Add(adjprojnumber);
            Controls.Add(adjprojnum);
            Controls.Add(newssn);
            Controls.Add(newfname);
            Controls.Add(newlname);
            Controls.Add(newdno);
            Controls.Add(newaddress);
            Controls.Add(adjssn);
            Controls.Add(emp_ssn);
            Controls.Add(display_all);
            Controls.Add(display_sum);
            Controls.Add(delete);
            Controls.Add(update);
            Controls.Add(insert_new_employee);
            Controls.Add(dno);
            Controls.Add(address);
            Controls.Add(ssn);
            Controls.Add(lname);
            Controls.Add(fname);
            Name = "Form1";
            Text = "Form1";
            Load += Form1_Load;
            ((System.ComponentModel.ISupportInitialize)empgrid).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private TextBox fname;
        private TextBox lname;
        private TextBox ssn;
        private TextBox address;
        private TextBox dno;
        private Button insert_new_employee;
        private Button update;
        private Button delete;
        private Button display_sum;
        private Button display_all;
        private TextBox emp_ssn;
        private Label adjssn;
        private Label newaddress;
        private Label newdno;
        private Label newlname;
        private Label newfname;
        private Label newssn;
        private TextBox adjprojnum;
        private Label adjprojnumber;
        private TextBox deletemp;
        private Label label1;
        private TextBox sumbox;
        private DataGridView empgrid;
        private Label label2;
        private ComboBox projNumber;
        private TextBox hoursbox;
        private Label hours;
    }
}
