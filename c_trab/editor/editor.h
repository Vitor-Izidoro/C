//#indef - verifica se já foi definido anteriormente
#ifndef editor_h
#define editor_h


//estrutura de dados - armazenamento de nome e cpf
typedef struct dados {
    char nome[30];
    int cpf; 
    struct dados *proximo;
} dados;

#endif