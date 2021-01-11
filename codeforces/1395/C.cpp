//Abhinav ---IIIT_A
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define f(i,x,n) for(int i=x;i<(int)n;++i)
#define vpii vector<pair<int,int>> 
#define vi vector<int>
#define vpii vector<pair<int,int>> 
#define mpii map<pair<int,int>,int>
#define mpivpii map<int,vector<pair<int,int>>> 
#define pii pair<int,int> 
#define all(x) x.begin(),x.end()
#define sz(x) x.size()
#define mpi map<int,int>
#define vvi vector<vector<int>>

ld pie=3.141592653;
int mod=1e9+7;

void solve(){
	int n,m; cin>>n>>m;
	int a[n]; f(i,0,n) cin>>a[i];
	int b[m]; f(i,0,m) cin>>b[i];
	f(ans,0,1ll<<9){
		bool fg1=1;
		f(i,0,n){
			bool fg=0;
			f(j,0,m){
				int here=a[i]&b[j];
				int tmp= ans|here;
				if(ans==tmp){
					fg=1;
				}
			}
			if(!fg) {fg1=0; break;}
		}
		if(fg1) {
			cout<<ans<<"\n";
			return ;
		}
	}
	return ;
}


int32_t main(){ 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
 	int t=1; //cin>>t;
 	while(t--) solve();
  return 0; 
}













