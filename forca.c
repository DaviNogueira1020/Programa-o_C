#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>


void forca(int estado){
	if(estado==0){
		printf("\n------------");
		printf("\n|          |");
		printf("\n|");
		printf("\n|");
		printf("\n|");
		printf("\n|");
		printf("\n|");
		printf("\n-");
	} else if(estado==1){
		printf("\n------------");
		printf("\n|          |");
		printf("\n|          O");
		printf("\n|");
		printf("\n|");
		printf("\n|");
		printf("\n|");
		printf("\n-");
	} else if(estado==2){
		printf("\n------------");
		printf("\n|          |");
		printf("\n|          O");
		printf("\n|          |");
		printf("\n|");
		printf("\n|");
		printf("\n|");
		printf("\n-");
	} else if(estado==3){
		printf("\n------------");
		printf("\n|          |");
		printf("\n|          O");
		printf("\n|         -|");
		printf("\n|");
		printf("\n|");
		printf("\n|");
		printf("\n-");
	} else if(estado==4){
		printf("\n------------");
		printf("\n|          |");
		printf("\n|          O");
		printf("\n|         -|-");
		printf("\n|");
		printf("\n|");
		printf("\n|");
		printf("\n-");
	} else if(estado==5){
		printf("\n------------");
		printf("\n|          |");
		printf("\n|          O");
		printf("\n|         -|-");
		printf("\n|         /");
		printf("\n|");
		printf("\n|");
		printf("\n-");
	} else if(estado==6){
		printf("\n------------");
		printf("\n|          |");
		printf("\n|          O");
		printf("\n|         -|-");
		printf("\n|         / \\");
		printf("\n|");
		printf("\n|   Perdeu o jogo");
		printf("\n-");
        exit(0);
	}
}

int main(){
    int erros = 0;
    char palavra_secreta[30];
    char *palavras[10] = {"abacaxi", "banana", "cachorro", "dinossauro", "elefante", "foca", "girafa", "hipopotamo", "iguana", "jacare"};
     
     srand(time(NULL));
      int index = rand() % 10;
      strcpy(palavra_secreta, palavras[index]);

	setlocale(0, "portuguese");
	
    printf("Jogando \n");
    printf("Palavra secreta: %s\n", palavra_secreta);
    printf("A palavra tem %lu caracteres\n", strlen(palavra_secreta));

    for(int i=0; i<30; i++){
    	printf("\n");
	}
	
	char palavra_tela[30];
	strcpy(palavra_tela, palavra_secreta);
	
	palavra_tela[strlen(palavra_tela)]='\0';
	for(int i =0; i < strlen(palavra_tela); i++){
		palavra_tela[i]='_';
	}
	
	while(1){
		forca(erros);
		printf("\n Adivinhe: ");
		for(int i = 0; i < strlen(palavra_tela); i++){
			printf("%c", palavra_tela[i]);
		}
		
		printf("\n Letra: ");
		char letra;
		scanf(" %c", &letra);
		
		int sera_que_errou=1;
		for(int i = 0; i < strlen(palavra_tela); i++){
			if(letra==palavra_secreta[i]){
				palavra_tela[i]=letra;
				sera_que_errou=0;
			}
		}
		if(sera_que_errou==1){
			erros++;
		}

        if(strcmp(palavra_tela, palavra_secreta) == 0) {
            printf("\nParabéns! Você adivinhou a palavra: %s\n", palavra_secreta);
            break;
        }
		
		if(erros >= 6) {
            printf("\nVocê perdeu! A palavra era: %s\n", palavra_secreta);
            break;
        }
	}
}