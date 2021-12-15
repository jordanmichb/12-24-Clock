// Project One
// Jordan Ballard
// November 14, 2021



#include <iostream>
#include <iomanip>
using namespace std;

class DisplayTwoClocks
{
private:
    // Private variables for use within the class
    int hours24;
    int minutes;
    int seconds;

    int GetHour12(bool& am_pm)
    {
        // Declare local variable
        int hours12;

        // Switch statement to convert hours12 to correct number based on value of hours24 and change to PM
        // If hours24 is none of these cases, default case keeps hours12 the same
        switch (hours24)
        {
            
            case 13:
                hours12 = 1;
                am_pm = false;
                break;
            case 14:
                hours12 = 2;
                am_pm = false;
                break;
            case 15:
                hours12 = 3;
                am_pm = false;
                break;
            case 16:
                hours12 = 4;
                am_pm = false;
                break;
            case 17:
                hours12 = 5;
                am_pm = false;
                break;
            case 18:
                hours12 = 6;
                am_pm = false;
                break;
            case 19:
                hours12 = 7;
                am_pm = false;
                break;
            case 20:
                hours12 = 8;
                am_pm = false;
                break;
            case 21:
                hours12 = 9;
                am_pm = false;
                break;
            case 22:
                hours12 = 10;
                am_pm = false;
                break;
            case 23:
                hours12 = 11;
                am_pm = false;
                break;
            case 0:
                hours12 = 12;
                // Keep as AM
                break;
            case 12:
                hours12 = hours24;
                // Switch to PM
                am_pm = false;
                break;
            default:
                hours12 = hours24;
        }

        return hours12;
    }

    // Directly adds one hour to 24-hour clock, indirectly causes one added to 12-hour clock 
    void AddHour()
    {
        hours24 += 1;
        if (hours24 > 23)
        {
            hours24 = 0;
        }
    }

    // Add one minute to clock, reset after reaching 59
    // After passing 59, increment hour
    void AddMinute()
    {
        minutes += 1;
        if (minutes > 59)
        {
            minutes = 0;
            AddHour();
        }
    }

    // Add one second to clock, reset after reaching 59
    // After passing 59, increment minute
    void AddSecond()
    {
        seconds += 1;
        if (seconds > 59)
        {
            seconds = 0;
            AddMinute();
        }
    }

    // Output both clocks to screen
    void DisplayClock()
    {
        // Initialize as AM
        bool amPm = true;

        // Alternate setting fill characters in columns to print two lines for top border of the boxes
        cout << setfill('*') << setw(26) << ""
             << setfill(' ') << setw(4) << ""
             << setfill('*') << setw(26) << "" << endl;
        // Reset fill character
        cout << setfill(' ');

        // Split line into columns to center align text and separate clocks, print each clock title surrounded by outer border
        cout << setw(6) << left << "*" << "12-Hour Clock"
             << setw(7) << right << "*"
             << setw(4) << ""
             << setw(7) << left << "*" << "24-Hour Clock"
             << setw(6) << right << "*" << endl;

        // Separate line into columns for alignment and creating outer border
        // Give numbers own columns and set fill to 0 to give a leading 0 to single-digit numbers
        cout << setw(7) << left << "*"
             << setfill('0')
             << setw(2) << right << GetHour12(amPm) << ":"
             << setw(2) << right << minutes << ":"
             << setw(2) << right << seconds;

        // Decide if AM or PM for output
        if (amPm == true)
        {
            cout << " AM";
        }
        else
        {
            cout << " PM";
        }

        cout << setfill(' ')
             << setw(8) << right << "*"
             << setw(4) << ""
             << setw(9) << left << "*"
             << setfill('0')
             << setw(2) << right << hours24 << ":"
             << setw(2) << right << minutes << ":"
             << setw(2) << right << seconds
             << setfill(' ')
            << setw(9) << right << "*" << endl;

        // Alternate setting fill characters in columns to print two lines for bottom border of the boxes
        cout << setfill('*') << setw(26) << ""
             << setfill(' ') << setw(4) << ""
             << setfill('*') << setw(26) << "" << endl;
        // Reset fill character
        cout << setfill(' ');
    }


    void DisplayMenu()
    {
        // Set fill characters to print top border of box 
        cout << setfill('*') << setw(26) << "" << endl;
        // Reset fill character
        cout << setfill(' ');

        // Format four menu options on their own line, surrounded by asterisk to create outer border
        cout << setw(2) << left << "*" << "1-Add One Hour"
             << setw(10) << right << "*" << endl;

        cout << setw(2) << left << "*" << "2-Add One Minute"
             << setw(8) << right << "*" << endl;

        cout << setw(2) << left << "*" << "3-Add One Second"
             << setw(8) << right << "*" << endl;

        cout << setw(2) << left << "*" << "4-Exit Program"
             << setw(10) << right << "*" << endl;

        // Set fill characters to print bottom border of box
        cout << setfill('*') << setw(26) << "" << endl;
        // Reset fill character
        cout << setfill(' ');
    }

public:
    // Print 40 endl to clear screen
    void ClearScreen()
    {
        for (int i = 0; i < 40; ++i)
        {
            cout << endl;
        }
    }

    // Output clock and option menu to screen
    void Display()
    {
        DisplayClock();
        DisplayMenu();
    }

    // Get input and take appropriate course of action
    bool ReadUserInput()
    {
        int userInput;

        cin >> userInput;

        if (userInput == 1)
        {
            AddHour();
            return false;
        }
        else if (userInput == 2)
        {
            AddMinute();
            return false;
        }
        else if (userInput == 3)
        {
            AddSecond();
            return false;
        }
        else if (userInput == 4)
        {
            return true;
        }
    }


    // To initialize data
    void Init(int hour, int minute, int second)
    {
        hours24 = hour;
        minutes = minute;
        seconds = second;

        ClearScreen();
        DisplayClock();
        DisplayMenu();
    }
};

int main()
{
    // Create new object based on the class
    DisplayTwoClocks newClock;

    // Initialize data with given values
    newClock.Init(17, 12, 34);

    
    // Loop until user prompts the program to exit
    while (1)
    {
        newClock.ClearScreen();
        newClock.Display();
        if (newClock.ReadUserInput())
        {
            cout << endl << "Exiting Program" << endl;
            break;
        }
    }

    return 0;
}
