#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define f(i,x,n) for(int i=x;i<(int)n;++i)
#define vi vector<int>
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define sz(x) x.size()
#define mpi map<int,int>

vector<pair<int,int>> vt;

void st(int curr,int L,int R,int l,int r,int v){
	if(L==R){
		if(L>=l && L<=r){
			vt[curr].ff=v;
			vt[curr].ss=-1;
		}
		return ;
	}
	if(R<l || r<L) return ;
	if(L>=l && R<=r){
		vt[curr].ss=v;
		return ;
	}
	int mid=L+R; mid/=2;
	st(2*curr+1,L,mid,l,r,v);
	st(2*curr+2,mid+1,R,l,r,v);
	vt[curr].ss=-1;
	int add=0;
	if(vt[2*curr+1].ss!=-1) add+=vt[2*curr+1].ss*(mid-L+1); else add+=vt[2*curr+1].ff;
	if(vt[2*curr+2].ss!=-1) add+=vt[2*curr+2].ss*(R-mid); else add+=vt[2*curr+2].ff;
	vt[curr].ff=add;
}

int gt(int curr,int L,int R,int l,int r){
	if(L==R){
		if(L>=l && L<=r) return vt[curr].ff;
		return 0;
	}
	if(R<l || r<L) return 0;
	if(L>=l && R<=r){
		if(vt[curr].ss!=-1) return vt[curr].ss*(R-L+1);
		else return vt[curr].ff;
	}
	int mid=L+R; mid/=2;
	if(vt[curr].ss!=-1) {
		vt[2*curr+1].ss=vt[curr].ss;
		vt[2*curr+2].ss=vt[curr].ss;
		vt[curr].ss=-1;
	}
	return gt(2*curr+1,L,mid,l,r)+gt(2*curr+2,mid+1,R,l,r);
}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int t; cin>>t;
	while(t--){
		int n,m; cin>>n>>m;
		int a[n][m]; f(i,0,n) f(j,0,m) cin>>a[i][j];
		int ans=0;
		for(int i=0;2*i<n;++i) for(int j=0;2*j<m;++j){
			vector<int> nums;
			nums.pb(a[i][j]);
			if(i!=n-i-1) nums.pb(a[n-i-1][j]);
			if(j!=m-j-1) nums.pb(a[i][m-j-1]);
			if(i!=n-i-1 && j!=m-j-1) nums.pb(a[n-i-1][m-j-1]);
			int add=LLONG_MAX;
			for(int i1=0;i1<nums.size();++i1){
				int th=0;
				for(int j1=0;j1<nums.size();++j1) th+=abs(nums[i1]-nums[j1]);
				add=min(add,th);
			}
			ans+=add;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
