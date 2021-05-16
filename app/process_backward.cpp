/**
 * process_backward.c -- реализует обобщенную функцию обработки текста
 * в обратном порядке следования строк
 */

#include "_text.h"

/**
 * Обрабатывает список, применяя заданную функцию к каждой строке
 *
 * @param txt текст
 * @param process функция-обработчик
 * @returns none
 */
void process_backward(
    text txt,
    void (*process)(int index, char *contents, int cursor, void *data),
    void *data
)
{
    /* Проверяем, имеется ли текст */
    if (txt == NULL || txt->lines->size() == 0) {
        fprintf(stderr, "There are already no any lines in the text!\n");
        return;
    }

    int index = txt->lines->size() - 1;
    int cursor_position = -1;

    for(list<string>::reverse_iterator rit = txt->lines->rbegin(); rit != txt->lines->rend(); rit++)  {
        if(txt->cursor->line_num == index) {
            cursor_position = txt->cursor->position;
        }
        process(index, (char*) &(*rit->c_str()), cursor_position, data);
        index--;
    }
}
