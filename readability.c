#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    //gets excerpt from user to be evaluated.
    string excerpt = get_string("Excerpt: ");

    int lettercount = 0;
    int spacecount = 1;
    int punctcount = 0;

    //counts alphabetic characters to determine # of letters, spaces to determine # of words, and punctuation marks to determine # of sentences.
    //this function requires correct grammar, single spacing, and single punctuation marks to perform correctly. (no "!!" || "??" || "..")
    for (int i = 0, n = strlen(excerpt); i < n; i++)
    {
        if (isalpha(excerpt[i]))
        {
            lettercount += 1;
        }
        else if (isspace(excerpt[i]))
        {
            spacecount += 1;
        }
        else if (excerpt[i] == '.' || excerpt[i] == '?' || excerpt[i] == '!')
        {
            punctcount += 1;
        }
    }
    
    //plugs obtained counts into equation to determine Coleman-Liau index, which is an accurate predictor of reading grade level.
    float L = ((float) lettercount / spacecount) * 100.0;
    float S = ((float) punctcount / spacecount) * 100.0;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    
    //prints grade level rounded to nearest integer. if under 1, prints before grade 1. if equal to or over 16, prints grade 16+
    if (index < 1.0)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16.0)
    {
        printf("Grade 16+\n");
    }
    else
    {
        index = round(index);
        printf("Grade %i\n", (int) index);
    }
}