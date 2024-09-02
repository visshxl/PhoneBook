#include <iostream>
#include <fstream>
#include <cctype>       // for isdigit function
#include <algorithm>    // for all_of function
using namespace std;

string fname, lname, phone_num;

void addContact();
void searchContact();
void help();
void self_exit();
bool check_digits(string);
bool check_numbers(string);

int main()
{
    short int choice;
    do {
        (void)system("cls");       // Explicitly ignore the return value
        (void)system("color 0A");  // Explicitly ignore the return value
        cout << "\n\n\n**************CONTACT MANAGEMENT**************";
        cout<<"\n\n Choose from the options:";
        cout << "\n\t1. Add Contact\n\t2. Search Contact\n\t3. Help\n\t4. Exit\n\t> ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                addContact();
                break;
            case 2:
                searchContact();
                break;
            case 3:
                help();
                break;
            case 4:
                self_exit();
                break;
            default:
                cout << "\n\n\tInvalid Input!";
                cout << "\n\tPress Any Key To Continue...";
                cin.ignore();
                cin.get();
                break;
        }
    } while(choice != 4);

    return 0;
}

void self_exit()
{
    (void)system("cls");  // Explicitly ignore the return value
    cout << "\n\n\n\t\tThank You For Using!";
    exit(0);
}

void help()
{
    (void)system("cls");  // Explicitly ignore the return value
    cout << "\n\n\tThis is a simple contact management system.";
    cout << "\n\tYou can add, search, and manage your contacts.";
    cout << "\n\t- Add Contact: Store a new contact.";
    cout << "\n\t- Search Contact: Find a contact by first or last name.";
    cout << "\n\t- Exit: Close the application.";
    cout << "\n\tPress any key to return to the main menu...";
    cin.ignore();
    cin.get();
}

void addContact()
{
    ofstream phone("number.txt", ios::app);
    (void)system("cls");  // Explicitly ignore the return value
    cout << "\n\n\tEnter First Name : ";
    cin >> fname;
    cout << "\n\tEnter Last Name : ";
    cin >> lname;
    cout << "\n\tEnter 10-Digit Phone Number : ";
    cin >> phone_num;

    if (check_digits(phone_num) && check_numbers(phone_num))
    {
        if (phone.is_open())
        {
            phone << fname << " " << lname << " " << phone_num << endl;
            cout << "\n\tContact Saved Successfully!";
        }
        else
        {
            cout << "\n\tError Opening File!";
        }
    }
    else
    {
        cout << "\n\tInvalid Phone Number! Please enter a 10-digit number containing only digits.";
    }

    phone.close();
    cout << "\n\tPress any key to return to the main menu...";
    cin.ignore();
    cin.get();
}

void searchContact()
{
    bool found = false;
    ifstream myfile("number.txt");
    string keyword;
    cout << "\n\tEnter Name To Search : ";
    cin >> keyword;

    if (myfile.is_open())
    {
        while (myfile >> fname >> lname >> phone_num)
        {
            if (keyword == fname || keyword == lname)
            {
                (void)system("cls");  // Explicitly ignore the return value
                cout << "\n\n\n\t\tContact details..";
                cout << "\n\n\tFirst Name : " << fname;
                cout << "\n\tLast Name : " << lname;
                cout << "\n\tPhone Number : " << phone_num;
                found = true;
            }
        }
        if (!found)
        {
            cout << "\n\tNo Such Contact Found";
        }
        myfile.close();
    }
    else
    {
        cout << "\n\tError Opening File!";
    }

    cout << "\n\tPress any key to return to the main menu...";
    cin.ignore();
    cin.get();
}

bool check_digits(string x)
{
    return x.length() == 10;
}

bool check_numbers(string x)
{
    return all_of(x.begin(), x.end(), ::isdigit);
}
