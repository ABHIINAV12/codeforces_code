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

 
int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);	
	srand(time(0));
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int t; cin>>t;
	while(t--){
		int n,m; cin>>n>>m;
		int a[n][m]; f(i,0,n) f(j,0,m) cin>>a[i][j];
		int diag1[n+m]={0},diag2[n+m]={0};
		f(i,0,n) f(j,0,m){
			if(a[i][j]==0) diag1[i+j]++;
			else diag2[i+j]++;
		} 
		int ch=0;
		// 0 .. n+m-2
		f(i,0,(n+m-1)/2){
			int one=diag2[i]+diag2[n+m-2-i];
			int zero=diag1[i]+diag1[n+m-2-i];
			ch+=min(one,zero);
		}
		cout<<ch<<"\n";
	}
	return 0;
}

// ============== Notes =============== //
/*
	

*/
