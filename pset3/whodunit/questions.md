# Questions

## What's `stdint.h`?

It's a library that provides some exact-width integer types as custom datatypes.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

Using these datatypes ensure that one will get same size storage variables across different platforms.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

BYTE = 1 Byte
DWORD = 4 Bytes
LONG = 4 Bytes
WORD = 2 Bytes

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

'BM'

## What's the difference between `bfSize` and `biSize`?

`bfSize` corresponds to the overall bmp file size, while `biSize` corresponds to the structure's size.

## What does it mean if `biHeight` is negative?

It means that the image is bottom down.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

`biBitCount`

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

If for some reason, the file the `fopen` is trying to open doesn't exist, the `fopen` gets a `NULL` in return.

## Why is the third argument to `fread` always `1` in our code? (For example, see lines 40, 44, and 75.)

It specifies the number of element to read, since we only need to read 1 pixel (contained by RGBTRIPLE), hence the 1.

## What value does line 63 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

3

## What does `fseek` do?

This function allows the programmer to shift the reading position in the stream.

## What is `SEEK_CUR`?

`SEEK_CUR` is the current position of the file pointer.
