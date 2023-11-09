#include <stdio.h>
#include <stdlib.h> // Adiciona a biblioteca necessária para malloc e free
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
        // Escreve a linha no arquivo de saída como dados binários
        fwrite(linha, sizeof(char), strlen(linha), arquivoSaida);

        // Detecta a quebra de linha - verifica se o último caractere é uma quebra de linha
        if (linha[strlen(linha) - 1] == '\n') {
            // Executar ação quando encontrar a quebra de linha
            printf("Quebra de linha detectada na linha lida.\n");
        }
    }

    // Fecha os arquivos
    fclose(arquivoEntrada);
    fclose(arquivoSaida);

    printf("As informações foram salvas com sucesso no arquivo de saída (saida.bin).\n");

    // Abre o arquivo de entrada para leitura
    arquivoEntrada = fopen("../dados.txt", "r");
    if (arquivoEntrada == NULL) {
        printf("Não foi possível abrir o arquivo de entrada.\n");
        return 1;
    }

    // Variável para armazenar todos os dados do arquivo
    char *dadosDoArquivo; // Usando ponteiro para char
    size_t tamanhoMaximo = 1000; // Defina o tamanho conforme necessário
    dadosDoArquivo = (char *)malloc(tamanhoMaximo * sizeof(char)); // Aloca dinamicamente memória

    if (dadosDoArquivo == NULL) {
        printf("Erro ao alocar memória para dados do arquivo.\n");
        return 1;
    }

    dadosDoArquivo[0] = '\0'; // Inicializa a string vazia

    // Lê o arquivo linha por linha e armazena na variável 'dadosDoArquivo'
    while (fgets(linha, sizeof(linha), arquivoEntrada) != NULL) {
        // Certifique-se de que há espaço suficiente na memória alocada
        if (strlen(dadosDoArquivo) + strlen(linha) < tamanhoMaximo) {
            strcat(dadosDoArquivo, linha);
        } else {
            printf("Erro: Tamanho máximo excedido ao ler dados do arquivo.\n");
            free(dadosDoArquivo); // Libera a memória alocada antes de sair
            fclose(arquivoEntrada);
            return 1;
        }
    }

    // Fecha o arquivo de entrada
    fclose(arquivoEntrada);

    // Exibe os dados lidos do arquivo
    printf("Conteudo do arquivo:\n%s", dadosDoArquivo);

    // Libera a memória alocada
    free(dadosDoArquivo);
    
    return 0;
}