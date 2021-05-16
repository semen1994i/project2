/**
 * save.c -- функция сохранения файла
 */

#include <stdio.h>
#include <assert.h>
#include <string>
#include "common.h"
#include "text.h"

static void save_line(int index, char *contents, int cursor, void *data);

/**
 * Сохраняет содержимое открытого файла
 */

void save(text txt, string filename)
{
    FILE *f;

    /* Открываем файл для записи, контролируя ошибки */
    if ((f = fopen(filename.c_str(), "w")) == NULL) {
        printf("Can't save to file %s\n", filename.c_str());
        return;
    }

    /* Применяем функцию save_line к каждой строке текста */
    process_forward(txt, save_line, f);

    fclose(f);
}

static void save_line(int index, char *contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);

    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(cursor);

    /* Сохраняем строку в файл */
    FILE* f = (FILE*)data;
    fprintf(f, "%s", contents);
}
