#include <bits/stdc++.h>
using namespace std;

class Trie{
   private :
      struct node{
         node * child[26];
         int end;
      };
      node * naya(){
         node * temp =new node;
         for(int i=0;i<26;i++) temp->child[i]=NULL;
         temp->end=0;
         return temp;
      }
      node * root=naya();

   public :
      node * Getroot(){
         return root;
      }
      void insert(string s){
         node * temp=Getroot();
         for(char x:s){
            int id=x-'a';
            if(!temp->child[id]) temp->child[id]=naya();
            temp=temp->child[id];
         }
         temp->end++;
      }
      int find(string s){
         node * temp=Getroot();
         for(char x:s){
            int id=x-'a';
            if(!temp->child[id]) return 0;
            temp=temp->child[id];
         }
         return temp->end;
      }
      void Print(node *temp ,string s){
         if(temp->end) cout<<s<<"\n";
         for(int i=0;i<26;i++){
            if(temp->child[i]){
               s+=('a'+i);
               Print(temp->child[i],s);
               s.pop_back();
            }
         }
      }
};

int main(){
   Trie mytrie;
   vector<string>arr={"asldflsdf","skldfjldkf","dfkskdd"};
   for(string s:arr) mytrie.insert(s);
   mytrie.Print(mytrie.Getroot(),"");
}
