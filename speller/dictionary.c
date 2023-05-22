// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dictionary.h"
#include <cs50.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

char w[LENGTH + 1];
unsigned int sizeo = 0;
// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int val = hash(word);
    node *cursor = table[val];

    while(cursor != NULL)
    {
        if(strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        else
        {
            cursor = cursor->next;
        }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int sum = 0;
    for(int i = 0; word[i] != '\0'; i++)
    {

        sum += tolower(word[i]);
    }

    return sum % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");

    if(file == NULL)
    {
    return false;
    }

    while(fscanf(file, "%s", w) != EOF)
    {
        node *n = malloc(sizeof(node));
        if(n == NULL)
        {
            return false;
        }
        int h = hash(w);

        strcpy(n->word, w);
        n->next = table[h];
        table[h] = n;
        sizeo++;
    }

        fclose(file);
        return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return sizeo;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{

    for(int i = 0; i < 26; i++)
    {
        node *cursor = table[i];
        node *tmp = cursor;
        while(cursor != NULL)
        {

            cursor = cursor->next;
            free(tmp);
            tmp = cursor;
        }
    }
    return true;
}
