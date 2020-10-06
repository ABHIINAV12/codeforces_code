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
		int a,b,c; cin>>a>>b>>c;
		cout<<a+b+c-1<<"\n";
	}
	return 0;
}
