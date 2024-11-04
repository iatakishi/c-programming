#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int response; // Variable for user input

    do
    {
        response = get_int("Height: "); // User input function
    }
    while (response < 1); // Condition for input

    int n = response;
    int first_spaces = n - 1; // Number of spaces before the first pyramid
    int left_height = 1;      // Height of the left pyramid
    int right_height = 1;     // Height of the right pyramid

    // How many lines should the pyramid be?
    for (int i = 0; i < n; i++)
    {

        // Spaces before first pyramid
        for (int z = 0; z < first_spaces; z++)
        {
            printf(" ");
        }
        first_spaces--;

        // First pyramid
        for (int x = 0; x < left_height; x++)
        {
            printf("#");
        }
        left_height++;

        // Space between pyramids
        printf("  ");

        // Second pyramid
        for (int x = 0; x < right_height; x++)
        {
            printf("#");
        }
        right_height++;
        // Line separation inside pyramid
        printf("\n");
    }
}
