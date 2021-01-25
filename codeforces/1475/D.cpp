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

void solve(){
	int n,m; cin>>n>>m; int a[n]; f(i,0,n) cin>>a[i]; int b[n]; f(i,0,n) cin>>b[i];
	vi x,y; f(i,0,n) if(b[i]==1) x.pb(a[i]); else y.pb(a[i]); sort(all(x)); sort(all(y));
	reverse(all(x)); reverse(all(y));
	int xx=sz(x), yy=sz(y),curr=0; 
	int pre[yy+1]; pre[0]=0; f(i,1,yy+1) pre[i]=pre[i-1]+y[i-1]; 
	int ret=INT_MAX;
	f(i,0,xx+1){
		if(i!=0) curr+=x[i-1];
		int l=0,h=yy,poss=-1,rem=m-curr;
		while(l<=h){
			int mid=l+h; mid/=2;
			if(pre[mid]>=rem){
				poss=mid; h=mid-1;
			}else l=mid+1;
		}
		if(poss!=-1) ret=min(ret,i+2*poss);
	}
	if(ret==INT_MAX) ret=-1;
	cout<<ret<<"\n";
}


int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);	
	srand(time(0));
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int t=1; cin>>t;
	while(t--) solve();
	return 0;
}

// ============== Notes =============== //
/*
	

*/