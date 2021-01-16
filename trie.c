#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

Trie *newTrie()
{
    Trie *new_trie = (Trie *)malloc(sizeof(Trie)); //Memory allocate
    new_trie->root = newNode(0);                   //Build node with no data for the root

    return new_trie;
}

Node *newNode(char l)
{
    Node *new_node = (Node *)malloc(sizeof(Node)); //Memory allocate
    new_node->letter = l;
    new_node->count = 0;
    new_node->isLeaf = false;
    for (int i = 0; i < NUM_LETTERS; i++) //Initialize the children array
    {
        new_node->children[i] = NULL;
    }

    return new_node;
}

void addStrToTrie(char* str, int len , Trie *t)
{
    char charIndex=' ';
    Node *node = t->root;
    for(int i = 0 ; i < len ; i++)
    {
        charIndex= *(str+i);
        //if the char in big letter --> add +32 the ascii value and make hime to small letter
        if ((charIndex >= 'A' && charIndex<='Z') || (charIndex >= 'a' && charIndex<='z'))
        {
            if (charIndex >= 'A' && charIndex<='Z') 
            {
                charIndex += MAKE_SMALL_CHAR;
            }
            if (node->children[charIndex - 'a'] == NULL){//font have word here
                Node *new = newNode(charIndex);
                node->children[charIndex - 'a'] = new;
            }
            node= node->children[charIndex-'a'];//moving on the trie
        }
    }
    node->isLeaf = true;
    node->count++;
}

//this func print all the word in order the letters
void printlec(Node *root, char *str, int level)
{
    if (root == NULL)
        return;

    if (root->isLeaf == true) //check if this node is a leaf
    {
        str[level] = '\0';
        printf("%s %ld\n", str, root->count); //print the String contains the word

    }

    int i;
    for (i = 0; i < NUM_LETTERS; i++) //running from the lower to upper
    {

        if (root->children[i] != NULL)
        {

            str[level] = i + 'a';                       //Add the letter to the String
            printlec(root->children[i], str, level + 1); //Recursive call
        }
    }
}

void printlecR(Node *root, char *str, int level)
{
    //Stop condition:
    if (root == NULL)
        return;
    

    int i;
    for (i = NUM_LETTERS - 1; i >= 0; i--) //Running for upper to lower
    {
        if (root->children[i] != NULL)
        {
            str[level] = i + 'a';
            printlecR(root->children[i], str, level + 1);
        }
    }

    if (root->isLeaf == true)
    {
        str[level] = '\0';
        printf("%s %ld\n", str, root->count);

    }

}
//free the alloce from the memory
void freeTrie(Trie *trie)
{
    freeNode(trie->root);
    free(trie);
}
//free the nodes
void freeNode(Node *node)
{
    int i;
    for (i = 0; i < NUM_LETTERS; i++)
    {
        if (node->children[i] != NULL)
        {
            freeNode(node->children[i]);
        }
    }
    free(node);
}