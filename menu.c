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
        printf("Escolha uma op��o: jogar, rank, sair\n");//pergunta menu
        scanf("%s", escolha); //resposta  digitado
        
        //logica
        if(strcmp(escolha, "jogar") == 0) { //O strcmp  � paara compara��o
            jogar(); //chamando a fun��o jogar
        } else if(strcmp(escolha, "rank") == 0) {
            int resultado = rank(); //chamando a fun��o rank
            printf("O resultado do rank �: %d\n", resultado);
        } else if(strcmp(escolha, "sair") == 0) {
            printf("Saindo...\n"); //saindo do loop menu
            break;
        } else {
            printf("Op��o invalida. Tente novamente.\n"); //digitou algo invalido
        }
    }
}
