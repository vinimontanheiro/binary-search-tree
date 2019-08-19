#ifndef BSTREE_H
#define BSTREE_H

#include"node.h"
#include"comparator.h"

class BSTree
{
public:
    Node *root;
    Validator validator;
    BSTree();
    void add(Node **root, int item);
    Node* search(Node **root, int item);
    static Node *moreThenRight(Node **pto);
    static Node *lessThenLeft(Node **pto);
    void remove(Node **root,int item);
    int height(Node *root);
    void show(Node *root);
};

#endif // BSTREE_H

