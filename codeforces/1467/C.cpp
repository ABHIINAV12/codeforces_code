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


int32_t main(){ 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
 	int t=1; //cin>>t;
 	while(t--){
 		int a,b,c; cin>>a>>b>>c;
 		vi v[3]; f(i,0,a){
 			int x; cin>>x; v[0].pb(x);
		 }
		 f(i,0,b){
 			int x; cin>>x; v[1].pb(x);
		 }f(i,0,c){
 			int x; cin>>x; v[2].pb(x);
		 }
		 f(i,0,3) sort(all(v[i]));
		 int s[3]={0}; f(i,0,3) {
		 	for(auto it : v[i]) s[i]+=it;
		 }
		 int ans=s[0]+s[1]+s[2]-2ll*min({v[0][0]+v[1][0],v[1][0]+v[2][0],v[0][0]+v[2][0],s[0],s[1],s[2]});
		 cout<<ans<<"\n";
	 }
  return 0; 
}













