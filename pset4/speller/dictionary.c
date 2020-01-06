Skip to content
Search or jump to…

Pull requests
Issues
Marketplace
Explore
 
@mo2274 

  
// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents number of buckets in a hash table
#define N 26

// Represents a hash table
node *hashtable[N];

// Hashes word to a number between 0 and 25, inclusive, based on its first letter
unsigned int hash(const char *word)
{
    return tolower(word[0]) - 'a';
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    unsigned int   key ;
    node *new_node ;

    // Initialize hash table
    for (int i = 0; i < N; i++)
    {
        hashtable[i] = NULL;
    }

    // Open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        unload();
        return false;
    }

    // Buffer for a word
    char word[LENGTH + 1];

    // Insert words into hash table
    while (fscanf(file, "%s", word) != EOF)
    {
        // calculate the key
        key = hash(word);

        // check if there is no nodes in the list
        if (hashtable[key] == NULL)
        {
            // create node
            hashtable[key] = malloc(sizeof(node));
            // check if there is enough memory
            if (hashtable[key] == NULL)
            {
                return false;
            }
            // add the name to the node
            strcpy(hashtable[key]->word, word) ;
            // make it the last node
            hashtable[key]->next = NULL ;

        }
        // else if there is at least one node
        else
        {
            // create new node
            new_node = malloc(sizeof(node)) ;

            // check if there is enough memory
            if (new_node == NULL)
            {
                return false;
            }

            // add the name to the node
            strcpy(new_node->word, word) ;


            // make the node the last node
            new_node->next = hashtable[key]  ;

            // make the head pointer points to the new node
            hashtable[key] = new_node ;

        }
    }

    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    unsigned int num_of_words = 0;
    node *current_node ;
    node *next_node ;


    // loop till the last key whose value is 25
    for (int i = 0; i < 26; i++)
    {
        // save the address of the current node
        current_node  = hashtable[i] ;

        // free all the remaining nodes
        while (current_node != NULL)
        {
            // save the address of the next node
            next_node = current_node->next ;
            // count the words
            num_of_words++ ;

            // update the current node with the next node
            current_node = next_node;

        }
    }

    return num_of_words;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    unsigned int key ;
    node *temp ;

    // determine the key
    key = hash(word);

    // determine the linked list of the word
    temp = hashtable[key];

    // loop till the end of the list
    while (temp != NULL)
    {
        // check if you find the word
        if (compare_strings(temp->word, word) == 1)
        {
            return true ;
        }

        // go to the next node
        temp = temp->next ;

    }


    // return false if you did not find the word
    return false;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    node *current_node ;
    node *next_node ;


    // loop till the last key whose value is 25
    for (int i = 0; i < 26; i++)
    {
        // save the address of the current node
        current_node  = hashtable[i] ;

        // free all the remaining nodes
        while (current_node != NULL)
        {
            // save the address of the next node
            next_node = current_node->next ;
            // free the current node
            free(current_node);
            // update the current node with the next node
            current_node = next_node;

        }
    }

    // success
    return true;
}

// compare two strings
bool compare_strings(const char *s1, const char *s2)
{

    int s1_length ;
    int s2_leghth ;

    // get the length of the two strings
    s1_length = strlen(s1) ;
    s2_leghth = strlen(s2) ;

    // check if the two strings not equal in length
    if (s1_length != s2_leghth)
    {
        return false ;
    }

    // compare the two strings character by character
    for (int i = 0; i < s1_length; i++)
    {
        // the word does not exist
        if (s1[i] != tolower(s2[i]))
        {
            return false ;
        }
    }



    // the word does exist
    return true;
}
