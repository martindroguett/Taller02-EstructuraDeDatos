#include "headers/Node.h"

Node::Node() { }
Node::Node(int r, int c, int v) {
    this -> row = r;
    this -> col = c;
    this -> value = v;
    this -> right = this;
    this -> down = this;
}
Node::~Node() { }

