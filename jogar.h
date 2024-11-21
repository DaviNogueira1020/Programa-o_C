#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

// Definição do struct para jogador
typedef struct {
    char nome[50];
} Jogador;

void salvarPontuacao(Jogador jogador, int pontos, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "a"); // Abre o arquivo no modo append
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita!\n");
        return;
    }

    fprintf(arquivo, "%s %d\n", jogador.nome, pontos);
    fclose(arquivo);
    printf("Pontuação salva com sucesso!\n");
}

void mostraPontuacao(Jogador jogador, int erros) {
    const char *nomeArquivo = "pontuacoes.txt";

    // Calcular a pontuação (quanto menos erros, maior a pontuação)
    int pontos = 100 - (erros * 25);
    if (pontos < 0) pontos = 0;

    // Exibir a pontuação
    printf("Você teve %d pontos.\n", pontos);

    // Salvar a pontuação no arquivo
    salvarPontuacao(jogador, pontos, nomeArquivo);
}

void forca(int estado) {
    if (estado == 0) {
        printf("\n------------");
        printf("\n|          |");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n-");
    } else if (estado == 1) {
        printf("\n------------");
        printf("\n|          |");
        printf("\n|          O");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n-");
    } else if (estado == 2) {
        printf("\n------------");
        printf("\n|          |");
        printf("\n|          O");
        printf("\n|          |");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n-");
    } else if (estado == 3) {
        printf("\n------------");
        printf("\n|          |");
        printf("\n|          O");
        printf("\n|         -|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n-");
    } else if (estado == 4) {
        printf("\n------------");
        printf("\n|          |");
        printf("\n|          O");
        printf("\n|         -|-");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n-");
    } else if (estado == 5) {
        printf("\n------------");
        printf("\n|          |");
        printf("\n|          O");
        printf("\n|         -|-");
        printf("\n|         /");
        printf("\n|");
        printf("\n|");
        printf("\n-");
    } else if (estado == 6) {
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

void jogando() {
    setlocale(LC_ALL, "Portuguese");

    Jogador jogador;

    // Capturar o nome do jogador
    printf("Digite seu nome: ");
    scanf("%s", jogador.nome);

    int erros = 0;
    char palavra_secreta[30];
    char *palavras[10] = {"abacaxi", "banana", "cachorro", "dinossauro", "elefante", "foca", "girafa", "hipopotamo", "iguana", "jacare"};
    
    srand(time(NULL));
    int index = rand() % 10;
    strcpy(palavra_secreta, palavras[index]);

    printf("Jogando \n");
    printf("A palavra tem %lu caracteres\n", strlen(palavra_secreta));

    char palavra_tela[30];
    strcpy(palavra_tela, palavra_secreta);
    palavra_tela[strlen(palavra_tela)] = '\0';

    for (int i = 0; i < strlen(palavra_tela); i++) {
        palavra_tela[i] = '_';
    }

    while (1) {
        forca(erros);
        printf("\nAdivinhe: ");
        for (int i = 0; i < strlen(palavra_tela); i++) {
            printf("%c", palavra_tela[i]);
        }

        printf("\nLetra: ");
        char letra;
        scanf(" %c", &letra);

        int sera_que_errou = 1;
        for (int i = 0; i < strlen(palavra_tela); i++) {
            if (letra == palavra_secreta[i]) {
                palavra_tela[i] = letra;
                sera_que_errou = 0;
            }
        }
        if (sera_que_errou) {
            erros++;
        }

        if (strcmp(palavra_tela, palavra_secreta) == 0) {
            printf("\nParabéns! Você adivinhou a palavra: %s\n", palavra_secreta);
            mostraPontuacao(jogador, erros);
            break;
        }

        if (erros >= 6) {
            printf("\nVocê perdeu! A palavra era: %s\n", palavra_secreta);
            mostraPontuacao(jogador, erros);
            break;
        }
    }
}
