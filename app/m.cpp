/**
 * m.c -- перемещает курсор в новую позицию
 */

#include "_text.h"

int m(const text txt, int line_n, int pos_in_line)
{
    /* Проверяем на наличие строки с данным номером */
    if (line_n < 0) {
        printf("Line numbering starts at 0\n");
        return 0;
    }

    if (line_n > (int) txt->lines->size() - 1) {
        printf("No line with this number\nLast number: %d\n", (int) txt->lines->size() - 1);
        return 0;
    }

    if (pos_in_line < 0) {
        printf("Numbering of positions in a line starts from 0\n");
        return 0;
    }

    list<string>::iterator it = txt->lines->begin();
    advance(it, line_n);

    if ((unsigned int) pos_in_line > it->size() - 1) {
        printf("There is no such position in the line\nLast position: %ld\n", txt->lines->size() - 1);
        return 0;
    }

    /* Новая строка курсора */
    txt->cursor->line_num = line_n;

    /* Новая позиция курсора в строке */
    txt->cursor->position = pos_in_line;

    return 0;
}
