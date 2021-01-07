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

const int mxn=210000;

vpii vt[mxn];
bool vis[mxn];
int n,m,k;

void dfs(int s){
	vis[s]=1; for(auto it : vt[s]) if(!vis[it.ff] && it.ss<=k) dfs(it.ff);
}

vector<array<int,3>> rp;
int par[mxn];

int get_parent(int i){
	if(par[i]==i) return i;
	par[i]=get_parent(par[i]);
	return par[i];
}

void solve(){
	cin>>n>>m>>k;
	f(i,0,n) vt[i].clear();
	f(i,0,n) vis[i]=false;
	f(i,0,m){
		int u,v,w; cin>>u>>v>>w; --u; --v;
		vt[u].pb({v,w}); vt[v].pb({u,w});
	}
	int com=0; f(i,0,n) if(!vis[i]) {
		dfs(i);
		++com;	
	}
	if(com==1){
		rp.clear();
		f(i,0,n) for(auto &it : vt[i]) rp.pb({it.ss,i,it.ff});
		sort(all(rp)); int ans=0;
		int here=LLONG_MAX,idx=-1;
		f(i,0,sz(rp)){
			if(abs(rp[i][0]-k)<=here){
				here=abs(rp[i][0]-k);
				idx=i;
			}
		}
		ans+=here;
		cout<<ans<<"\n";
	}else{
		rp.clear();
		f(i,0,n) for(auto &it : vt[i]) rp.pb({max(it.ss-k,0ll),i,it.ff});
		sort(all(rp)); int ans=0;
		f(i,0,n) par[i]=i;
		for(auto it : rp){
			int add=it[0],to=it[1],from=it[2];
			int par_to=get_parent(to),par_from=get_parent(from);
			if(par_to!=par_from){
				ans+=add;
				par[par_to]=par_from;
			}
		}
		cout<<ans<<"\n";
	}
}

void input(){
	int t=1; cin>>t;
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