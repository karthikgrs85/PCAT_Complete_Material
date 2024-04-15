/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

#define NAME_LEN 50

typedef enum
{
    undefined=-1,
    vowel=1,
    consonant
} character_type;


character_type getCharacterType(char inp)
{
    if(!((inp >='a') && (inp <= 'z')) && !((inp>='A') &&(inp <='Z')))
        return undefined;
    switch (inp)
    {
        case 'a': case 'A': case 'e': case 'E': case 'i': case 'I': case 'o': case 'O': case 'u': case 'U':
            return vowel;
    }
    return consonant;
}


int main()
{
    char ch;
    character_type type;
    
    printf("\n Enter a character :");
    scanf("%c",&ch);
    type = getCharacterType(ch);
    switch(type)
    {
        case vowel: printf("\n You have entered a vowel, enum val = %d ",type ); break;
        case consonant: printf("\n You have entered an consonant, enum val = %d ", type); break;
        case undefined: printf("\n You have entered invalid char type, enum val = %d ", type);
    }
    
    
}
