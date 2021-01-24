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
	int t=1; //cin>>t;
	while(t--){
		string s; cin>>s;
		int cnt=0,n=sz(s);
		int r=0;
		stack<int> st;
		while(r<n){
			if(st.empty()){
				st.push(r); ++r;
			}else{
				int l=st.top();
				if(s[l]==s[r]){
					st.pop(); ++cnt; ++r;
				}else{
					st.push(r); ++r;
				}
			}
		}
		if(cnt&1) cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}

// ============== Notes =============== //
/*
	

*/
