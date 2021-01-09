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
vi adj[mxn];
int n,m,k,s;
int sp[mxn];
int ty[mxn];
int dis[mxn][110];

void bfs(int t){
	queue<int> q;
	f(i,0,n) if(ty[i]==t) {
		q.push(i); dis[i][t]=0;
	}else dis[i][t]=INT_MAX;
	while(!q.empty()){
		int tt= q.front(); q.pop();
		for(auto it : adj[tt]) if(dis[it][t]>(dis[tt][t]+1)) {
			dis[it][t]=dis[tt][t]+1;
			q.push(it);
		}
	}
}


void solve(){
	cin>>n>>m>>k>>s;
	f(i,0,n) cin>>ty[i];
	f(i,0,n) --ty[i];
	f(i,0,m){
		int u,v; cin>>u>>v; --u; --v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	f(i,0,k) bfs(i);
	f(i,0,n){
		vi ret; f(j,0,k) ret.pb(dis[i][j]);
		sort(all(ret)); int sum=0;
		f(j,0,s) sum+=ret[j];
		cout<<sum<<" ";
	}
	cout<<"\n";
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