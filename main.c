#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

//main pogram
int main(int argc, char *argv[]){
    if (argc > 2 || (argc == 2 && strcmp(argv[1], "r") != 0))
    {
        printf("Invalid parameters!\n");
        return 1;
    }
    int size = 100;   
    Trie *trie = newTrie(); //Initialize new trie.
    char *str = (char*)malloc(sizeof(char)*size);
    if(str == NULL){
        printf("Failed to reallocate new memory space.."); 
        return 1;
    }
    int j=0;//the lenght of the word
    int maxS=0;//the max lenght of word

    while (scanf("%c", (str+j)) == 1){/*enter to the str*/
        //when the word is and
        if(str[j] == EOF || str[j] == ' ' || str[j] =='\0' || str[j] =='\n'){
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
        else{        
            if(j==size-1){
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
    }
    char cha[maxS];
    cha[0]='\0';
    //if there is 'r' parameter, print reverse.
    if (argc == 2) {
        printlecR(trie->root,cha,0);
    }
    else {
        printlec(trie->root,cha,0);
    }
    free(str);  //free str
    freeTrie(trie); //free memory
    return 0;
}