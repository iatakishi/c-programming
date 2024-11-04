#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    long number = get_long("Number: ");

    // lenght of the number
    long n_for_length = number;
    int length = 0;

    if (n_for_length == 0)
    {
        length = 1;
    }
    else
    {
        while (n_for_length != 0)
        {
            n_for_length /= 10;
            length++;
        }
    }

    // first two digits
    long first_two_digits = number;
    while (first_two_digits > 100)
    {
        first_two_digits /= 10;
    }

    // first digit

    long first_digit = first_two_digits / 10;

    // Process all digits from right to left
    long m = number;
    int is_second_digit = 0;
    int checksum = 0;
    while (m > 0)
    {
        int digit = m % 10; // Get the last digit

        // If it's the second-to-last (alternating), multiply by 2
        if (is_second_digit)
        {
            digit *= 2;
            // If the product is greater than 9, sum its digits
            if (digit > 9)
            {
                checksum += (digit / 10) + (digit % 10);
            }
            else
            {
                checksum += digit;
            }
        }
        else
        {
            // Just add the digit if it's not the second-to-last
            checksum += digit;
        }

        is_second_digit = !is_second_digit; // Alternate on each iteration
        m /= 10;                            // Move to the next digit (drop the last digit)
    }

    // IF STATEMENTS FOR VALIDATING NUMBERS
    if (checksum % 10 == 0) /*checksum condition*/
    {
        if ((first_two_digits == 34 || first_two_digits == 37) &&
            length == 15) /*conditions for american express*/
        {
            printf("AMEX\n");
        }
        else if (first_digit == 4 && (length == 13 || length == 16)) /*conditions for visa*/
        {
            printf("VISA\n");
        }
        else if ((first_two_digits == 51 || first_two_digits == 52 || first_two_digits == 53 ||
                  first_two_digits == 54 || first_two_digits == 55) &&
                 length == 16) /*conditions for mastercard*/
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
