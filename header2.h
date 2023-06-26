#include <iostream>
#include <windows.h>
#include <fstream>
using namespace std;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // For use of SetConsoleTextAttribute()//to change color of text

bool check_digits(string str)
{
    if (str.length() == 10)
        return true;
    else
        return false;
}
bool check_numbers(string str)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 48 && str[i] <= 57)
            continue;
        else
        {
            return false;
        }
    }
    return true;
}
void number_of_contacts()
{
    SetConsoleTextAttribute(console, 12);
    int count = 0;
    string str;
    ifstream file("number.txt");
    while (getline(file, str))
    {
        count++;
    }
    cout << "Number of total contacts are: " << count << endl;
}