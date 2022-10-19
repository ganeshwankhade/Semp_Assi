#include "dictionary.h"
#include <stdbool.h>
#include <time.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>


#define INPUT_WORD_SIZE (100)

// this function is used to take inputs from the user
char *receiveInput(char *s){
    scanf("%99s", s);
    return s;
}

// this function is used to validate the user's input
bool isValidWord(char *word){
	int len = strlen(word);
	int i;

	for(i = 0; i < len; i++){
		if((int)word[i] < 97 || (int)word[i] > 122){
			return false;
			}
		} 
	return true;
}

int main(){
	TrieNode root;
	int i;
	char word[INPUT_WORD_SIZE];
	char input[INPUT_WORD_SIZE];
	
	// setting the main root as 'not a word'
	root.isEndOfWord = 0;


//-----------------------------------------------------------------------------

node* root1=load();
   int ch;
   char word1[50];
   char meaning[200];
//----------------------------
   for(i = 0; i < 26; i++){
		root.children[i] = NULL;
		} 
	
	// opening resource file to populate the trie
	FILE *fp = fopen("resources/dictionary.txt", "r");
	if(fp == 0){
		fprintf(stderr, "Error while opening dictionary file");
		exit(1);
	}
	
	// populating the trie by taking inputs from the file line by line
	while(!feof (fp)){
		fscanf(fp, "%s", word);
		insert(&root, word);
	}
	
	fclose(fp);

//------------------------------------------------------------

   while(1)
   {
    printf("\n");
    printf("----------------------------");
    printf("\n\t1.View\n\t2.Add\n\t3.Search\n\t4.Delete\n\t5.Prefix Search\n\t6.Exit\n");
    printf("----------------------------");
    printf("\nEnter your choice : ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 6: printf("Unloading dictionary");
                  unload_rec(root1);
                  exit(0);
            break;
        case 1: view();
            break;
        case 2: add(root1);
            break;
        case 3: printf("Enter the word:\n");
                  scanf("%s",word1);

                  
                   for(int i=0;i<1000;i++);

                 if(search1(root1,word1))
                  {


                      strcpy(meaning,search1(root1,word1));
                      printf("Meaning:%s\n",meaning);

                  }
                  else printf("Word not found\n");
                

            break;
        case 4: printf("Enter the word to be deleted:\n");
                scanf("%s",&word1);
                deletion(&root1,word1);
            break;
       

        case 5:printf("Enter keyword: ");
               receiveInput(input);
               printf("\n==========================================================\n");
               printf("\n********************* Possible Words ********************\n");
		
		       if(isValidWord(input)){
			   clock_t begin = clock();
			   search (&root, input);
			   clock_t end = clock();
			   double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
			   printf("%f", time_spent);
		    }else
			   printf("\n===================== Invalid Input =====================\n");

        default : printf("\nEnter a valid key\n");

		
	
        // printf("==========================================================\n");
	}
}
return 0;
}

