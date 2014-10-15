/**
 * Lib de hashing com tratamento de colisão por rehash
 */

// Include guard
#ifndef H_HASHING
#define H_HASHING 1
#pragma once

#define H_HASHING_TAM 10

#define H_HASHING_EMPTY -1

/**
 * Reseta o vetor
 * @param array vetor que será resetado
 */
void h_hashing_reset(int array[]) {
    int i;

    for (i = 0; i < H_HASHING_TAM; i++)
        array[i] = H_HASHING_EMPTY;
}

/**
 * Gera o valor hash de um valor
 * @param  val Valor a ser inserido/buscado
 * @return     chave no vetor
 */
int h_hashing_hash(int val) {

    return val % H_HASHING_TAM;

}

/**
 * Gera o rehash para caso de colisão
 * @param  oldKey chave anterior
 * @return        nova chave
 */
int h_hashing_reHash(int oldKey) {

    return (oldKey + 1) % H_HASHING_TAM;

}

/**
 * Função para inserir na tabela hash
 * @param array array no qual será inserido o valor
 * @param val   valor a ser inserido
 */
void h_hashing_insert(int array[], int val) {

    int hash = h_hashing_hash(val), count = 0;

    if(array[hash] != H_HASHING_EMPTY) {
        while((array[hash = h_hashing_reHash(hash)] != H_HASHING_EMPTY) && (++count < H_HASHING_TAM));

        if(count == H_HASHING_TAM) {
            puts("Erro de implementação, tabela hash estourou");
            return;
        }

        array[hash] = val;
    } else
        array[hash] = val;

}

/**
 * Função de busca na tabela hash
 * @param array array no qual será buscado o valor
 * @param  val Valor para buscar na tabela hash
 * @return     índice no vetor
 */
int h_hashing_search(int array[], int val) {

    int hash = h_hashing_hash(val), count = 0;

    if(array[hash] == val) {
        return hash;
    } else {
        while((array[hash = h_hashing_reHash(hash)] != val) && (count++ < H_HASHING_TAM));

        if(array[hash] == val)
            return hash;
        else
            return H_HASHING_EMPTY;
    }

}

/**
 * Imprime a tabela hash simples
 * @param array tabela hash
 */
void h_hashing_print(int array[]) {

    int i = 0;

    puts("+----+-----------------+");

    for (; i < H_HASHING_TAM; i++) {
        printf("| %2d | %15d |\n", i, array[i]);
        puts("+----+-----------------+");
    }

}

#endif /* H_HASHING */
