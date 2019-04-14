namespace ClockUI
{
    partial class ClockGUI
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
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(ClockGUI));
            this.label2 = new System.Windows.Forms.Label();
            this.currentTimeLabel = new System.Windows.Forms.Label();
            this.snoozeButton = new System.Windows.Forms.Button();
            this.addAlarmButton = new System.Windows.Forms.Button();
            this.setTimeButton = new System.Windows.Forms.Button();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.label8 = new System.Windows.Forms.Label();
            this.snoozePeriod = new System.Windows.Forms.NumericUpDown();
            this.secondTextBox = new System.Windows.Forms.TextBox();
            this.minuteTextBox = new System.Windows.Forms.TextBox();
            this.hourTextBox = new System.Windows.Forms.TextBox();
            this.messageTextBox = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.alarmsListBox = new System.Windows.Forms.ListBox();
            this.removeAlarmButton = new System.Windows.Forms.Button();
            this.toolTips = new System.Windows.Forms.ToolTip(this.components);
            this.timeSimulation = new System.Windows.Forms.NumericUpDown();
            this.alarmOffButton = new System.Windows.Forms.Button();
            this.resetTimeButton = new System.Windows.Forms.Button();
            this.applyTimeScale = new System.Windows.Forms.Button();
            this.currentAlarmsGroup = new System.Windows.Forms.GroupBox();
            this.panel1 = new System.Windows.Forms.Panel();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.snoozeTimer = new System.Windows.Forms.Timer(this.components);
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.snoozePeriod)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.timeSimulation)).BeginInit();
            this.currentAlarmsGroup.SuspendLayout();
            this.panel1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.SuspendLayout();
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Rockwell", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.ForeColor = System.Drawing.Color.White;
            this.label2.Location = new System.Drawing.Point(258, 88);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(208, 19);
            this.label2.TabIndex = 1;
            this.label2.Text = "(Hours : Minutes : Seconds)";
            // 
            // currentTimeLabel
            // 
            this.currentTimeLabel.AutoSize = true;
            this.currentTimeLabel.Font = new System.Drawing.Font("SansSerif", 60F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(2)));
            this.currentTimeLabel.ForeColor = System.Drawing.Color.White;
            this.currentTimeLabel.Location = new System.Drawing.Point(71, -3);
            this.currentTimeLabel.Name = "currentTimeLabel";
            this.currentTimeLabel.Size = new System.Drawing.Size(578, 94);
            this.currentTimeLabel.TabIndex = 2;
            this.currentTimeLabel.Text = "11 : 30 : 24 PM";
            this.toolTips.SetToolTip(this.currentTimeLabel, "Shows the current time, or if set, the Time spceficed below");
            // 
            // snoozeButton
            // 
            this.snoozeButton.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(197)))), ((int)(((byte)(202)))), ((int)(((byte)(233)))));
            this.snoozeButton.FlatAppearance.BorderSize = 2;
            this.snoozeButton.FlatAppearance.MouseOverBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(3)))), ((int)(((byte)(169)))), ((int)(((byte)(244)))));
            this.snoozeButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.snoozeButton.Font = new System.Drawing.Font("Rockwell", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.snoozeButton.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(33)))), ((int)(((byte)(33)))), ((int)(((byte)(33)))));
            this.snoozeButton.Location = new System.Drawing.Point(206, 381);
            this.snoozeButton.Name = "snoozeButton";
            this.snoozeButton.Size = new System.Drawing.Size(149, 48);
            this.snoozeButton.TabIndex = 4;
            this.snoozeButton.Text = "Snooze";
            this.toolTips.SetToolTip(this.snoozeButton, "Stop the flashing of the message and wait for the duration indicated by \"Snooze P" +
        "eriod\".\r\nWill only snooze the most recent activated alarm, and will stop ALL act" +
        "ive, flashing alarms.");
            this.snoozeButton.UseVisualStyleBackColor = false;
            this.snoozeButton.Click += new System.EventHandler(this.snoozeButton_Click);
            // 
            // addAlarmButton
            // 
            this.addAlarmButton.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(197)))), ((int)(((byte)(202)))), ((int)(((byte)(233)))));
            this.addAlarmButton.FlatAppearance.BorderSize = 2;
            this.addAlarmButton.FlatAppearance.MouseOverBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(3)))), ((int)(((byte)(169)))), ((int)(((byte)(244)))));
            this.addAlarmButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.addAlarmButton.Font = new System.Drawing.Font("Rockwell", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.addAlarmButton.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(33)))), ((int)(((byte)(33)))), ((int)(((byte)(33)))));
            this.addAlarmButton.Location = new System.Drawing.Point(8, 171);
            this.addAlarmButton.Name = "addAlarmButton";
            this.addAlarmButton.Size = new System.Drawing.Size(143, 48);
            this.addAlarmButton.TabIndex = 5;
            this.addAlarmButton.Text = "Add Alarm";
            this.toolTips.SetToolTip(this.addAlarmButton, "Add alarm to \"Current Alarms\" listbox.");
            this.addAlarmButton.UseVisualStyleBackColor = false;
            this.addAlarmButton.Click += new System.EventHandler(this.addAlarmButton_Click);
            // 
            // setTimeButton
            // 
            this.setTimeButton.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(197)))), ((int)(((byte)(202)))), ((int)(((byte)(233)))));
            this.setTimeButton.FlatAppearance.BorderSize = 2;
            this.setTimeButton.FlatAppearance.MouseOverBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(3)))), ((int)(((byte)(169)))), ((int)(((byte)(244)))));
            this.setTimeButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.setTimeButton.Font = new System.Drawing.Font("Rockwell", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.setTimeButton.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(33)))), ((int)(((byte)(33)))), ((int)(((byte)(33)))));
            this.setTimeButton.Location = new System.Drawing.Point(203, 171);
            this.setTimeButton.Name = "setTimeButton";
            this.setTimeButton.Size = new System.Drawing.Size(143, 48);
            this.setTimeButton.TabIndex = 6;
            this.setTimeButton.Text = "Set Time";
            this.toolTips.SetToolTip(this.setTimeButton, "Set the current time above to the time provided in the text boxes.");
            this.setTimeButton.UseVisualStyleBackColor = false;
            this.setTimeButton.Click += new System.EventHandler(this.setTimeButton_Click);
            // 
            // groupBox1
            // 
            this.groupBox1.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.groupBox1.Controls.Add(this.label8);
            this.groupBox1.Controls.Add(this.snoozePeriod);
            this.groupBox1.Controls.Add(this.secondTextBox);
            this.groupBox1.Controls.Add(this.minuteTextBox);
            this.groupBox1.Controls.Add(this.hourTextBox);
            this.groupBox1.Controls.Add(this.messageTextBox);
            this.groupBox1.Controls.Add(this.setTimeButton);
            this.groupBox1.Controls.Add(this.addAlarmButton);
            this.groupBox1.Controls.Add(this.label6);
            this.groupBox1.Controls.Add(this.label5);
            this.groupBox1.Controls.Add(this.label4);
            this.groupBox1.Controls.Add(this.label3);
            this.groupBox1.Font = new System.Drawing.Font("Rockwell", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.groupBox1.ForeColor = System.Drawing.Color.White;
            this.groupBox1.Location = new System.Drawing.Point(3, 121);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(352, 229);
            this.groupBox1.TabIndex = 7;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Enter New Alarm";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Font = new System.Drawing.Font("Rockwell", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label8.ForeColor = System.Drawing.Color.White;
            this.label8.Location = new System.Drawing.Point(165, 23);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(186, 19);
            this.label8.TabIndex = 12;
            this.label8.Text = "Snooze Period (Minutes)";
            // 
            // snoozePeriod
            // 
            this.snoozePeriod.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(197)))), ((int)(((byte)(202)))), ((int)(((byte)(233)))));
            this.snoozePeriod.DecimalPlaces = 1;
            this.snoozePeriod.Font = new System.Drawing.Font("Rockwell", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.snoozePeriod.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(33)))), ((int)(((byte)(33)))), ((int)(((byte)(33)))));
            this.snoozePeriod.Location = new System.Drawing.Point(192, 49);
            this.snoozePeriod.Maximum = new decimal(new int[] {
            30,
            0,
            0,
            0});
            this.snoozePeriod.Name = "snoozePeriod";
            this.snoozePeriod.Size = new System.Drawing.Size(120, 26);
            this.snoozePeriod.TabIndex = 10;
            this.toolTips.SetToolTip(this.snoozePeriod, "Set the snooze period (in minutes) for this alarm. If no snooze period, use a val" +
        "ue of 0.");
            // 
            // secondTextBox
            // 
            this.secondTextBox.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(197)))), ((int)(((byte)(202)))), ((int)(((byte)(233)))));
            this.secondTextBox.Font = new System.Drawing.Font("Rockwell", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.secondTextBox.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(33)))), ((int)(((byte)(33)))), ((int)(((byte)(33)))));
            this.secondTextBox.Location = new System.Drawing.Point(83, 94);
            this.secondTextBox.Name = "secondTextBox";
            this.secondTextBox.Size = new System.Drawing.Size(64, 26);
            this.secondTextBox.TabIndex = 11;
            this.toolTips.SetToolTip(this.secondTextBox, "Second value for alarm or new time; valid values range from 1 to 59.");
            // 
            // minuteTextBox
            // 
            this.minuteTextBox.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(197)))), ((int)(((byte)(202)))), ((int)(((byte)(233)))));
            this.minuteTextBox.Font = new System.Drawing.Font("Rockwell", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.minuteTextBox.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(33)))), ((int)(((byte)(33)))), ((int)(((byte)(33)))));
            this.minuteTextBox.Location = new System.Drawing.Point(83, 61);
            this.minuteTextBox.Name = "minuteTextBox";
            this.minuteTextBox.Size = new System.Drawing.Size(64, 26);
            this.minuteTextBox.TabIndex = 10;
            this.toolTips.SetToolTip(this.minuteTextBox, "Minute value for alarm or new time; valid values range from 1 to 59.");
            // 
            // hourTextBox
            // 
            this.hourTextBox.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(197)))), ((int)(((byte)(202)))), ((int)(((byte)(233)))));
            this.hourTextBox.Font = new System.Drawing.Font("Rockwell", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.hourTextBox.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(33)))), ((int)(((byte)(33)))), ((int)(((byte)(33)))));
            this.hourTextBox.Location = new System.Drawing.Point(83, 28);
            this.hourTextBox.Name = "hourTextBox";
            this.hourTextBox.Size = new System.Drawing.Size(64, 26);
            this.hourTextBox.TabIndex = 9;
            this.toolTips.SetToolTip(this.hourTextBox, "Hour value for alarm or new time; valid values range from 1 to 24.");
            // 
            // messageTextBox
            // 
            this.messageTextBox.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(197)))), ((int)(((byte)(202)))), ((int)(((byte)(233)))));
            this.messageTextBox.Font = new System.Drawing.Font("Rockwell", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.messageTextBox.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(33)))), ((int)(((byte)(33)))), ((int)(((byte)(33)))));
            this.messageTextBox.Location = new System.Drawing.Point(83, 138);
            this.messageTextBox.Name = "messageTextBox";
            this.messageTextBox.Size = new System.Drawing.Size(263, 26);
            this.messageTextBox.TabIndex = 8;
            this.toolTips.SetToolTip(this.messageTextBox, "Message to be displayed when alarm goes off. Will flash on screen.");
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Rockwell", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label6.ForeColor = System.Drawing.Color.White;
            this.label6.Location = new System.Drawing.Point(6, 139);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(74, 19);
            this.label6.TabIndex = 3;
            this.label6.Text = "Message";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Rockwell", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.ForeColor = System.Drawing.Color.White;
            this.label5.Location = new System.Drawing.Point(10, 101);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(63, 19);
            this.label5.TabIndex = 2;
            this.label5.Text = "Second";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Rockwell", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.ForeColor = System.Drawing.Color.White;
            this.label4.Location = new System.Drawing.Point(10, 68);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(59, 19);
            this.label4.TabIndex = 1;
            this.label4.Text = "Minute";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Rockwell", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.ForeColor = System.Drawing.Color.White;
            this.label3.Location = new System.Drawing.Point(10, 35);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(45, 19);
            this.label3.TabIndex = 0;
            this.label3.Text = "Hour";
            // 
            // alarmsListBox
            // 
            this.alarmsListBox.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(197)))), ((int)(((byte)(202)))), ((int)(((byte)(233)))));
            this.alarmsListBox.Font = new System.Drawing.Font("Rockwell", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.alarmsListBox.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(33)))), ((int)(((byte)(33)))), ((int)(((byte)(33)))));
            this.alarmsListBox.FormattingEnabled = true;
            this.alarmsListBox.ItemHeight = 19;
            this.alarmsListBox.Location = new System.Drawing.Point(16, 26);
            this.alarmsListBox.Name = "alarmsListBox";
            this.alarmsListBox.Size = new System.Drawing.Size(163, 137);
            this.alarmsListBox.Sorted = true;
            this.alarmsListBox.TabIndex = 8;
            this.toolTips.SetToolTip(this.alarmsListBox, "Shows all active alarms that have been added.");
            // 
            // removeAlarmButton
            // 
            this.removeAlarmButton.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(197)))), ((int)(((byte)(202)))), ((int)(((byte)(233)))));
            this.removeAlarmButton.FlatAppearance.BorderSize = 2;
            this.removeAlarmButton.FlatAppearance.MouseOverBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(3)))), ((int)(((byte)(169)))), ((int)(((byte)(244)))));
            this.removeAlarmButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.removeAlarmButton.Font = new System.Drawing.Font("Rockwell", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.removeAlarmButton.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(33)))), ((int)(((byte)(33)))), ((int)(((byte)(33)))));
            this.removeAlarmButton.Location = new System.Drawing.Point(185, 72);
            this.removeAlarmButton.Name = "removeAlarmButton";
            this.removeAlarmButton.Size = new System.Drawing.Size(137, 52);
            this.removeAlarmButton.TabIndex = 10;
            this.removeAlarmButton.Text = "Remove Selected Alarm";
            this.toolTips.SetToolTip(this.removeAlarmButton, "Remove the selected alarm from the ListBox to the left.");
            this.removeAlarmButton.UseVisualStyleBackColor = false;
            this.removeAlarmButton.Click += new System.EventHandler(this.removeAlarmButton_Click);
            // 
            // toolTips
            // 
            this.toolTips.AutomaticDelay = 700;
            this.toolTips.AutoPopDelay = 7000;
            this.toolTips.InitialDelay = 500;
            this.toolTips.ReshowDelay = 100;
            // 
            // timeSimulation
            // 
            this.timeSimulation.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(197)))), ((int)(((byte)(202)))), ((int)(((byte)(233)))));
            this.timeSimulation.Font = new System.Drawing.Font("Rockwell", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.timeSimulation.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(33)))), ((int)(((byte)(33)))), ((int)(((byte)(33)))));
            this.timeSimulation.Location = new System.Drawing.Point(6, 34);
            this.timeSimulation.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.timeSimulation.Name = "timeSimulation";
            this.timeSimulation.Size = new System.Drawing.Size(120, 26);
            this.timeSimulation.TabIndex = 0;
            this.toolTips.SetToolTip(this.timeSimulation, "Accelerate the rate at which time passes. 1 is normal time. (For testing purposes" +
        " only!)");
            this.timeSimulation.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            // 
            // alarmOffButton
            // 
            this.alarmOffButton.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(197)))), ((int)(((byte)(202)))), ((int)(((byte)(233)))));
            this.alarmOffButton.FlatAppearance.BorderSize = 2;
            this.alarmOffButton.FlatAppearance.MouseOverBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(3)))), ((int)(((byte)(169)))), ((int)(((byte)(244)))));
            this.alarmOffButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.alarmOffButton.Font = new System.Drawing.Font("Rockwell", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.alarmOffButton.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(33)))), ((int)(((byte)(33)))), ((int)(((byte)(33)))));
            this.alarmOffButton.Location = new System.Drawing.Point(3, 381);
            this.alarmOffButton.Name = "alarmOffButton";
            this.alarmOffButton.Size = new System.Drawing.Size(149, 48);
            this.alarmOffButton.TabIndex = 3;
            this.alarmOffButton.Text = "Alarm Off";
            this.toolTips.SetToolTip(this.alarmOffButton, "Stop the flashing of alarm message and wait for the next alarm to be triggered.\r\n" +
        "Will stop ALL active, flashing alarms.");
            this.alarmOffButton.UseVisualStyleBackColor = false;
            this.alarmOffButton.Click += new System.EventHandler(this.alarmOffButton_Click);
            // 
            // resetTimeButton
            // 
            this.resetTimeButton.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(197)))), ((int)(((byte)(202)))), ((int)(((byte)(233)))));
            this.resetTimeButton.FlatAppearance.BorderSize = 2;
            this.resetTimeButton.FlatAppearance.MouseOverBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(3)))), ((int)(((byte)(169)))), ((int)(((byte)(244)))));
            this.resetTimeButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.resetTimeButton.Font = new System.Drawing.Font("Rockwell", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.resetTimeButton.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(33)))), ((int)(((byte)(33)))), ((int)(((byte)(33)))));
            this.resetTimeButton.Location = new System.Drawing.Point(361, 383);
            this.resetTimeButton.Name = "resetTimeButton";
            this.resetTimeButton.Size = new System.Drawing.Size(328, 46);
            this.resetTimeButton.TabIndex = 13;
            this.resetTimeButton.Text = "RESET TIME";
            this.toolTips.SetToolTip(this.resetTimeButton, "Reset the time above to the current local time.");
            this.resetTimeButton.UseVisualStyleBackColor = false;
            this.resetTimeButton.Click += new System.EventHandler(this.resetTimeButton_Click);
            // 
            // applyTimeScale
            // 
            this.applyTimeScale.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(197)))), ((int)(((byte)(202)))), ((int)(((byte)(233)))));
            this.applyTimeScale.FlatAppearance.BorderSize = 2;
            this.applyTimeScale.FlatAppearance.MouseOverBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(3)))), ((int)(((byte)(169)))), ((int)(((byte)(244)))));
            this.applyTimeScale.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.applyTimeScale.Font = new System.Drawing.Font("Rockwell", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.applyTimeScale.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(33)))), ((int)(((byte)(33)))), ((int)(((byte)(33)))));
            this.applyTimeScale.Location = new System.Drawing.Point(138, 26);
            this.applyTimeScale.Name = "applyTimeScale";
            this.applyTimeScale.Size = new System.Drawing.Size(79, 43);
            this.applyTimeScale.TabIndex = 13;
            this.applyTimeScale.Text = "Enter";
            this.toolTips.SetToolTip(this.applyTimeScale, "Apply current time scale to time above.");
            this.applyTimeScale.UseVisualStyleBackColor = false;
            this.applyTimeScale.Click += new System.EventHandler(this.applyTimeScale_Click);
            // 
            // currentAlarmsGroup
            // 
            this.currentAlarmsGroup.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.currentAlarmsGroup.Controls.Add(this.alarmsListBox);
            this.currentAlarmsGroup.Controls.Add(this.removeAlarmButton);
            this.currentAlarmsGroup.Font = new System.Drawing.Font("Rockwell", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.currentAlarmsGroup.ForeColor = System.Drawing.Color.White;
            this.currentAlarmsGroup.Location = new System.Drawing.Point(361, 121);
            this.currentAlarmsGroup.Name = "currentAlarmsGroup";
            this.currentAlarmsGroup.Size = new System.Drawing.Size(328, 175);
            this.currentAlarmsGroup.TabIndex = 11;
            this.currentAlarmsGroup.TabStop = false;
            this.currentAlarmsGroup.Text = "Current Alarms";
            // 
            // panel1
            // 
            this.panel1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(48)))), ((int)(((byte)(63)))), ((int)(((byte)(159)))));
            this.panel1.Controls.Add(this.resetTimeButton);
            this.panel1.Controls.Add(this.groupBox2);
            this.panel1.Controls.Add(this.snoozeButton);
            this.panel1.Controls.Add(this.groupBox1);
            this.panel1.Controls.Add(this.alarmOffButton);
            this.panel1.Controls.Add(this.currentAlarmsGroup);
            this.panel1.Controls.Add(this.currentTimeLabel);
            this.panel1.Controls.Add(this.label2);
            this.panel1.Location = new System.Drawing.Point(12, 12);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(697, 443);
            this.panel1.TabIndex = 12;
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.applyTimeScale);
            this.groupBox2.Controls.Add(this.timeSimulation);
            this.groupBox2.Font = new System.Drawing.Font("Rockwell", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.groupBox2.ForeColor = System.Drawing.Color.White;
            this.groupBox2.Location = new System.Drawing.Point(414, 302);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(223, 75);
            this.groupBox2.TabIndex = 12;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Time Simulation for Testing";
            // 
            // timer1
            // 
            this.timer1.Interval = 1000;
            // 
            // snoozeTimer
            // 
            this.snoozeTimer.Interval = 1;
            // 
            // ClockGUI
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(96F, 96F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Dpi;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(48)))), ((int)(((byte)(63)))), ((int)(((byte)(159)))));
            this.ClientSize = new System.Drawing.Size(717, 467);
            this.Controls.Add(this.panel1);
            this.Font = new System.Drawing.Font("Rockwell", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.Name = "ClockGUI";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Clock Simulation";
            this.Load += new System.EventHandler(this.ClockGUI_Load);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.snoozePeriod)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.timeSimulation)).EndInit();
            this.currentAlarmsGroup.ResumeLayout(false);
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label currentTimeLabel;
        private System.Windows.Forms.Button snoozeButton;
        private System.Windows.Forms.Button addAlarmButton;
        private System.Windows.Forms.Button setTimeButton;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.TextBox messageTextBox;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox secondTextBox;
        private System.Windows.Forms.TextBox minuteTextBox;
        private System.Windows.Forms.TextBox hourTextBox;
        private System.Windows.Forms.ListBox alarmsListBox;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.NumericUpDown snoozePeriod;
        private System.Windows.Forms.Button removeAlarmButton;
        private System.Windows.Forms.ToolTip toolTips;
        private System.Windows.Forms.GroupBox currentAlarmsGroup;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.NumericUpDown timeSimulation;
        private System.Windows.Forms.Button alarmOffButton;
        private System.Windows.Forms.Button resetTimeButton;
        private System.Windows.Forms.Button applyTimeScale;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.Timer snoozeTimer;
    }
}

