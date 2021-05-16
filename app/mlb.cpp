/**
 * mlb.c -- перемещает курсор в начало следующей строки
 * реализация команды "mnlb"
 */

#include "_text.h"

/**
 * Перемещает курсор в начало следующей строки
 * @param txt текст
 * @returns статус
 */
int mlb(const text txt)
{
  if((unsigned int) txt->cursor->line_num == -1)
    txt->cursor->line_num = 0;
    if((unsigned int) txt->cursor->line_num != txt->lines->size() - 1) {
        txt->cursor->position = 0;
        return SUCCESS;
    } else {
        return FAILED_NO_LINE;
    }
}
