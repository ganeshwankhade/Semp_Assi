#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE (26)
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

typedef struct TrieNode{
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
} TrieNode;

//---------------------------------
struct node{
    struct node* child[26];
    int end_of_word;
    char meaning[100];
 };
 typedef struct node node;
node* load();
//-----------------------------------

void insert(TrieNode* root, char* word1);
void search(TrieNode *root, char *prefix);
void print(TrieNode *subRoot, char *prefix);
char *concat (char *begin, char letter);



//-------------------------------
void unload_rec (node* dict_rem);
char* search1(node *root1, char* key);
void view();
void add(node* root1);
int haveChildren(node* curr);
int deletion(node **curr, char* str);
//-------------------------------


