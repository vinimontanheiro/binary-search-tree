#include <iostream>
#include <stdlib.h>
#include<string>
using namespace std;

#include "node.h"
#include "bstree.h"

int main() {

   BSTree tree;
   int operacao;

   while(true){
        cout<<endl;
        cout<<"\t[ARVORE DE BUSCA BINARIA]"<<endl;
        cout<<"\n[AÇOES]\n"<<endl;
        cout<<" 0 - INSERIR\n"<<endl;
        cout<<" 1 - REMOVER\n"<<endl;
        cout<<" 2 - BUSCAR\n"<<endl;
        cout<<" 3 - IMPRIMIR\n"<<endl;
        cout<<" 4 - SAIR\n"<<endl;
        cout<<": ";
        cin>>operacao;
        cout<<endl;

        switch (operacao){
            int item;
            case 0:
                 cout<<"\n[Informe o valor]: ";
                 cin>>item;
                 tree.add(&tree.root,item);
                 cout<<endl;
                 break;
            case 1:
                cout<<"\n[Informe o valor a ser removido]: ";
                cin>>item;
                 tree.remove(&tree.root, item);
                 cout<<endl;
                 break;
            case 2:
                cout<<"\n[Informe o valor a ser buscado]: ";
                cin>>item;
                Node *result;
                result = tree.search(&tree.root, item);
                if(result){
                    cout<<endl;
                    cout<<"[O valor "<<result->item<<" foi encontrado]";
                }
                cout<<endl;
                 break;
            case 3:
                  tree.show(tree.root);
                  cout<<endl;
                 break;
            case 4:
                 exit(1);
                 break;
            default:
                cout<<"[ERR]-[Opção inválida]";
                cout<<endl;
                break;
          }

   }
   return 0;
}
