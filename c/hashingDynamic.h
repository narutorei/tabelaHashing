/**
 * Lib de hashing com tratamento de colisão por subitens dinâmicos
 */

// Include guard
#ifndef H_HASHDYN
#define H_HASHDYN 1
#pragma once

#define H_HASHDYN_TAM 10

#define H_HASHDYN_EMPTY -1

struct h_hashdyn_node {
    int val;
    struct h_hashdyn_node *next;
};

typedef struct h_hashdyn_node t_h_hashdyn_node;

/**
 * Reseta o vetor
 */
void h_hashdyn_reset(t_h_hashdyn_node *array[]) {
    int i;

    for (i = 0; i < H_HASHDYN_TAM; i++)
        array[i] = NULL;

}
/**
 * Gera o valor hash de um valor
 * @param  val Valor a ser inserido/buscado
 * @return     chave no vetor
 */
int h_hashdyn_hash(int val) {
    return val % H_HASHDYN_TAM;
}

/**
 * Cria um nó na tabela hash
 * @param  val Valor a ser inserido
 * @return     retorna o ponteiro para o novo elemento
 */
t_h_hashdyn_node *h_hashdyn_createNode(int val) {
    t_h_hashdyn_node *item = (t_h_hashdyn_node*) malloc(sizeof(t_h_hashdyn_node));

    item->val = val;
    item->next = NULL;

    return item;
}

/**
 * Função para inserir na tabela hash
 * @param val valor a ser inserido
 */
void h_hashdyn_insert(t_h_hashdyn_node *array[], int val) {

    int pHash = h_hashdyn_hash(val);

    t_h_hashdyn_node *here = array[pHash],
        *before = NULL,
        *newItem = h_hashdyn_createNode(val);

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
t_h_hashdyn_node *h_hashdyn_search(t_h_hashdyn_node *array[], int val) {

    int pHash = h_hashdyn_hash(val);

    t_h_hashdyn_node *here = array[pHash],
        *before = NULL;

    while(here != NULL) {
        if(here->val == val) {
            return here;
        } else {
            before = here;
            here = here->next;
        }
    }

    return NULL;

}

/**
 * Verifica a maior largura necessária para a impressão (eg. maior número de
 *     subelementos)
 * @param  array array para ser lido
 * @return       tamanho verificado
 */
int h_hashdyn_getMaxWidth(t_h_hashdyn_node *array[]) {

    t_h_hashdyn_node *here = NULL;
    int i = 0, width = 0, count = 0;

    for (; i < H_HASHDYN_TAM; i++) {

        if(array[i] != NULL) {
            here = array[i];
            for (count = 1; here->next != NULL; ++count)
                here = here->next;
        }

        if (count > width)
            width = count;

    }

    return width;

}

/**
 * Imprime uma linha divisória dependendo da largura da tabela
 * @param width largura aferida anteriormente
 */
void h_hashdyn_printDiv(int width) {

    int i = 0;

    printf("+----+");

    for (; i < width; i++)
        printf("------------+");

    putchar('\n');

}

/**
 * Imprime uma linha da tabela hash na tela
 * @param node  nó atual
 * @param index índice na tabela
 * @param width largura máxima da tabela
 */
void h_hashdyn_printLine(t_h_hashdyn_node *node, int index, int width) {

    int i = 0;

    printf("| %2d |", index);

    for (; i < width; i++) {
        if(node == NULL)
            printf("            |");
        else {
            printf(" %10d |", node->val);
            node = node->next;
        }
    }

    putchar('\n');

}

/**
 * Imprime a tabela hash na tela
 * @param array tabela a ser impressa
 */
void h_hashdyn_print(t_h_hashdyn_node *array[]) {

    int width = h_hashdyn_getMaxWidth(array), i = 0;

    h_hashdyn_printDiv(width);

    for(; i < H_HASHDYN_TAM; i++) {
        h_hashdyn_printLine(array[i], i, width);
        h_hashdyn_printDiv(width);
    }

}



#endif /* H_HASHDYN */