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
	int n; cin>>n;
	string s; cin>>s;
	int rem=0;
	for(char c='z';c>'a';--c){
		bool fg=0;
		f(i,0,sz(s)){
			if(s[i]==c){
				if((i>0 && s[i-1]==c-1) || (i<(n-1) && s[i+1]==(c-1))){
					fg=1; ++rem;
					string tmp=s.substr(0,i) + s.substr(i+1); 	
					s=tmp;
				}
			}
		}
		if(fg) ++c;
	}
	cout<<rem<<"\n";
	return ;
}


int32_t main(){ 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
 	int t=1; //cin>>t;
 	while(t--) solve();
  return 0; 
}













