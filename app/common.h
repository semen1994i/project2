/**
 * common.h -- прототипы функций реализации команд редактора
 */

#ifndef COMMON_H
#define COMMON_H

#include "text.h"

/* Декларирует неиспользуемый аргумент,
 * корректно подавляя предупреждение вида "unused parameter" */
#define UNUSED(x) (void)(x)

/**
 * Выводит содержимое указанного файла на экран
 */
void show(text txt);

/**
 * Сохраняет содержимое указанного файла
 */
void save(text txt, string filename);


/**
 * Загружает содержимое указанного файла
 */
void load(text txt, string filename);

/**
 * Выводит содержимое указанного файла на экран в обратном порядке
 * пропуская нечётные строки
 */
void showreveven(text txt);

const string CURSOR_CHAR = "|";
char* set_cursor(char* contents, int cursor);

#endif
