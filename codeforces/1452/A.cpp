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
		int x,y; cin>>x>>y;
		if(x==y) cout<<2*x<<"\n";
		else if(abs(x-y)==1) cout<<x+y<<"\n";
		else {
			int tt=min(x,y);
			x-=tt; y-=tt;
			if(x!=0){
				 tt*=2; x*=2; --x;
				cout<<tt+x<<"\n";
			}else{
			    tt*=2; y*=2; --y;
				cout<<tt+y<<"\n";
			}
		}
	}
	return 0;
}

// ============== Notes =============== //
/*
	

*/
