#include "monty.h"

/**
 * main - entry to program
 * @ac: ..
 * @av: ..
 * Return: ..
*/

int main(int ac, char **av)
{
    (void)av;
    if (ac != 2)
    {
        write(2, "USAGE: monty file\n", 19);
        exit(EXIT_FAILURE);
    }

    return (0);
}
