/*
** EPITECH PROJECT, 2022
** B-PSU-400-LIL-4-1-malloc-leo.neumuller
** File description:
** my_assert
*/
#include <unistd.h>
#include <stdio.h>

void myputchar(char mychar)
{
    write(STDOUT_FILENO, &mychar, 1);
}

void my_putstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        myputchar(str[i]);
    }
}

void my_assert(int comp, char *testname)
{
    if (!comp) {
        my_putstr("test failed: ");
        my_putstr(testname);
        myputchar('\n');
        _exit(1);
    }
}

void my_put_nbr(long int n)
{
    int mod = 0;
    if (n <= 9 && n >= 0)
        myputchar(n + 48);
    if (n < 0) {
        myputchar('-');
        n = n * (-1);
        if (n <= 9 && n >= 0)
            my_put_nbr(n);
    }
    if (n > 9) {
        mod = n % 10;
        my_put_nbr(n / 10);
        myputchar(mod + 48);
    }
}
