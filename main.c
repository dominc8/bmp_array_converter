#include "stdio.h"
#include "errno.h"
#include "string.h"
#include "bitmap_parser.h"
#include "formatter.h"

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
    bitmap_t bitmap_data;
    int32_t status = bitmap_parse_file(&bitmap_data, f_bitmap);
    if (BITMAP_OK == status)
    {
        if (OK == format_bitmap(&bitmap_data, f_output))
        {
            printf("Bitmap saved to file\n");
        }
        else
        {
            printf("Formatting bitmap failed\n");
        }
    }
    else
    {
        printf("Parsing bitmap file failed with status %d\n", status);
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

