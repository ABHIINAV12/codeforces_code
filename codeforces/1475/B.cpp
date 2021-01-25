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

const int mxn=2200000;

void solve(){
	int n; cin>>n;
	int curr=0;
	while(curr<=n){
		int rem=n-curr;
		if(rem%2021 ==0 ){
			cout<<"YES\n";
			return ;
		}
		curr+=2020;
	}
	cout<<"NO\n";
}


int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);	
	srand(time(0));
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int t=1; cin>>t;
	while(t--) solve();
	return 0;
}

// ============== Notes =============== //
/*
	

*/