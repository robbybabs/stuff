#include <cs50.h>
#include <stdio.h>

long get_nums(void);

int main(void)
{
    get_nums();
}

long get_nums(void)
{
    long n;
    long i;
    long digits;
    long x;
    
    // this will prompt the user for a CC number as input.
    n = get_long("CC Number: ");
    x = n;
    
    // i is length of number. this for loops will find the length of the CC number
    for (i = 0; x != 0; x = x / 10)
    {
        i++;
    }
    
    // this will check the length of the cc number and determine if its a valid number. if invalid, the program will terminate.
    if ((i < 13) || (i > 16) || (i == 14))
    {
        printf("INVALID\n");
        return 0;
    }
    
    // this will calculate a checksum using luhns algorithm to be used for validating the cc number .
    long cc;
    long dig1;
    long dig2;
    long sum1;
    long sum2;
    long total;
    long d1;
    long d2;
    
    cc = n;
    sum1 = 0;
    sum2 = 0;
    do
    {
        dig1 = cc % 10;
        cc = cc / 10;
        sum1 = sum1 + dig1;
        
        dig2 = cc % 10;
        cc = cc / 10;
        dig2 = dig2 * 2;
        d1 = dig2 % 10;
        d2 = dig2 / 10;
        sum2 = sum2 + d1 + d2;
        
        total = sum1 + sum2;
        
    }
    while (cc > 0);
    
    // this will check if the checksum total indicates a valid cc number. if invalid, the program will terminate. 
    if (total % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }
    
    // this will get the two starting numbers of the cc number
    long start;
    start = n;
    do
    {
        start = start / 10;
    }
    while (start >= 100);
    
    // this will determine the card type depending on the first two numbers, or declare the card is invalid if it does not meet the conditions. 
    if ((start == 34) || (start == 37))
    {
        printf("AMEX\n");
    }
    else if ((start == 51) || (start == 52) || (start == 53) || (start == 54) || (start == 55))
    {
        printf("MASTERCARD\n");
    }
    else if ((start == 40) || (start == 41) || (start == 42) || (start == 43) || (start == 44) || (start == 45) || (start == 46) 
             || (start == 47) || (start == 48) || (start == 49))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
    return 0;
}

