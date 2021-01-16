#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

int main(int argc, char *argv[]){
    if (argc > 2 || (argc == 2 && strcmp(argv[1], "r") != 0))
    {
        printf("Invalid parameters!\n");
        return 1;
    }
    int size = 200;   
    Trie *trie = newTrie(); //Initialize new trie.
    char *str = (char*)malloc(sizeof(char)*size);
    if(str == NULL){
        printf("Failed to reallocate new memory space.."); 
        return 1;
    }
    int j=0;//the lenght of the word
    int maxS=0;//the max lenght of word
    while (scanf("%c", (str+j)) == 1)//enter to the str
    {
        if(str[j] != ' ' && str[j] !='\0' && str[j] !='\n'){
            if(j==size-2){
                size =size*2;
                char *temp =(char*)malloc(sizeof(char)*size);
                if(temp == NULL) {
                    printf("Failed to reallocate new memory space..");
                    return 1;
                    }
                else {
                    strcpy(temp , str);
                    free(str);
                    str = (char*)malloc(sizeof(char)*size);
                    strcpy(str, temp);
                    free(temp);
                    break;
                }
            }
            j++;
        }
        else if(str[j] == ' ' || str[j] =='\0' || str[j] =='\n'){//when the word is and
            if(j > maxS) maxS = j;
            addStrToTrie(str ,j, trie);//send the word to the trie
            j=0;
            free(str);//free the string
            str = (char *)malloc(sizeof(char) * size);//init new
            if(str == NULL) {
                printf("Failed to reallocate new memory space..");  
                return 1;
            }

        }
    }
    char cha[maxS];
    if (argc == 2) //if there is 'r' parameter, print reverse.
    {
        printlecR(trie->root,cha,0);
    }
    else //Otherwise
    {
        printlec(trie->root,cha,0);
    }
    free(str);  
    freeTrie(trie); //free memory

    return 1;
}