//bibliotecas
#include <stdio.h>
#include <string.h>
#include <locale.h>

//chamar arquivos
#include "jogar.h"
#include "rank.h"


int main(){

    // lingua
    setlocale(0, "Portuguese");

    // Variavel
    char escolha[10];
    
    //logica
    while(1) {  // Loop infinito/ escolha "sair" ;)
        printf("Escolha uma opção: jogar, rank, sair\n");//pergunta menu
        scanf("%s", escolha); //resposta  digitado
        
        //logica
        if(strcmp(escolha, "jogar") == 0) { //O strcmp  é paara comparação
            jogar(); //chamando a função jogar
        } else if(strcmp(escolha, "rank") == 0) {
            int resultado = rank(); //chamando a função rank
            printf("O resultado do rank é: %d\n", resultado);
        } else if(strcmp(escolha, "sair") == 0) {
            printf("Saindo...\n"); //saindo do loop menu
            break;
        } else {
            printf("Opção invalida. Tente novamente.\n"); //digitou algo invalido
        }
    }
}
