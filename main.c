#include "stdio.h"
#include "errno.h"
#include "string.h"
#include "parser_fh.h"
#include "parser_bh.h"

extern int errno;

static void print_help(void);

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("Wrong number of arguments, expected 2, got %d\n", argc-1);
        print_help();
        return 1;
    }

    FILE *f_bitmap = fopen(argv[1], "rb");
    if (NULL == f_bitmap)
    {
        int errnum = errno;
        printf("Cannot open file %s: %s\n", argv[1], strerror(errnum));
        return 2;
    }

    FILE *f_output = fopen(argv[2], "wb");
    if (NULL == f_output)
    {
        int errnum = errno;
        printf("Cannot open file %s: %s\n", argv[2], strerror(errnum));
        return 2;
    }

    /***********************/


    fclose(f_bitmap);
    fclose(f_output);

    return 0;
}

static void print_help(void)
{
    printf("Help:\n");
}

