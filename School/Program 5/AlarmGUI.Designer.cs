namespace ClockUI
{
    partial class AlarmGUI
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(AlarmGUI));
            this.panel1 = new System.Windows.Forms.Panel();
            this.messageLabel = new System.Windows.Forms.Label();
            this.alarmTime = new System.Windows.Forms.Label();
            this.flashTimer = new System.Windows.Forms.Timer(this.components);
            this.panel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.messageLabel);
            this.panel1.Controls.Add(this.alarmTime);
            this.panel1.Location = new System.Drawing.Point(16, 18);
            this.panel1.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(518, 270);
            this.panel1.TabIndex = 0;
            // 
            // messageLabel
            // 
            this.messageLabel.AutoSize = true;
            this.messageLabel.Font = new System.Drawing.Font("Rockwell", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.messageLabel.Location = new System.Drawing.Point(26, 102);
            this.messageLabel.Name = "messageLabel";
            this.messageLabel.Size = new System.Drawing.Size(214, 31);
            this.messageLabel.TabIndex = 1;
            this.messageLabel.Text = "Time To Get Up!";
            // 
            // alarmTime
            // 
            this.alarmTime.AutoSize = true;
            this.alarmTime.Font = new System.Drawing.Font("SansSerif", 48F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(2)));
            this.alarmTime.Location = new System.Drawing.Point(26, 19);
            this.alarmTime.Name = "alarmTime";
            this.alarmTime.Size = new System.Drawing.Size(470, 74);
            this.alarmTime.TabIndex = 0;
            this.alarmTime.Text = "11 : 20 : 34 PM";
            // 
            // flashTimer
            // 
            this.flashTimer.Enabled = true;
            this.flashTimer.Interval = 1300;
            // 
            // AlarmGUI
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(48)))), ((int)(((byte)(63)))), ((int)(((byte)(159)))));
            this.ClientSize = new System.Drawing.Size(547, 302);
            this.ControlBox = false;
            this.Controls.Add(this.panel1);
            this.Font = new System.Drawing.Font("Roboto", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ForeColor = System.Drawing.Color.White;
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "AlarmGUI";
            this.ShowInTaskbar = false;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "ALARM";
            this.TopMost = true;
            this.Load += new System.EventHandler(this.AlarmGUI_Load);
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Label messageLabel;
        private System.Windows.Forms.Label alarmTime;
        private System.Windows.Forms.Timer flashTimer;
    }
}