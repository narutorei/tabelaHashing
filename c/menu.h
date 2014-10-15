/**
 * Lib de menu simples para programas cmd
 */

// Include guard
#ifndef H_MENU
#define H_MENU 1
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

/**
 * Força a parada do programa com uma entrada de teclado e limpa o buffer após
 */
void stopOnChar() {

    getchar();

    fflush(stdin);
    __fpurge(stdin);


}

/**
 * Retorna uma opção do menu, a qual pode ser um caractere de "0" à "9"
 * @return a opção selecionada
 */
char getOption() {

    char op;

    puts("\tSelecione uma opção:\n");

    do {
        op = getchar();
    } while((op != '\n') && ((int) op < 48 || (int) op > 57));

    // Dá flush na stream de maneira padrão
    fflush(stdin);

    // Dá flush na stream de maneira unix
    __fpurge(stdin);

    return op;

}


#endif /* H_MENU */