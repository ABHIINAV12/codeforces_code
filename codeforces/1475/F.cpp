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

vi dp[200005];
void div(){
	for(int i=1;i<200005;++i){
		for(int j=i;j<200005;j+=i) dp[j].pb(i);
	}
}

void solve(){
	int n; cin>>n; 
    string s[n]; f(i,0,n) cin>>s[i];
    string ss[n]; f(i,0,n) cin>>ss[i];
    int a[n][n];
    f(i,0,n) f(j,0,n) if(s[i][j]==ss[i][j]) a[i][j]=0; else a[i][j]=1;
    
    int tmp[n]; f(i,0,n) tmp[i]=1-a[0][i];
    f(i,0,n){
    	bool ok=1;
    	f(j,0,n) if(tmp[j]!=a[i][j]) ok=0;
    	if(!ok){
    		ok=1;
    		f(j,0,n) if(a[0][j]!=a[i][j]) ok=0;    		
    	}  


    	if(!ok){
    		cout<<"NO\n";
    		return ;
    	}
    }
    cout<<"YES\n";
}


int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);	
	srand(time(0));
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	//facto();
	//	div();
	int t=1; cin>>t;
	while(t--) solve();
	return 0;
}

// ============== Notes =============== //
/*
	

*/