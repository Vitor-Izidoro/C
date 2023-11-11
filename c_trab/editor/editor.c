// includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// include: liga com o arquivo.h
#include "editor.h"  

// Definição da estrutura de dados
typedef struct No {
    dados dado;
    struct No *prox;
} No;

// Função para inserir um novo elemento na lista
No *inserir(No *lista, dados novoRegistro) {
    No *novoNo = (No *)malloc(sizeof(No));
    if (!novoNo) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }

    novoNo->dado = novoRegistro;
    novoNo->prox = lista;

    return novoNo;
}

// Função para remover um elemento da lista com base na chave
No *remover(No *lista, int chave) {
    No *atual = lista;
    No *anterior = NULL;

    while (atual != NULL && atual->dado.cpf != chave) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Elemento com chave %d não encontrado.\n", chave);
        return lista;
    }

    if (anterior == NULL) {
        lista = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    free(atual);
    printf("Elemento com chave %d removido com sucesso.\n", chave);
    return lista;
}

// Função para exibir os dados de um elemento com base na chave
void exibirElemento(No *lista, int chave) {
    No *atual = lista;

    while (atual != NULL && atual->dado.cpf != chave) {
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Elemento com chave %d não encontrado.\n", chave);
    } else {
        printf("Nome: %s\n", atual->dado.nome);
        printf("CPF: %d\n", atual->dado.cpf);
        // Exibir outros campos conforme necessário
    }
}

// Função para exibir todos os elementos da lista
void exibirLista(No *lista) {
    No *atual = lista;

    while (atual != NULL) {
        printf("Nome: %s\n", atual->dado.nome);
        printf("CPF: %d\n", atual->dado.cpf);
        // Exibir outros campos conforme necessário
        atual = atual->prox;
    }
}

// Função para liberar a memória alocada para a lista
void liberarMemoria(No *lista) {
    No *atual = lista;
    No *proximo;

    while (atual != NULL) {
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
}

int main() {
    No *lista = NULL;
    char nomeArquivo[] = "editor.bin";

    // Leitura dos dados do arquivo binário
    FILE *arquivoLeitura = fopen("editor.bin", "r");
    if (arquivoLeitura == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo %s.\n", nomeArquivo);
        exit(EXIT_FAILURE);
    }

    dados temp;
    while (fread(&temp, sizeof(dados), 1, arquivoLeitura) == 1) {
        lista = inserir(lista, temp);
    }

    fclose(arquivoLeitura);

    // Interagir com o usuário
    int opcao;
    do {
        printf("\n1. Inserir novo elemento\n");
        printf("2. Remover elemento\n");
        printf("3. Exibir elemento\n");
        printf("4. Exibir lista\n");
        printf("5. Encerrar\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Informe o nome do novo elemento: ");
                scanf("%s", temp.nome);
                printf("Informe o CPF do novo elemento: ");
                scanf("%d", &temp.cpf);
                lista = inserir(lista, temp);
                break;
            case 2:
                printf("Informe o CPF do elemento a ser removido: ");
                scanf("%d", &temp.cpf);
                lista = remover(lista, temp.cpf);
                break;
            case 3:
                printf("Informe o CPF do elemento a ser exibido: ");
                scanf("%d", &temp.cpf);
                exibirElemento(lista, temp.cpf);
                break;
            case 4:
                exibirLista(lista);
                break;
            case 5:
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 5);

    // Gravar os dados atualizados no arquivo binário
    FILE *arquivoEscrita = fopen(nomeArquivo, "w");
    if (arquivoEscrita == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo %s.\n", nomeArquivo);
        exit(EXIT_FAILURE);
    }

    No *atual = lista;
    while (atual != NULL) {
        fwrite(&atual->dado, sizeof(dados), 1, arquivoEscrita);
        atual = atual->prox;
    }

    fclose(arquivoEscrita);

    // Liberar a memória alocada
    liberarMemoria(lista);

    return 0;
}
