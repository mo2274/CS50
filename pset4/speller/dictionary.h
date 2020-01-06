
  
/*
 *      DICTIONARY.h
 *
 *  Created on: 10 // 12 // 2019
 *      Author: Mohamed Abo Raia.
 */



// Declares a dictionary's functionality

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>

// Maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45

// Represents a node in a hash table
typedef struct node_1
{
    char word[LENGTH + 1];
    struct node_1 *next;
}
node;

// Prototypes

/*
 *                      Load function
 * This function is used to load words from dictionary to memory using hash table
 * @param  : const char *dictionary : string that represent the dictionary name .
 * @return : bool                   : return true if every thing is done properly and false other wise
 *
 */
bool load(const char *dictionary);
/*
 *                      Size function
 * This function is used to calculate the number of words in the dictionary .
 * @param  : void  : the function will take nothing .
 * @return : bool  : return true if every thing is done properly and false other wise
 *
 */
unsigned int size(void);
/*
 *                      Check function
 * This function is used to  check if a word is exist in the dictionary or not .
 * @param  : const char *word : the word that we will search for  .
 * @return : bool             : return true if every thing is done properly and false other wise
 *
 */
bool check(const char *word);
/*
 *                      Unload function
 * This function is used to  free the memory that used to store the dictionary .
 * @param  : void : the function will take nothing .
 * @return : bool : return true if every thing is done properly and false other wise
 *
 */
bool unload(void);
/*
 *                      Print_list function
 * This function is used to  print a linked list .
 * @param  : node *head : the address of the first node of the list .
 * @return : char       : return 0 if every thing is done properly and 1 other wise
 *
 */
char print_list_2(node *head);
/*
 *                      compare_strings function
 * This function is used to  compare two strings in case insensitive way .
 * @param  : char *s1 : the first string must be lower case letters .
 * @param  : char *s1 : the second string .
 * @return : bool     : return 1 if the two strings are equal.
 *
 */
bool compare_strings(const char *s1, const char *s2);

