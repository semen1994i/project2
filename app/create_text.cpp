/**
 * create_text.c -- создает в памяти структуры для представления текста
 */

#include "_text.h"

/**
 * Создает новый текстовый объект
 * @returns текст
 */
text create_text()
{
    text txt = new _list;
    txt->lines = new list<string>;

    /* Создаем структуру описания текста */
    if (txt == NULL) {
        fprintf(stderr, "Not enough memory!\n");
        exit(EXIT_FAILURE);
    }

    /* Создаем структуру описания курсора */
    txt->cursor = new _crsr;
    if (txt->cursor == NULL) {
        fprintf(stderr, "Not enough memory!\n");
        exit(EXIT_FAILURE);
    }

    txt->cursor->position = 0;
    txt->cursor->line_num = txt->lines->size() - 1;
    return txt;
}
