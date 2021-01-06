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

int lcm(int a,int b){
	int g=__gcd(a,b);
	a*=b; a/=g;
	return a;
}

const int mxn=3010000;

int rep[mxn];
void pri(){
	rep[0]=1;
	rep[1]=1;
	f(i,2,mxn){
		if(rep[i]==0)
		for(int j=i;j<mxn;j+=i){
			rep[j]=i;
		}
	}
}
 


void solve(){
	int n; cin>>n;
	map<int,vector<pair<int,int>>> mp;
	int ans[n],h[n],w[n]; f(i,0,n) {
		cin>>h[i]>>w[i];
		ans[i]=-1;
		// important part to notice is 
		// the pair wont couple with itself
		// both the orientations are considered
		mp[h[i]].pb({w[i],i+1});
		mp[w[i]].pb({h[i],i+1});
	}
	int mn=LLONG_MAX,idx=-1;
	for(auto it : mp){
		int here=LLONG_MAX,id1=-1;
		for(auto ip : it.ss){
			if(ip.ff > mn) {
				ans[ip.ss-1] = idx;
			}
			if(ip.ff < here){
				here=ip.ff;
				id1=ip.ss;
			}
		}
		if(here<mn){
			mn=here;
			idx=id1;
		}
	}
	f(i,0,n) cout<<ans[i]<<" ";
	cout<<"\n";
}


void input(){
	//pri();
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