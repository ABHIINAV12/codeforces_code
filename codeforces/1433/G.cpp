#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define f(i,x,n) for(int i=x;i<(int)n;++i)
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define vpii vector<pair<int,int>>
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define sz(x) x.size()
#define mpi map<int,int>
#define my vector<array<array<int,2>,2>>

int mod=1e9+7;

int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,0,1,-1,1,-1,0,1};

int n,m,k;
int sum=LLONG_MAX;

vpii adj[1005];
int cost[1005][1005];


void dik(int s){
	f(i,0,n) cost[s][i]=LLONG_MAX;
	cost[s][s]=0;
    priority_queue <int, vector<int>, greater<int>> pq;
    pq.push(s);
    while(!pq.empty()){
    	int lp=pq.top(); pq.pop();
    	for(auto it : adj[lp]){
    		if(cost[s][it.ff]>cost[s][lp]+it.ss){
    			cost[s][it.ff]=cost[s][lp]+it.ss;
    			pq.push(it.ff);
			}
		}
	}
}


void solve(){
	cin>>n>>m>>k;
	vpii edge;
	f(i,0,m){
		int u,v,w; cin>>u>>v>>w; --u; --v;
		adj[u].pb({v,w});
		adj[v].pb({u,w});
		edge.pb({u,v});
	}
	f(i,0,n) dik(i);
	vpii cp; f(i,0,k){
		int u,v; cin>>u>>v; --u; --v;
		cp.pb({u,v});
	}
	for(auto it : edge){
		int th=0;
		f(i,0,k) th+=min({cost[cp[i].ff][cp[i].ss], cost[cp[i].ff][it.ff] + cost[it.ss][cp[i].ss], cost[cp[i].ff][it.ss] + cost[it.ff][cp[i].ss]});	
		sum=min(sum,th);
	}
}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int t=1; //cin>>t; 
	while(t--) solve();
    cout<<sum<<"\n";
	return 0;
}
