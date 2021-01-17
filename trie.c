#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

Trie *newTrie()
{
    Trie *trie = (Trie *)malloc(sizeof(Trie)); //memory allocate
    if(trie == NULL){
        printf("Failed to reallocate new memory space.."); 
        return NULL;
    }
    trie->root = newNode(' ');//root is node with empty data
    trie->root->isRoot = true;
    return trie;
}

Node *newNode(char l){
    Node *node = (Node *)malloc(sizeof(Node)); //memory allocate
    if(node == NULL){
        printf("Failed to reallocate new memory space.."); 
        return NULL;
    }
    node->letter = l;
    node->count = 0;
    node->isLeaf = false;
    node->isRoot = false;
    //init the children array
    for (int i = 0; i < NUM_LETTERS; i++) {
        node->children[i] = NULL;
    }
    return node;
}

//add to the trie the words
void addStrToTrie(char* str, int len , Trie *t){
    char charIndex=' ';
    Node *node = t->root;
    for(int i = 0 ; i < len ; i++){
        charIndex= *(str+i);
        //if the char in big letter --> add +32 the ascii value and make hime to small letter
        if ((charIndex >= 'A' && charIndex<='Z') || (charIndex >= 'a' && charIndex<='z')){
            if (charIndex >= 'A' && charIndex<='Z') {
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
void printlec(Node *root, char *str, int high){
    if (root == NULL) return; //void return nothing
    
    //check if this node is a leaf
    if (root->isLeaf == true && root->isRoot==false){ 
        str[high] = '\0';
        printf("%s %ld\n", str, root->count); //printing the string
    }
    int i;
    for (i = 0; i < NUM_LETTERS; i++){ //running from the lower to upper
        if (root->children[i] != NULL){
            str[high] ='a'+i;//add the letter to the String
            printlec(root->children[i], str, high + 1); //recurs
        }
    }
}
//print revers order
void printlecR(Node *root, char *str, int high){
    if (root == NULL) return; //void return nothing
    
    int i;
    //running from the big to small
    for (i = NUM_LETTERS - 1; i >= 0; i--){ 
        if (root->children[i] != NULL){
            str[high] ='a'+i;
            printlecR(root->children[i], str, high + 1);
        }
    }
    if (root->isLeaf == true && root->isRoot==false){
        str[high] = '\0';
        printf("%s %ld\n", str, root->count);
    }
}

//free the alloce from the memory
void freeTrie(Trie *trie){
    freeNode(trie->root);
    free(trie);
}
//free the nodes
void freeNode(Node *node){
    int i;
    for (i = 0; i < NUM_LETTERS; i++){
        if (node->children[i] != NULL){
            freeNode(node->children[i]);
        }
    }
    free(node);
}