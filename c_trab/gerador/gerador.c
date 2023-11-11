//includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//include: liga com o arquivo.h
#include "gerador.h"


// declaração de funções usadas na main
dados* AlocacaoDeMemoria(char nome[], int cpf);
dados* OrdemAlfabetica(dados *head, dados *novo);
void liberaMemoria(dados *head);
void arquivoBinario(dados *head, const char *nomeArquivo);


//função principal
int main(int argc, char *argv[]) {
    //verificação dos argumentos de entrada
    if (argc < 2) {
        fprintf(stderr, "Arquivo: %s gerador.txt\n", argv[0]);
        return 1;
    }

    FILE *arquivoTexto;
    dados *head = NULL;
    char nome[50];
    int cpf;

    //abre arquivo txt
    arquivoTexto = fopen(argv[1], "r");
    if (arquivoTexto == NULL) {
        perror("Não foi possível ler o arquivo gerador.txt");
        return 1;
    }

    //lê aquivo txt e cria uma lista encadeada
    while (fscanf(arquivoTexto, "%49s %d", nome, &cpf) == 2) {
        dados *novo = AlocacaoDeMemoria(nome, cpf);
        head = OrdemAlfabetica(head, novo);
    }

    fclose(arquivoTexto);

    //chama a função que escreve a lista encadeado em bin
    arquivoBinario(head, "gerador.bin");

    //chama a função que libera a memória
    liberaMemoria(head);

    return 0;
}

// função para criar um novo nó para uma lista encadeada
dados* AlocacaoDeMemoria(char nome[], int cpf) {
    //alocação dinâmica - malloc - o ponteiro novo aponta para a memória recém alocada
    dados *novo = (dados *)malloc(sizeof(dados));
    if (novo != NULL) {
        strcpy(novo->nome, nome);
        novo->cpf = cpf;
        novo->proximo = NULL;
    }
    return novo;
}

// função para inserir um novo nó na lista encadeada em ordem alfabética
dados* OrdemAlfabetica(dados *head, dados *novo) {
    dados *atual = head, *anterior = NULL;

    //percorre a lista enquanto não chega ao final
    while (atual != NULL && strcmp(atual->nome, novo->nome) < 0) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (anterior == NULL) {
        novo->proximo = head;
        head = novo;
    } else {
        novo->proximo = atual;
        anterior->proximo = novo;
    }

    return head;
}

// função para escrever no arquivo bin
void arquivoBinario(dados *head, const char *nomeArquivo) {
    FILE *arquivoBinario = fopen(nomeArquivo, "wb");

    if (arquivoBinario == NULL) {
        perror("Erro ao abrir o aquivo bin");
        exit(1);
    }

    dados *atual = head;
    while (atual != NULL) {
        fwrite(atual, sizeof(dados), 1, arquivoBinario);
        atual = atual->proximo;
    }

    fclose(arquivoBinario);
}

// função para liberar memoria alocada
void liberaMemoria(dados *head) {
    dados *atual = head, *anterior;

    while (atual != NULL) {
        anterior = atual;
        atual = atual->proximo;
        free(anterior);
    }
}