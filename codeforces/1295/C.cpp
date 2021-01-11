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
	string s,t; cin>>s>>t;
	int n=sz(s); int dp[n][26]; 
	int id=s[n-1]-'a'; f(i,0,26) if(i==id) dp[n-1][i]=n-1; else dp[n-1][i]=-1;
	for(int i=n-2;i>=0;--i){
		id=s[i]-'a';
		f(j,0,26) if(j==id) dp[i][j]=i; else dp[i][j]=dp[i+1][j];
	}
	for(auto it : t) if(dp[0][it-'a']==-1) {
		cout<<-1<<"\n";
		return ;
	}	
	int curr=0,ret=1,here=0;
	while(curr<sz(t)){
		if(dp[here][t[curr]-'a']!=-1){
			here=dp[here][t[curr]-'a'];
			++here;
		}else{
			here=dp[0][t[curr]-'a'];
			++here;
			++ret;
		}
		++curr;
		if(curr==sz(t)) break;
		if(here==n) {
			here=0;
			++ret;
		}
	}
	cout<<ret<<"\n";
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