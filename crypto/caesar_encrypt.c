#include <error.h>
#include "include/caesar.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int input_key()
{
    //We will first have raw input as characters and then validate it so that it matches the correct format
    //valid input types: -12, 24,...
    //invalid input types: 12abv, 12.4 12-

    char input_buffer[16];
    int key;

    printf("Enter key size: ");
    if(fgets(input_buffer, sizeof(input_buffer), stdin) == NULL){
        printf("Error getting key size.\n");
        exit(EXIT_FAILURE);
    }

    //when user press enter("\n") after giving input, strcspn puts null terminator at the place where "\n" was placed.
    //why this is needed ? To ensure no further processing is required and now you just need to convert string to digits
    //using atoi()
    input_buffer[strcspn(input_buffer, "\n")] = '\0';
    
    //Validate user input. Say no to bad input.
    for(size_t i = 0; i < strlen(input_buffer); i++) 
    {
        //case=0//example data = 9b (isdigit = 0) AND (is i == 0 ?(1) AND isVal = '-' ? (0)) FAIL
        //case=1//example data = -9b (isdigit = 0) AND (is i == 0 ?(0) AND is first char '-' = 1) FAIL
        //case=2//example data = 9b (isdigit = 0) ... FAIL
        //case=3//example data = 12-....you get the idea.....
        if(!isdigit(input_buffer[i]) && !(i == 0 && input_buffer[i] == '-'))
        {
            printf("Inavlid input! Key must be an integer!\n");
            exit(EXIT_FAILURE);
        }
    }
    
    key = atoi(input_buffer);

    key = key % 26;

    if(key < 0){
        key += 26;
    }

    return key;
    

}

char *caesar_encrypt(char *text, int key){
    
    for(int i = 0 ; i < strlen(text); i++)
    {
        if (text[i] >= 'A' && text[i] <= 'Z') {

            text[i] = 'A' + (text[i] - 'A' + key) % 26;

        } else if (text[i] >= 'a' && text[i] <= 'z') {
            
            text[i] = 'a' + (text[i] - 'a' + key) % 26;

        }
    }

    return text;
}
