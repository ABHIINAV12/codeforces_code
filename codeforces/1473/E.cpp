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
#define sz(x) (int)x.size()
#define mpi map<int,int>
#define d1(x,y) cout<<x<<" ----------------------------- "<<y<<"\n"

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
 
 
vpii vt[mxn]; 

void solve(){
	int n,m; cin>>n>>m;
	f(i,0,m){
		int u,v,w; cin>>u>>v>>w; --u; --v;
		vt[u].pb({v,w});
		vt[v].pb({u,w});
	}
	int dp[n][2][2]; f(i,0,n) f(j,0,2) f(k,0,2) dp[i][j][k]=LLONG_MAX; dp[0][0][0]=0;
	set<array<int,4>> st; st.insert({0,0,0,0});
	while(!st.empty()){
		array<int,4> ar = *st.begin();
		st.erase(*st.begin());
		if(ar[2]==0 && ar[3]==0){
			for(auto it : vt[ar[1]]){
				int to = it.ff; int w= it.ss;
				if(dp[to][0][0]>(dp[ar[1]][0][0]+w)){
					auto ip = st.find({dp[to][0][0],to,0,0});
					if(ip!=st.end()) st.erase(ip);
					dp[to][0][0]=dp[ar[1]][0][0]+w;
					st.insert({dp[to][0][0],to,0,0});
				}
				if(dp[to][0][1]>(dp[ar[1]][0][0]+2*w)){
					auto ip = st.find({dp[to][0][1],to,0,1});
					if(ip!=st.end()) st.erase(ip);
					dp[to][0][1]=dp[ar[1]][0][0]+2*w;
					st.insert({dp[to][0][1],to,0,1});
				}
				if(dp[to][1][0]>(dp[ar[1]][0][0])){
					auto ip = st.find({dp[to][1][0],to,1,0});
					if(ip!=st.end()) st.erase(ip);
					dp[to][1][0]=dp[ar[1]][0][0];
					st.insert({dp[to][1][0],to,1,0});
				}
				if(dp[to][1][1]>(dp[ar[1]][0][0]+w)){
					auto ip = st.find({dp[to][1][1],to,1,1});
					if(ip!=st.end()) st.erase(ip);
					dp[to][1][1]=dp[ar[1]][0][0]+w;
					st.insert({dp[to][1][1],to,1,1});
				}
			}
		}else if(ar[2]==0 && ar[3]==1){
			for(auto it : vt[ar[1]]){
				int to = it.ff; int w= it.ss;
				if(dp[to][0][1]>(dp[ar[1]][0][1]+w)){
					auto ip = st.find({dp[to][0][1],to,0,1});
					if(ip!=st.end()) st.erase(ip);
					dp[to][0][1]=dp[ar[1]][0][1]+w;
					st.insert({dp[to][0][1],to,0,1});
				}
				if(dp[to][1][1]>(dp[ar[1]][0][1])){
					auto ip = st.find({dp[to][1][1],to,1,1});
					if(ip!=st.end()) st.erase(ip);
					dp[to][1][1]=dp[ar[1]][0][1];
					st.insert({dp[to][1][1],to,1,1});
				}
			}
		}else if(ar[2]==1 && ar[3]==0){
			for(auto it : vt[ar[1]]){
				int to = it.ff; int w= it.ss;
				if(dp[to][1][1]>(dp[ar[1]][1][0]+2*w)){
					auto ip = st.find({dp[to][1][1],to,1,1});
					if(ip!=st.end()) st.erase(ip);
					dp[to][1][1]=dp[ar[1]][1][0]+2*w;
					st.insert({dp[to][1][1],to,1,1});
				}
				if(dp[to][1][0]>(dp[ar[1]][1][0]+w)){
					auto ip = st.find({dp[to][1][0],to,1,0});
					if(ip!=st.end()) st.erase(ip);
					dp[to][1][0]=dp[ar[1]][1][0]+w;
					st.insert({dp[to][1][0],to,1,0});
				}
			}
		}else{
			for(auto it : vt[ar[1]]){
				int to = it.ff; int w= it.ss;
				if(dp[to][1][1]>(dp[ar[1]][1][1]+w)){
					auto ip = st.find({dp[to][1][1],to,1,1});
					if(ip!=st.end()) st.erase(ip);
					dp[to][1][1]=dp[ar[1]][1][1]+w;
					st.insert({dp[to][1][1],to,1,1});
				}
			}
		}
	}
	f(i,1,n) cout<<dp[i][1][1]<<" ";
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
/*

check overflow -- if not in hurry use long long max
	

*/