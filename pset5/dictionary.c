/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "dictionary.h"



//define node
typedef struct node
{
    bool is_word;
    struct node* children[27]; //alphabet and apostrophie
}
node;

//define root
node *root;

unsigned int total_nodes = 0;

//if apostrophie return last position, otherwise return char from start
int getIndex(const char c)
{
    if (c == '\'')
    {
        return 26;
    }
    else
    {
        return tolower(c) % 'a';
    }
}

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{ 
    // TODO
        node *cursor = root;
        
        //iterate through each letter in the word
        for (int i = 0; word[i] != '\0'; i++)
        {
            //get index of the letter and go to that item in children unless null
            int index = getIndex(word[i]);
            if (cursor->children[index] == NULL)
            {
                return false;
            }
            //otherwise move on to next letter
            cursor = cursor->children[index];
        }
        
        //once at end of input, check if its a word
    return cursor->is_word;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    // TODO
    //create space
    root = malloc(sizeof(node));
    total_nodes = 0;
    
    //read the dictionary
    FILE *dict = fopen(dictionary, "r");
    if(dict == NULL)
    {
        printf("Could not open %s.\n", dictionary);
        unload();
        return false;
    }
    
    //set cursor to point to root
    node *cursor = root;
    
    //iterate through every character in the dictionary
    for (int c = fgetc(dict); c != EOF; c = fgetc(dict))
    {
        //if its a new line, mark this point as a new word adn reset cursor
        if (c == '\n')
        {
            cursor->is_word = true;
            total_nodes ++;
            cursor = root;
        }
        else
        {
            //find index of letter, if it doesnt exist create a new node
            int index = getIndex(c);
            if (cursor->children[index] == NULL)
            {
                cursor->children[index] = malloc(sizeof(node));
            }
            
            //move on to next mode
            cursor = cursor->children[index];
        }
    }
    
    //when done, close dictionary
    fclose(dict);
    
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return total_nodes;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */

    bool free_nodes(node *ptr)
    {
        //iterate though all the children of node
        for( int i = 0; i < 27; i++)
        {
            //check if children are pointer too, so forth, free them all
            if (ptr->children[i] != NULL)
            {
                free_nodes(ptr->children[i]);
            }
        }
        
        //free all null children
        free(ptr);
        
        return true;
    }


bool unload(void)
{
    // TODO
    
    return free_nodes(root);
}
