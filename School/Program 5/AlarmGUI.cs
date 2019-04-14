using System;
using System.Windows.Forms;
using ClockLibrary;
using System.IO;
using System.Speech.Synthesis;
using System.Media;

namespace ClockUI
{
    public partial class AlarmGUI : Form
    {
        private AlarmTime alarm;
        private bool hidden; //boolean to help control showing and hiding the form; simulates a flashing effect
        private SoundPlayer snd; //so a subtle alarm tone can be played
        private SpeechSynthesizer synth; //so the alarm message can be read outloud

        public AlarmGUI(AlarmTime a)
        {
            InitializeComponent();
            alarm = a;
        }

        //Initilizing most objects on form load
        private void AlarmGUI_Load(object sender, EventArgs e)
        {
            alarmTime.Text = alarm.ToString();
            messageLabel.Text = alarm.Message;

            flashTimer.Start();
            flashTimer.Tick += new EventHandler(flashTimer_Tick);

            Stream str = Properties.Resources.alarmTone;
            snd = new SoundPlayer(str);

            synth = new SpeechSynthesizer();
            synth.SetOutputToDefaultAudioDevice();

            //Play the alarm sound and speak the message; happens as soon as the form has loaded.
            synth.SpeakAsync(alarm.Message);
            snd.Play();
        }

        //Flashes the form in and out so it grabs the attention of the user and plays alarm tone
        private void flashTimer_Tick(object sender, EventArgs e)
        {
            if (sender == flashTimer)
            {
                if (hidden)
                {
                    this.Show();
                    synth.SpeakAsync(alarm.Message); //Synthesizer continues speaking message until form is closed.
                    snd.Play();
                    hidden = false;
                }
                else
                {
                    this.Hide();
                    hidden = true;
                }
            }
        }
    }
}
