// Codeforces Problem Link :https://codeforces.com/contest/1433/problem/G

#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

const int N=1e3+5;
vector<pair<int,int>>A[N];
int dist[N][N],isdone[N][N];

void DIJ(int v){
	dist[v][v]=0;
	priority_queue<pair<int,int>>pq;
	pq.push({0,v});
	while(pq.size()){
		auto cur_node=pq.top();
		pq.pop();
		if(isdone[v][cur_node.S]) continue;
		isdone[v][cur_node.S]=true;
		for(auto x:A[cur_node.S]){
			if(dist[v][x.F]>x.S+dist[v][cur_node.S]){
				dist[v][x.F]=x.S+dist[v][cur_node.S];
				pq.push({-dist[v][x.first],x.first});
			}
		}
	}
}
int main(){

	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int a,b,w;
		cin>>a>>b>>w;
		A[a].push_back({b,w});
		A[b].push_back({a,w});
	}
	vector<pair<int,int>>paths(k);
	for(auto &x: paths) cin>>x.F>>x.S;

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++) dist[i][j]=1e9;
	}
	for(int i=1;i<=n;i++) DIJ(i);
	
	int ans=1e9;	
	for(int i=1;i<=n;i++){
		for(auto a:A[i]){
			int sum=0;
			for(auto x:paths){
				sum+=min({dist[x.F][x.S], dist[x.F][i]+dist[a.F][x.S], dist[x.F][a.F]+dist[i][x.S]});
			}
			ans=min(ans,sum);
		}
	}
	cout<<ans;
}