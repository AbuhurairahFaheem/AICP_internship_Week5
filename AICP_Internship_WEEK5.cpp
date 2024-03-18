#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

void setTextColor(int colorCode) {
#ifdef _WIN32
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorCode);
#else
    cout << "\033[1;" << colorCode << "m";
#endif
}

void resetTextColor() {
#ifdef _WIN32
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
#else
    cout << "\033[0m";
#endif
}

void displayHeader() {
    setTextColor(14);
    cout << "-----------------------------" << endl;
    cout << "     Car Park Simulator      " << endl;
    cout << "-----------------------------" << endl;
    resetTextColor();
}

void displayFooter() {
    setTextColor(14);
    cout << "-----------------------------" << endl;
    resetTextColor();
}

int calculateCheckDigit(int number) {
    int sum = 0;
    int multiplier = 1;

    while (number > 0) {
        int digit = number % 10;
        sum += digit * multiplier;
        multiplier++;
        number /= 10;
    }

    int remainder = sum % 11;
    int checkDigit = (11 - remainder) % 11;

    return checkDigit;
}

double calculateParkingPrice(const string& day, int arrivalHour, int parkingHours, int frequentParkingNumber, bool& discountApplied) {
    double price = 0.0;
    discountApplied = false;

    if (arrivalHour < 0 || arrivalHour > 23 || parkingHours < 1 || parkingHours > 24) {
        return -1;
    }

    if ((day == "Sunday" || day == "Saturday") && parkingHours > 8) {
        price = (day == "Sunday") ? 2.0 : 3.0;
    }
    else {
        price = 10.0;
    }

    if (arrivalHour >= 16 && arrivalHour <= 23) {
        price *= 0.5;
        discountApplied = true;
    }

    if (calculateCheckDigit(frequentParkingNumber) == 0) {
        price *= 0.9;
        discountApplied = true;
    }

    return price * parkingHours;
}

void task1() {
    displayHeader();
    setTextColor(11);
    cout << "Task 1: Calculating the price to park" << endl;
    resetTextColor();

    string day;
    int arrivalHour, parkingHours, frequentParkingNumber;
    cout << "Enter day (e.g., Sunday): ";
    cin >> day;
    cout << "Enter arrival hour (24-hour format): ";
    cin >> arrivalHour;
    cout << "Enter parking hours: ";
    cin >> parkingHours;
    cout << "Enter frequent parking number: ";
    cin >> frequentParkingNumber;

    bool discountApplied;
    double price = calculateParkingPrice(day, arrivalHour, parkingHours, frequentParkingNumber, discountApplied);

    if (price < 0) {
        cout << "Invalid input. Please enter valid values." << endl;
    }
    else {
        cout << fixed << setprecision(2);
        cout << "Price to park: $" << price << endl;
        if (discountApplied) {
            cout << "Discount applied." << endl;
        }
    }

    displayFooter();
}

void task2() {
    displayHeader();
    setTextColor(11);
    cout << "Task 2: Keeping a total of the payments" << endl;
    resetTextColor();

    double dailyTotal = 0.0;
    int numCustomers;
    cout << "Enter the number of customers: ";
    cin >> numCustomers;

    for (int i = 0; i < numCustomers; ++i) {
        string day;
        int arrivalHour, parkingHours, frequentParkingNumber;
        cout << "Enter day (e.g., Sunday) for customer " << i + 1 << ": ";
        cin >> day;
        cout << "Enter arrival hour (24-hour format) for customer " << i + 1 << ": ";
        cin >> arrivalHour;
        cout << "Enter parking hours for customer " << i + 1 << ": ";
        cin >> parkingHours;
        cout << "Enter frequent parking number for customer " << i + 1 << ": ";
        cin >> frequentParkingNumber;

        bool discountApplied;
        double price = calculateParkingPrice(day, arrivalHour, parkingHours, frequentParkingNumber, discountApplied);
        if (price < 0) {
            cout << "Invalid input. Skipping customer." << endl;
            continue;
        }
        cout << fixed << setprecision(2);
        cout << "Price to park for customer " << i + 1 << ": $" << price << endl;
        dailyTotal += price;
    }

    cout << "Total earnings today: $" << fixed << setprecision(2) << dailyTotal << endl;

    displayFooter();
}

double calculateFairParkingPrice(const string& day, int arrivalHour, int parkingHours, int frequentParkingNumber, bool& dummy) {
    double priceBeforeDiscount = calculateParkingPrice(day, arrivalHour, parkingHours, frequentParkingNumber, dummy);
    double priceAfterDiscount = 0.0;

    if (arrivalHour < 16) {
        priceAfterDiscount = priceBeforeDiscount;
    }
    else {
        priceAfterDiscount = calculateParkingPrice(day, 16, parkingHours - (16 - arrivalHour), frequentParkingNumber, dummy);
    }

    return priceAfterDiscount;
}

void task3() {
    displayHeader();
    setTextColor(11);
    cout << "Task 3: Making payments fairer" << endl;
    resetTextColor();

    string day;
    int arrivalHour, parkingHours, frequentParkingNumber;
    cout << "Enter day (e.g., Sunday): ";
    cin >> day;
    cout << "Enter arrival hour (24-hour format): ";
    cin >> arrivalHour;
    cout << "Enter parking hours: ";
    cin >> parkingHours;
    cout << "Enter frequent parking number: ";
    cin >> frequentParkingNumber;

    bool dummy; // Declaring the boolean variable dummy
    double price = calculateFairParkingPrice(day, arrivalHour, parkingHours, frequentParkingNumber, dummy);

    if (price < 0) {
        cout << "Invalid input. Please enter valid values." << endl;
    }
    else {
        cout << fixed << setprecision(2);
        cout << "Price to park with fair pricing: $" << price << endl;
    }

    displayFooter();
}

int main() {
    char choice;
    do {
        displayHeader();
        setTextColor(11);
        cout << "Welcome to Car Park Simulator" << endl;
        cout << "------------------------------" << endl;
        resetTextColor();

        cout << "Choose a task to perform:" << endl;
        cout << "1. Calculate the price to park" << endl;
        cout << "2. Keep a total of the payments" << endl;
        cout << "3. Make payments fairer" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case '1':
            task1();
            break;
        case '2':
            task2();
            break;
        case '3':
            task3();
            break;
        case '4':
            cout << "Exiting program..." << endl;
            break;
        default:
            setTextColor(12); // Red color for error
            cout << "Invalid choice. Please enter a valid option (1-4)." << endl;
            resetTextColor();
        }
    } while (choice != '4');

    return 0;
}
