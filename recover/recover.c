#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        printf("Correct usage: ./recover card.raw\n");
        return 1;
    }

    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }
    char name[8];
    BYTE buffer[512];
    int file_number = 0;
    FILE *img;
    while (fread(buffer, 1, 512, card) == 512)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (file_number == 0)
            {
                sprintf(name, "%03i.jpg", file_number);
                img = fopen(name, "w");
                fwrite(buffer, 1, 512, img);
                file_number++;

            }
            else
            {
                fclose(img);
                sprintf(name, "%03i.jpg", file_number);
                img = fopen(name, "w");
                fwrite(buffer, 1, 512, img);
                file_number++;

            }
        }
        else if (img != NULL)
        {
            fwrite(buffer, sizeof(buffer), 1, img);
        }
    }
    fclose(img);
    fclose(card);
return 0;

}