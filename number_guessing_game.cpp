// Copyright (c) 2020 Marcus A. Mosley All rights reserved.
//
// Created by Marcus A. Mosley
// Created on September 2020
// This program is a Number Guessing Game with
//   Random Numbers and While True, Break

#include <iostream>
#include <random>

int main() {
    // This function creates a random number and checks if the user's guess
    //   is equal to the generated number
    std::string guess_str;
    int guess_int;
    int random_number;

    // Input
    std::random_device random_device;
    std::mt19937 engine{random_device()};
    std::uniform_int_distribution<> dist(0, 9);
    random_number = dist(engine);

    while (true) {
        std::cout << "Enter a number between 0 and 9: ";
        std::cin >> guess_str;
        std::cout << "" << std::endl;

        // Process
        try {
            // Output
            guess_int = std::stoi(guess_str);
            if (guess_int < 0 || guess_int > 9) {
            std::cout << "You have not inputted a number between 0-9, please"
                         " input one in that range!" << std::endl;
            std::cout << "" << std::endl;
            } else {
                if (guess_int == random_number) {
                    std::cout << "That is correct, the right number was "
                    << std::fixed << guess_int << "!" << std::endl;
                    break;
                } else {
                    std::cout << "That is incorrect, please try again!"
                    << std::endl;
                    std::cout << "" << std::endl;
                }
            }
        } catch (std::invalid_argument) {
            std::cout << "That is not an integer, please input a number"
                " between 0 and 9!" << std::endl;
            std::cout << "" << std::endl;
        }
    } std::cout << "" << std::endl;
    std::cout << "Thanks for Playing!" << std::endl;
}
