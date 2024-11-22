#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char nome[50];
    int pontuacaoTotal;
} Jogador;

void salvarPontuacao(Jogador jogador, int pontos, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "a");
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
    int pontos = 100 - (erros * 25);
    if (pontos < 0) pontos = 0;

    printf("Você teve %d pontos.\n", pontos);
    salvarPontuacao(jogador, pontos, nomeArquivo);
}

void forca(int estado, int jogador) {
    if (jogador == 1) {
        printf("\n------------");
        printf("\n|          |");
    } else {
        printf("\n------------");
        printf("\n|          |");
    }

    if (estado == 0) {
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n-");
    } else if (estado == 1) {
        printf("\n|          O");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n-");
    } else if (estado == 2) {
        printf("\n|          O");
        printf("\n|          |");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n-");
    } else if (estado == 3) {
        printf("\n|          O");
        printf("\n|         -|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n-");
    } else if (estado == 4) {
        printf("\n|          O");
        printf("\n|         -|-");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n-");
    } else if (estado == 5) {
        printf("\n|          O");
        printf("\n|         -|-");
        printf("\n|         /");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n-");
    } else if (estado == 6) {
        printf("\n|          O");
        printf("\n|         -|-");
        printf("\n|         / \\");
        printf("\n|");
        printf("\n|   Perdeu o jogo");
        printf("\n-");
    }
}

char adivinhar_computador(char palavra[], char palavra_tela[]) {
    char letra;
    int i;
    int tentada = 0;

    do {
        letra = 'a' + rand() % 26;
        tentada = 0;
        for (i = 0; i < strlen(palavra_tela); i++) {
            if (palavra_tela[i] == letra) {
                tentada = 1;
                break;
            }
        }
    } while (tentada);

    return letra;
}

void mostrarRanking(Jogador jogador) {
    FILE *arquivo = fopen("pontuacoes.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura!\n");
        return;
    }

    char nome[50];
    int pontos;
    int rank = 1;
    jogador.pontuacaoTotal = 0;
    while (fscanf(arquivo, "%s %d", nome, &pontos) != EOF) {
        if (strcmp(nome, jogador.nome) == 0) {
            jogador.pontuacaoTotal += pontos;
        }
    }
    fclose(arquivo);

    printf("Sua pontuação total é: %d pontos\n", jogador.pontuacaoTotal);
    printf("Você está na posição %d no ranking.\n", rank);
}

void jogando(Jogador *jogador) {
    setlocale(LC_ALL, "Portuguese");

    int erros_jogador1 = 0;
    int erros_jogador2 = 0;
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
        forca(erros_jogador1, 1);
        forca(erros_jogador2, 2);
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
            erros_jogador1++;
        }

        if (strcmp(palavra_tela, palavra_secreta) == 0) {
            printf("\nParabéns! Você adivinhou a palavra: %s\n", palavra_secreta);
            mostraPontuacao(*jogador, erros_jogador1);
            mostrarRanking(*jogador);
            return;
        }

        if (erros_jogador1 >= 6) {
            printf("\nVocê perdeu! A palavra era: %s\n", palavra_secreta);
            mostraPontuacao(*jogador, erros_jogador1);
            mostrarRanking(*jogador);
            return;
        }

        if (strcmp(palavra_tela, palavra_secreta) != 0) {
            char letra_computador = adivinhar_computador(palavra_secreta, palavra_tela);
            printf("\n(PC) Alex escolheu a letra: %c\n", letra_computador);

            int computador_errou = 1;
            for (int i = 0; i < strlen(palavra_tela); i++) {
                if (letra_computador == palavra_secreta[i]) {
                    palavra_tela[i] = letra_computador;
                    computador_errou = 0;
                }
            }
            if (computador_errou) {
                erros_jogador2++;
            }

            if (strcmp(palavra_tela, palavra_secreta) == 0) {
                printf("\n Alex venceu! A palavra era: %s\n", palavra_secreta);
                mostraPontuacao(*jogador, erros_jogador2);
                mostrarRanking(*jogador);
                return;
            }
        }
    }
}

int main() {
    Jogador jogador;
    jogador.pontuacaoTotal = 0;

    printf("Digite seu nome: ");
    scanf("%s", jogador.nome);

    jogando(&jogador);

    return 0;
}
