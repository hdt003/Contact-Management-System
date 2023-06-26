#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include<iomanip>
#include <conio.h> //to get getch( )function and textcolor function
#include"header1.h"
using namespace std;

int main()
{

    system("cls");
    while (1)
    {
        // system("color 0A"); // color background id,textcolor id
        SetConsoleTextAttribute(console, 6); // set color for the next print

        cout << "\t\t\t\t-------:Contact Management System:-------" << endl;
        cout << "\t\t\t1. add contact" << endl;
        cout << "\t\t\t2. Search contact" << endl;
        cout << "\t\t\t3. display all contacts" << endl;
        cout << "\t\t\t4. Edit Contact Details" << endl;
        cout << "\t\t\t5. Delete Contact" << endl;
        cout << "\t\t\t6. Find number of contacts saved" << endl;
        cout << "\t\t\t7. exit" << endl;
        cout << "\t\t\t-->Enter choice: ";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            add_contact();
            break;
        case 2:
            search_contact();
            break;
        case 3:
            display_all();
            break;
        case 4:
            edit_contact();
            break;
        case 5:
            SetConsoleTextAttribute(console, 12); // set color for the next print
            delete_contact();
            break;
        case 6:
            number_of_contacts();
            break;
        case 7:
            exit(0);
        default:
            cout << "Invalid Input !" << endl;
            cout << "press any key to continue" << endl;
            getch();
            main();
        }
    }
    return 0;
}