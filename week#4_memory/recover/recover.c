#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recovery file_name\n");
        return 1;
    }

    FILE *raw_file = fopen(argv[1], "r");

    if (raw_file == NULL)
    {
        return 1;
    }

    //keep track of jpeg files found
    uint8_t buffer[512];
    int counter = 0;
    int jpeg_open = 0;

    char filename[8];
    FILE *img = NULL;

    //store and track the name of each jpeg file 
    while (fread(buffer, 1, 512, raw_file) == 512)
    {
        //these are those four bites which indicate start of a jpeg file
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            //if a jpeg is already open then close it before opening a new file
            if (img != NULL)
            {
                fclose(img);
            }

            //providing a number to each jpeg file
            sprintf(filename, "%03i.jpg", counter);
            counter++;

            //opening a new jpeg file
            img = fopen(filename, "w");

            fwrite(buffer, 1, 512, img);

            jpeg_open = 1;
        }
        else if (jpeg_open)
        //this block is related to that jpeg which we are trying to recover
        {
            fwrite(buffer, 1, 512, img);
        }
    }

    if (img != NULL)
    {
        fclose(img);
    }

    fclose(raw_file);
}
