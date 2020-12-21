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

int lcm(int a,int b){
	int g=__gcd(a,b);
	a*=b; a/=g;
	return a;
}

int lcm1(int a,int b,int c){
	int l=lcm(a,b);
	l=lcm(l,c);
	return l;
}

void solve(){
	int n; cin>>n;
	map<int,int> mp;
	f(i,2,n+1){
		int c=i,d=i;
		for(int j=2;j*j<=c;++j){
			if(d%j==0){
				int cnt=0;
				while(d%j==0){
					d/=j;
					++cnt;
				}
				mp[j]=max(mp[j],cnt);
			}
		}
		if(d!=1) mp[d]=max(mp[d],1ll);
	}
	vi nums;
	for(auto it : mp){
		int f=it.ff,c=it.ff; int v=it.ss;
		f(i,0,v){
			nums.pb(c);
			c*=f;
		}	
	}
	cout<<sz(nums)<<"\n";
	for(auto it : nums) cout<<it<<" ";
	cout<<"\n";
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