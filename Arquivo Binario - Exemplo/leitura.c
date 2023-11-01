#include <stdio.h> // Inclui a biblioteca padrão de entrada e saída em C.

int main() { // Início da função principal.

    char ch; // Declaração da variável 'ch' do tipo char, que será usada para armazenar o caractere lido do arquivo.

    FILE* arq = fopen("teste.bin", "rb"); // Abre o arquivo "teste.bin" em modo de leitura binária ("rb") e atribui o ponteiro do arquivo a 'arq'.

    fread(&ch, 1, 1, arq); // Utiliza a função 'fread' para ler 1 byte do arquivo aberto 'arq' e armazena esse byte na variável 'ch'.
                           // O primeiro argumento é o endereço onde os dados lidos serão armazenados (neste caso, o endereço de 'ch').
                           // O segundo argumento é o tamanho de cada elemento a ser lido (1 byte).
                           // O terceiro argumento é a quantidade de elementos a ser lida (1, pois estamos lendo apenas um byte).
                           // O quarto argumento é o ponteiro para o arquivo a ser lido.

    fclose(arq); // Fecha o arquivo 'arq' que foi aberto anteriormente.

    printf("ch = %c\n", ch); // Imprime na tela o valor lido do arquivo 'teste.bin' no formato de caractere.

    return 0; // Retorna 0 para indicar que o programa foi executado sem erros.
}
