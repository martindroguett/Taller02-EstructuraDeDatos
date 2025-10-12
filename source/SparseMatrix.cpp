#include "../headers/SparseMatrix.h"
#include <iostream>

SparseMatrix::SparseMatrix() { 
    this -> start = new Node(0, 0, 0);
}
SparseMatrix::~SparseMatrix() { }



void SparseMatrix::add(int value, int xPos, int yPos) {
    Node* head = this -> start;

    if (xPos == 0 || yPos == 0) {
        std::cout << "You can't add a value on a head row/column" << std::endl;
        return;
    } 

    Node* auxCol = head;
    while (auxCol -> right != head && auxCol -> right -> col <= xPos) {
        auxCol = auxCol -> right;
    } //Continues until it finds the column 

    if (auxCol -> col != xPos) { //If the column don't exists
        Node* temp = auxCol -> right;
        auxCol -> right = new Node(0, xPos, 0);
        auxCol = auxCol -> right; 
        auxCol -> right = temp;

    }

    Node* auxRow = head;
    while (auxRow -> down != head && auxRow -> down -> row <= yPos) {
        auxRow = auxRow -> down;
    } //Continues until it finds the row

    if (auxRow -> row != yPos) { //If the row don't exists
        Node* temp = auxRow -> down;
        auxRow -> down = new Node(0, 0, yPos);
        auxRow = auxRow -> down;
        auxRow -> down = temp;
    }

    
    Node* tempHeadR = auxRow;
    while (auxRow -> right != tempHeadR && auxRow -> right -> col <= xPos) {
        auxRow = auxRow -> right;
    } //Continues until it finds the column 

    Node* tempHeadC = auxCol;
    while (auxCol -> down != tempHeadC && auxCol -> down -> row <= yPos) {
        auxCol = auxCol -> down;
    } //Continues until it finds the row

    if (auxCol -> row == yPos && auxRow -> col == xPos) auxRow -> value += value; //If the node already exists add to the value
    else {
        Node* newNode = new Node(value, xPos, yPos); //If not it creates a new node
        Node* tempR = auxRow -> right;
        auxRow -> right = newNode;
        newNode -> right = tempR;

        Node* tempC = auxCol -> down;
        auxCol -> down = newNode;
        newNode -> down = tempC;
    }

}

int SparseMatrix::get(int xPos, int yPos) {
    Node* head = this -> start;

    if (xPos == 0 || yPos == 0) {
        std::cout << "The head node of a row/column has no value" << std::endl;
        return 0;
    }

    Node* aux = head;
    while (aux -> right != head && aux -> right -> col <= xPos) {
        aux = aux -> right;
    } //Continues until it finds the column

    if (aux -> col != xPos) return 0; //If it doesn't exists returns 0

    Node* tempHead = aux; //If it found the column it saves the starting node

    while (aux -> down != tempHead && aux -> down -> row <= yPos) {
        aux = aux -> down;
    } //Continues until it finds the row

    if (aux -> row != yPos) return 0; //If it doesn't exists returns 0

    return aux -> value; //If it exists, it means that the node is in the column and row we want
}
        
void SparseMatrix::remove(int xPos, int yPos) { //Ready
    Node* head = this -> start;

    if (xPos == 0 || yPos == 0) {
        std::cout << "You can't remove a head node" << std::endl;
        return;
    }

    Node* auxCol = head;
    while (auxCol -> right != head && auxCol -> right -> col <= xPos) {
        auxCol = auxCol -> right;
    } //Continues until it finds the column 

    if (auxCol -> col != xPos) { //If the column don't exists
        std::cout << "There's no value stored in that position" << std::endl;
        return;
    }

    Node* auxRow = head;
    while (auxRow -> down != head && auxRow -> down -> row <= yPos) {
        auxRow = auxRow -> down;
    } //Continues until it finds the row

    if (auxRow -> row != yPos) { //If the row don't exists
        std::cout << "There's no value stored in that position" << std::endl;
        return;
    }

    Node* prevCol = auxRow; //Now we are gonna move the row to the right
    auxRow = auxRow -> right;
    while (auxRow != prevCol && auxRow -> col < xPos) {
        prevCol = auxRow;
        auxRow = auxRow -> right;
    } //Continues until it finds the column 

    if (auxRow -> col != xPos) {
        std::cout << "There's no value stored in that position" << std::endl;
        return;
    }

    Node* prevRow = auxCol; //Now we are gonna move the column down
    auxCol = auxCol -> down;
    while (auxCol != prevRow && auxCol -> row < yPos) {
        prevRow = auxCol;
        auxCol = auxCol -> down;
    } //Continues until it finds the row

    if (auxCol -> row != yPos) {
        std::cout << "There's no value stored in that position" << std::endl;
        return;
    }

    prevCol -> right = auxRow -> right;
    prevRow -> down = auxCol -> down;

    delete auxCol;
}

void SparseMatrix::printStoredValues() { //Ready!!!!
    Node* head = this -> start;
    Node* aux = head -> down;

    while (aux != head) {
        Node* tempHead = aux -> right;

        while (tempHead != aux) {
            if (tempHead -> value != 0) std::cout << "(" << tempHead -> col << "," << tempHead -> row << ") --> " << tempHead -> value << std::endl;
            tempHead = tempHead -> right;
        }
        aux = aux -> down;
    }
}

int SparseMatrix::density(){
    return 0;
}

SparseMatrix* SparseMatrix::multiply(SparseMatrix* second){
    return nullptr;
}