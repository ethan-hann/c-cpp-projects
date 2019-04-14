using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClockLibrary
{
    public class AlarmTime : Time2
    {
        //Initialize AlarmTime object with explicit values
        public AlarmTime(int hour = 0, int minute = 0, int second = 0)
        {
            SetTime(hour, minute, second); //invoke SetTime to validate time
        }

        //Initialize AlarmTime object with explicit values
        public AlarmTime(int hour = 0, int minute = 0, int second = 0, String message = "", decimal snoozePeriod = 0)
        {
            SetTime(hour, minute, second); //invoke SetTime to validate time
            Message = message;
            SnoozePeriod = snoozePeriod;
        }

        //Initialize an AlarmTime object with another object
        public AlarmTime(AlarmTime time) : this(time.Hour, time.Minute, time.Second) { }

        public String Message { get; set; } //String holder for a message

        public decimal SnoozePeriod { get; set; }

        // convert to string in standard-time format (H:MM:SS AM or PM)
        public override string ToString() =>
            $"{((Hour == 0 || Hour == 12) ? 12 : Hour % 12)} : " +
            $"{Minute:D2} : {Second:D2} {(Hour < 12 ? "AM" : "PM")}";
    }
}
