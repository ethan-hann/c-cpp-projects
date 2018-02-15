#ifndef APPOINTMENT_H_INCLUDED
#define APPOINTMENT_H_INCLUDED

#include <string>

using namespace std;

class Appointment
{
public:

    Appointment(string description, string day, int starting, int ending);

    string get_description() const;

    string get_day() const;

    int get_time_start() const;

    int get_time_end() const;

private:
    string description;
    string day;
    int starting;
    int ending;
};

#endif // APPOINTMENT_H_INCLUDED
