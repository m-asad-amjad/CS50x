// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

int word_count = 0;
// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    //obtainig hash value
    int hash_value = hash(word);

    //access link list in hash table
    node *cursor = table[hash_value];

    while(cursor != NULL)
    {
        if(strcasecmp(cursor->word,word) == 0)
        {
            return true; //found
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
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }
    //open dictionary file
    FILE *dictionary_file = fopen(dictionary,"r");

    if (dictionary_file == NULL)
    {
        printf("could not open file");
        return false;
    }

    //read words from dictionary file
    char buffer [LENGTH + 1];

    while(fscanf(dictionary_file, "%s", buffer) == 1)
    //creating new node for each word
    {
        node *new_word = malloc(sizeof(node));

        if (new_word == NULL)
        {
            fclose(dictionary_file);
            return false;
        }
    //hash word to obtain hash value
    int hash_value = hash(buffer);

    //inserting node into hash table
    strcpy(new_word->word, buffer);
    new_word->next = table[hash_value];
    table[hash_value] = new_word;

    word_count++;
    }
    fclose(dictionary_file);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for(int i = 0; i < N; i++)
    {
        node *cursor = table[i];

        while(cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    return true;
}

