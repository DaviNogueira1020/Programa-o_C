#include <stdio.h>
#include <locale.h>

void exibirPontuacoes(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r"); // Abre o arquivo no modo leitura
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo ou arquivo não encontrado.\n");
        return;
    }

    printf("\n=== Pontuações Registradas ===\n");
    char nome[50];
    int pontuacao;
    while (fscanf(arquivo, "%s %d", nome, &pontuacao) != EOF) {
        printf("Jogador: %s - Pontuação: %d\n", nome, pontuacao);
    }
    printf("================================\n");

    fclose(arquivo);
}

void rank() {
    setlocale(LC_ALL, "Portuguese");

    const char *nomeArquivo = "pontuacoes.txt";
    exibirPontuacoes(nomeArquivo);

}
