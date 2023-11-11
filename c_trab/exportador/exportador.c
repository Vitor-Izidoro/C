//includes
#include <stdio.h>
#include <stdlib.h>

//include do arquivo.h
#include "exportador.h" 

// Função para exportar dados para um arquivo texto
void exportarParaTexto(Dado *dados, int numDados, const char *nomeArquivo) {
    FILE *arquivoTexto = fopen(nomeArquivo, "w");

    if (arquivoTexto == NULL) {
        perror("Erro ao abrir o arquivo texto");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < numDados; i++) {
        fprintf(arquivoTexto, "%s %d\n", dados[i].nome, dados[i].cpf);
    }

    fclose(arquivoTexto);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Uso: %s arquivo_binario arquivo_texto\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *nomeArquivoBinario = argv[1];
    const char *nomeArquivoTexto = argv[2];

    // Abrir o arquivo binário para leitura
    FILE *arquivoBinario = fopen(nomeArquivoBinario, "rb");

    if (arquivoBinario == NULL) {
        perror("Erro ao abrir o arquivo binário");
        exit(EXIT_FAILURE);
    }

    // Obter o número de dados no arquivo binário
    fseek(arquivoBinario, 0, SEEK_END);
    long tamanhoArquivo = ftell(arquivoBinario);
    int numDados = tamanhoArquivo / sizeof(Dado);

    // Voltar para o início do arquivo
    rewind(arquivoBinario);

    // Alocar memória para armazenar os dados
    Dado *dados = (Dado *)malloc(numDados * sizeof(Dado));

    if (dados == NULL) {
        perror("Erro de alocação de memória");
        exit(EXIT_FAILURE);
    }

    // Ler dados do arquivo binário
    fread(dados, sizeof(Dado), numDados, arquivoBinario);

    // Fechar o arquivo binário
    fclose(arquivoBinario);

    // Chamar a função para exportar dados para o arquivo texto
    exportarParaTexto(dados, numDados, nomeArquivoTexto);

    // Liberar a memória alocada
    free(dados);

    printf("Exportação concluída com sucesso!\n");

    return 0;
}
