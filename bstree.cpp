#include "bstree.h"
#include "comparator.h"
#include <queue>
#include <math.h>
#include <iostream>
#include <iomanip>
using namespace std;

BSTree::BSTree(){
    this->root = NULL;
}

/**
 * @description Insere um novo elemento
 * @params Node** , int
 */
void BSTree::add(Node **root, int item) {
    if (!(*root)) {
        *root = new Node(item);
    } else {
        if (this->validator.lessThen((*root)->item, item)) {
            this->add(&(*root)->right, item);

        } else {
            if (this->validator.moreThen((*root)->item, item)) {
                this->add(&(*root)->left, item);
            }
        }
    }
}

/**
 * @description Busca por um elemento
 * @params Node, int
 */
Node* BSTree::search(Node **root, int item) {
    if (!(*root)) {
        cout<<endl;
        cout<<"[ERR]-[O valor não foi encontrado]"<<endl;
        return NULL;
    } else {
        if (this->validator.equal((*root)->item, item)) {
                return *root;
        } else {
            if (this->validator.lessThen((*root)->item, item)) {
                return this->search(&(*root)->right, item);
            } else {
                if (this->validator.moreThen((*root)->item, item)) {
                    return this->search(&(*root)->left, item);
                }
            }
        }
    }
}

/**
 * @description Recupera o menor a esquerda
 * @param Node
 */
Node *BSTree::lessThenLeft(Node **pto) {
    if ((*pto)->left) {
        return lessThenLeft(&(*pto)->left);
    } else {
        Node *aux = *pto;
        if ((*pto)->right) {
            *pto = (*pto)->right;
        } else {
            *pto = NULL;
        }
        return aux;
    }
}

/**
 *@description Recupera o maior a direita
 *  * @param Node
 */
Node *BSTree::moreThenRight(Node **pto) {
    if ((*pto)->right) {
        return moreThenRight(&(*pto)->right);
    } else {
        Node *aux = *pto;
        if ((*pto)->left) {
            *pto = (*pto)->left;
        } else {
            *pto = NULL;
        }
        return aux;
    }
}

/**
 * @description Remove um elemento
 * @params Node, int
 */
void BSTree::remove(Node **root, int item) {

    if (!(*root)) {
        cout <<endl;
        cout << "[ERR]-[Valor não encontrado]" << endl;
        return;
    }else{
        if (this->validator.lessThen((*root)->item, item)) {
            remove(&(*root)->right,item);
        } else {
            if (this->validator.moreThen((*root)->item, item)) {
                remove(&(*root)->left,item);
            } else {
                Node *pto = *root;
                if (!(*root)->left && !(*root)->right) {
                    (*root) = NULL;
                } else {
                    // Possui apenas filhos a direita
                    if (!(*root)->left) {
                        (*root) = (*root)->right;
                        pto->right = NULL;
                    } else {
                        // Possui apenas filhos a esquerda
                        if (!(*root)->right) {
                            (*root) = (*root)->left;
                            pto->left = NULL;
                        }
                        else {
                            //Se não, buscamos o menor da sub árvore a direita
                            pto = lessThenLeft(&(*root)->right);
                            pto->left = (*root)->left;
                            pto->right = (*root)->right;
                            (*root)->left = (*root)->right = NULL;
                            *root = pto;
                        }
                    }
                }

            }
        }
    }
}

/**
 * @description Verifica a altura
 * @param Node
 */
int BSTree::height(Node *root) {
    if (!root || (!root->left && !root->right)) {
        return 1;
    }
    else {
        return 1 + this->validator.getMoreThenNodes(this->height(root->left), this->height(root->right));
    }
}

/**
 * @description Exibe a árvore por level
 * @params Node
 */
void BSTree::show(Node *root) {

    if(!root){
        cout<<"[ERR]-[Impossível imprimir, árvore vazia...]";
        return;
    }else{
        int position;
        deque<Node*> d;
        int height = this->height(root);
        int size = (int)(pow((float)2, height) - 1);
        vector<int> itens(size, -1);
        itens[0] = root->item;
        d.push_back(root);
        string spacing;

        while(!d.empty()){
            Node* current = d.front();
            d.pop_front();

            for(int pos = 0; pos < itens.size(); pos++){
                if(itens[pos] == current->item){
                    position = pos;
                }
            }
            if(current->left){
                itens[2 * position + 1] = current->left->item;
                d.push_back(current->left);
            }
            if(current->right){
                itens[2 * position + 2] = current->right->item;
                d.push_back(current->right);
            }
        }
        for(int i = 0; i < size; i++){
            if(itens[i] != -1){

                if(i== 0){
                    spacing = "       ";
                }else{
                    spacing = " ";
                }

                cout <<spacing<<"[" << setw(4) << itens[i] << "]     ";
            }else{

               cout << "  ";
            }
            if(!((i + 2) & (i + 1))){
                cout << endl;
            }
        }
    }

}






