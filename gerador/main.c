#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *arquivoEntrada;

    // Abre o arquivo de entrada para leitura
    arquivoEntrada = fopen("../dados.txt", "r");
    if (arquivoEntrada == NULL) {
        printf("Não foi possível abrir o arquivo de entrada.\n");
        return 1;
    }

    char linha[100]; // Tamanho máximo de cada linha no arquivo de entrada
    char *dadosDoArquivo = NULL; // Ponteiro para armazenar os dados do arquivo
    size_t tamanho = 0;

    // Lê o arquivo linha por linha e armazena na variável 'dadosDoArquivo'
    while (fgets(linha, sizeof(linha), arquivoEntrada) != NULL) {
        size_t tamanhoLinha = strlen(linha);
        char *temp = realloc(dadosDoArquivo, tamanho + tamanhoLinha + 1); // Aloca memória suficiente para a linha atual
        if (temp == NULL) {
            free(dadosDoArquivo);
            printf("Erro de alocação de memória.\n");
            return 1;
        }
        dadosDoArquivo = temp;
        strcat(dadosDoArquivo + tamanho, linha); // Concatena a linha no buffer de dados
        tamanho += tamanhoLinha;
    }

    // Fecha o arquivo de entrada
    fclose(arquivoEntrada);

    // Exibe os dados lidos do arquivo
    if (dadosDoArquivo != NULL) {
        printf("Conteudo do arquivo:\n%s", dadosDoArquivo);

        free(dadosDoArquivo); // Libera a memória alocada dinamicamente
    }

    return 0;
}
