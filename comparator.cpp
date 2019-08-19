#include "comparator.h"

Validator::Validator() { }

/**
 * @description Verifica se o itemA é igual ao itemB
 * @params int, int
 */
bool Validator::equal(int itemA, int itemB) {
    return itemA == itemB;
}

/**
 * @description Verifica se o itemA é menor que o itemB
 * @params int, int
 */
bool Validator::lessThen(int itemA, int itemB) {
    return itemA < itemB;
}

/**
 * @description Verifica se o itemA é maior que o itemB
 * @params int, int
 */
bool Validator::moreThen(int itemA, int itemB) {
    return itemA > itemB;
}

/**
 * @description Verifca qual é maior entro os dois itens
 * @params int, int
 */
int Validator::getMoreThenNodes(int itemA,int itemB){
    return itemA > itemB ? itemA : itemB;
}
