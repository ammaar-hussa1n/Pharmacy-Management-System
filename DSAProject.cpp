#include <iostream>
#include <string>
using namespace std;

#define BLUE    "\033[36m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define PURPLE  "\033[35m"
#define RESET   "\033[0m"

// Pharmacy Management System
// This program simulates a pharmacy management system with inventory tracking,
// sales recording, undo functionality using a stack, and profit calculation.
// It uses a menu-driven interface for user interaction.

struct Medicine {
    int id;
    string name;
    int quantity;
    float price;
};

struct Stack {
    Medicine sold[50];
    int top = -1;

    void push(Medicine m) {
        if (top < 49)
            sold[++top] = m;
        else
            cout << RED << "Stack Is Full! Can't record more sales.\n" << RESET;
    }

    Medicine pop(double &profit) {
        Medicine undone;
        undone.id = -1;

        if (top >= 0) {
            undone = sold[top];
            cout << YELLOW << "Undo Sale : " << sold[top].name << " (" << sold[top].quantity << " pcs) removed.\n" << RESET;
            profit -= undone.quantity * undone.price;
            top--;
        }
        else {
            cout << RED << "No sales to undo!\n" << RESET;
        }
        return undone;
    }

    //new method to display recent sales

    void display() {
        if (top == -1) {
            cout << RED << "No recent sales!\n" << RESET;
            return;
        }
        cout << BLUE << "\n=== Recent Sales ===\n" << RESET;
        for (int i = top; i >= 0; i--)
            cout << sold[i].name << " | Qty : " << sold[i].quantity << endl;
    }
};

int main() {
    // Initialize inventory with 5 medicines
    Medicine inventory[5] = {
        {1, "Panadol", 50, 5.0},
        {2, "Disprin", 30, 18.0},
        {3, "Amoxil", 25, 3.5},
        {4, "Brufen", 25, 12.0},
        {5, "Calpol", 40, 3.0}
    };

    // Stack to record sales for undo functionality
    Stack sales;
    // Variable to track total profit
    double profit = 0;

    // Main menu loop
    do {
        cout << BLUE << "\n===== Pharmacy Management System =====\n" << RESET;
        cout << GREEN << "1) " << RESET << "View Medicines\n";
        cout << GREEN << "2) " << RESET << "Sell Medicine\n";
        cout << GREEN << "3) " << RESET << "Undo Last Sale\n";
        cout << GREEN << "4) " << RESET << "Show Recent Sales\n";
        cout << GREEN << "5) " << RESET << "Show Profit\n";
        cout << GREEN << "6) " << RESET << "Exit\n";
        cout << "\nEnter choice : ";
        cin >> choice;

        if (choice == 1) {
            // Display available medicines with quantities and prices
            cout << PURPLE << "\n============ Available Medicines ============\n" << RESET;
            for (int i = 0; i < 5; i++) {
                cout << inventory[i].id << ". " << inventory[i].name << "\t| Qty : ";
                if (inventory[i].quantity == 0) {
                    cout << RED << "NO STOCK" << RESET;
                }
                else {
                    cout << inventory[i].quantity << "\t";
                }
                cout << "| Price : $" << inventory[i].price << endl;
            }
                
        }

        else if (choice == 2) {
            // Sell medicine: reduce inventory and record sale
            int id, qty;
            cout << "\nEnter Medicine ID : ";
            cin >> id;
            cout << "Enter Quantity : ";
            cin >> qty;

            if (id >= 1 && id <= 5) {
                if (inventory[id - 1].quantity >= qty) {
                    inventory[id - 1].quantity -= qty;
                    cout << YELLOW << "Sold " << qty << " pcs of " << inventory[id - 1].name << RESET << endl;
                    profit += (qty * inventory[id - 1].price);
                    sales.push({ id, inventory[id - 1].name, qty, inventory[id - 1].price });
                }
                else {
                    cout << RED << "Not enough stock!\n" << RESET;
                }
            }
            else {
                cout << RED << "Invalid medicine ID!\n" << RESET;
            }
        }

        else if (choice == 3) {
            // Undo last sale: restore inventory and adjust profit
            Medicine undone = sales.pop(profit);
            if (undone.id != -1) {
                inventory[undone.id - 1].quantity += undone.quantity;
                cout << YELLOW << "Stock restored for " << undone.name << RESET << endl;
            }
        }

        else if (choice == 4) {
            // Display recent sales from the stack
            sales.display();    
        }

        else if (choice == 5) {
            // Display total profit
            cout << GREEN << "Total Profit" << RESET << " : " << YELLOW << "$" << profit << RESET << endl;
        }

        else if (choice == 6) {
            // Exit the program
            cout << RED << "Exiting System...\n" << RESET;
        }

        else {
            cout << RED << "Invalid Choice!\n" << RESET;
        }

    } while (choice != 6);
}
