//Bibliotecas
#include <stdio.h>
#include <locale.h>

//Chamar arquivos
#include "jogar.h"
#include "rank.h"

int main() {
    // Configurar idioma
    setlocale(0, "portuguese");

    // Variaveis
    int escolha;

    // Logica do menu
    while (1) {  // Loop infinito até o usuario escolher "sair"
        printf("\nMENU: \n [1] Jogar\n [2] Rank\n [3] Sair\nEscolha a opção: ");
        scanf("%d", &escolha); // Resposta digitada pelo usuario

        // Logica das opções
        switch (escolha) {
            case 1:
                jogando(); // Chamar a função jogar
                break;
            case 2:{
                    rank(); // Chamar a função rank
                }
                break;
            case 3:
                printf("Saindo...\n"); // Sair do loop
                return 0;
            default:
                printf("Opção invalida. Tente novamente.\n"); // Opção invalida
                break;
        }
    }
}
