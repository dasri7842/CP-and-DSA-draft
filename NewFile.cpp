#include<bits/stdc++.h>
using namespace std;

#define fi  first
#define se	second
#define lb	lower_bound
#define ub	upper_bound
#define pb	push_back
#define mp	make_pair
#define int long long
#define inf (int)1e18
#define num 100000007 
#define mod 998244353

#define all(x)	  x.begin(),x.end()
#define rev(x)	  x.rbegin(),x.rend()
#define forn(i,x) for(int i=0;i<x;i++)
#define forn1(i,x) for(int i=1;i<=x;i++)
#define Pi		  pair<int,int>
#define Vi		  vector<int>
#define VVi		  vector<Vi>
#define VPi		  vector<Pi>
#define Vb  	  vector<bool>
#define deb1(i)    cout<<i<<" ";
#define deb2(i,j)  cout<<i<<" "<<j<<"\n";
#define deb3(i,j,k) cout<<i<<" "<<j<<" "<<k<<"\n";

// void doit(int n,int p){
// 	int ans=INT_MAX,val;
// 	for(int i=0;i<(1<<n);i++){
// 		int a=0,b=0;
// 		for(int j=0;j<n;j++){
// 			if((i>>j)&1) a+=pow(j+1,p);
// 			else b+=pow(j+1,p);
// 		}
// 		if(abs(a-b)<=ans) ans=abs(a-b),val=i;
// 	}
// 	bitset<20>ok(val);
// 	cout<<"\t"<<p<<" "<<ans<<" "<<ok<<endl<<"\n";
// }






/*
// tree example
8 
1 2
2 4
2 5
1 6
1 3
3 7
3 8
*/

// fast exponention (a^n)%m.
int powr(int a,int n,int m){
	int res=1;
	a%=m;
	while(n){
		if(n%2) res=res*a%m;
		a=a*a%m;
		n/=2;
	}
	return res;
}

//seive of erathranoes
const int N=1e6+6;
Vb isprime(N,1);
Vi primes;
void preprocess(){
	isprime[0]=isprime[1]=0;
	for(int i=2;i*i<N;i++){
		if(isprime[i]){
			primes.pb(i);
			for(int j=i*i;j<N;j+=i) isprime[j]=0;
		}
	}
}

//prime factorisation.
void primefact(bool a, int x) {
	while(x%2==0){
		x/=2;
	}
	for(int i=3;i*i<=x;i+=2) {
		while(x%i==0){
			x/=i;
		}
	}
	if(x>2) ;
	return ;
}

// ncr calculations.
// const int N=100005;
vector<int>fact(N,1);
vector<int>modinv(N,-1);
void prefact(){
	for(int i=1;i<N;i++)
	fact[i]=fact[i-1]*i%num;
}
int powr(int a,int n,int m){
	int res=1;
	a%=m;
	while(n){
		if(n%2) res=res*a%m;
		a=a*a%m;
		n/=2;
	}
	return res;
}
int modI(int r){
	if(modinv[r]==-1)
		modinv[r]=powr(fact[r],num-2,num);
	return modinv[r];
}
int ncr(int n,int r) {
	if(n<r) return 0;
	return fact[n]*modI(r)%num*modI(n-r)%num;
}

//dsu
// const int N=3e5+5;
int par[N],sz[N];
void build(int n){
	forn1(i,n){
		par[i]=i;
		sz[i]=1;
	}
}
int find(int x){
	while(x!=par[x]) x=par[x];
	return x;
}
void merge(int a,int b){
	a=find(a),b=find(b);
	if(a==b) return;
	if(sz[a]<sz[b]) swap(a,b);
	sz[a]+=sz[b];
	par[b]=a;
}

// binary lifting ans lca.
int arr[N][20],hgt[N],par[N];
vector<int> A[N];
void dfs(int n,int p,int h){
	par[n]=p;
	hgt[n]=h;
	for(int x:A[n]){
		if(x!=p) dfs(x,n,h+1);
	}
}
void preprocess(int n){
	for(int j=0;j<20;j++){
		for(int i=1;i<=n;i++){
			if(j==0) arr[i][j]=par[i];
			else if(arr[i][j-1]!=-1)
			arr[i][j]=arr[arr[i][j-1]][j-1];
			else arr[i][j]=-1;
		}
	}
}
int kth_a(int n,int k){
	for(int i=0;i<20;i++){
		if((k>>i)&1) n=arr[n][i];
		if(n==-1) return n;
	}
	return n;
}
int lca(int a,int b){
	if(hgt[a]<hgt[b]) swap(a,b);
	a=kth_a(a,hgt[a]-hgt[b]);
	if(a==b) return a;
	for(int i=19;i>=0;i--){
		if(arr[a][i]!=arr[b][i]){
			a=arr[a][i];
			b=arr[b][i];
		}
	}
	return arr[a][0];
}

// zalgo for prefix matching and linear pattern serching.
void zalgo(string s,vector<int>&z,int n){
	int l=0,r=0;
	for(int i=1;i<n;i++){
		if(i>r){
			l=r=i;
			while(r<n&&s[r-l]==s[r]) r++;
			z[i]=r-l;
			r--;
		}
		else{
			if(i+z[i-l]<=r) z[i-l]=z[i];
			else{
				l=i;
				while(r<n&&s[r-l]==s[r]) r++;
				z[i]=r-l;
				r--;
				
			}
		}
	}
}

// fenwick or binary tree for inverse and cumulative quarries(l,r).
vector<int>bit;
void update(int k,int n){
	while(k<=n){
		bit[k]++;
		k+=k&-k;
	}
}
int getsum(int k){
	int s=0;
	while(k){
		s+=bit[k];
		k-=k&-k;
	}
	return s;
}

// segment tree for range quarries.
// int n;
int seg[400005];
// quaries 1 indexed.
int get(int l,int r){
	int s=0;
	for(l+=n-1,r+=n-1;l<=r;l>>=1,r>>=1){
		if(l&1) s+=seg[l++];
		if(r&1^1) s+=seg[r--];
	}
	return s;
}
void update(int p,int val){
	p+=n-1;
	seg[p]=val;
	for(int i=p;i>1;i>>=1){
		seg[i>>1]=seg[i]+seg[i^1];
	}
}
void solve(){
	int q,temp;
	cin>>n>>q;
	forn(i,n) {
		cin>>temp;
		seg[i+n]=temp;
	}
	for(int i=n-1;i>0;i--)
		seg[i]=seg[i<<1]+seg[i<<1|1];
	cout<<get(1,5);
}

//tosegort or cycle detection 0 indexed.
Vi tosegort(VVi A,int n){
	Vi ord,ind(n,0);
	forn(i,n) for(int x:A[i]) ind[x]++;
	queue<int>ok;
	forn(i,n) if(!ind[i]) ok.push(i);
	while(ok.size()){
		int x=ok.front();
		ok.pop();
		ord.pb(x);
		for(int y:A[x]) if(!(--ind[y])) ok.push(y);
	}
	if(ord.size()<n){
		cout<<"NO\n";
		return {0};
	}
	return ord;
}

// quick sort implemantation
// const int N=1e6+5;
// int arr[N],n;
// int partiate(int l,int r){
// 	int piv=arr[l],seg=l+1;
// 	for(int i=l+1;i<=r;i++){
// 		if(arr[i]<piv){
// 			swap(arr[seg],arr[i]);
// 			seg++;
// 		}
// 	}
// 	swap(arr[l],arr[--seg]);
// 	return seg;
// }
// void quick_sort(int l,int r){
// 	if(l<r){
// 		int piv=partiate(l,r);
// 		quick_sort(l,piv-1);
// 		quick_sort(piv+1,r);
// 	}
// }

// merge sort implementation.
// const int N=1e6+5;
int arr[N],ans,n;
void merge(int l,int mid,int r);
void mergesort(int l,int r){
	if(l<r){
		int mid=(l+r)/2;
		mergesort(l,mid);
		mergesort(mid+1,r);
		merge(l,mid,r);
	}
// }
// void merge(int l,int m,int r){
// 	int temp[r+1];
//     int a=l,b=m+1,k=l;
//     while(a<=m and b<=r){
//         if(arr[a]<=arr[b]) temp[k++]=arr[a++];
//         else {
// 			ans+=m-a+1;
// 			temp[k++]=arr[b++];
// 		}
//     }
//     while(a<=m) temp[k++]=arr[a++];
//  	while(b<=r) temp[k++]=arr[b++];
//     for(int i=l;i<=r;i++) arr[i]=temp[i];
// }

// int32_t main(){
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(0),cout.tie(0),cout<<fixed;
	
//   	int tc=1;
// 	//cin>>tc;
// 	while(tc--){
// 		//solve();
// 		//cout<<solve()<<"\n";
// 	}
// }
