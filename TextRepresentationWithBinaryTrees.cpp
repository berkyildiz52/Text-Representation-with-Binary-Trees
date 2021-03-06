#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

 
struct node {
    int key;
    struct node *left, *right;
};
 
// A utility function to create a new BST node
struct node* newNode(int item)
{
    struct node* temp
        = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
// A utility function to do inorder traversal of BST
void inorder(struct node* root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("%d \n", root->key);
        inorder(root->right);
    }
}
 
/* A utility function to insert
   a new node with given key in
 * BST */
struct node* insert(struct node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL)
        return newNode(key);
 
    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
 
    /* return the (unchanged) node pointer */
    return node;
}
 

 
 
// Driver Code
int main()
{
    FILE *input=fopen("input.txt","r");

char *word;
int frequency;
char line [50];

if(input ==NULL){
	printf("Error : Failed to open input file ");
	exit(1);
}

while (fgets(line,50,input)!=NULL){
	char *temp;
    strtok (line,",");
	char *word;
	char como[20];
	temp=strtok(NULL,",");
	word =temp;
	int i;
	for (i=0;i<25;i++){
		como [i]=tolower(word[i]);
	}
	
	
	frequency=atoi(strtok(NULL,","));
	

    struct node* root = NULL;
    root = insert(root, frequency);

inorder(root);
}

    return 0;
}


//https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/

