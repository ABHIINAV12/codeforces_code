//  You're not going to master the rest of your life in one day.
//  Just relax. Master the day. 
//  Then just keep doing that every day.
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
#define pq priority_queue<int>
#define pqs priority_queue<int,vi,greater<int>>
#define vpii vector<pair<int,int>>
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define sz(x) x.size()
#define mpi map<int,int>

int mod=1e9+7;

const int mxn=310000;
vi vt[mxn];
int n,x,y;
int sp[mxn];

int dfs(int s,int p){
	int here=1;
	for(auto it : vt[s]) if(it!=p) here+=dfs(it,s);
	sp[s]=here;	
	return here;	
}

bool dfs1(int s,int p){
	if(s==x) return 1;
	for(auto it : vt[s]) if(it!=p) {
		bool xx=dfs1(it,s);
		if(xx==1) return 1;
	}
	return 0;
}


void solve(){
	cin>>n>>x>>y;
	f(i,0,n-1){
		int u,v; cin>>u>>v;
		--u; --v;
		vt[v].pb(u);
		vt[u].pb(v);	
	}		
	--x; --y;
	int total=n*(n-1);
	int tmp=dfs(y,-1);
	int del=sp[x]; int sum=n; for(auto it : vt[y]) if(dfs1(it,y)) sum-=sp[it];
	del*=sum;
	cout<<total-del<<"\n";	
}

void input(){	
	int t=1; //	cin>>t;
	f(T,1,t+1)
		solve(); 
}
 
int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);	
	#ifdef Me
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);	
	#endif
	srand(time(0));
	input();
	return 0;
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases