#include <stdio.h>
#include <string.h>

int main() {
    FILE *arquivoEntrada, *arquivoSaida;
    char linha[100]; // Tamanho máximo de cada linha no arquivo de entrada

    // Abre o arquivo de entrada para leitura
    arquivoEntrada = fopen("../dados.txt", "r");
    if (arquivoEntrada == NULL) {
        printf("Não foi possível abrir o arquivo de entrada.\n");
        return 1;
    }

    // Abre o arquivo de saída para escrita binária
    arquivoSaida = fopen("../saida.bin", "wb");
    if (arquivoSaida == NULL) {
        printf("Não foi possível criar o arquivo de saída.\n");
        fclose(arquivoEntrada);
        return 1;
    }

    // Lê linha por linha do arquivo de entrada e escreve no arquivo de saída binário
    while (fgets(linha, sizeof(linha), arquivoEntrada) != NULL) {
        // Remove o caractere de nova linha, se presente
        linha[strcspn(linha, "\n")] = 0;

        // Escreve a linha no arquivo de saída como dados binários
        fwrite(linha, sizeof(char), strlen(linha), arquivoSaida);
    }

    // Fecha os arquivos
    fclose(arquivoEntrada);
    fclose(arquivoSaida);

    printf("As informações foram salvas com sucesso no arquivo de saída (saida.bin).\n");

    return 0;
}