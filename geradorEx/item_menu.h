#ifndef ITEM_MENU_H
#define ITEM_MENU_H

typedef struct ItemMenu {
    char nome[50];
    float preco;
    struct ItemMenu *proximo;
} ItemMenu;

#endif

