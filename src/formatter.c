#include "formatter.h"
#include "stdio.h"

static const char *indent = "    ";

static void format_16(uint16_t val, const char *pre_text, const char *post_text, FILE *f_out);

static void format_32(uint32_t val, const char *pre_text, const char *post_text, FILE *f_out);

static void format_line(uint8_t *ptr, int32_t n, const char *pre_text, FILE *f_out);

static void format_line_end(uint8_t *ptr, int32_t n, const char *pre_text, FILE *f_out);

static void align_fh_for_32bit_data(fh_handle_t handle);

static inline void format_byte(uint8_t byte, FILE *f_out);

int32_t format_bitmap(bitmap_handle_t handle, FILE *f_out)
{
    if (NULL == handle || NULL == f_out)
    {
        return NULLPTR_ERR;
    }

    if (32 == handle->bitmap_header.n_bits_per_pixel)
    {
        align_fh_for_32bit_data(&handle->file_header);
    }

    if (OK != format_fh(&handle->file_header, f_out) || OK != format_bh(&handle->bitmap_header, f_out))
    {
        return NULLPTR_ERR;
    }

    uint8_t *ptr = handle->bitmap_data;
    uint32_t bytes_left = handle->bitmap_header.bitmap_size;
    const int32_t n_chars_in_line = 16;
    for (; bytes_left >= n_chars_in_line; bytes_left -=n_chars_in_line)
    {
        format_line(ptr, n_chars_in_line, indent, f_out);
        ptr += n_chars_in_line;
    }
    format_line_end(ptr, bytes_left, indent, f_out);

    return OK;
    
}

int32_t format_fh(fh_handle_t handle, FILE *f_out)
{
    if (NULL == handle || NULL == f_out)
    {
        return NULLPTR_ERR;
    }

    format_16(handle->type, indent, " // Bitmap type 0x4D42", f_out);
    format_32(handle->size_of_file, indent, " // Size of file", f_out);
    format_16(handle->reserved_1, indent, " // Reserved", f_out);
    format_16(handle->reserved_2, indent, " // Reserved", f_out);
    format_32(handle->bitmap_offset, indent, " // Bitmap data offset", f_out);

    return OK;
}

int32_t format_bh(bh_handle_t handle, FILE *f_out)
{
    if (NULL == handle || NULL == f_out)
    {
        return NULLPTR_ERR;
    }

    format_32(handle->header_size, indent, " // Size of header (40)", f_out);
    format_32(handle->img_width, indent, " // Image width", f_out);
    format_32(handle->img_height, indent, " // Image height", f_out);
    format_16(handle->n_color_planes, indent, " // Number of color planes (1)", f_out);
    format_16(handle->n_bits_per_pixel, indent, " // Number of bits per pixel", f_out);
    format_32(handle->compression, indent, " // Compression", f_out);
    format_32(handle->bitmap_size, indent, " // Size of bitmap data", f_out);
    format_32(handle->ppm_hor, indent, " // Pixel per metre horizontal", f_out);
    format_32(handle->ppm_ver, indent, " // Pixel per metre horizontal", f_out);
    format_32(handle->n_colors_in_palette, indent, " // Number of colors in palette", f_out);
    format_32(handle->n_important_colors, indent, " // Number of colors in palette", f_out);
    if (32 == handle->n_bits_per_pixel)
    {
        format_16(0, indent, " // Alignment so 32bit data is aligned properly", f_out);
    }

    return OK;
}

static void align_fh_for_32bit_data(fh_handle_t handle)
{
    handle->size_of_file += 2;
    handle->bitmap_offset += 2;
}

static void format_16(uint16_t val, const char *pre_text, const char *post_text, FILE *f_out)
{
    uint8_t v1 = val & 0x00FF;
    uint8_t v2 = (val & 0xFF00) >> 8;
    fprintf(f_out, "%s0x%02hhX, 0x%02hhX,%s\n", pre_text, v1, v2, post_text);
}

static void format_32(uint32_t val, const char *pre_text, const char *post_text, FILE *f_out)
{
    uint8_t v1 = val & 0x000000FF;
    uint8_t v2 = (val & 0x0000FF00) >> 8;
    uint8_t v3 = (val & 0x00FF0000) >> 16;
    uint8_t v4 = (val & 0xFF000000) >> 24;
    fprintf(f_out, "%s0x%02hhX, 0x%02hhX, 0x%02hhX, 0x%02hhX,%s\n",
            pre_text, v1, v2, v3, v4, post_text);
}

static void format_line(uint8_t *ptr, int32_t n, const char *pre_text, FILE *f_out)
{
    if (n > 0)
    {
        fprintf(f_out, "%s", pre_text);
        for (int32_t i = 0; i < n; ++i)
        {
            format_byte(ptr[i], f_out);
            fprintf(f_out, ",");
        }
        fprintf(f_out, "\n");
    }

}

static void format_line_end(uint8_t *ptr, int32_t n, const char *pre_text, FILE *f_out)
{
    if (n > 0)
    {
        fprintf(f_out, "%s", pre_text);
        for (int32_t i = 0; i < n - 1; ++i)
        {
            format_byte(ptr[i], f_out);
            fprintf(f_out, ",");
        }
        format_byte(ptr[n-1], f_out);
        fprintf(f_out, "\n");
    }

}

static inline void format_byte(uint8_t byte, FILE *f_out)
{
    fprintf(f_out, "0x%02hhX", byte);
}
