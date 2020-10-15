#include <iostream>
#include <vector>
using namespace std;
#define forn(i,n) for(int i=0;i<n;i++)

class Stack{
	private:
	vector<int>arr;
	public:
	void push(int val){
		arr.push_back(val);
	}
	void pop(){
		if(arr.size()) arr.pop_back();
	}
	int top(){
		if(arr.size()) 
		return arr.back();
	}
	int size(){
		return arr.size();
	}
	bool empty(){
		return !arr.size();
	}
};

int main(){
	Stack ok;
	forn(i,10){
		ok.push(i);
	}
	while(!ok.empty()){
		cout<<ok.top()<<" ";
		ok.pop();
	}
}
