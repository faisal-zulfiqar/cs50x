#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }
    
    char *infile = argv[1];
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }
    
    int is_open = 0;
    int counter = 0;
    char filename[8];
    uint8_t buffer[512];
    FILE *img;
    
    while (fread(buffer, 1, 512, inptr) == 512)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (is_open)
            {
                fclose(img);
            }
            sprintf(filename, "%03i.jpg", counter++);
            img = fopen(filename, "w");
            fwrite(buffer, 1, 512, img);
            is_open = 1;
        }
        else if (is_open)
        {
            fwrite(buffer, 1, 512, img);
        }   
    }
    
    fclose(img);
}
