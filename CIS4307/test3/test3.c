#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct Node {
	struct Node *left;
	struct Node *right;
	int value;	
} node;

node *createnode(int value){
	node* result=malloc(sizeof(node));
	if(result != NULL) { // if malloc was successful 
		result->left = NULL;
		result->right = NULL;
		result->value = value;
	}
	return result; 
}

int largest(node *root);

void printtabs(int numtabs){
	for(int i=0; i<numtabs; i++){
		printf("\t");
	}
}

void printtree_rec(node *root, int level){
	if(root==NULL) {
		printtabs(level);
		printf("---<empty>---\n");
		return;
	}
	printtabs(level);
	printf("value = %d\n", root->value);
	printtabs(level);
	printf("left\n");

	printtree_rec(root->left,level+1);
	printtabs(level);
	printf("right\n");
	printtree_rec(root->right,level+1);
	printtabs(level);
	printf("done\n");
}

void printtree(node* root){
	printtree_rec(root,0);
}

int largest(node *root){
    // Base case
    if (root == NULL)
        return INT_MIN;
 
    // Return maximum of 3 values:
    // 1) Root's data 2) Max in Left Subtree
    // 3) Max in right subtree
    int res = root->value;
    int lres = largest(root->left);
    int rres = largest(root->right);
    if (lres > res)
        res = lres;
    if (rres > res)
        res = rres;
    return res;
}

int main(){
	node *n1 = createnode(10);
	node *n2 = createnode(11);
	node *n3 = createnode(123);
	node *n4 = createnode(13);
	node *n5 = createnode(14);
	node *n6 = createnode(9);
	node *n7 = createnode(11);

	n1->left=n2;
	n1->right=n3;
	n3->left=n4;
	n3->right=n5;
	n4->left=n6;
	n5->right=n7;

	printtree(n1);
	printf("\n\n");
	printf("largest value in tree is:\t%d\n", largest(n1));

	free(n1);
	free(n2);
	free(n3);
	free(n4);
	free(n5);
	free(n6);
	free(n7);
}
