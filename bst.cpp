#include <iostream>
using namespace std;

struct node{
	int key;
	node *left,*right;
};
node * newnode(int val){
	node *temp=new node;
	temp->key=val;
	temp->left=temp->right=NULL;
	return temp;
}
//left root data.
void inorder(node *root){
	if(root!=NULL){
		inorder(root->left);
		cout<<root->key<<" ";
		inorder(root->right);
	}
}
node* search(node * root,int val){
	if(root==NULL|| root->key==val) return root;
	if(root->key<val)
		return search(root->right,val);
	return search(root->left,val);
}
void insert(node *&root,int val){
	if(root==NULL) {
		root=newnode(val);
		return;
	}
	if(val<root->key) insert(root->left,val);
	else if(val>root->key) insert(root->right,val);
}
int main(){
	node *root=NULL;
	insert(root, 30); 
	insert(root, 20);
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80); 
    inorder(root);
    cout<<search(root,20)->key;
}
