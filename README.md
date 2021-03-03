# Converter of image files to C arrays for use in embedded projects

### Convert image to bmp (format BMP 3.x, ARGB8888)

Example conversion using ImageMagick:
```
convert image.jpg -resize 45x69 -matte -define bmp3:alpha=on bmp3:image.bmp
```

Call program with proper arguments:
```
./main image.bmp image.h
```




