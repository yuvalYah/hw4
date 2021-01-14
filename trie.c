#include <stdio.h>
#include <stdlib.h>
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

// void readFromTheText()
// {
//     int n;
//     char *text;
//     printf("Enter limit of the text: ");
//     scanf("%d",&n);
//     /*allocate memory dynamically*/
//     Trie *trie = newTrie(); //Initialize new trie.
//     text=(char*)malloc(n*sizeof(char));
//     printf("Enter text: ");

//     scanf(" "); /*clear input buffer*/
//     gets(text);

//     printf("Inputted text is: %s\n",text);
//     int i = 0;
//     int k =0 ;
//     while(text[i] !='\0')
//     {
       
//         while(text[i] == ' ' || text[i] =='\0' || text[i] =='\n')
//         {
//             i++;
//             printf("%c",text[i]);

//         }
//         addStrToTrie(text[k] ,i , k , trie);
//         //addStrToTrie(text[k] , len word=i ,start ind =k)
//         k=i;
//         //if ( i!=0 && text[i-1] == ' ' || text[i-1] =='\0' || text[i-1] =='\n')) k=i;
//         i++;

//     }
//     char ch[100];
//     printlec(trie,ch,0);
// /*Free Memory*/
//     free(text);  
//     freeTrie(trie); //free memory
// }
void addStrToTrie(char* str, int len, int startIndex , Trie *t)
{
    //printf(" i= %d ,k= %d",len,startIndex);
    char charIndex=' ';
    int size = len - startIndex;
    Node *node = t->root;
    for(int i = 0 ; i < size ; i++)
    {
        charIndex= *(str+i);
        if ((charIndex >= 'A' && charIndex<='Z') || (charIndex >= 'a' && charIndex<='z'))
        {
            if (charIndex >= 'A' && charIndex<='Z') 
            {
                charIndex += MAKE_SMALL_CHAR;
            }
            if (node->children[charIndex - 'a'] == NULL){
                Node *new = newNode(charIndex);
                node->children[charIndex - 'a'] = new;
            }
            node= node->children[charIndex-'a'];
        }
    }
    node->isLeaf = true;
    node->count++;
}

void printlec(Node *root, char *str, int level)
{
    //Stop condition:
    if (root == NULL)
        return;
    //

    if (root->isLeaf == true) //Check whether this node is a leaf
    {
        str[level] = '\0';
        printf("%s\t%ld\n", str, root->count); //Print the String contains the word until this node
    }

    int i;
    for (i = 0; i < NUM_LETTERS; i++) //Running from the lower to upper
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
        printf("%s\t%ld\n", str, root->count);
    }

}
void freeTrie(Trie *trie)
{
    freeNode(trie->root);
    free(trie);
}

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