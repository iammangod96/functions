#include<iostream>
#include<stdlib.h> //for malloc

using namespace std;

typedef struct tree {int item;struct tree* parent;struct tree* left;struct tree* right;} tree;

//searching
tree* BST_search(tree* l,int tbs){if(l == NULL){return NULL;}if(l->item == tbs){return l;}
	if(l->item >tbs){return BST_search(l->left,tbs);}else{return BST_search(l->right,tbs);}}

//minimum
tree* BST_minimum(tree* l){if(l==NULL){return NULL;}tree* min;min = l;if(min->left != NULL){min = min->left;}return min;}

//maximum
tree* BST_maximum(tree* l){if(l==NULL){return NULL;}tree* max;max = l;if(max->right != NULL){max = max->right;}return max;}

//traversal
void BST_traverse(tree* l){if(l!=NULL){BST_traverse(l->left);
		//	process l;// change this line;
		BST_traverse(l->right);
	}}

//insertion
void BST_insert(tree*& l,int x,tree* parent){tree* p;if(l==NULL){
p = (tree*)malloc(sizeof(tree));p->item = x;p->left = NULL;p->right = NULL;p->parent = parent;l = p;return;}
if(x<l->item){BST_insert(l->left, x, l);}else{BST_insert(l->right, x, l);}}

int main(){
	

	
	return 0;
}
