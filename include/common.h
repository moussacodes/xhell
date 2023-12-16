#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <fcntl.h>
#include <ncurses.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include "io.h"
#include "exec.h"

#define MAX_BUFFER 256
#define MAXPATH 1024
#define clear() printf("\033[H\033[J")

#define CHECK_MEMORY(ptr)                                                               \
    do                                                                                  \
    {                                                                                   \
        if (!(ptr))                                                                     \
        {                                                                               \
            fprintf(stderr, "Memory allocation failed at %s:%d\n", __FILE__, __LINE__); \
            exit(EXIT_FAILURE);                                                         \
        }                                                                               \
    } while (0)

#define IS_PIPE_OPRATOR(CH) ( \
    (CH) == '|' || (CH) == '<' || (CH) == '>')

enum Keypress
{
    ENTER = 10,
    ESCAPE = 27,
    BACKSPACE = 127,
    TAB = 9,
    CTRL_C = 3,
    CTRL_S = 19,
    CTRL_V = 22,
    CTRL_X = 24,
    UP_ARROW = 57,
    DOWN_ARROW = 80,
    RIGHT_ARROW = 77,
    LEFT_ARROW = 75
};

typedef struct
{
    char *cur_dir;
} dir_info;

typedef struct
{
    char *cont; // command content
    int c_pos;  // cursor position
    int length; // longueur de la chaîne

} Cmd;

void insertChar(char addedChar, Cmd *cmd, dir_info *dir);
void addCharToBuffer(const char addedChar, Cmd *cmd, dir_info *dir);
void insert_key_press(int key_press, Cmd *cmd);
void move_cursor(int x);
void setup_env();
int parse_command(Cmd *cmd, dir_info *d);
// Cmd *store_command(char *cmd, size_t input_size, int *nb_token);
// char *get_command_history(int index);

#endif /* COMMON_H */