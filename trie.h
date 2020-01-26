
#define LETTERS 26
#include <stdbool.h>
#include <stdio.h>


typedef struct Node
{
    bool flag1;
    bool flag2;
    struct Node* childs[LETTERS];
    long unsigned int Counter ;

}Node;



void Insert(Node* root , char* new);

void print(Node *root, char * str, int index);

void printR(Node *root, char * string, int index);

int Help(Node *current);

Node* AddNode();

void Free(Node* );

void resetWord(char *word);


#endif 