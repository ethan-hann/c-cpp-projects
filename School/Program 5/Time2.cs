/**
 * Class Time2 from Figure 10.5
 */

using System;

namespace ClockLibrary
{
    public class Time2 : IComparable<Time2>
    {
        private int hour; //0 - 23
        private int minute; // 0 - 59
        private int second; // 0 - 59

        public Time2(int hour = 0, int minute = 0, int second = 0)
        {
            SetTime(hour, minute, second); //invoke SetTime to validate time
        }

        // Time2 constructor: another Time2 object supplied as an argument
        public Time2(Time2 time) : this(time.hour, time.minute, time.second) { }

        public void SetTime(int hour, int minute, int second)
        {
            Hour = hour;
            Minute = minute;
            Second = second;
        }

        // property that gets or sets the hour
        public int Hour
        {
            get { return hour; }
            set
            {
                if (value > 23)
                {
                    value = 0;
                    hour = value;
                    minute = 0;
                    second = 0;
                }

                hour = value;
            }
        }

        // property that gets or sets the minute
        public int Minute
        {
            get { return minute; }
            set
            {
                if (value > 59)
                {
                    Hour++;
                    value = 0;
                    minute = value;
                }

                minute = value;
            }
        }

        // property that gets or sets the second
        public int Second
        {
            get { return second; }
            set
            {
                if (value > 59)
                {
                    Minute++;
                    value = 0;
                    second = value;
                }

                second = value;
            }
        }

        // convert to string in universal-time format (HH:MM:SS)
        public string ToUniversalString() => $"{Hour:D2} : {Minute:D2} : {Second:D2}";

        // convert to string in standard-time format (H:MM:SS AM or PM)
        public override string ToString() =>
            $"{((Hour == 0 || Hour == 12) ? 12 : Hour % 12)} : " +
            $"{Minute:D2} : {Second:D2} {(Hour < 12 ? "AM" : "PM")}";

        //Compares two Time2 objects; returns 1 if this object is greater time than the compared object.
        //Returns -1 if compared object is a greater time.
        public int CompareTo(Time2 other)
        {
            if (Hour > other.Hour || Minute > other.Minute || Second > other.Second)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
    }
}
