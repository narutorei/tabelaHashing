/*
* @Author: Reinaldo Antonio Camargo Rauch
* @Date:   2014-10-15 13:25:17
* @Last Modified by:   Reinaldo Antonio Camargo Rauch
* @Last Modified time: 2014-10-15 16:53:16
*/

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

// lib de menu
#include "menu.h"

// Lib de hashing com tratamento de colisão por rehash
#include "hashing.h"

// Lib de hashing com tratamento de colisão por subitens dinâmicos
#include "hashingDynamic.h"

/**
 * tabela hash simples global
 */
int hashtable[H_HASHING_TAM];

/**
 * Tabela hash dinamica global
 */
t_h_hashdyn_node *hashDynTable[H_HASHDYN_TAM];

/**
 * Imprime o menu do programa na tela
 */
void menu() {

    puts("|  Menu:                                      |");
    puts("+---------------------------------------------+");
    puts("|  0: Inserir valor na tabela hash            |");
    puts("|  1: Procurar valor na tabela hash           |");
    puts("|  2: Listar tabela hash                      |");
    puts("|  3: Inserir valor na tabela hash dinâmica   |");
    puts("|  4: Procurar valor na tabela hash dinâmica  |");
    puts("|  5: Listar tabela hash dinâmica             |");
    puts("|  6: Resetar tabela hash                     |");
    puts("|  7: Resetar tabela hash dinâmica            |");
    puts("+---------------------------------------------+");

}

/**
 * Printa o header do programa na tela
 * @param withMenu se é para imprimir o menu junto ou não
 */
void header(int withMenu) {

    system("clear");

    puts("+------------------------------------------------------+");
    puts("|  Programa para teste de implementação de hash table  |");

    if(withMenu) {
        puts("+---------------------------------------------+--------+");
        menu();
    } else
        puts("+------------------------------------------------------+");

    puts("\n");

}

/**
 * Opção para inserir na tabela hash simples
 */
void insertHashOption() {

    int val = 0;

    header(0);

    puts("Digite um valor para ser inserido na tabela hash:");

    scanf("%d", &val);

    fflush(stdin);
    __fpurge(stdin);

    h_hashing_insert(hashtable, val);

    puts("Valor inserido com sucesso");

}

/**
 * Ação da opção no menu para procurar o valor na tabela hash
 */
void searchHashOption() {

    int val = 0;

    header(0);

    puts("Digite o um valor para ser procurado na tabela hash:");

    scanf("%d", &val);

    fflush(stdin);
    __fpurge(stdin);

    if(h_hashing_search(hashtable, val) != H_HASHING_EMPTY)
        puts("Encontrado");
    else
        puts("Valor não encontrado");

}

/**
 * Opção para imprimir a tabela hash simples
 */
void printHashOption() {

    header(0);

    puts("Tabela hash:\n");

    h_hashing_print(hashtable);

}

/**
 * Opção para resetar a tabela hash simples
 */
void resetHashOption() {

    header(0);

    puts("Tem certeza que deseja limpar a tabela hash? (1: Sim, 0: Não):");

    if(getOption() == '1') {
        h_hashing_reset(hashtable);
        puts("Tabela hash resetada com sucesso");
    } else
        puts("Tabela inalterada");

}

/**
 * Opção para inserir um valor na tabela hash dinâmica
 */
void insertHashDynOption() {

    int val = 0;

    header(0);

    puts("Digite um valor para ser inserido na tabela hash dinâmica:");

    scanf("%d", &val);

    fflush(stdin);
    __fpurge(stdin);

    h_hashdyn_insert(hashDynTable, val);

    puts("Valor inserido com sucesso");

}

/**
 * Opção para procurar um valor na tabela hash dinâmica
 */
void searchHashDynOption() {

    int val = 0;

    header(0);

    puts("Digite o um valor para ser procurado na tabela hash dinâmica:");

    scanf("%d", &val);

    fflush(stdin);
    __fpurge(stdin);

    if(h_hashdyn_search(hashDynTable, val) != NULL)
        puts("Encontrado");
    else
        puts("Valor não encontrado");

}

/**
 * Opção para imprimir a tabela hash dinâmica na tela
 */
void printHashDynOption() {

    header(0);

    puts("Tabela hash dinâmica:\n");

    h_hashdyn_print(hashDynTable);

}

/**
 * Opção para resetar a tabela hash dinâmica
 */
void resetHashDynOption() {

    header(0);

    puts("Tem certeza que deseja limpar a tabela hash dinâmica? (1: Sim, 0: Não):");

    if(getOption() == '1') {
        h_hashdyn_reset(hashDynTable);
        puts("Tabela hash dinâmica resetada com sucesso");
    } else
        puts("Tabela inalterada");

}

/**
 * Função de inicialização do programa
 */
void onProgramInit() {

    h_hashing_reset(hashtable);
    h_hashdyn_reset(hashDynTable);

}

/**
 * main function
 * @return success
 */
int main() {

    onProgramInit();

    while (1) {

        header(1);

        switch(getOption()) {

            case '0':
                insertHashOption();
                break;
            case '1':
                searchHashOption();
                break;
            case '2':
                printHashOption();
                break;
            case '3':
                insertHashDynOption();
                break;
            case '4':
                searchHashDynOption();
                break;
            case '5':
                printHashDynOption();
                break;
            case '6':
                resetHashOption();
                break;
            case '7':
                resetHashDynOption();
                break;
            default:
                puts("Opção inválida, tente novamente");
                break;

        }

        puts("\nAperte qualquer tecla para continuar");
        stopOnChar();

    }

    return 0;
}