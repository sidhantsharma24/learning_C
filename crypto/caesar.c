#include "include/caesar.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>
#define MEM_ALLOC_ERR 1


int main()
{
    size_t initial_size = 4; // initial_size of buffer
    size_t length = 0; //counter to record length of buffer

    char *text = (char*)malloc(initial_size * sizeof(char));
    if(text == NULL)
    {
        printf("Memory allocation failed.\n");
        return MEM_ALLOC_ERR;
    }

    printf("<----------------CAESAR CIPHER GENERATIOR---------------->\n\n");
    printf("Enter text: ");
    
    /*We use getchar() to take user input. No risk of Buff. Oflw.*/
    int character;

    while((character = getchar()) != '\n' && character != EOF)
    {
        //Resizing if input exceeds buffer
        if(length + 1 >= initial_size)
        {
            size_t new_size = initial_size * 2;
            char *resize_text = (char*)realloc(text, new_size * sizeof(char));
            if(resize_text == NULL)
            {
                printf("Memory allocation failed!\n");
                free(text);
                return MEM_ALLOC_ERR;
            }

            text = resize_text;
            initial_size = new_size;
        }

        text[length] = character;
        length++;
    }

    text[length] = '\0';//ensure 

    //printf("Entered text: %s\n", text);
    
    //Taking key input

    int key = input_key();

    char *cipher = caesar_encrypt(text, key);
    
    printf("Plain text: %s\n", text);
    printf("Ciphertext with shift value %d: %s\n\n", key, cipher);
    printf("<---------------END--------------->\n");

    return 0;
}
