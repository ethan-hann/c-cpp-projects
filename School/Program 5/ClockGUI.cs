/**
 * Programming Assingment 2 - CSCI 4315.01
 * Advanced Software Development with .NET and C#
 * DUE: 12/7/2018
 * AUTHOR: Ethan D. Hann
 * GUI Design and Programming: Ethan D. Hann
 * Icons and sounds are free and open-source.
 * */

using System;
using System.Collections.Generic;
using System.Windows.Forms;
using ClockLibrary;

namespace ClockUI
{
    public partial class ClockGUI : Form
    {
        private DateTime currentTime;
        private Time2 currentTimeConverted;
        private Time2 currentTimeCustom;
        private AlarmTime currentAlarm;
        private AlarmTime snoozedAlarm;

        private bool usingCustomTime = false;

        private int hours = 0;
        private int minutes = 0;
        private int seconds = 0;

        private int alarmHours = 0;
        private int alarmMinutes = 0;
        private int alarmSeconds = 0;

        public ClockGUI()
        {
            InitializeComponent();
        }

        private void ClockGUI_Load(object sender, EventArgs e)
        {
            currentTimeLabel.Text = ConvertDateTime(DateTime.Now).ToString(); //set starting time to current time
            timer1.Start();
            timer1.Tick += new EventHandler(timer1_Tick);
        }

        //Update the current time label using Time2 object
        private void timer1_Tick(object sender, EventArgs e)
        {
            if (sender == timer1)
            {
                if (!usingCustomTime)
                {
                    //capture current time in DateTime object
                    currentTime = DateTime.Now;

                    currentTimeConverted = ConvertDateTime(currentTime);

                    //Update time label on form
                    currentTimeLabel.Text = currentTimeConverted.ToString();
                }
                else
                {
                    currentTimeCustom.Second++;
                    currentTimeLabel.Text = currentTimeCustom.ToString();
                }

                //Loop through alarms and see if one needs to be triggered.
                foreach (AlarmTime a in alarmsListBox.Items)
                {
                    if (!usingCustomTime)
                    {
                        if ((currentTimeConverted.ToString()).Equals(a.ToString()))
                        {
                            currentAlarm = a;
                            alarmTriggered(currentAlarm);
                        }
                    }
                    else
                    {
                        if ((currentTimeCustom.ToString()).Equals(a.ToString()))
                        {
                            currentAlarm = a;
                            alarmTriggered(currentAlarm);
                        }
                    }
                }
            }
        }

        private void setTimeButton_Click(object sender, EventArgs e)
        {
            usingCustomTime = true;

            Int32.TryParse(hourTextBox.Text, out hours);
            Int32.TryParse(minuteTextBox.Text, out minutes);
            Int32.TryParse(secondTextBox.Text, out seconds);

            currentTimeCustom = new Time2(hours, minutes, seconds);
        }

        //Reset the time to the actual current time
        private void resetTimeButton_Click(object sender, EventArgs e)
        {
            usingCustomTime = false;
        }

        //Convert DateTime object to custom Time2 object
        private Time2 ConvertDateTime(DateTime time)
        {
            return new Time2(currentTime.Hour, currentTime.Minute, currentTime.Second);
        }

        //Adds an alarm to the alarm list; checks if alarm already exists before adding it
        private void addAlarmButton_Click(object sender, EventArgs e)
        {
            Int32.TryParse(hourTextBox.Text, out alarmHours);
            Int32.TryParse(minuteTextBox.Text, out alarmMinutes);
            Int32.TryParse(secondTextBox.Text, out alarmSeconds);

            AlarmTime alarm = new AlarmTime(alarmHours, alarmMinutes, alarmSeconds,
                messageTextBox.Text, snoozePeriod.Value);

            //used to keep track of an existing AlarmTime item in the listbox
            // 0 if item doesn't exist; 1 if it does exist.
            int existsFlag = 0; 
            foreach (AlarmTime a in alarmsListBox.Items)
            {
                if ((a.ToString()).Equals(alarm.ToString()))
                {
                    MessageBox.Show("This alarm already exists in the Alarm List.",
                        "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    existsFlag = 1;
                    break;
                }
            }

            //Alarm doesn't already exist, so we can add it to the listbox
            if (existsFlag == 0)
            {
                alarmsListBox.Items.Add(alarm);
            }
        }

        //Remove selected alarm from the alarm list
        private void removeAlarmButton_Click(object sender, EventArgs e)
        {
            alarmsListBox.Items.Remove(alarmsListBox.SelectedItem);
        }

        //Change time scale for simulation
        //If interval was 1000 ms (1 second) and new time scale is 2, new interval is 500 ms (0.5 seconds)
        //This means for every second of real-time, 0.5 seconds pass on the Form
        //At a time scale of 100, Hours become minutes, Minutes become seconds, and Seconds become milliseconds
        //100 is the maximum time scale that is allowed
        private void applyTimeScale_Click(object sender, EventArgs e)
        {
            timer1.Stop();
            timer1.Interval = (int) (1000 / timeSimulation.Value);
            timer1.Start();
        }

        //Called when a match is found between one of the alarms in the alarm list and the current time
        private void alarmTriggered(AlarmTime alarm)
        {
            new AlarmGUI(alarm).Show();
            
            //Converts snoozePeriod to milliseconds and sets timer interval if alarm has a snooze period
            if (snoozePeriod.Value > 0)
            {
                snoozeTimer.Interval = (int)(alarm.SnoozePeriod * 60000);
                snoozedAlarm = alarm;
            }
        }

        //Closes all forms except for the main ClockGUI Form
        private void closeAlarmForms()
        {
            List<Form> openForms = new List<Form>();

            foreach (Form f in Application.OpenForms)
            {
                openForms.Add(f);
            }

            foreach (Form f in openForms)
            {
                if (f.Name != "ClockGUI") f.Close();
            }
        }

        //Close all alarm instances on button click
        private void alarmOffButton_Click(object sender, EventArgs e)
        {
            closeAlarmForms();
        }

        //If the current alarm (i.e. the last alarm triggered) has a snooze period, start its timer
        //Otherwise, nothing happens
        private void snoozeButton_Click(object sender, EventArgs e)
        {
            if (currentAlarm.SnoozePeriod > 0)
            {
                snoozeTimer.Enabled = true;
                snoozeTimer.Start();
                snoozeTimer.Tick += new EventHandler(snoozeTimer_Tick);
                closeAlarmForms();
            }
        }

        //Ticker for the snooze timer; shows the Alarm again after the specified snooze interval
        private void snoozeTimer_Tick(object sender, EventArgs e)
        {
            if (sender == snoozeTimer)
            {
                new AlarmGUI(snoozedAlarm).Show();
            }

            //disable the snooze timer; this prevents multiple windows being open if
            //the user doesn't close the alarm before the next snooze period has passed.
            snoozeTimer.Enabled = false;
        }
    }
}
