

#ifndef llist_included		/* prevent multiple inclusion */
#define llist_included

typedef struct Node{
    struct Node *right, *left;
    char *str;
}Node;

typedef struct{

    Node *root;
}Tree;

Node * addNode(Node *root, Node *newNode);
Tree * treeAlloc(); 
void makeNode(Tree *binTree, char *s);
void print(Tree *root);
void treePrint(Node *root);
//void remove(Node *node);
void deleteNode(Node *node);
char* removeNode(int i, Node *node);

void readFile();
void createFile(Tree *tree);
void writeFile(Node *node, FILE *file);

//Node* findNode(Tree *tree, char *str);
//Node* searchNode(Node *root, char *s);


//xtern int llDoCheck;		/* set true for paranoid consistency checking */




#endif	/* included */
