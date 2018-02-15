#include "Appointment.h"
#include <iostream>
#include <string>

using namespace std;

Appointment::Appointment(string desc, string day_of, int time_start, int time_end)
{
    description = desc;
    day = day_of;
    starting = time_start;
    ending = time_end;
}

string Appointment::get_description() const
{
    return description;
}

string Appointment::get_day() const
{
    return day;
}

int Appointment::get_time_start() const
{
    return starting;
}

int Appointment::get_time_end() const
{
    return ending;
}
