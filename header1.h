#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <iomanip>
#include <conio.h> //to get getch( )function and textcolor function
#include "header2.h"
using namespace std;

// global vars
string fname, lname, phone_num;

void write_in_file()
{
    SetConsoleTextAttribute(console, 11); // set color for the next print
    ofstream file;                        // or file("number.txt",ios::app);
    file.open("number.txt", ios::app);    // append in file
    file << fname << " " << lname << " " << phone_num << endl;
    cout << "\t\t\tYour Contact saved Successfully" << endl;
    file.close();
}

void add_contact()
{
    SetConsoleTextAttribute(console, 11); // set color for the next print
    char ch = 'y';
    system("cls");
    while (ch == 'y' || ch == 'Y')
    {
        cout << "Enter first name: ";
        cin >> fname;
        cout << "Enter last name: ";
        cin >> lname;
        cout << "Enter 10 digit phone number: ";
        cin >> phone_num;
        while (1)
        {
            if (check_numbers(phone_num) == true)
            {
                if (check_digits(phone_num) == true)
                {
                    write_in_file();
                    cout << "Do you want to enter more?(y/n): ";
                    cin >> ch;
                    break;
                }
                else
                {
                    cout << "Enter 10 digit phone number :";
                    cin >> phone_num;
                }
            }
            else
            {
                cout << "phone number has only digits,Enter correct number :";
                cin >> phone_num;
            }
        }
    }
}

void display_all()
{
    while (1)
    {
        SetConsoleTextAttribute(console, 12); // set color for the next print
        ifstream file;
        file.open("number.txt");
        bool isEmpty = file.peek() == EOF;
        if (isEmpty == true)
        {
            cout << "No contacts" << endl;
            break;
        }
        string first, last, number;
        cout << setw(69) << "-------------------------:All contacts list:-------------------------" << endl;
        SetConsoleTextAttribute(console, 11); // set color for the next print
        if (!file)
        {
            cout << "File Not Found";
            break;
        }
        // getline(file, line); // getline(file name,string)
        cout << "-->" << setw(16) << "First Name" << setw(9) << " <--> " << setw(16) << "Last Name" << setw(9) << " <--> " << setw(16) << "Phone Number" << endl;
        SetConsoleTextAttribute(console, 10); // set color for the next print
        while (file >> first >> last >> number)
        {
            cout << "-->" << setw(16) << first << setw(9) << " <--> " << setw(16) << last << setw(9) << " <--> " << setw(16) << number << endl;
        }
        SetConsoleTextAttribute(console, 12); // set color for the next print

        cout << setw(69) << "--------------------------------------------------------------------" << endl;
        file.close();
        break;
    }
}
void search_contact()
{
    SetConsoleTextAttribute(console, 13); // set color for the next print
    string keyword;
    bool found = false;
    cout << "Enter First Name or Last Name, or Phone Number to search:";
    cin >> keyword;
    ifstream file("number.txt"); // to read from file
    // first it will read fname then lname then phone_num
    // here fname,lname is curently entered new fro, user
    while (file >> fname >> lname >> phone_num)
    {
        if (keyword == fname || keyword == lname || keyword == phone_num)
        {
            SetConsoleTextAttribute(console, 12); // set color for the next print

            cout << "--> Contact details: " << endl;
            SetConsoleTextAttribute(console, 11); // set color for the next print

            cout << "--> First Name: " << fname << endl;
            cout << "--> Last Name: " << lname << endl;
            cout << "--> Phone number: " << phone_num << endl
                 << endl;
            found = true;
        }
    }
    if (found == false)
    {
        cout << "contact not found" << endl;
    }
}
bool edit(string str1, string str2, string str3)
{
    bool check = false;
    ifstream file_read("number.txt"); // read
    ofstream tempfile("temp.txt");    // write
    string first, last, phone;
    while (file_read >> first >> last >> phone)
    {
        if (str1 == first && str2 == last) // writing new data in temp file
        {
            tempfile << str1 << " " << str2 << " " << str3 << endl;
            check = true;
        }
        else
        { // writing old data in temp file
            tempfile << first << " " << last << " " << phone << endl;
        }
    }
    file_read.close();
    tempfile.close();
    remove("number.txt");
    rename("temp.txt", "number.txt");
    return check;
}
void edit_contact()
{
    string str1, str2, str3;
    cout << "Enter first name to edit phone number:";
    fflush(stdin);
    getline(cin, str1);
    cout << "Enter last name to edit phone number:";
    fflush(stdin);
    getline(cin, str2);

    cout << "Enter new phone no.:";
    fflush(stdin);
    cin >> str3;
    bool check = edit(str1, str2, str3);
    if (check == true)
    {
        cout << "edited sucsessfully" << endl;
    }
    else
    {
        cout << "your name Not found " << endl;
    }
}

bool delete_(string str1) // str1 is fname+lanme
{
    // to delete dat we make 1 new "temp"file in which we will write
    //  those data which we don't want to delete and rename temp file as number.txt
    ifstream file("number.txt"); // main file
    ofstream tempfile("temp.txt");
    string first, last;
    string phone;
    bool check = false;
    if (file.good())
    {
        while (file >> first, file >> last, file >> phone) // first and last name and phone taken from file to variable
        {
            if (str1 != first + " " + last)
            {
                tempfile << first << " ";
                tempfile << last << " ";
                tempfile << phone << endl;
            }
        }

        check = true;
    }
    else
    {
        cout << "\nFile not found\n";
        check = false;
    }
    file.close();
    tempfile.close();
    remove("number.txt");
    rename("temp.txt", "number.txt");
    return check;
}

void delete_contact()
{
    string str1;
    cout << "Enter Full name (space sepreted first name and last name) to delete:";
    fflush(stdin);
    getline(cin, str1);
    bool check = delete_(str1);
    if (check)
    {
        cout << "Deleted successfully" << endl;
    }
    else
    {
        cout << "Not deleted or not found" << endl;
    }
}
