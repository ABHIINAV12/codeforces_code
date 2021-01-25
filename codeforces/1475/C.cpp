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

const int mxn=2200000;

int fact[2000005];
int infact[2000005];
 
int inv(int a){
  int y=mod-2;
  int r=1;
  while(y!=0){
    if(y&1){
      r*=a; r%=mod;
    }
    y/=2; a*=a; a%=mod;
  }
  return r;
}
 
int po(int a,int y){
  int r=1;
  while(y!=0){
    if(y&1){
      r*=a; r%=mod;
    }
    y/=2; a*=a; a%=mod;
  }
  return r; 
}
 
void facto(){
  fact[0]=1;
  f(i,1,2000005) {fact[i]=i*fact[i-1]; fact[i]%=mod;}
  f(i,0,2000005) infact[i]=inv(fact[i]); 
}
 
int nck (int n,int k){
  if(k<0 || k>n) return 0;
  int ret=fact[n]; ret*=infact[k]; ret%=mod;
  ret*=infact[n-k]; ret%=mod;
  return ret;
}


void solve(){
	int n,m,k; cin>>n>>m>>k;
	int a[k],b[k]; f(i,0,k) cin>>a[i]; f(i,0,k) cin>>b[i];
	map<pair<int,int>,int> mp; 
	map<int,int> fre_b,fre_g; f(i,0,k){
		mp[{a[i],b[i]}]++;
		fre_b[a[i]]++;
		fre_g[b[i]]++;
	}
	int ret=0; n=k;
	f(i,0,n){
		int tt=mp[{a[i],b[i]}]-1;
		int t1=fre_b[a[i]]-1;
		int t2=fre_g[b[i]]-1;
		ret+= n - 1 - t1 - t2  + tt ;
	}
	ret/=2;


	cout<<ret<<"\n";
}


int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);	
	srand(time(0));
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	//facto();
	int t=1; cin>>t;
	while(t--) solve();
	return 0;
}

// ============== Notes =============== //
/*
	

*/