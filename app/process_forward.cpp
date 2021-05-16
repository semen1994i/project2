/**
 * process_forward.c -- реализует обобщенную функцию обработки текста
 */

#include "_text.h"

/**
 * Обрабатывает список, применяя заданную функцию к каждой строке
 *
 * @param txt текст
 * @param process функция-обработчик
 * @returns none
 */
void process_forward(
    text txt,
    void (*process)(int index, char* contents, int cursor, void *data),
    void *data
)
{
    /* Проверяем, имеется ли текст */
    if (txt == NULL || txt->lines->size() == 0) {
        fprintf(stderr, "There are already no any lines in the text!\n");
        return;
    }

    int index = 0;

    for(list<string>::iterator it = txt->lines->begin(); it != txt->lines->end(); it++) {
        int cursor_position = -1;
        if(txt->cursor->line_num == index) {
            cursor_position = txt->cursor->position;
        }
        process(index, (char*) &(*it->c_str()), cursor_position, data);
        index++;
    }
}
