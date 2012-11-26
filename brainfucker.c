#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASCII_CHS 128

struct ch {
    unsigned int freq;
    char         c;
};

int
cmp (const void *a, const void *b)
{
    return ((struct ch *) b)->freq - ((struct ch *) a)->freq;
}

int
main (int argc, char *argv)
{
    char      *input;
    struct ch  tape[ASCII_CHS];
    int        idx[ASCII_CHS];
    int        read            = 0;
    int        input_size      = BUFSIZ;
    int        pos             = 0;
    int        i;
    char       c;

    memset (tape, 0, sizeof (struct ch) * ASCII_CHS);
    memset (idx, 0, sizeof (int) * ASCII_CHS);
    input = calloc (input_size, 1);

    while ((c = getchar ()) != EOF) {
        if (c > ASCII_CHS) {
            c = '.';
        }

        tape[c].freq++;
        tape[c].c = c;

        if (read >= input_size) {
            input_size += BUFSIZ;
            input = realloc (input, input_size);
        }
        input[read++] = c;
    }
    input[read] = 0;

    qsort (tape, ASCII_CHS, sizeof (struct ch), cmp);

    for (i = 0; i < ASCII_CHS && tape[i].freq; i++) { 
        int j;

        printf ("++++++++++");
        if (tape[i].c / 10 > 0) {
            putchar ('[');
            for (j = 0; j <= i; j++)              { putchar ('>'); }

            for (j = 0; j < tape[i].c / 10; j++ ) { putchar ('+'); }
            for (j = 0; j <= i; j++)              { putchar ('<'); }
            printf ("-]");
        }

        for (j = 0; j <= i; j++)                  { putchar ('>'); }
        for (j = 0; j < tape[i].c % 10; j++ )     { putchar ('+'); }
        for (j = 0; j <= i; j++)                  { putchar ('<'); }

        idx[tape[i].c] = i; 
    }

    putchar ('>');
    while (*input) {
        char direction;
        int  shift;

        shift = idx[*input] - pos;
        direction = shift > 0 ? '>' : '<';

        for (i = 0; i < abs (shift); i++)         { putchar (direction); }

        putchar ('.');
        pos = idx[*input];

        ++input;
    }
    putchar ('\n');

    return EXIT_SUCCESS;
}
