#include <iostream>
using namespace std;
#define forn(i,n) for(int i=0;i<n;i++)

struct node{
	int data;
	node *next;
};

void append(node * &p,int val){
	node *k=new node, *l=p;
	k->data=val;
	k->next=NULL;
	if(p==NULL) {
		p=k;
		return;
	}
	while(l->next!=NULL) l=l->next;
	l->next=k;
}

void insert(node *p,int val){
	if(p==NULL){
		return;
	}
	node *k=new node;
	k->data=val;
	k->next=p->next;
	p->next=k;
}

void push(node * &h,int val){
	node *k=new node;
	k->data=val;
	k->next=h;
	h=k;
}

void print(node *p){
	while(p!=NULL){
		cout<<p->data<<" ->";
		p=p->next;
	}
	cout<<"NULL\n";
}

void removefront(node * &p){
	if(p==NULL) return;
	delete (p);
	p=p->next;
}

void removeback(node * &h){
	if(h==NULL) return;
	if(h->next==NULL) {
		h=NULL;
		return;
	}
	node *l=h;
	while(l->next->next!=NULL) l=l->next;
	delete (l->next);
	l->next=NULL;
}

void reverse(node *&h){
	node *prev=NULL,*cur=h,*nex=NULL;
	while(cur!=NULL){
		nex=cur->next;
		cur->next=prev;
		prev=cur;
		cur=nex;
	}
	h=prev;
}

int main (){
	node *h=NULL;
	forn(i,5) {
		append(h,i);
		reverse(h);
		print(h);
	}
}
