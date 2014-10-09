/*
* @Author: Reinaldo Antonio Camargo Rauch
* @Date:   2014-10-08 19:25:07
* @Last Modified by:   Reinaldo Antonio Camargo Rauch
* @Last Modified time: 2014-10-08 19:47:52
*/

#include <stdio.h>

#define TAM 10

#define EMPTY -1


struct node {
    int val;
    struct no *next;
};

typedef struct no t_node;

/**
 * Array global
 */
t_node *array[TAM];

/**
 * Reseta o vetor
 */
void reset() {
    int i;

    for (i = 0; i < TAM; i++)
        array[i] = NULL;
}

/**
 * Gera o valor hash de um valor
 * @param  val Valor a ser inserido/buscado
 * @return     chave no vetor
 */
int hash(int val) {

    return val % TAM;

}

/**
 * Cria um nó na tabela hash
 * @param  val Valor a ser inserido
 * @return     retorna o ponteiro para o novo elemento
 */
t_node *createNode(int val) {
    t_node *item = (t_node*) malloc(sizeof(t_node));

    item->val = val;
    item->next = NULL;

    return item;
}

/**
 * Função para inserir na tabela hash
 * @param val valor a ser inserido
 */
void insert(int val) {

    int hash = hash(val);

    t_node *here = array[hash],
        *before = NULL,
        *newItem = createNode(val);

    while(here != NULL) {
        before = here;
        here = here->prox;
    }

    if(before == NULL)
        array[hash] = newItem;
    else
        before->next = newItem;

}

/**
 * Função de busca na tabela hash
 * @param  val Valor para buscar na tabela hash
 * @return     índice no vetor
 */
int search(int val) {

    int hash = hash(val), count = 0;

    if(array[hash] == val)
        return hash;
    else {
        while(array[hash = reHash(hash)] != val && (count++ < TAM || array[hash] != EMPTY));

        if(count == TAM - 1 || array[hash] == TAM) {
            puts("Achou");
            return hash;
        }

    }

}

/**
 * main function
 * @return SUCCESS
 */
int main() {

    int i;

    reset();

    srand(time());

    for(i = 0; i < 5; i++)
        insert(rand());




    return 0;
}