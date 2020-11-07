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

int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,0,1,-1,1,-1,0,1};

int par[200];

int gt(int idx){
	if(par[idx]==idx) return idx;
	return par[idx] = gt(par[idx]);
}

void solve(){
	int n; cin>>n;
	int a[n], b[n];
	f(i,0,n) cin>>a[i]; 
	f(i,0,n) cin>>b[i];
	int poss=-1, l=0,h=1e15;
	while(l<=h){
		int mid=l+h; mid/=2;
		int sum=0;
		f(i,0,n) if(a[i]>mid) sum+=b[i];
		if(sum<=mid){
			poss=mid;
			h=mid-1;
		}else l=mid+1;
	} 
	cout<<poss<<"\n";
}


int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);	
	int t=1; cin>>t;
	while(t--) solve();
	return 0;
}