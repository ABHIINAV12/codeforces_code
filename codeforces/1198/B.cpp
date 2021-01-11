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
	int a[n]; f(i,0,n) cin>>a[i];
	int q; cin>>q;
	int f[q][2];
	f(i,0,q){
		int ty; cin>>ty;
		if(ty==1){
			cin>>f[i][0]>>f[i][1];
		}else{
			cin>>f[i][0]; f[i][1]=-1;
		}
	}
	int suff[q]; for(int i=q-1;i>=0;--i) if(f[i][1]==-1){
		if(i==q-1){
			suff[i]=f[i][0];	
		}else{
			suff[i]=max(suff[i+1],f[i][0]);
		}
	}else{
		if(i==q-1){
			suff[i]=LLONG_MIN;	
		}else{
			suff[i]=suff[i+1];
		}
	}
	bool done[n]={0};
	f(i,0,q) if(f[i][1]!=-1) {
		a[f[i][0]-1]=f[i][1];
		a[f[i][0]-1]=max(a[f[i][0]-1],suff[i]);
		done[f[i][0]-1]=1;
	}
	f(i,0,n) if(!done[i]) a[i]=max(a[i],suff[0]);
	f(i,0,n) cout<<a[i]<<" ";
	return ;
}


int32_t main(){ 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
 	int t=1; //cin>>t;
 	while(t--) solve();
  return 0; 
}













