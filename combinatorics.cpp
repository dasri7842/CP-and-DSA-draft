#include <bits/stdc++.h>
using namespace std;

const int N=1e3+5;
int fact[N],modI[N], num = 1e9+7;

int powr(int a,int n,int m){
	int res=1;
	a%=m;
	while(n){
		if(n&1) res = 1LL * res * a % m;
		a= 1LL* a * a % m;
		n /= 2;
	}
	return res;
}

void prefact(){
	fact[0]=fact[1]=1;
	for(int i=2;i<N;i++) {
		fact[i] = 1LL * fact[i-1] * i % num;
	}
	for(int i=0;i<N;i++){
		modI[i] = powr(fact[i], num-2, num);
	}
}

int nCr(int n, int r){
	if(n<r) return 0;
	return 1LL * fact[n] * modI[r] % num * modI[n-r] % num;
}

int nPr(int n, int r){
	if(n<r) return 0;
	return 1LL * nCr(n,r) * fact[r] % num;
}
void bs(int & low,int & up, int n, int pos){
	int left=0,right=n;
	while(left<right){
		int mid = (left + right) /2;
		if(mid <= pos){
			low += (mid!=pos);
			left = mid + 1;
		} 
		else{
			up ++;
			right = mid;
		}
	}
}
signed main(){
	ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
	// freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);

	prefact();

	int n, x, pos;
	cin>>n>>x>>pos;
	int low=0,up=0;
	bs(low,up,n,pos);
	int ans = 1LL * nPr(x-1,low) * nPr(n-x,up) % num * fact[n-low-up-1] %num;
	cout<<ans;
}