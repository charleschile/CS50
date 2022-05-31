#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    // test whether there is exactly one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover card.raw\n");
        return 1;
    }

    // open the file in the memory card
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("The %s file cannot be opened\n", argv[1]);
        return 1;
    }

    int jpgFound = 0;
    int fileCount = 0;

    // set a buffer with 512 bytes
    uint8_t buffer[512];

    // define a file for picture
    FILE *picture = NULL;

    // set space for filename
    char filename[8];

    while (fread(buffer, sizeof(buffer), 1, file) == 1)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && buffer[3] >= 0xe0 && buffer[3] <= 0xef)
        {
            if (jpgFound == 1)
            {
                fclose(picture);
            }
            else
            {
                jpgFound = 1;
            }
            sprintf(filename, "%03d.jpg", fileCount);
            picture = fopen(filename, "w");
            fileCount++;
        }
        if (jpgFound == 1)
        {
            fwrite(&buffer, 512, 1, picture);
        }
    }
    fclose(file);
    fclose(picture);
    return 0;
}
