//Abhinav ---IIIT_A
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define f(i,x,n) for(int i=x;i<(int)n;++i)
#define vpii vector<pair<int,int>> 
#define vi vector<int>
#define vpii vector<pair<int,int>> 
#define mpii map<pair<int,int>,int>
#define mpivpii map<int,vector<pair<int,int>>> 
#define pii pair<int,int> 
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define mpi map<int,int>
#define vvi vector<vector<int>>

ld pie=3.141592653;
int mod=1e9+7;

struct node{
	vector<int> vt;
	node* left=nullptr,*right=nullptr;
};

set<int> st;

void build_tree(node * root){
	int mx=*max_element(all(root->vt));
	int mn=*min_element(all(root->vt));
	int mid=mx+mn; mid/=2;
	vi g,gg; int sum=0;  
	for(auto it : root->vt) {
		if(it<=mid) g.pb(it); else gg.pb(it);	
		sum+=it;	
	}
	st.insert(sum); 
	if(sz(g)==0 || sz(gg)==0) return ;
	node *k=new node(),*kk=new node();
	k->vt=g; kk->vt=gg; 
	build_tree(k); build_tree(kk);
	root->left=k; root->right=kk;
	return ;
}

void solve(){
	int n,q; cin>>n>>q;
	st.clear();
	vi ret; f(i,0,n){
		int x; cin>>x;
		ret.pb(x);
	}
	node *rp = new node;
	rp->vt=ret; 
	build_tree(rp);
	while(q--){
		int xx; cin>>xx;
		if(st.find(xx)!=st.end()) cout<<"Yes\n";
		else cout<<"No\n";
	}
}


int32_t main(){ 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
 	int t=1; cin>>t;
 	while(t--) solve();
  return 0; 
}













