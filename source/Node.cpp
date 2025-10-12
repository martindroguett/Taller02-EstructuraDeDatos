#include "../headers/Node.h"

Node::Node() { }
Node::Node(int v, int c, int r) {
    this -> row = r;
    this -> col = c;
    this -> value = v;
    this -> right = this;
    this -> down = this;
}
Node::~Node() { }

