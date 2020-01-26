#include <stdio.h>
#include "trie.h"
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define a 97
#define z 122
#define max 256
#define childrens 25

void Insert(Node *root, char *new)
{
    Node *Head = root;
    int length = strlen(new);

    for (size_t i = 0; i < length; i++)
    {
        if (Head->childs[*(new + i) - a])
        {
            Head = Head->childs[*(new + i) - a];
        }
        else
        {
            Head->childs[*(new + i) - a] = (Node *)malloc(sizeof(Node));
            Head = Head->childs[*(new + i) - a];
        }
    }
    Head->Counter = Head->Counter + 1;
}

Node *AddNode()
{
    Node *AddNode = (Node *)malloc(sizeof(Node));
    AddNode->count = 0;
    AddNode->flag1 = false;
    AddNode->flag2 = false;
    for (size_t i = 0; i < childrens; i++)
    {
        AddNode->childs[i] = NULL;
    }
    return AddNode;
}



void print(Node *root, char *string, int index)
{

    if (!Help(root))
    {
        string[index] = '\0';
        printf("%s %ld\n", string, root->count);
        return;
    }
    if (root->count > 0)
    {
        string[index] = '\0';
        printf("%s %ld\n", string, root->count);
    }
    for (int i = 0; i < LETTERS; i++)
    {
        if (root->childs[i])
        {
            string[index] = (char)(a + i);
            print(root->childs[i], string, index + 1);
        }
    }
}

void printR(Node *root, char *string, int index)
{

    if (!Help(root))
    {
        string[index] = '\0';
        printf("%s %ld\n", string, root->count);
        return;
    }
  
    for (int i = LETTERS - 1; i >= 0; i--)
    {
        if (root->childs[i])
        {
            string[index] = (char)(a + i);
            printR(root->childs[i], string, index + 1);
        }
    }
        if (root->count > 0)
    {
        if(string[0] == '\0') return;
        string[index] = '\0';
        printf("%s %ld\n", string, root->count);
    }
}

int Help(Node *current)
{
    int Flag = 0;
    for (size_t i = 0; i < childrens+1; i++)
    {
        if (current->childs[i])
            Flag = 1;
    }
    return Flag;
}

void Free(Node *root)
{
    Node *p = root;
    for (size_t i = 0; i < LETTERS; i++)
    {
        if (p->childs[i] != NULL)
        {
            Free((p->childs[i]));
        }
    }
    free(p);
}

void Reset(char *word)
{
    for (int i = 0; i < max; ++i)
    {
        word[i] = '\n';
    }
}
