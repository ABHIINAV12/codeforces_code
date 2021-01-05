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

int rep[1100005];
void pri(){
	rep[0]=1;
	rep[1]=1;
	f(i,2,1100005){
		if(rep[i]==0)
		for(int j=i;j<1100005;j+=i){
			rep[j]=i;
		}
	}
}
 


void solve(){
	int n; cin>>n;
	int a[n]; f(i,0,n) cin>>a[i];
	mpi mp;
	f(i,0,n){
		int pro=1;
		while(a[i]!=1){
			int div=rep[a[i]];
			int cnt=0;
			assert(div!=0);
			assert(div!=1);
			while(a[i]%div==0){
				a[i]/=div;
				++cnt;
			}
			if(cnt&1) pro*=div;
		}
		mp[pro]++;		
	}
	int ans=0;
	int odd=0,even=0;
	for(auto it : mp) ans=max(ans,it.ss);
	for(auto it : mp){
		if((it.ss)%2==0) ++even;
		if(it.ff != 1) {
			if(it.ss%2==1) odd+=it.ss;
		}
	} 
	int ano=n-odd;
	odd=max(ano,ans);
	int q; cin>>q;
	while(q--){
		int tmp; cin>>tmp;
		if(tmp==0)
		cout<<ans<<"\n";
		else cout<<odd<<"\n";
	}
}


void input(){
	pri();
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