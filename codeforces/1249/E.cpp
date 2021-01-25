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

int fx(vector<int> &a){
	sort(all(a));
	int ret=0; f(i,1,sz(a)) ret+=a[i]-a[0];
	int curr=ret; f(i,1,sz(a)){
		int dec=a[i]-a[i-1]; dec*=(sz(a)-i);
		curr-=dec; ret+=curr;
	}
	return ret;
}
const int mxn=2200000;
int a[mxn],n;

int rec(int rem){
	if(rem==-1) return 0;
	if(a[rem]==0) return 1ll<<(rem) + rec(rem-1);
	return rec(rem-1);
}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);	
	srand(time(0));
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int t=1; //cin>>t;
	while(t--){
		 int n,c; cin>>n>>c;
		 int a[n-1]; f(i,0,n-1) cin>>a[i];
		 int b[n-1]; f(i,0,n-1) cin>>b[i];
		 int dp[n][2]; dp[0][0]=0; dp[0][1]=c;
		 f(i,1,n){
		 	dp[i][0]=min(dp[i-1][0]+a[i-1],dp[i-1][1]+a[i-1]);
		 	dp[i][1]=min(dp[i-1][0]+c+b[i-1],dp[i-1][1]+b[i-1]);
		 }
		 f(i,0,n) cout<<min(dp[i][0],dp[i][1])<<" "; 
		 cout<<"\n";
	}
	return 0;
}

// ============== Notes =============== //
/*
	the idea is to think of problem as when you arrived at state i,
	were you in elevator or in stairs ?

	i -- by stairs -- i-1 you were at stairs 
	i -- by stairs -- i-1 you were at elevator
	i -- by elevator -- i-1 at stairs
	i -- by elevator -- i-1 at elevator too.

*/