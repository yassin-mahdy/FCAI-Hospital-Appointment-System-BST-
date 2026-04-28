#include <iostream>
#include <fstream>
#include <string>
#include "BST.h"
using namespace std;

// =====================
// Load data from file
// =====================
void loadFromFile(BST &tree, const string &filename)
{
    ifstream file(filename);

    if (!file)
    {
        cout << "Error opening file\n";
        return;
    }

    string line;

    // Read number of appointments
    getline(file, line);
    int n = stoi(line);

    for (int i = 0; i < n; i++)
    {
        string name, department;
        int priority;

        getline(file, name);

        getline(file, line);
        priority = stoi(line);

        getline(file, department);

        tree.insert(Appointment(name, priority, department));
    }

    file.close();
}

// =====================
// Main Menu
// =====================
int main()
{
    BST tree;

    // Load initial data
    loadFromFile(tree, "input.txt");

    int choice;

    do
    {
        cout << "\n===== Hospital Appointment System =====\n";
        cout << "1. Schedule an appointment\n";
        cout << "2. Display all appointments\n";
        cout << "3. Search for an appointment\n";
        cout << "4. Cancel an appointment\n";
        cout << "5. Display more urgent than\n";
        cout << "6. Display less urgent than\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore(); // clear newline

        switch (choice)
        {
        case 1:
        {
            string name, department;
            int priority;

            cout << "Enter patient name: ";
            getline(cin, name);

            cout << "Enter priority level: ";
            cin >> priority;
            cin.ignore();

            cout << "Enter department: ";
            getline(cin, department);

            tree.insert(Appointment(name, priority, department));

            cout << "Appointment scheduled.\n";
            break;
        }

        case 2:
        {
            cout << "\nAll Appointments:\n";
            tree.displayAll();
            break;
        }

        case 3:
        {
            int priority;
            cout << "Enter priority level: ";
            cin >> priority;

            cout << "\nMatching Appointments:\n";
            tree.search(priority);
            break;
        }

        case 4:
        {
            int priority;
            cout << "Enter priority level: ";
            cin >> priority;

            tree.remove(priority);

            cout << "Appointments cancelled.\n";
            break;
        }

        case 5:
        {
            int priority;
            cout << "Display more urgent than: ";
            cin >> priority;

            cout << "\nResults:\n";
            tree.displayMoreUrgent(priority);
            break;
        }

        case 6:
        {
            int priority;
            cout << "Display less urgent than: ";
            cin >> priority;

            cout << "\nResults:\n";
            tree.displayLessUrgent(priority);
            break;
        }

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
