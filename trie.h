#define NUM_LETTERS 26
#define MAKE_SMALL_CHAR 32
typedef enum
{
    false = 0,
    true = 1
} boolean;

typedef struct Node {
	char letter;
    long unsigned int count;
	struct Node* children[NUM_LETTERS];
    boolean isLeaf;                     //indicate whether this node is a end of word
} Node;

typedef struct Trie
{
    Node *root;
} Trie;

Trie *newTrie();
Node *newNode(char l);
//void readFromTheText();
void addStrToTrie(char* str, int len , Trie *t);
void printlec(Node *root, char *str, int level);
void printlecR(Node *root, char *str, int level);
void freeTrie(Trie *trie);
void freeNode(Node *node);
