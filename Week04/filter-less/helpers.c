#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int bluemain, greenmain, redmain;
    float grayout;

    for (int col = 0; col < height; col++)
    {
        for (int row = 0; row < width; row++)
        {
            bluemain = image[col][row].rgbtBlue;
            greenmain = image[col][row].rgbtGreen;
            redmain = image[col][row].rgbtRed;

            grayout = round((bluemain + greenmain + redmain) / 3.0);

            image[col][row].rgbtBlue = grayout;
            image[col][row].rgbtGreen = grayout;
            image[col][row].rgbtRed = grayout;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int originalBlue, originalGreen, originalRed;
    int sepiaBlue, sepiaGreen, sepiaRed;
    for (int col = 0; col < height; col++)
    {
        for (int row = 0; row < width; row++)
        {
            originalBlue = image[col][row].rgbtBlue;
            originalGreen = image[col][row].rgbtGreen;
            originalRed = image[col][row].rgbtRed;

            sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[col][row].rgbtBlue = sepiaBlue;
            image[col][row].rgbtGreen = sepiaGreen;
            image[col][row].rgbtRed = sepiaRed;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE rowplace[width];
    for (int col = 0; col < height; col++)
    {
        for (int row = 0; row < width; row++)
        {
            rowplace[row] = image[col][row];
        }
        for (int row = 0; row < width; row++)
        {
            image[col][row].rgbtBlue = rowplace[width - row - 1].rgbtBlue;
            image[col][row].rgbtGreen = rowplace[width - row - 1].rgbtGreen;
            image[col][row].rgbtRed = rowplace[width - row - 1].rgbtRed;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int col = 0; col < height; col++)
    {
        for (int row = 0; row < width; row++)
        {
            copy[col][row] = image[col][row];
        }
    }

    for (int col = 0; col < height; col++)
    {
        for (int row = 0; row < width; row++)
        {
            int counter = 0;
            float redsum = 0;
            float greensum = 0;
            float bluesum = 0;

            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    if (!(col + k < 0 || col + k >= height || row + l < 0 || row + l >= height))
                    {
                        redsum += copy[col + k][row + l].rgbtRed;
                        greensum += copy[col + k][row + l].rgbtGreen;
                        bluesum += copy[col + k][row + l].rgbtBlue;
                        counter++;
                    }
                    else
                    {
                        continue;
                    }
                }
            }
            image[col][row].rgbtRed = (int) round(redsum / counter);
            image[col][row].rgbtGreen = (int) round(greensum / counter);
            image[col][row].rgbtBlue = (int) round(bluesum / counter);
        }
    }
}
