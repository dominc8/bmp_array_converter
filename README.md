# Converter of image files to C arrays for use in embedded projects

### Build

To build just run make:
```
make
```
To run tests:
```
run_test
```

### Usage

First convert image to supported bmp format (BMP 3.x, ARGB8888).
Example conversion using ImageMagick:
```
convert image.jpg -resize 45x69 -matte -define bmp3:alpha=on bmp3:image.bmp
```
Then call program with proper arguments:
```
./bmp_array_converter image.bmp image_array.h
```

### TODO
- Support more variations of bits per pixel (only ARGB8888 for now)
- Add conversion from any format to bmp already inside program.

