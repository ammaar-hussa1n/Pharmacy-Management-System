# Pharmacy Management System

A simple console-based pharmacy management system implemented in C++ using data structures like arrays and stacks.

## Overview

This program allows users to manage a pharmacy's inventory, record sales, undo recent sales, view recent sales, and track total profit. It uses a stack data structure to implement the undo functionality for sales.

## Features

- **View Medicines**: Display the list of available medicines with their IDs, names, quantities, and prices.
- **Sell Medicine**: Sell a specified quantity of a medicine, updating inventory and recording the sale.
- **Undo Last Sale**: Undo the most recent sale, restoring the inventory and adjusting profit.
- **Show Recent Sales**: Display a list of recent sales from the stack.
- **Show Profit**: Display the total profit earned from sales.
- **Exit**: Exit the program.

## Data Structures Used

- **Medicine Struct**: Represents a medicine with ID, name, quantity, and price.
- **Stack Struct**: A stack to store sold medicines for undo operations. It includes push, pop, and display methods.

## How to Compile and Run

1. Ensure you have a C++ compiler installed (e.g., g++).
2. Compile the program: `g++ DSAProject.cpp -o pharmacy`
3. Run the executable: `./pharmacy` (on Linux/Mac) or `pharmacy.exe` (on Windows).

## Requirements

- C++ compiler supporting C++11 or later.
- Console/terminal for input and output.

## Usage

The program presents a menu with options numbered 1-6. Enter the corresponding number to perform an action. The system uses color-coded output for better readability (may not work on all terminals).

## Limitations

- Fixed inventory of 5 medicines.
- Stack size limited to 50 sales.
- No data persistence; all data is lost when the program exits.