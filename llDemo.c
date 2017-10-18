#include <stdio.h>		/* for printf */
#include <stdlib.h>		/* for free() */
#include <string.h> 		/* for strlen */
#include "llist.h"		/* for list operations */


/* read no more than limit chars into s, return #chars read.  Doesn't include trailing \n */
int gets_n(char *s, int limit)	
{
  char *p = s;			/* for indexing into s */
  char c;
  if (fgets(s, limit, stdin)) {
    while ((c = *p) && c != '\n') /* scan p through s until 0 or \n */
      p++;
    if (c == '\n')		/* erase \n */
      *p = 0;
  }
  return (p - s);		/* #chars read (not including terminator or \n*/
}

void main(){
  Tree *tree = treeAlloc();//creates the list
  char buf[100];
  while(strcmp(buf, "done") != 0){
      
      printf("Enter name of employee or enter \"done\" to exit\n");
      gets_n(buf, 100);
      if(strcmp(buf, "done") == 0)break;
      makeNode(tree, buf);
    }
    print(tree);
    /*printf("What is the name of the employee you wish to remove\n");
    scanf("%s", buf);
    Node *temp = findNode(tree, buf);*/
    deleteNode(tree->root);
    printf("\n");
    print(tree);
    createFile(tree);
    readFile();
    
}
