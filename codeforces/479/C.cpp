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
 
// mod value -- set it right dummy
 
int mod=1e9+7;
 
// eight directions -- which way you wanna go ?
 
int dx8[]={-1,-1,-1,0,0,1,1,1};
int dy8[]={-1,0,1,-1,1,-1,0,1};
 
int dx4[]={-1,1,0,0};
int dy4[]={0,0,1,-1};
 
// string splitter
 
vector<string> vec_splitter(string s) {
	s += ',';
	vector<string> res;
	while(!s.empty()) {
		res.push_back(s.substr(0, s.find(',')));
		s = s.substr(s.find(',') + 1);
	}
	return res;
}
 
// integer to string -- need better datatypes ?
 
string fx(int a){
	string s;
	while(a!=0){
		s+='0'+a%10;
		a/=10;
	}
	reverse(all(s));
	return s;
}
 
// prime generator -- 
 
vi pr;
int rep[100005];
void pri(){
	f(i,2,100005){
		if(rep[i]==0)
		for(int j=2*i;j<100005;j+=i){
			rep[j]=1;
		}
	}
	f(i,2,100005) if(rep[i]==0) pr.pb(i);
}
 
 
// min segment tree -- 
 
vi vt;
 
void st(int curr,int l,int r,int v,int id){
	if(l==r){
		if(l==id) vt[curr]=v;
		return ;
	}
	if(r<id || id<l) return ;
	int mid=l+r; mid/=2;
	st(2*curr+1,l,mid,v,id);
	st(2*curr+2,mid+1,r,v,id);
	vt[curr]=min(vt[2*curr+1],vt[2*curr+2]);
}
 
int gt(int curr,int l,int r,int L,int R){
	if(l==r){
		if(l>=L && l<=R) return vt[curr];
		return LLONG_MAX;
	}
	if(l>R || r<L) return LLONG_MAX;
	if(l>=L && r<=R) return vt[curr];
	int mid=l+r; mid/=2;
	return min(gt(2*curr+1,l,mid,L,R) ,gt(2*curr+2,mid+1,r,L,R));
}
 
// start solving -- 
 
int a[20][20];
int vis[20][20];
int m,n,s;
 
int rec(int x,int y,int rem){
	if(rem==-1) return 0;
	vis[x][y]=1;
	int here=0;
	if(a[x][y]==10) {
		a[x][y]=0;
		here+=1;
	} 
	int mx=0;
	vpii vp,nvp;
	f(i,0,4){
		int nx=x+dx4[i];
		int ny=y+dy4[i];
		if(nx<0 || nx>=m || ny<0 || ny>=n) continue;
		if(a[nx][ny]==-1) continue;
		if(vis[nx][ny]==1)
			vp.pb({nx,ny});
		else nvp.pb({nx,ny});
	}
	for(auto it : vp)
		mx=max(mx,rec(it.ff,it.ss,rem-1));
	for(auto it : nvp)
		mx=max(mx,rec(it.ff,it.ss,rem-1));
	if(here==1) a[x][y]=10;
	vis[x][y]=0;
	return here+mx;
}
 
void solve(){
	int n; cin>>n;
	vector<pair<int,int>> vt(n);
	f(i,0,n) cin>>vt[i].ff>> vt[i].ss;
	sort(all(vt));
	int curr=-1;
	f(i,0,n){
		if(curr<=vt[i].ss) curr=vt[i].ss;
		else curr=vt[i].ff;	
	}
	cout<<curr<<"\n";
	return ;
}
 
void input(){
	int t=1; //cin>>t;
	f(T,1,t+1)
		solve(); 
}
 
int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);	
	input();
	return 0;
}
 
// read question properly and think a little before you type