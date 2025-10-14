#include "../headers/SparseMatrix.h"
#include <iostream>

SparseMatrix::SparseMatrix() { 
    this -> start = new Node(0, 0, 0);
}
SparseMatrix::~SparseMatrix() { }

void SparseMatrix::add(int value, int xPos, int yPos) { //Ready
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

int SparseMatrix::get(int xPos, int yPos) { //Ready
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

    Node* aux = head; //This aux will be used to remove the row or column headers if they become empty.
    if (prevCol -> right == prevCol) {
        while (aux -> down != prevCol) {
            aux = aux -> down;
        } 
        aux -> down = prevCol -> down;
        delete prevCol;
    }

    aux = head;

    if (prevRow -> down == prevRow) {
        while (aux -> right != prevRow) {
            aux = aux -> right;
        }
        aux -> right = prevRow -> right;
        delete prevRow;
    }

    delete auxCol;
}

void SparseMatrix::printStoredValues() { //Ready
    Node* head = this -> start;
    Node* aux = head -> down;

    while (aux != head) {
        Node* tempHead = aux -> right;

        while (tempHead != aux) {
            std::cout << "(" << tempHead -> col << "," << tempHead -> row << ") --> " << tempHead -> value << std::endl;
            tempHead = tempHead -> right;
        }
        aux = aux -> down;
    }
}

int SparseMatrix::density() { //Ready
    int maxCol = 0;
    int maxRow = 0;
    int count = 0;
    
    Node* head = this -> start;
    Node* aux = head -> down;

    while (aux != head) {
        Node* tempHead = aux -> right;

        while (tempHead != aux) {
            if (tempHead -> row > maxRow) maxRow = tempHead -> row;
            if (tempHead -> col > maxCol) maxCol = tempHead -> col;
            count++;
            tempHead = tempHead -> right;
        }
        aux = aux -> down;
    }

    if (maxCol != 0 && maxRow != 0) {
        std::cout << "Nodes != 0: " << count << std::endl;
        std::cout << "Possible nodes: " << maxCol * maxRow << std::endl;

        return (count * 100/(maxCol * maxRow));
    }
    std::cout << "The matrix is empty" << std::endl;

    return 0;
}

SparseMatrix* SparseMatrix::multiply(SparseMatrix* mx2) { //Ready
    Node* head1 = this -> start;
    Node* aux1 = head1 -> down;

    Node* head2 = mx2 -> start;
    Node* aux2 = nullptr;

    SparseMatrix* newMx = new SparseMatrix();

    while (aux1 != head1) {
        Node* tempHead1 = aux1 -> right;
 
        aux2 = head2 -> right;

        while (tempHead1 != aux1) {
            int finalRow = tempHead1 -> row; //En que fila trabajaremos al final

            int tempRow = tempHead1 -> col; //En que fila debemos iterar sobre la otra matriz

            while (aux2 != head2) {
                int mx1Value = tempHead1 -> value;
                int mx2Value = mx2 -> get(aux2 -> col, tempRow);

                if (mx1Value * mx2Value != 0) newMx -> add(mx1Value * mx2Value, aux2 -> col, finalRow);

                aux2 = aux2 -> right;
            }

            tempHead1 = tempHead1 -> right;
            aux2 = head2 -> right;
        }
        aux1 = aux1 -> down;
    }

    return newMx;
}