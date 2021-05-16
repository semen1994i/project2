/**
 * _text.h -- внутренние структуры представления текста
 */

#ifndef _TEXT_H
#define _TEXT_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <assert.h>
#include <list>
#include <string>

#include "text.h"

/**
 * @struct
 * @brief Представление одной строки текста как элемента линейного списка
 *
 */
typedef struct _node {
    char contents[MAXLINE + 1]; /**< содержимое строки текста */
    struct _node *previous;     /**< указатель на предыдущую строку */
    struct _node *next;         /**< указатель на следующую строку */
} node;


/**
 * @struct
 * @brief Представление курсора
 *
 */
typedef struct _crsr {
    int line_num;
    int position;
} crsr;

typedef struct _list {
    list<string>* lines;
    struct _crsr* cursor;
} l;

#endif
