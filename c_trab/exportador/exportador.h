#ifndef EXPORTADOR_H
#define EXPORTADOR_H

// Estrutura para armazenar os dados
typedef struct {
    char nome[50];
    int cpf;
} Dado;

// Função para exportar dados para um arquivo texto
void exportarParaTexto(Dado *dados, int numDados, const char *nomeArquivo);

#endif 
