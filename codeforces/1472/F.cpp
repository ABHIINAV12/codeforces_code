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
	// the basic idea is there must be even obstacles
	// we fill the area by taking two at a time in blocks. 
	// it is not possible to fill the block if obstacles have same parity of row and col
	// the space between blocks is filled with vertical tiles and other with horizontal 
	// last to check is two blocks should not intersect, there is no solution for that	
	int m,n; cin>>m>>n;
	vpii vt; f(i,0,n){
		int r,c; cin>>r>>c;
		vt.pb({c,r});
	}
	sort(all(vt));
	if(n&1) cout<<"NO\n";
	else{
		for(int i=0;i<n;i+=2){
			if(((vt[i].ss+vt[i].ff)%2) == ((vt[i+1].ss+vt[i+1].ff)%2)){
				cout<<"NO\n";
				return ;
			}
			if(i>0 && vt[i].ff == vt[i-1].ff) {
				cout<<"NO\n";
				return ;
			}
		}
		cout<<"YES\n";
	}
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