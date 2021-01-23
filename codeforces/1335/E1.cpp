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

int lcm(int a,int b){
	int g=__gcd(a,b);
	a*=b; a/=g;
	return a;
}

const int mxn=3010000;

int rep[mxn];
void pri(){
	rep[0]=1;
	rep[1]=1;
	f(i,2,mxn){
		if(rep[i]==0)
		for(int j=i;j<mxn;j+=i){
			rep[j]=i;
		}
	}
}
 

void solve(){
	int n; cin>>n;
	int a[n]; f(i,0,n) {cin>>a[i]; --a[i];}
	int pre[n][26]={0}; f(i,0,n) f(j,0,26) pre[i][j]=0;
	pre[0][a[0]]=1; f(i,1,n){
		pre[i][a[i]]=1; f(j,0,26) pre[i][j]+=pre[i-1][j];
	}
	int suff[n][26]; f(i,0,n) f(j,0,26) suff[i][j]=0;
	suff[n-1][a[n-1]]=1;
	for(int i=n-2;i>=0;--i){
		suff[i][a[i]]=1; f(j,0,26) suff[i][j]+=suff[i+1][j];
	}
	int ret=0; f(i,0,26) ret=max(ret,pre[n-1][i]);
	f(i,0,n){
		f(j,i+1,n){
			f(k,0,26){
				int mx1=pre[i][k];
				int mx2=suff[j][k];
				int mx3=0; f(K,0,26) mx3=max(mx3,pre[j-1][K]-pre[i][K]);	
				ret=max(ret,mx3+2ll*min(mx1,mx2));
			}
		}
	}
	cout<<ret<<"\n";
}


void input(){
	int t=1; cin>>t;
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
/*
	

*/