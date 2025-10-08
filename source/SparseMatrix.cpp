#include "headers/SparseMatrix.h"

SparseMatrix::SparseMatrix() { 
    this -> start = new Node(0, 0, 0);
}
SparseMatrix::~SparseMatrix() { }



void SparseMatrix::add(int value, int xPos, int yPos) {
    Node* head = this -> start;

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

    

    while (auxRow -> right != head && auxRow -> right -> col <= xPos) {
        auxRow = auxRow -> right;
    } //Continues until it finds the column 

    while (auxCol -> down != head && auxCol -> down -> row <= yPos) {
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

    Node* auxCol = head;
    while (auxCol -> right != head && auxCol -> right -> col <= xPos) {
        auxCol = auxCol -> right;
    } //Continues until it finds the column 

    Node* auxRow = head;
    while (auxRow -> down != head && auxRow -> down -> row <= yPos) {
        auxRow = auxRow -> down;
    } //Continues until it finds the row

     while (auxRow -> right != head && auxRow -> right -> col <= xPos) {
        auxRow = auxRow -> right;
    } //Continues until it finds the column 

    while (auxCol -> down != head && auxCol -> down -> row <= yPos) {
        auxCol = auxCol -> down;
    } //Continues until it finds the row

    if (auxCol -> row == yPos && auxRow -> col == xPos) return auxCol -> value;


    return 0;
}
        
void SparseMatrix::remove(int xPos, int yPos){

}

void SparseMatrix::printStoredValues(){

}

int SparseMatrix::density(){
    return 0;
}

SparseMatrix* SparseMatrix::multiply(SparseMatrix* second){
    return nullptr;
}