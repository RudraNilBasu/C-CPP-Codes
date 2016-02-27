/*
Implementation of trie
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define ALPHABET_SIZE 26
#define ALP_TO_INDEX(c) c-'a'
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
using namespace std;
typedef struct trie_node
{
    int value; // determines whether it is a leaf node or not
    struct trie_node *children[ALPHABET_SIZE]; // 26 positions for each letters
} trie_node_t;
// Trie ADt
typedef struct trie_t
{
    int count;
    struct trie_node *root;
} trie_t;
trie_node_t *getNode()
{
    trie_node_t *pNode=NULL;
    pNode=(trie_node_t *)malloc(sizeof(trie_node_t));
    //printf("%d\n",pNode);
    if(pNode)
    {
        int i;
        pNode->value=0;
        for(i=0;i<ALPHABET_SIZE;i++)
        {
            pNode->children[i]=NULL;
        }
    }
    return pNode;
}
int initialise(trie_t *pTrie)
{
    pTrie->root=getNode();
    pTrie->count=0;
}
void insert(trie_t *pTree,char key[])
{
    int level;
    int length=strlen(key);
    trie_node_t *pCrawl;
    pTree->count++;
    pCrawl=pTree->root;
    for(level=0;level<length;level++)
    {
        int index=ALP_TO_INDEX(key[level]);
        if(!pCrawl->children[index])
        {
            pCrawl->children[index]=getNode();
        }
        pCrawl=pCrawl->children[index];
    }
    //mark as leaf
    pCrawl->value=pTree->count;
}
int search(trie_t *pTree, char key[])
{
    int level;
    int length=strlen(key);
    trie_node_t *pCrawl;
    pCrawl=pTree->root;
    for(level=0;level<length;level++)
    {
        int index=ALP_TO_INDEX(key[level]);
        if(!pCrawl->children[index])
        {
            return 0;
        }
        pCrawl=pCrawl->children[index];
    }
    // either the key[] string has ended, or key[] string is longer or they matched
    return (0!=pCrawl && pCrawl->value);
}
// Initializes trie (root is dummy node)
void initialize(trie_t *pTrie)
{
    pTrie->root = getNode();
    pTrie->count = 0;
}
int main()
{
    // Input keys (use only 'a' through 'z' and lower case)
    char keys[][8] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
    trie_t trie;

    char output[][32] = {"Not present in trie", "Present in trie"};

    initialize(&trie);

    // Construct trie
    for(int i = 0; i < ARRAY_SIZE(keys); i++)
    {
        insert(&trie, keys[i]);
    }

    // Search for different keys
    printf("%s --- %s\n", "the", output[search(&trie, "the")] );
    printf("%s --- %s\n", "these", output[search(&trie, "these")] );
    printf("%s --- %s\n", "their", output[search(&trie, "their")] );
    printf("%s --- %s\n", "thaw", output[search(&trie, "thaw")] );

    return 0;
}
