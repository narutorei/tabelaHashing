/*
* @Author: Reinaldo Antonio Camargo Rauch
* @Date:   2014-10-08 19:25:07
* @Last Modified by:   Reinaldo Antonio Camargo Rauch
* @Last Modified time: 2014-10-08 20:19:08
*/

#include <stdio.h>
#include <stdlib.h>

#define TAM 10

#define SEARCHES 10000000

#define EMPTY -1


struct node {
    int val;
    struct node *next;
};

typedef struct node t_node;

/**
 * Array global
 */
t_node *array[TAM];

int comp = 0;

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

    int pHash = hash(val);

    t_node *here = array[pHash],
        *before = NULL,
        *newItem = createNode(val);

    while(here != NULL) {
        before = here;
        here = here->next;
    }

    if(before == NULL)
        array[pHash] = newItem;
    else
        before->next = newItem;

}

/**
 * Função de busca na tabela hash
 * @param  val Valor para buscar na tabela hash
 * @return     índice no vetor
 */
int search(int val) {

    int pHash = hash(val);

    t_node *here = array[pHash],
        *before = NULL;

    while(here != NULL) {
        comp++;
        if(here->val == val) {
            // puts("Achou");
            return;
        } else {
            before = here;
            here = here->next;
        }
    }

    // puts("Não achou");

}

/**
 * main function
 * @return SUCCESS
 */
int main() {

    int i;

    puts("Reseting array");

    reset();

    srand(time(NULL));

    puts("Inserting in array");

    for(i = 0; i < 5; i++)
        insert(rand());

    puts("Running searches");

   for (i = 0; i < SEARCHES; i++)
        search(rand());
    printf("Comparações %d\n", comp);
    printf("Média de comparações: %10.10f\n", (double) comp / (double) SEARCHES);

    return 0;
}