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

int mod=1e9+7;

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


vi pr;
int rep[2000005];
void pri(){
	f(i,2,2000005){
		if(rep[i]==0)
		for(int j=2*i;j<2000005;j+=i){
			rep[j]=1;
		}
	}
	f(i,2,2000005) if(rep[i]==0) pr.pb(i);
}

int X;

int fun(int n){
	int curr=0,mx=0;
	f(i,0,n){
		cin>>X;
		curr+=X;
		mx=max(mx,curr);	
	}
	return mx;
}

void solve(){
	int n; cin>>n;
	int a=fun(n);
	cin>>n;
	int b= fun(n);
	cout<<a+b<<"\n";
}


void input(){
	//pri();
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
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases