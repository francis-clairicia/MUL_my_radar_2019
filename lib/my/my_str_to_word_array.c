/*
** EPITECH PROJECT, 2019
** my_str_to_word_array
** File description:
** Split a string in a word array
*/

#include <stdlib.h>
#include "my.h"

int get_nb_words(char const *str)
{
    int nb = 1;
    int i = 0;
    int j = 0;

    while (str[i] != '\0') {
        j = i;
        i += 1;
        if (my_find_char("0123456789", str[j]) >= 0)
            continue;
        if (my_find_char("abcdefghijklmnopqrstuvwxyz", str[j]) >= 0)
            continue;
        if (my_find_char("ABCDEFGHIJKLMNOPQRSTUVWXYZ", str[j]) >= 0)
            continue;
        nb += 1;
    }
    return (nb);
}

int get_index_end_word(char const *str)
{
    int i = 0;
    int j = 0;

    while (str[i] != '\0') {
        j = i;
        i += 1;
        if (my_find_char("0123456789", str[j]) >= 0)
            continue;
        if (my_find_char("abcdefghijklmnopqrstuvwxyz", str[j]) >= 0)
            continue;
        if (my_find_char("ABCDEFGHIJKLMNOPQRSTUVWXYZ", str[j]) >= 0)
            continue;
        return (j);
    }
    return (i);
}

void generate_array(char **array, char const *str, int nb_words)
{
    int i = 0;
    int index_word;

    while (i < nb_words) {
        index_word = get_index_end_word(str);
        array[i] = my_strndup(str, index_word);
        str = &str[index_word + 1];
        i += 1;
    }
}

char **my_str_to_word_array(char const *str)
{
    int nb_words;
    char **array;

    if (str == NULL)
        return (NULL);
    nb_words = get_nb_words(str);
    array = malloc(sizeof(char *) * (nb_words + 1));
    if (array == NULL)
        return (NULL);
    generate_array(array, str, nb_words);
    array[nb_words] = NULL;
    return (array);
}
