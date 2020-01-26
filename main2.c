#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "trie.h"
#define a 97
#define z 122
#define A 65
#define Z 90

int main(int argc, char const *argv[])
{
    
    int Max = 256;
    char* word = (char*)malloc(sizeof(char)*Max);
    char * c = NULL;
    
    int count = 0;
    int counter1 = 0;
    Node *root = AddNode();
    
    char current = getchar();

    while (current!=EOF||(current==EOF&&counter1!=1))
    {
        //tranform letter big to letter small
        if(current >= A && current <= Z){
            current = current+32;
        }
        // if end of word
        if (current != ' ' && current != '\0' && current != '\t' && current != '\n' && current >= a && current <= z)
        {
        //if you bigger then 256 do *2 for size
            if(count==Max) {
                c = (char *) realloc(word, (Max * 2) * sizeof(char));
                Max = Max * 2;
                //if the c is null free word
                if (c == NULL && word != NULL) {
                    free(word);
                    return -1;
                }
                
                word = (char*)calloc(Max, sizeof(char));
                strcpy(word,c);
                free(c);
            }
            // add the current word
            word[count] = current;
            count++;

        }
	
        //end of the word
        else if ((current == ' ' || current == '\0' || current == '\t' || current == '\n') || current == EOF)
        {

            if (word[0] != '\n'&& word[0] != '\0')
            {
                
                    //insert then reset with /0
                    word[count] = '\0';
                    Insert(root, word);
                    resetWord(word);
                    count = 0;
                
            }
        }
       
        if(current == EOF) 
        counter1 = 1;

        current = getchar();
    }
    //choice reverse or none reverse
    if (argc == 2 && strcmp(argv[1], "r")==0)
    {
        printR(root, word, 0);
    }
    else
    {
        print(root, word, 0);
    }
    //free the last word 
	free(word);
    //free all the tree
    Free(root);
    return 0;
}