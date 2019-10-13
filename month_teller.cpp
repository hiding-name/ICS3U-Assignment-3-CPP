// Copyright (c) 2019 Matsuru All rights reserved.
//
// Created by: Matsuru Hoshi
// Created on: Oct 2019
// This program gives user number of days in a month based on month given

#include <iostream>
#include <string>
#include <list>
#include <algorithm>



std::list<std::string> days_with_31 { "january", "march", "may", "july",
                                      "august", "october", "december" };
std::list<std::string> days_with_30 { "april", "june", "september",
                                      "november" };

main() {
    // funciton gives user number of days in month

    // variables;
    std::string month;
    int year = 0, days = 0;

    // Welcome statement
    std::cout << "Welcome, I will tell you the number of days in a month."
                 "\n*Leap years work as well." << std::endl;
    std::cout << "Press Enter to continue." << std::endl;
    std::cin.ignore();

    // input
    std::cout << "What month is it: " << std::endl;
    std::cin >> month;
    std::cout << "What year is it:" << std::endl;
    std::cin >> year;

    // This makes sure anything the user inputs is formated to lower case
    // This way it doesn't matter if they type first letter capital or something
    // This transforms each character to lower case
    transform(month.begin(), month.end(), month.begin(), ::tolower);

    // process & output
    // This checks if month is 30 or 31
    if (std::find (days_with_31.begin(), days_with_31.end(), month)
        != days_with_31.end()) {
        days = 31;
    } else if (std::find (days_with_30.begin(), days_with_30.end(), month)
        != days_with_30.end()) {
        days = 30;
    // This deals with Frebruary
    } else if (month == "february") {
        days = 28;
        if (year % 4 == 0) {
            if (year % 100 == 0) {
                if (year % 400) {
                    days = 29;
                }
            } else {
                days = 29;
            }
        }
    } else {
        std::cout << "Invalid input." << std::endl;
    }

    month[0] = toupper(month[0]);
    std::cout << "\n" << month << " of " << year << " has " << days <<
                 " days."<< std::endl;
}
