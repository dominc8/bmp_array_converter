#include "stdio.h"
#include "stdlib.h"
#include "errno.h"
#include "string.h"
#include "bitmap_parser.h"
#include "formatter.h"

extern int errno;

static void print_help(void);

static void write_prebitmap(const char* name, FILE *f_output);
static void write_postbitmap(const char* name, FILE *f_output);

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
        uint32_t filename_length = strlen(argv[2]);
        char *name = malloc(filename_length + 1);
        memcpy(name, argv[1], filename_length);
        name[filename_length] = '\0';

        char *last_dot_ptr = strrchr(name, '.');
        if (last_dot_ptr == name)
        {
            memcpy(name, "bitmap", 6 > filename_length ? filename_length : 6);
        }
        else if (last_dot_ptr != NULL)
        {
            *last_dot_ptr = '\0';
        }

        write_prebitmap(name, f_output);

        if (OK == format_bitmap(&bitmap_data, f_output))
        {
            write_postbitmap(name, f_output);
            printf("Bitmap saved to file\n");
        }
        else
        {
            printf("Formatting bitmap failed\n");
        }
        free(name);
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
    printf("CURRENTLY ONLY ARGB8 WORKS FOR SURE\nExample usage: ./bmp_array_converter logo_bitmap_image.bmp logo.h\n");
}

static void write_prebitmap(const char* name, FILE *f_output)
{
    fprintf(f_output, "#ifndef __ALIGNED\n#define __ALIGNED(x) __attribute__((aligned(x)))\n#endif\n");
    fprintf(f_output, "__ALIGNED(4) const unsigned char %s[] =\n{\n", name);
}

static void write_postbitmap(const char* name, FILE *f_output)
{
    fprintf(f_output, "};\n");
}

