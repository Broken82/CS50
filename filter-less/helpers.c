#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int b;
    int r;
    int g;
    float avg;
    for (int i = 0; i < height; i++ )
    {
        for (int j = 0; j < width; j++)
        {
    b = image[i][j].rgbtBlue;
    r = image[i][j].rgbtRed;
    g = image[i][j].rgbtGreen;

    avg = (b + r + g) / 3.0;
    int rounded = round(avg);


    image[i][j].rgbtBlue = rounded;
    image[i][j].rgbtRed = rounded;
    image[i][j].rgbtGreen = rounded;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int b = image[i][j].rgbtBlue;
            int r = image[i][j].rgbtRed;
            int g = image[i][j].rgbtGreen;

            int sb = round((0.272 * r) + (0.534 * g) + (0.131 * b));
            int sr = round((0.393 * r) + (0.769 * g) + (0.189 * b));
            int sg = round((0.349 * r) + (0.686 * g) + (0.168 * b));

            if (sb > 255)
            {
                sb = 255;
            }
            if (sr > 255)
            {
                sr = 255;
            }
            if (sg > 255)
            {
                sg = 255;
            }

            image[i][j].rgbtBlue = sb;
            image[i][j].rgbtRed = sr;
            image[i][j].rgbtGreen = sg;
        }
    }


}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

       if (j == width / 2)
            {
                break;
            }

            // temp takes value of 1 pixel
            RGBTRIPLE tempb = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = tempb;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE copy[height][width];

for (int i = 0; i < height; i++) //Loop for height of image.
{
    for (int j = 0; j < width; j++) //Loop for width of image and save color values in temp.
    {
        copy[i][j] = image[i][j];
    }
}



    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int R = 0;
            int G = 0;
            int B = 0;
            float counter = 0.00;

            for  (int k = 0; k < 3; k++)
            {
                for (int l = 0; l < 3; l++)
                {
                    if ((i + k - 1) < 0 || (i + k - 1) > (height - 1))
                    {
                        continue;
                    }
                    if ((j + l - 1) < 0 || (j + l - 1) > (width - 1))
                    {
                        continue;
                    }

                    R += image[(i + k - 1)][(j + l - 1)].rgbtRed;
                    G += image[(i + k - 1)][(j + l - 1)].rgbtGreen;
                    B += image[(i + k - 1)][(j + l - 1)].rgbtBlue;
                    counter++;

                }
                    copy[i][j].rgbtRed = round(R / counter);
                    copy[i][j].rgbtGreen = round(G / counter);
                    copy[i][j].rgbtBlue = round(B / counter);
            }
        }
    }

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                    image[i][j].rgbtRed = copy[i][j].rgbtRed;
                    image[i][j].rgbtBlue = copy[i][j].rgbtBlue;
                    image[i][j].rgbtGreen = copy[i][j].rgbtGreen;
            }
        }

}

