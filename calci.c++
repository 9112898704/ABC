#include <iostream>

using namespace std;

void menu() 
{
    cout << "Simple Calculator" << endl;
    cout << "Select an operation:" << endl;
    cout << "1. Addition (+)" << endl;
    cout << "2. Subtraction (-)" << endl;
    cout << "3. Multiplication (*)" << endl;
    cout << "4. Division (/)" << endl;
    cout << "5. Exit" << endl;
}

double add(double a, double b) 
{
    return a + b;
}

double sub(double a, double b) 
{
    return a - b;
}

double mul(double a, double b) 
{
    return a * b;
}

double division(double a, double b) 
{
    if (b == 0) 
    {
        throw invalid_argument("Error: Division by zero is not allowed.");
    }
    return a / b;
}

int main() 
{
    int choice;
    double num1, num2;

    while (true) 
    {
        menu();
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        if (choice == 5) 
        {
            cout << "Exiting the calculator. Goodbye!" << endl;
            break;
        }

        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;

        try 
        {
            switch (choice) 
            {
                case 1:
                    cout << "Result: " << num1 << " + " << num2 << " = " << add(num1, num2) << endl;
                    break;
                case 2:
                    cout << "Result: " << num1 << " - " << num2 << " = " << sub(num1, num2) << endl;
                    break;
                case 3:
                    cout << "Result: " << num1 << " * " << num2 << " = " << mul(num1, num2) << endl;
                    break;
                case 4:
                    cout << "Result: " << num1 << " / " << num2 << " = " << division(num1, num2) << endl;
                    break;
                default:
                    cout << "Invalid choice! Please select a valid operation." << endl;
            }
        } 
        catch (const invalid_argument& e) 
        {
            cout << e.what() << endl;
        }

        cout << endl; // Print a newline for better readability
    }

    return 0;
}
