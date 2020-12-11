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


void solve(){
	int n,m; cin>>n>>m;
	string s[n]; f(i,0,n) cin>>s[i];
	int ret=0;
	f(i,1,n+1){
		int r=i,c=2*i-1;
		if(c>m) break;
		f(i1,0,n){
			f(j1,0,m){
				int max_l=j1-i+1,max_r=j1+i-1,max_d=i+i1-1;
				if(max_l<0 || max_r>=m || max_d>=n) continue;
				int poss=1;
				int sr,sc;
				f(k1,0,i){
					int exp_c=(k1+1)*2; exp_c-=1;
					sr=i1+k1; sc=j1-k1;
					int cnt=0;
					f(l1,0,exp_c){
						if(s[sr][sc]=='*') ++cnt;
						++sc;
					}
					if(cnt!=exp_c) {
						poss=0;
						break;
					}
				}
				ret+=poss;
			}
		}	
	}
	cout<<ret<<"\n";
	return ;
}

void C(){
	int n,m; cin>>n>>m;
	int a[n+5]={0};
	f(i,1,n+1) cin>>a[i];
	ld ret=1;
	int mx=-1;
	for(int i=n;i>=1;--i) if(a[i]!=i) {
		mx=i;
		break;
	}
	ld dec=1;
	f(i,0,m){
		int id; cin>>id;
		ld p; cin>>p;
		if(id>=mx)
			dec*=(1-p);
	}
	ret-=dec;
	if(mx==-1) 
		cout<<"1.0000000000\n";
	else
		cout<<fixed<<setprecision(7)<<ret<<"\n";
} 
 
void input(){
	int t=1; cin>>t;
	f(T,1,t+1)
		C(); 
}
 
int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);	
	srand(time(0));
	input();
	return 0;
}
 
// read question properly and think a little before you type