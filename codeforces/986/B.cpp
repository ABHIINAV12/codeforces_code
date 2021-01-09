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

vi vt;

void st(int curr,int l,int r,int id){
	if(l==r){
		if(l==id) vt[curr]=1;
		return ;
	}
	if(id<l || id>r) return ;
	int mid=l+r; mid/=2;
	st(2*curr+1,l,mid,id);
	st(2*curr+2,mid+1,r,id);
	vt[curr]=vt[2*curr+1]+vt[2*curr+2];
	return ;
}

int gt(int curr,int l,int r,int L,int R){
	if(l==r){
		if(l>=L && l<=R)
			return vt[curr];
		return 0;
	}
	if(l>=L && r<=R) return vt[curr];
	if(r<L || R<l) return 0;
	int mid=l+r; mid/=2;
	return gt(2*curr+1,l,mid,L,R) + gt(2*curr+2,mid+1,r,L,R);
}


void solve(){
	int n; cin>>n;
	int x=1; while(x<n) x*=2;
	f(i,0,2*x-1) vt.pb(0);
	int inv=0; f(i,0,n){
		int tp; cin>>tp; --tp;
		inv+=gt(0,0,x-1,tp,x-1);
		st(0,0,x-1,tp);
	}
	if(n%2==1){
		if(inv%2==1){
			cout<<"Petr\n";	
		}else{
			cout<<"Um_nik\n";	
		}	
	} 
	else {
		if(inv%2==0){
			cout<<"Petr\n";	
		}else{
			cout<<"Um_nik\n";	
		}
	}
}

int32_t main(){ 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t=1; // cin>>t;
  while(t--) solve();
  return 0; 
}













