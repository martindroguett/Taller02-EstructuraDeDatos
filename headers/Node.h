#pragma once

class Node {

    public:
        Node();
        Node(int r, int c, int v);

        int row;
        int col;
        int value;
        Node* right;
        Node* down;
        
        void setRow(int r);
        void setCol(int c);
        void setValue(int v);
        void setText(Node* n);

        ~Node();

};