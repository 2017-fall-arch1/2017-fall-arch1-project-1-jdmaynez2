#include <stdio.h>		/* for puts,  */
#include <stdlib.h> 		/* for malloc */
#include <assert.h>		/* for assert */
#include "llist.h"		
#include <string.h>

//int llDoCheck = 1;		/* set true for paranoid consistency checking */

#define doCheck(_lp) (llDoCheck && llCheck(_lp))

Tree* treeAlloc(){

    Tree *lp = (Tree *)malloc(sizeof(Tree));
    lp->root = NULL;
    
    return lp;
} 
    

/*Node* findNode(Tree *tree, char *str){
    Node *temp = searchNode(tree->root, str);
    if(temp == NULL){printf("name not found\n");return temp;}

    return searchNode(tree->root, str);
}

Node* searchNode(Node *root, char *s){
    if(root != NULL){
        if(strcmp(s, root->str) == 0){return root;}
        treePrint(root->left);
        //printf("%s\n", root->str);
        treePrint(root->right);
       
    }
    return NULL;
}*/
    
    
    
    





void readFile(){
    
    FILE *fileReader;
    char x;
    char str[20];
    printf("Whats the name of the file?\n");
    scanf("%s", str);
    fileReader = fopen(str, "r");
    
    if(fileReader == NULL){
        printf("unable to read file\n");
        exit(0);
    }
    x = fgetc(fileReader);//checks if characters have been read
    
    while(x != EOF){
        
        printf("%c", x);
        x = fgetc(fileReader);
    }
    printf("\n");
    fclose(fileReader);
}

void createFile(Tree *tree){
    
    FILE *file;
    file = fopen("tree.txt", "w");//w stands for write and r for read
    writeFile(tree->root, file);
}

void writeFile(Node *node, FILE *file){
    
    if(node != NULL){
    
        writeFile(node->left, file);
        printf("%s\n", node->str);
        fprintf(file, "%s\n", node->str);//writes into the file
        writeFile(node->right, file);
    }
}

void deleteNode(Node *node){
    if(node->left == NULL && node->right == NULL){node == NULL;}
    if(node->left != NULL ){
         node->str = removeNode(1, node->left);
        //node->str = temp;
    }
    else{
        node->str = removeNode(0, node->right);
    }
}

char* removeNode(int i, Node *node){
    
    if(i == 1){
        if(node->right != NULL){return removeNode(i, node->right);}
        else{
            if(node->left == NULL){
                char *replacement = node->str;
                node = NULL;
                return replacement;}
            else{
                Node *temp = node->left;
                node = NULL;
                node = temp;
                return node->str;
            }
        }
    }
    
    else{
        if(node->left != NULL){return removeNode(i, node->left);}
        else{
            if(node->right == NULL){
                char *replacement = node->str;
                node = NULL;
                return replacement;}
            else{
                Node *temp = node->right;
                node = NULL;
                node = temp;
                return node->str;
            }
        }
    }
}
/*append a copy of str to end of list */
void makeNode(Tree *binTree, char *s){

    int len;
    char *scopy;
    Node *i;
    
    i = (Node *)malloc(sizeof(Node));
    /*w = freshly allocated copy of putword*/
    for(len = 0; s[len];len++)//compute length
        ;
    scopy = (char *)malloc(len+1);
    for(len=0;s[len];len++)//copy chars
        scopy[len] = s[len];
    scopy[len] = 0;//terminate copy
    
    //i = new item containing s
    //i = (Node *)malloc(sizeof(Node));
    i->str = scopy;
    i->left = NULL;
    i->right = NULL;
    
    binTree->root = addNode(binTree->root, i);
}
    
Node* addNode(Node *root, Node *newNode){

    if(root == NULL){
    
        return newNode;
    }
    
    if(strcmp(root->str, newNode->str) < 0){
        
        root->right = addNode(root->right, newNode);
    }
    else{
    
        root->left = addNode(root->left, newNode);
    }
    
    return root;
}
    
    
    
    //new item is last on list 
   /* lp->last = i;
    doCheck(lp);
}*/
void print(Tree *tree){

    treePrint(tree->root);
}

void treePrint(Node *root){
    
    if(root != NULL){

        treePrint(root->left);
        printf("%s\n", root->str);
        treePrint(root->right);
       
    }
}
//print will be recursive af boiii!!
