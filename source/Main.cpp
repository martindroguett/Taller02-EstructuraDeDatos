#include "../headers/SparseMatrix.h"
#include <iostream>

using namespace std;

SparseMatrix* mx = new SparseMatrix();

void add() {
    cout << "Enter the value you want to add (Integer > 0)" << endl;
    cout << "> ";
    int value; cin >> value;

    while (value <= 0) {
        cout << "The value is not valid (Integer > 0)" << endl;
        cin >> value;
    }

    cout << "Enter the X-coordinate (Integer > 0)" << endl;
    cout << "> ";
    int x; cin >> x;

    while (x <= 0) {
        cout << "The X-coordinate is not valid (Integer > 0)" << endl;
        cin >> x;
    }

    cout << "Enter the Y-coordinate (Integer > 0)" << endl;
    cout << "> ";
    int y; cin >> y;

    while (y <= 0) {
        cout << "The Y-coordinate is not valid (Integer > 0)" << endl;
        cin >> y;
    }

    mx -> add(value, x, y);
}

void get() {
    cout << "Enter the X-coordinate (Integer > 0)" << endl;
    cout << "> ";
    int x; cin >> x;

    while (x <= 0) {
        cout << "The X-coordinate is not valid (Integer > 0)" << endl;
        cin >> x;
    }

    cout << "Enter the Y-coordinate (Integer > 0)" << endl;
    cout << "> ";
    int y; cin >> y;

    while (y <= 0) {
        cout << "The Y-coordinate is not valid (Integer > 0)" << endl;
        cin >> y;
    }

    cout << "The value in the coordinates (" << x << "," << y << ") is: " << mx -> get(x,  y) << endl;

}

void remove() {
    cout << "Enter the X-coordinate (Integer > 0)" << endl;
    cout << "> ";
    int x; cin >> x;

    while (x <= 0) {
        cout << "The X-coordinate is not valid (Integer > 0)" << endl;
        cin >> x;
    }

    cout << "Enter the Y-coordinate (Integer > 0)" << endl;
    cout << "> ";
    int y; cin >> y;

    while (y <= 0) {
        cout << "The Y-coordinate is not valid (Integer > 0)" << endl;
        cin >> y;
    }

    mx -> remove(x, y);
}

void density() {
    
}

void multiply() {

}

int main() {
    cout << "Welcome to the Sparse Matrix test" << endl;
    cout << "Consideration: " << endl;
    cout << "- The values must be stored starting on the coordinates (1,1)" << endl;
    cout << "this is because the (0,y) and (x,0) are the head rows and columns respectively" << endl << endl;

    int option = 0;

    while (option != 7) {
        cout << "=== Menu ===" << endl;
        cout << "1. Add value" << endl;
        cout << "2. Get value" << endl;
        cout << "3. Remove value" << endl;
        cout << "4. Print stored values" << endl;
        cout << "5. See matrix density" << endl;
        cout << "6. Multiply with another matrix" << endl;
        cout << "7. Exit" << endl;
        cout << "> "; cin >> option;

        if (option == 1) add();
        else if (option == 2) get();
        else if (option == 3) remove();
        else if (option == 4) mx -> printStoredValues();
        else if (option == 5) density();
        else if (option == 6) multiply();
        else if (option == 7) cout << "Goodbye!" << endl;
        else cout << "Please choose a valid option" << endl;
    }

    return 0;
}