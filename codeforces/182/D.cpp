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
	string s,ss; cin>>s>>ss;
	int n=sz(s),nn=sz(ss); int g=__gcd(n,nn);
	vi gg; for(int i=1;i*i<=g;++i){
		if(g%i==0){
			int ano=g/i;
			gg.pb(i);
			if(ano!=i) gg.pb(ano);
		}
	}
	int ret=0;
	for(auto it : gg){
		string ck=s.substr(0,it);
		bool poss=1;
		for(int i=0;i<n;i+=it){
			string ano=s.substr(i,it);
			if(ano!=ck){
				poss=0;
				break;
			}
		}
		for(int i=0;i<nn;i+=it){
			string ano=ss.substr(i,it);
			if(ano!=ck){
				poss=0;
				break;
			}
		}
		ret+=poss;		
	}
	cout<<ret<<"\n";
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