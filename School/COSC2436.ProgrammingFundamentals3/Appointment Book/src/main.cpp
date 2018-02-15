/**
    @file main.cpp
    @author Ethan D. Hann
    @version 1.0
    @date 4/21/2016
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

#include "Appointment.h" // Include the header file that defines what an appointment is.

using namespace std;

//Prototyping all of the functions.
void menu();
void new_appointment(vector<Appointment> &appts);
void view_appointments(vector<Appointment> appts, string day);
void view_appointments(vector<Appointment> appts);
void delete_appointments(vector<Appointment> &appts, string day, int choice);

int main()
{
    vector<Appointment> appts = {}; //Initializing the vector that will store all of the appointments.
    menu();
    int choice = 0;
    cout << "Option: " << endl;
    cin >> choice;

    //while statement continues until user enters 4, which exits the program.
    while (choice != 4)
    {
        //switch statement that allows different choices for the user.
        switch(choice)
        {
        case 1: // Create a new appointment.
            {
                new_appointment(appts);
                break;
            }
        case 2: // View either a single day's appointments or ALL appointments.
            {
                string day_to_view = "";
                cout << "Enter day ('ALL' to view all appointments): ";
                cin >> day_to_view;
                if (day_to_view == "ALL")
                {
                    view_appointments(appts);
                }
                else
                {
                    view_appointments(appts, day_to_view);
                }
                system("pause");
                break;
            }
        case 3: //Delete an appointment.
            {
                string day_to_delete = "";
                int counter = 0;
                int choice = 0;
                if (appts.size() == 0)
                {
                    cout << "There are no appointments to delete." << endl;
                    break;
                }
                else
                {
                    cout << "Enter day to view appointments to delete: ";
                    cin >> day_to_delete;
                    for (unsigned int i = 0; i < appts.size(); i++)
                    {
                        if (day_to_delete == appts[i].get_day())
                        {
                            cout << i + 1 << " : " << appts[i].get_description() << '\t' << appts[i].get_day() << '\t' << appts[i].get_time_start() << " to " << appts[i].get_time_end() << endl;
                            counter += 1;
                        }
                        else
                        {
                            continue;
                        }
                    }
                    if (counter == 0)
                    {
                        cout << "No appointments to delete that day." << endl;
                        break;
                    }
                    cout << "Select appointment to delete by number: ";
                    cin >> choice;
                    delete_appointments(appts, day_to_delete, (choice - 1));
                    break;
                }
            }
        default: // User entered something other than the allowed option numbers.
            {
                cout << "That is not a valid choice. Please choose either 1, 2, 3, or 4." << endl;
                system("pause");
                break;
            }
        }
        system("cls");
        menu();
        cout << "Option: " << endl;
        cin >> choice;
    }
}

/**
    Displays a menu to the user.

    @param void
    @return void
*/
void menu()
{
    cout << "|----------------|" << endl;
    cout << "|APPOINTMENT BOOK|" << endl;
    cout << "|----------------|" << endl;
    cout << "| 1. Create new appointment" << endl;
    cout << "| 2. View appointments" << endl;
    cout << "| 3. Delete appointment(s)" << endl;
    cout << "| 4. Exit" << endl;
}

/**
    This function is what creates new appointments.

    @param vector vector of appointments
    @return void
*/
void new_appointment(vector<Appointment> &appts)
{
    string desc = "";
    string day = "";
    int start_time = 0;
    int end_time = 0;

    cin.clear();
    cin.sync();
    cout << "To create a new appointment, enter the following information:" << endl;
    cout << "Short Description: ";
    getline(cin, desc);
    cout << "" << endl;

    cout << "Day of Appointment: ";
    cin >> day;
    cout << "" << endl;

    cout << "Starting Time: ";
    cin >> start_time;
    cout << "" << endl;

    cout << "Ending Time: ";
    cin >> end_time;
    cout << "" << endl;

    Appointment new_appt = Appointment(desc, day, start_time, end_time);
    appts.push_back(new_appt);
}

/**
    This function is what allows the user to view appointments for a single day.

    @param vector vector of appointments, day day to view
    @return void
*/
void view_appointments(vector<Appointment> appts, string day)
{
    int counter = 0;
    for (unsigned int i = 0; i < appts.size(); i++)
    {
        if (day == appts[i].get_day())
        {
            cout << "Desc: " << appts[i].get_description() << '\t' << "Day: " << appts[i].get_day() << '\t' << "Time: " << appts[i].get_time_start() << " to " << appts[i].get_time_end() << endl;
            counter += 1;
        }
        else
        {
            continue;
        }
    }
    if (counter == 0)
    {
        cout << "No appointments for " << day << "." << endl;
    }
}

/**
    This is the overloaded view appointments function that allows the user to view all appointments.

    @param vector vector of appointments
    @return void
*/
void view_appointments(vector<Appointment> appts)
{
    for (unsigned int i = 0; i < appts.size(); i++)
    {
        cout << "Desc: " << appts[i].get_description() << '\t' << "Day: " << appts[i].get_day() << '\t' << "Time: " << appts[i].get_time_start() << " to " << appts[i].get_time_end() << endl;
    }
}

/**
    This function allows the user to delete appointments.

    @param vector vector of appointments, day day to view, choice day to delete
    @return void
*/
void delete_appointments(vector<Appointment> &appts, string day, int choice)
{
    for (unsigned int i = 0; i < appts.size(); i++)
    {
        if (day == appts[i].get_day())
        {
            appts.erase(appts.begin() + i);
        }
        else
        {
            continue;
        }
    }
}
