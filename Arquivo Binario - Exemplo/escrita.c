#include <stdio.h>  // Inclui a biblioteca padrão de entrada e saída em C.

int main() {
    char ch = 'z';  // Declara uma variável do tipo char e atribui o valor 'Z' a ela.

    FILE* arq = fopen("teste.bin", "wb");  // Abre um arquivo chamado "teste.bin" no modo de escrita binária ("wb").

    fwrite(&ch, 1, 1, arq);  // Escreve o conteúdo da variável 'ch' no arquivo aberto. 
                            // O primeiro argumento é o endereço de 'ch', o segundo é o tamanho de cada elemento a ser escrito (1 byte no caso de um char),
                            // o terceiro é o número de elementos (1, já que escrevemos apenas um caractere) e o quarto é o ponteiro para o arquivo.

    fclose(arq);  // Fecha o arquivo previamente aberto.

    return 0;  // Retorna 0 para indicar que o programa foi executado sem erros.
}
