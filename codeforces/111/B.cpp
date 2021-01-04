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

const int mod=1e9+7;

void solve(){
	int n; cin>>n;
	mpi mp;
	f(i,1,n+1){
		int x,y; cin>>x>>y;
		vi d; for(int j=1;j*j<=x;++j){
			if(x%j==0){
				int ano=x/j;
				d.pb(j); if(ano!=j) d.pb(ano);
			}
		}
		if(y==0){
			cout<<sz(d)<<"\n";
		}else{
			int l=i-1, ll=i-y;
			int r=0; for(auto it : d){
				int l2=mp[it];
				if(l2>=ll && l2<=l) ++r;
			}
			cout<<sz(d)-r<<"\n"; 
		}
		for(auto it : d) mp[it]=i; 
	}
}


void input(){
	int t=1; //cin>>t;
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