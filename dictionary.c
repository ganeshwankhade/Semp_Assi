#include "dictionary.h"
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>

// this function concatenates a letter to agiven set of letters
char *concat(char *begin, char letter){
	//allocating memory for the new char set
	char *result = malloc(sizeof (char)* (strlen (begin) + 2));
	int i = 0;
	
	//coping the existing prefix to new memory
	while(begin[i]!='\0'){
		result[i] = begin[i];
		i++;
	} 
	
	//put the letter to end of it
	result[i++] = letter;
	result[i] = '\0';
	
	//returning the reference of concatenated chars
	return result;
}


// this function inserts a new word to the trie creating appropriate nodes
void insert(TrieNode *node, char *word){

	int len = strlen(word);		
	int i;
	
	//populating the new word to the trie
	for(i = 0; i<len; i++){
		TrieNode *currentNode = node->children[word[i] % 97];
		
		//creating a new node if a matching node is not present in the trie
		if(currentNode == NULL){
			int i;
			currentNode = malloc(sizeof(TrieNode));
			currentNode->isEndOfWord = 0;
			for(i = 0; i < 26; i++)currentNode->children[i] = NULL;
		}
		
		//setting the last node corresponding to the last letter of the word as 'end of a word'
		if(i + 1 == len){
			currentNode->isEndOfWord = 1;
			}

		node->children[word[i] % 97] = currentNode;
		node = node->children[word[i] % 97];
	}

}

// this function prints all the words from a given prefix root
void print(TrieNode *subRoot, char *prefix){

	//base case returning if the node is null
	if(subRoot == NULL) 
		return;
	
	//start printing if 'is end of word' is set
	if(subRoot->isEndOfWord){
		printf("%s\n", prefix);
		}
	
	//recursive calling with the next letter concatinated
	int i;
	for(i = 0; i < 26; i++){
		if(subRoot->children[i] != NULL){
			print(subRoot->children[i], concat(prefix, i + 97));
		}
	}
}

//this function finds the subroot of a given prefix and call print
//to print all the words from that subroot
void search(TrieNode *root, char *prefix){
	TrieNode *subRoot = root;
	int len = strlen(prefix);
	int i;
	
	//iterating until the subroot
	for(i = 0; i < len; i++){
		subRoot = subRoot->children[prefix[i] % 97];
		} 
	
	//calling print to print all the words starting from that subroot
	print(subRoot, prefix);
}

//-----------------------------------------------


node* load()
{
    int i;
     node* root=NULL;
    // Initialize trie for dictionary
    if ((root = malloc (sizeof(node))) == NULL)
    {
        printf ("Out of memory. Dictionary could not be loaded.\n");

    }
    for (i = 0; i < 26; i++)
        root -> child[i] = NULL;
    root->end_of_word=0;
	int index;
	node* tmp = root;

    // Dictionary file
    FILE *dict_file=fopen("resources/dictionary1.txt","r+");

    // Dictionary file not opened
    if (dict_file == NULL)
       printf("Error opening dictionary");

    // Store words from Dictionary file
    char word_str[20];
    char meaning[200];


   while((fscanf(dict_file,"%s",word_str))!=EOF)
    { fgets(meaning,200,dict_file);
       int word_len = strlen(word_str);

        for(i=0;i<word_len;i++)
       {



            // Handle letters of the alphabet
            // Neglect character case
             if (isalpha (word_str[i]))
                index = (int)tolower (word_str[i]) - 'a';

            // Handle error cases
            if (index > 25 || index < 0)
                continue;

            // Insert character from word read from dictionary into Trie
            if (tmp -> child[index] == NULL)
            {
                // Create and initialize new next nodes for subsequent letter
                if ((tmp -> child[index] = malloc ( sizeof (node))) == NULL)
                {
                    printf ("Out of memory. Dictionary could not be loaded.\n");

                }
                tmp = tmp -> child[index];
                for (int j = 0; j < 26; j++)
                    tmp -> child[j] = NULL;
                    tmp->end_of_word=0;
            }
            else
                tmp = tmp -> child[index];
             // Set word as present in dictionary
            if (i == word_len - 1){
                tmp -> end_of_word =1;
                strcpy(tmp->meaning,meaning);
                }
        } tmp=root;


    // If end of file not reached before loop termination and error indicator is not set


} fclose(dict_file);

return root;
}
void unload_rec (node* dict_rem)
{
    node* tmp = dict_rem;

    // Recursively freeing allocated memory
    for (int i = 0; i < 26; i++)
        if (tmp -> child[i] != NULL)
            unload_rec (tmp -> child[i]);

    free (tmp);
    tmp = NULL;


}
char* search1(node *root, char* key)
{
    node *pCrawl = root;

    for (int i = 0;key[i]!='\0'; i++)
    {
        int index = (int)tolower(key[i]) - 'a';
        if (pCrawl->child[index]==NULL)
            return NULL;

        pCrawl = pCrawl->child[index];
    }

    if((pCrawl->end_of_word==1))
        return pCrawl->meaning;
    else return NULL;
}
void view()
{
    FILE *dict_file=fopen("resources/dictionary1.txt","r");
    if (dict_file == NULL)
       printf("Error opening dictionary");
    char word_str[20];
    char meaning[200];
   while((fscanf(dict_file,"%s",word_str))!=EOF)
    { fgets(meaning,200,dict_file);

       printf("%s\n",word_str);
    }
    fclose(dict_file);
}

void add(node* root)
{
    char word1[20];
    char meaning[200];
    char tmpmeaning[20];
    printf("Enter the word to add\n");
    scanf("%s",word1);
    printf("Enter the meaning\n");
   scanf("%s",meaning);
    int word_len = strlen(word1);
int index;
node* tmp=root;
        for(int i=0;i<word_len;i++)
       {



            // Handle letters of the alphabet
            // Neglect character case
             if (isalpha (word1[i]))
                index = (int)tolower (word1[i]) - 'a';

            // Handle error cases
            if (index > 25 || index < 0)
                continue;

            // Insert character from word read from dictionary into Trie
            if (tmp -> child[index] == NULL)
            {
                // Create and initialize new next nodes for subsequent letter
                if ((tmp -> child[index] = malloc ( sizeof (node))) == NULL)
                {
                    printf ("Out of memory. Dictionary could not be loaded.\n");

                }
                tmp = tmp -> child[index];
                for (int j = 0; j < 26; j++)
                    tmp -> child[j] = NULL;
                    tmp->end_of_word=0;
            }
            else
                tmp = tmp -> child[index];
             // Set word as present in dictionary
            if (i == word_len - 1){
                tmp -> end_of_word =1;
                strcpy(tmp->meaning,meaning);
                }
        }
    FILE *dict_file=fopen("resources/dictionary1.txt","a");

    fprintf(dict_file,"\n%s ",word1);fputs(meaning,dict_file);
    fclose(dict_file);


}
// returns 1 if given node has any children
int haveChildren(node* curr)
{
	for (int i = 0; i < 26; i++)
		if (curr->child[i])
			return 1;	// child found

	return 0;
}

// Recursive function to delete a string in Trie
int deletion(node **curr, char* str)
{
	// return if Trie is empty
	if (*curr == NULL)
		return 0;

	// if we have not reached the end of the string
	if (*str)
	{
		// recur for the node corresponding to next character in
		// the string and if it returns 1, delete current node
		// (if it is non-leaf)
		if (*curr != NULL && (*curr)->child[*str - 'a'] != NULL &&
			deletion(&((*curr)->child[*str - 'a']), str + 1) &&
			(*curr)->end_of_word == 0)
		{
			if (!haveChildren(*curr))
			{
				free(*curr);
				(*curr) = NULL;
				return 1;
			}
			else {
				return 0;
			}
		}
	}

	// if we have reached the end of the string
	if (*str == '\0' && (*curr)->end_of_word)
	{
		// if current node is a leaf node and don't have any children
		if (!haveChildren(*curr))
		{
			free(*curr); // delete current node
			(*curr) = NULL;
			return 1; // delete non-leaf parent nodes
		}

		// if current node is a leaf node and have children
		else
		{
			// mark current node as non-leaf node (DON'T DELETE IT)
			(*curr)->end_of_word = 0;
			return 0;	   // don't delete its parent nodes
		}
	}

	return 0;
}

