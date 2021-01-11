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

int fx(int a){
	int r=0;
	while(a!=0){
		if(a&1)	++r;
		a/=2;
	}
	return r;
}

void solve(){
	int n,p; cin>>n>>p;
	f(i,1,32){
		int tmp=n-i*p;
		if(tmp<0) break;
		int mx=tmp,mn=fx(tmp);
		if(i>= mn && i<=mx){
			cout<<i;
			return ;
		} 
	}
	cout<<"-1";
	return ;
}


int32_t main(){ 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
 	int t=1; //cin>>t;
 	while(t--) solve();
  return 0; 
}













