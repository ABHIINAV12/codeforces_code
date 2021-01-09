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

ld pie=3.141592653589793238462643383279;
int mod=1e9+7;


int32_t main(){ 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin>>t;
  while(t--){
  	int n; cin>>n;
  	int a[n]; f(i,0,n) cin>>a[i];
  	auto score = [&](int id){
  		if(id<=0 || id>=n-1) return 0;
  		if(a[id]>a[id-1] && a[id]>a[id+1]) return 1;
  		if(a[id]<a[id-1] && a[id]<a[id+1]) return 1;
  		return 0;
	  };
	int ret=0; f(i,0,n) ret+=score(i);
	int mx=0;
	f(i,0,n){
		int here=score(i-1)+score(i)+score(i+1);
		int tmp=a[i];
		if(i>0) a[i]=a[i-1];
		int dec1=score(i-1)+score(i)+score(i+1);
		if(i<(n-1)) a[i]=a[i+1];
		int dec2=score(i-1)+score(i)+score(i+1);
		dec1=min(dec1,dec2);
		here-=dec1;
		a[i]=tmp;
		mx=max(mx,here);
	}
	cout<<ret-mx<<"\n";
  }
  return 0; 
}













