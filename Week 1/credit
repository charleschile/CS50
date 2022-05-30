#include <stdio.h>
#include <cs50.h>

bool check_card(long card);
int get_length(long card);
bool checksum(long card);
void print_card_type(long card);

int main(void)
{
    long card_number;
    // Prompt user for credit card number
    do
    {
        card_number = get_long("Number: ");
    }
    while (card_number < 0);
    // Print card type
    if (check_card(card_number) == true)
    {
        print_card_type(card_number);
    }
    else
    {
        printf("INVALID\n");
    }
}
// Check card lenth and check sum
bool check_card(long card)
{
    int length = get_length(card);
    return (length == 13 || length == 15 || length == 16) && checksum(card);
}
// Get the length of credit card
int get_length(long card)
{
    int i;
    for (i = 0; card != 0; card /= 10, i++);
    return i;
}
// Check sum
bool checksum(long card)
{
    int sum = 0;
    int i;
    for (i = 0; card != 0; card /= 10, i++)
    {
        if (i % 2 == 0)
        {
            sum += card % 10;
        }
        else
        {
            int multiple = 2 * (card % 10);
            sum += multiple / 10 + multiple % 10;
        }
    }
    return (sum % 10) == 0;
}
// Identify and print card type
void print_card_type(long card)
{
    if ((card >= 34e13 && card < 35e13) || (card >= 37e13 && card < 38e13))
    {
        printf("AMEX\n");
    }
    else if (card >= 51e14 && card < 56e14)
    {
        printf("MASTERCARD\n");
    }
    else if ((card >= 4e12 && card < 5e12) || (card >= 4e15 && card < 5e15))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
