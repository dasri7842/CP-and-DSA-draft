#include <iostream>
#include <vector>
using namespace std;
#define forn1(i,n) for(int i=1;i<=n;i++)

//singly linked list node .
//it contains a data and a pointer to another node.

struct node{
	int data;
	node *next;
};

//STaque can be used as a stack and queue at the same time .in simple words as a stack from one end and as a queue from another end.
// pop() -> which delets front item.
// push_front() -> adds element at the front.
// push_back() ->adds element at the back.

class STaque{
	private:
	node *head=NULL,*rear=NULL;
	int qsize=0;
	public:
	void pop(){
		if(head==NULL) return;
		qsize--;
		delete(head);
		head=head->next;
		if(head==NULL) rear=NULL;
	}
	void push_front(int val){
		node *k=new node;
		k->data=val;
		k->next=head;
		if(!qsize){
			rear=k;
		}
		head=k;
		qsize++;
	}
	void push_back(int val){
		node *k=new node;
		k->data=val;
		k->next=NULL;
		if(!qsize){
			rear=head=k;
			qsize++;
			return;
		}
		rear->next=k;
		rear=k;
		qsize++;
	}
	
	int front(){
		if(head==NULL){
			cout<<"queue is empty!\n";
			return -1;
		}
		return head->data;
	}
	
	int size(){
		return qsize;
	}
	
	bool empty(){
		return !qsize;
	}
};

int main(){
	STaque ok;
	cout<<"as a stack\n";
	forn1(i,10){
		ok.push_front(i);
	}
	while(!ok.empty()){
		cout<<ok.front()<<" ";
		ok.pop();
	}
	cout<<"\nas a queue\n";
	forn1(i,10){
		ok.push_back(i);
	}
	while(!ok.empty()){
		cout<<ok.front()<<" ";
		ok.pop();
	}
	cout<<"\nas a STaque\n";
	forn1(i,10){
		ok.push_front(i);
	}
	forn1(i,10){
		ok.push_back(i);
	}
	while(!ok.empty()){
		cout<<ok.front()<<" ";
		ok.pop();
	}
}
