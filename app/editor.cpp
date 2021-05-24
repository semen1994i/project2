/**
 * editor.c -- строковый текстовый редактор
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <list>

#include "text.h"
#include "common.h"

int main()
{
    char cmdline[MAXLINE + 1];
    char *cmd;
    const char *arg;
    const char *second_arg;

    /* Создаем объект для представления текста */
    text txt = create_text();

    /* Вывод сообщения о командах */
    printf("\nEnter help for instructions\n");

    /* Цикл обработки команд */
    while (1) {
        printf("\ned > ");

        /* Получаем команду */
       // fgets(cmdline, MAXLINE, stdin);

        /* Извлекаем имя команды */
        if ((cmd = strtok(cmdline, " \n")) == NULL) {
            continue;
        }

        /* Распознаем поддерживаемую команду */

        /* Завершаем работу редактора */
        if (strcmp(cmd, "q") == 0) {
            fprintf(stderr, "Bye!\n");
            break;
        }

        /* Загружаем содержимое файла, заданного параметром */
        if (strcmp(cmd, "load") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: load filename\n");
            } else {
                load(txt, arg);
            }
            continue;
        }

        /* Загружаем содержимое файла, заданного параметром */
        if (strcmp(cmd, "save") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: save filename\n");
            } else {
                save(txt, arg);
            }
            continue;
        }

        /* Выводим текст */
        if (strcmp(cmd, "show") == 0) {
            show(txt);
            continue;
        }

        if(strcmp(cmd, "showreveven") == 0) {
            showreveven(txt);
            continue;
        }

        if(strcmp(cmd, "m") == 0) {
	    arg = strtok(NULL, " \n");
	    second_arg = strtok(NULL, " \n");
            if (arg == NULL || second_arg == NULL) {
                fprintf(stderr, "Usage: m line_number position\n");
            } else {
                m(txt, atoi(arg), atoi(second_arg));
            }
            continue;
        }

        if(strcmp(cmd, "mlb") == 0) {
            int status = mlb(txt);
            switch (status) {
                case SUCCESS:
                    break;
                case FAILED_NO_LINE:
                    fprintf(stderr, "Next line didn't exist\n");
                    break;
                default:
                    fprintf(stderr, "Unhandled error!\n");
                    exit(EXIT_FAILURE);
            }
            continue;
        }

        if(strcmp(cmd, "p1") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: p line text\n");
            } else {
                if ((second_arg = strtok(NULL, "\0")) == NULL) {
                    fprintf(stderr, "Usage: p line text\n");
                } else {
                    int status = p1(txt, second_arg);
                    switch (status) {
                        case SUCCESS:
                            break;
                        case FAILED_NO_LINE:
                            fprintf(stderr, "No line with number %d\n", atoi(arg));
                            break;
                        default:
                            fprintf(stderr, "Unhandled error!\n");
                            exit(EXIT_FAILURE);
                    }
                }
            }
            continue;
        }


        /* Если команда не известна */
        fprintf(stderr, "Unknown command: %s\n", cmd);
    }

    return 0;
}
