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
    if(str == NULL) printf("Failed to reallocate new memory space.."); 
    int i = 0;
    int j=0;
    int k =0 ;
   int maxS=0;
    while (scanf("%c", (str+i)) == 1)
    {
        if(str[i] != ' ' && str[i] !='\0' && str[i] !='\n'){
        
            if(j==size-2){
                size =size*2;
                char *temp =(char*)malloc(sizeof(char)*size);
                if(temp == NULL) printf("Failed to reallocate new memory space..");
                if (!temp) {
                    strcpy(temp , str);
                    free(str);
                    str = (char*)malloc(sizeof(char)*size);
                    strcpy(str, temp);
                    free(temp);

                    break;
                }
            }
            i++;
            j++;
        }
        else if(str[i] == ' ' || str[i] =='\0' || str[i] =='\n'){
            if(j > maxS) maxS = j;
            addStrToTrie(str+k ,i , k , trie);
            j=0;
            k=i;
            free(str);
            str = (char *)malloc(sizeof(char) * size);
            if(str == NULL) printf("Failed to reallocate new memory space..");  

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
/* #include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "trie.h"
int main(){

    //readFromTheText();

   // int n;
  //  char *text;

    Trie *trie = newTrie(); //Initialize new trie.
   // text=(char*)malloc(n*sizeof(char));
    char *str = (char *)malloc(sizeof(char) * 2);
    int size = 0;
   // printf("Enter text: ");

   // scanf(" "); clear input buffer
//    gets(text);

  //  printf("Inputted text is: %s\n",text);
    int i = 0;
    int k =0 ;
    //char s[strlen(text)];

    printf("text[i] = %c ,",s[i]);
    while (scanf("%c", &ch) == 1)
    {
       
        while(text[i] == ' ' || text[i] =='\0' || text[i] =='\n')
        {
            i++;
            printf("text[i] = %c ,",text[i]);

        }
        addStrToTrie(text[k] ,i , k , trie);
        k=i;
        i++;

    }
    char ch[100];
    printlec(trie,ch,0);
    free(text);  
    freeTrie(trie); //free memory

    return 1;
}*/