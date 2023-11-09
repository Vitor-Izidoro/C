#include "item_menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Arquivo utilizado: %s itens-menu.txt\n", argv[0]);
        return 1;
    }

    FILE *arquivoTexto, *arquivoBinario;
    ItemMenu *cabeca = NULL, *atual, *anterior, *novo;
    char linha[100];
    char nome[50];
    float preco;

    
    arquivoTexto = fopen(argv[1], "r");            
    if (arquivoTexto == NULL) {                  
        perror("LINHA21: Erro ao abrir o arquivo de texto");
        return 1;
    }
    
    
    while (fgets(linha, sizeof(linha), arquivoTexto)) {
        novo = (ItemMenu *)malloc(sizeof(ItemMenu));               
        if (sscanf(linha, "%49[^0-9] %f", nome, &preco) == 2) {       
            strcpy(novo->nome, nome);
            novo->preco = preco;
            novo->proximo = NULL;

            
            atual = cabeca;
            anterior = NULL;
            while (atual != NULL && strcmp(atual->nome, novo->nome) < 0) {
                anterior = atual;
                atual = atual->proximo;
            }
            if (anterior == NULL) {
                novo->proximo = cabeca;
                cabeca = novo;
            } else {
                novo->proximo = atual;
                anterior->proximo = novo;
            }
        } else {
            free(novo);
        }
    }

    fclose(arquivoTexto);
    
    arquivoBinario = fopen("itens_menu.bin", "wb");
    if (arquivoBinario == NULL) {
        perror("LINHA56: Erro ao abrir o arquivo binário");        //test 1
        return 1;
    }
    
    
    atual = cabeca;
    while (atual != NULL) {                // um loop while p gravarr a lista encadeada no arquivo binário
        fwrite(atual, sizeof(ItemMenu), 1, arquivoBinario);
        atual = atual->proximo;
    }
    
    fclose(arquivoBinario);

    
    atual = cabeca;                                    // loop while p libera a memória da lista encadeada
    while (atual != NULL) {
        anterior = atual;
        atual = atual->proximo;
        free(anterior);
    }
    
    return 0;
}