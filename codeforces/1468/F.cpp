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
	map<pair<int,int>,int> mp;
	f(i,0,n){
		int x,y,u,v; cin>>x>>y>>u>>v; 
		u-=x; v-=y;
		int g=__gcd(abs(u),abs(v));
		u/=g; v/=g;
		mp[{u,v}]++;
	}
	int res=0;
	for(auto it : mp){
		int fre=it.ss;
		pair<int,int> p= it.ff;
		p.ff*=-1; p.ss*=-1;
		int fre1=mp[p];
		res+=fre*fre1;
	}
	res/=2;
	cout<<res<<"\n";
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
	co-ordinates select the angle at which they meet
	and if they meet then in starting they have opposite vectors.
*/