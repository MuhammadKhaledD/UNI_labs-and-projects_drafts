namespace lab1
{
    partial class Form2
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
            taskTxt = new TextBox();
            statusCmbx = new ComboBox();
            addTaskBtn = new Button();
            clearInBtn = new Button();
            taskLbl = new Label();
            statusLbl = new Label();
            TodoGrid = new DataGridView();
            inprogGrid = new DataGridView();
            doneGrid = new DataGridView();
            todoLbl = new Label();
            inprogLbl = new Label();
            donLbl = new Label();
            missingTasklbl = new Label();
            missingStatusLbl = new Label();
            ((System.ComponentModel.ISupportInitialize)TodoGrid).BeginInit();
            ((System.ComponentModel.ISupportInitialize)inprogGrid).BeginInit();
            ((System.ComponentModel.ISupportInitialize)doneGrid).BeginInit();
            SuspendLayout();
            // 
            // taskTxt
            // 
            taskTxt.Location = new Point(249, 30);
            taskTxt.Name = "taskTxt";
            taskTxt.Size = new Size(306, 31);
            taskTxt.TabIndex = 0;
            taskTxt.TextAlign = HorizontalAlignment.Right;
            // 
            // statusCmbx
            // 
            statusCmbx.FormattingEnabled = true;
            statusCmbx.Location = new Point(249, 80);
            statusCmbx.Name = "statusCmbx";
            statusCmbx.Size = new Size(306, 33);
            statusCmbx.TabIndex = 0;
            // 
            // addTaskBtn
            // 
            addTaskBtn.Location = new Point(249, 129);
            addTaskBtn.Name = "addTaskBtn";
            addTaskBtn.Size = new Size(146, 34);
            addTaskBtn.TabIndex = 2;
            addTaskBtn.Text = "Add Task";
            addTaskBtn.UseVisualStyleBackColor = true;
            addTaskBtn.Click += addTaskBtn_Click;
            // 
            // clearInBtn
            // 
            clearInBtn.Location = new Point(401, 129);
            clearInBtn.Name = "clearInBtn";
            clearInBtn.Size = new Size(154, 34);
            clearInBtn.TabIndex = 3;
            clearInBtn.Text = "Clear Input";
            clearInBtn.UseVisualStyleBackColor = true;
            clearInBtn.Click += clearInBtn_Click;
            // 
            // taskLbl
            // 
            taskLbl.AutoSize = true;
            taskLbl.Location = new Point(137, 33);
            taskLbl.Name = "taskLbl";
            taskLbl.Size = new Size(49, 25);
            taskLbl.TabIndex = 4;
            taskLbl.Text = "Task:";
            // 
            // statusLbl
            // 
            statusLbl.AutoSize = true;
            statusLbl.Location = new Point(137, 83);
            statusLbl.Name = "statusLbl";
            statusLbl.Size = new Size(64, 25);
            statusLbl.TabIndex = 5;
            statusLbl.Text = "Status:";
            // 
            // TodoGrid
            // 
            TodoGrid.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            TodoGrid.Location = new Point(24, 223);
            TodoGrid.Name = "TodoGrid";
            TodoGrid.RowHeadersWidth = 62;
            TodoGrid.Size = new Size(284, 276);
            TodoGrid.TabIndex = 6;
            TodoGrid.CellClick += TodoGrid_CellClick;
            // 
            // inprogGrid
            // 
            inprogGrid.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            inprogGrid.Location = new Point(333, 223);
            inprogGrid.Name = "inprogGrid";
            inprogGrid.RowHeadersWidth = 62;
            inprogGrid.Size = new Size(290, 276);
            inprogGrid.TabIndex = 7;
            inprogGrid.CellClick += inprogGrid_CellClick;
            // 
            // doneGrid
            // 
            doneGrid.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            doneGrid.Location = new Point(653, 223);
            doneGrid.Name = "doneGrid";
            doneGrid.RowHeadersWidth = 62;
            doneGrid.Size = new Size(301, 276);
            doneGrid.TabIndex = 8;
            doneGrid.CellClick += doneGrid_CellClick;
            // 
            // todoLbl
            // 
            todoLbl.AutoSize = true;
            todoLbl.Font = new Font("Segoe UI", 15F);
            todoLbl.ForeColor = Color.Gray;
            todoLbl.Location = new Point(80, 179);
            todoLbl.Name = "todoLbl";
            todoLbl.Size = new Size(96, 41);
            todoLbl.TabIndex = 9;
            todoLbl.Text = "To Do";
            // 
            // inprogLbl
            // 
            inprogLbl.AutoSize = true;
            inprogLbl.Font = new Font("Segoe UI", 15F);
            inprogLbl.Location = new Point(371, 179);
            inprogLbl.Name = "inprogLbl";
            inprogLbl.Size = new Size(166, 41);
            inprogLbl.TabIndex = 10;
            inprogLbl.Text = "In Progress";
            // 
            // donLbl
            // 
            donLbl.AutoSize = true;
            donLbl.Font = new Font("Segoe UI", 15F);
            donLbl.ForeColor = Color.GreenYellow;
            donLbl.Location = new Point(744, 179);
            donLbl.Name = "donLbl";
            donLbl.Size = new Size(90, 41);
            donLbl.TabIndex = 11;
            donLbl.Text = "Done";
            // 
            // missingTasklbl
            // 
            missingTasklbl.AutoSize = true;
            missingTasklbl.ForeColor = Color.Red;
            missingTasklbl.Location = new Point(594, 33);
            missingTasklbl.Name = "missingTasklbl";
            missingTasklbl.Size = new Size(90, 25);
            missingTasklbl.TabIndex = 13;
            missingTasklbl.Text = "Required*";
            missingTasklbl.Visible = false;
            // 
            // missingStatusLbl
            // 
            missingStatusLbl.AutoSize = true;
            missingStatusLbl.ForeColor = Color.Red;
            missingStatusLbl.Location = new Point(594, 83);
            missingStatusLbl.Name = "missingStatusLbl";
            missingStatusLbl.Size = new Size(90, 25);
            missingStatusLbl.TabIndex = 14;
            missingStatusLbl.Text = "Required*";
            missingStatusLbl.Visible = false;
            // 
            // Form2
            // 
            AutoScaleDimensions = new SizeF(10F, 25F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(966, 598);
            Controls.Add(missingStatusLbl);
            Controls.Add(missingTasklbl);
            Controls.Add(donLbl);
            Controls.Add(inprogLbl);
            Controls.Add(todoLbl);
            Controls.Add(doneGrid);
            Controls.Add(inprogGrid);
            Controls.Add(TodoGrid);
            Controls.Add(statusLbl);
            Controls.Add(taskLbl);
            Controls.Add(clearInBtn);
            Controls.Add(statusCmbx);
            Controls.Add(addTaskBtn);
            Controls.Add(taskTxt);
            Name = "Form2";
            Text = "Form2";
            ((System.ComponentModel.ISupportInitialize)TodoGrid).EndInit();
            ((System.ComponentModel.ISupportInitialize)inprogGrid).EndInit();
            ((System.ComponentModel.ISupportInitialize)doneGrid).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private TextBox taskTxt;
        private FlowLayoutPanel flowLayoutPanel1;
        private ComboBox statusCmbx;
        private Button button1;
        private Button addTaskBtn;
        private Button clearInBtn;
        private Label taskLbl;
        private Label statusLbl;
        private DataGridView TodoGrid;
        private DataGridView inprogGrid;
        private DataGridView doneGrid;
        private Label todoLbl;
        private Label inprogLbl;
        private Label donLbl;
        private Label missingTasklbl;
        private Label missingStatusLbl;
    }
}