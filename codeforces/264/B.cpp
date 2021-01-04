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
#define sz(x) x.size()
#define mpi map<int,int>

const int mod=1e9+7;

int lcm(int a,int b){
	int g=__gcd(a,b);
	a*=b; a/=g;
	return a;
}

int lcm1(int a,int b,int c){
	int l=lcm(a,b);
	l=lcm(l,c);
	return l;
}

int n,m;
vpii adj[2000010];
bool vis[2000010];
bool invalid=false;
int par[2000010];

void dfs(int s,int exp){
	if(vis[s]){
		if(par[s]!=exp) invalid=true;
  		return ;
	}
	vis[s]=1; par[s]=exp;
	for(auto it : adj[s]){
		int ver=it.ff;
		int ano=it.ss;
		if(exp==0) ano=1-ano;
		dfs(ver,ano);
	}
}

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

int fx(int n){
	int s=0;
	while(n!=0){
		s+=(n%10);
		n/=10;
	}
	return s;
}

int po(int a,int y){
  int r=1;
  while(y!=0){
    if(y&1){
      r*=a; r%=mod;
      if(r<0) r+=mod;
    }
    y/=2; a*=a; a%=mod;
    if(a<0) a+=mod;
  }
  if(r<0) r+=mod;
  return r; 
}

int t,k;
int dp[4100][2];
vi vt;
int rec(int curr,int s1,int s2){
	if(s1>=t && s2>=t) return 0;
	if(curr==n) return INT_MAX;
	return 1+min(rec(curr+1,+vt[curr],s2),rec(curr+1,s1,s2+vt[curr]));
}

vi pr;
int rep[2000005];
void pri(){
	f(i,2,2000005){
		if(rep[i]==0)
		for(int j=i;j<2000005;j+=i){
			rep[j]=i;
		}
	}
	f(i,2,2000005) if(rep[i]==0) pr.pb(i);
}



void solve(){
	pri();
	cin>>n; int a[n]; f(i,0,n) cin>>a[i];
	mpi mp;
	int mx=-1;
	f(i,0,n){
		// set base case properly --there is atleast 1
		int here=1;
		int nn=a[i];
		vi ff;
		while(nn!=1){
			int div=rep[nn];
			ff.pb(div);
			while(nn%div==0) nn/=div;
		}
		for(auto it : ff){
			mp[it]++;
			here=max(here,mp[it]);
		}
		for(auto it : ff){
			mp[it]=here;
			//here=max(here,mp[it]);
		}
		mx=max(mx,here);
	}
	cout<<mx;
}


void input(){
	//pri();
	//facto();
	int t=1; //cin>>t;
	f(T,1,t+1)
		solve(); 
}
 
int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);	
	#ifdef Me
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);	
	#endif
	srand(time(0));
	input();
	return 0;
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases