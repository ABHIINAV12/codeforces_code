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


/*
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

int** intMatrix(int n, int m) {
	int **A = (int**)malloc(sizeof(int*)*n);
	for (int i=0; i<n; i++) {
		A[i] = (int*)malloc(sizeof(int)*m);
	}
	return A;
}

void destroy_intMatrix(int **A, int n, int m) {
	for (int i=0; i<n; i++) {
		free(A[i]);
	}
	free(A);
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

int add(int a, int b){
	return (a + b + 1LL*mod) % mod;
}
int mul(int a, int b){
	return a * b % mod;
}
void sadd(int &a, int b){
	a = add(a, b);
}
void smul(int &a, int b){
	a = mul(a, b);
}

// finding anagrams

class FindAnagrams {
public:
	std::vector<int> getStartIndices(std::string s, std::string t) {
		vector<int> ret;
		if(s.size()<t.size()) return ret;
		int fre[26]={0};
		int com[26]={0};
		for(auto it : t) com[it-'a']++;
		for(int i=0;i<t.size();++i) fre[s[i]-'a']++;
		for(int i=0;i<s.size();++i){
			bool add=1;
			for(int j=0;j<26;++j) if(fre[j]!=com[j]) add=0;
			if(add) ret.push_back(i);
			--fre[s[i]-'a'];
			if(i+t.size()<s.size()) ++fre[s[i+t.size()]-'a'];
			else break;
		}
		return ret;		
	}
};

class ValidParentheses {
public:
	std::string getValidString(std::string s) {
		int cnt=0;
		string ret;
		for(auto it : s){
			if(it=='('){
				++cnt;
				ret+=it;
			}else{
				if(cnt>0){
					--cnt;
					ret+=it;
				}
			}
		}
		reverse(ret.begin(),ret.end());
		string fp;
		for(auto it : ret){
			if(cnt>0){
				if(it=='('){
					--cnt;
					continue;
				}
			}
			fp+=it;
		}
		reverse(fp.begin(),fp.end());
		return fp;
	}
};

// wanna choose some ?
int fact[2000005];
int infact[2000005];
 
int inv(int a){
  int y=mod-2;
  int r=1;
  while(y!=0){
    if(y&1){
      r*=a; r%=mod;
    }
    y/=2; a*=a; a%=mod;
  }
  return r;
}
 
int po(int a,int y){
  int r=1;
  while(y!=0){
    if(y&1){
      r*=a; r%=mod;
    }
    y/=2; a*=a; a%=mod;
  }
  return r; 
}
 
void facto(){
  fact[0]=1;
  f(i,1,2000005) {fact[i]=i*fact[i-1]; fact[i]%=mod;}
  f(i,0,2000005) infact[i]=inv(fact[i]); 
}
 
int nck (int n,int k){
  if(k<0 || k>n) return 0;
  int ret=fact[n]; ret*=infact[k]; ret%=mod;
  ret*=infact[n-k]; ret%=mod;
  return ret;
}

vi vt;

void st(int curr,int l,int r,int id,int val){
	if(l==r){
		if(l==id) vt[curr]^=val;
		return ;
	}
	if(id<l || id> r) return ;
	int mid=l+r; mid/=2;
	st(2*curr+1,l,mid,id,val);
	st(2*curr+2,mid+1,r,id,val);
	vt[curr]=vt[2*curr+1]^vt[2*curr+2];
}

int gt(int curr,int l,int r,int l1,int r1){
	if(l==r){
		if(l>=l1 && l<=r1) return vt[curr];
		return 0;
	}
	if(l>r1 || l1>r) return 0;
	if(l>=l1 && r<=r1) return vt[curr];
	int mid = l+r; mid/=2;
	int res=0;
	res^=gt(2*curr+1,l,mid,l1,r1);
	res^=gt(2*curr+2,mid+1,r,l1,r1);
	return res;
	
}



void solve(){
	int n,m; cin>>n>>m;
	int x=1; while(x<n) x*=2;
	f(i,0,2*x-1) vt.pb(0);
	f(i,0,n){
		int val; cin>>val;
		st(0,0,x-1,i,val);
	}
	f(i,0,m){
		int ty,a,b; cin>>ty>>a>>b;
		if(ty==1){
			--a; st(0,0,x-1,a,b);
		}else{
			--a; --b;
			int res=gt(0,0,x-1,a,b);
			cout<<res<<"\n";
		}
	}
	return ;
}

void D(){
	int n,m; cin>>n>>m;
	vi vt; vt.pb(0); vt.pb(n+1);
	f(i,0,m) {
		int x; cin>>x;
		vt.pb(x);
	}
	sort(all(vt));
	vi ano;
	f(i,1,sz(vt)){
		int add=vt[i]-vt[i-1]-1;
		if(add!=0) ano.pb(add);
	}
	sort(all(ano));
	if(sz(ano)==0) {
		cout<<0;
		return ;	
	} 
	int step=ano[0];
	int ret=0;
	f(i,0,sz(ano))
		ret+=((ano[i]+step-1)/step);
	cout<<ret;
}

int n,m; 
int a[1010],b[1010];
int dp[1010][1010];

int rec(int s,int ss){
	if(s==n) return m-ss;
	if(ss==m) return n-s;
	if(dp[s][ss]!=-1) return dp[s][ss];
	int here;
	if(a[s]==b[ss]) here=rec(s+1,ss+1);
	else {
		here=1+min(rec(s+1,ss),rec(s,ss+1));
		here=min(here,1+rec(s+1,ss+1));
	}
	dp[s][ss]=here;
	return here;
}

int josephus(int n) 
{ 
    // Find value of 2 ^ (1 + floor(Log n)) 
    // which is a power of 2 whose value 
    // is just above n. 
    int p = 1; 
    while (p < n) 
        p *= 2; 
  
    // Return 2n - 2^(1+floor(Logn)) + 1 
    return (2 * n) - p ; 
}

ld dp[110][110][110];
int a,b,c;

ld rec(int x,int y,int z){
	if(x==100 || y==100 || z==100) return 0;
	if(dp[x][y][z]!=-1) return dp[x][y][z];
	ld e[3]; 
	if(x!=0)
		e[0]=(x/(x+y+z))*rec(x+1,y,z);
	else e[0]=0;
	if(y!=0)
		e[1]=(y/(x+y+z))*rec(x,y+1,z);
	else e[1]=0;
	if(z!=0)
		e[2]=(z/(x+y+z))*rec(x,y,z+1);
	else e[2]=0;
	dp[x][y][z]=1.00+e[0]+e[1]+e[2];
	return dp[x][y][z];
}

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


void A(){
	int n; cin>>n;
	f(i,2,n+1) cout<<i<<" "; cout<<"1 \n";
}

void B(){
	int n; cin>>n;
	int a[n]; f(i,0,n) cin>>a[i];
	map<int,int> mp; f(i,0,n) ++mp[a[i]];
	int look=-1;
	for(auto it : mp) if(it.ss==1) {
		look=it.ff;
		break;
	}
	if(look==-1) cout<<"-1\n";
	else{
		f(i,0,n) if(a[i]==look) {
			cout<<i+1<<"\n";
			return ;
		}
	}
}
void C(){
	int n; cin>>n;  int pre=-1;
	vi vt; f(i,0,n){
		int x; cin>>x;
		if(x!=pre) vt.pb(x);
		pre=x;
	}
	mpi mp; f(i,0,sz(vt)) ++mp[vt[i]];
	int ret=INT_MAX;
	f(i,1,sz(vt)-1){
		int here=mp[vt[i]]+1;
		ret=min(ret,here);
	}
	if(vt[0]==vt[sz(vt)-1]) {
		int here=mp[vt[0]]-1;
		ret=min(ret,here);
	}else{
		int here=mp[vt[0]];
		here=min(here,mp[vt[sz(vt)-1]]);
		ret=min(ret,here);
	}
    cout<<ret<<"\n";
}
void D(){
	int n; cin>>n;
	int c=n;
	int mx=-1,nu;
	for(auto it : pr){
		if(c%it==0){
			int num=0;
			while(c%it==0){
				c/=it;
				++num;
			}
			if(num>mx){
				mx=num;
				nu=it;
			}
		}
	}
	if(c!=1){
		int num=1;
		if(num>mx){
			mx=num;
			nu=c;
		}
	}
	cout<<mx<<"\n";
	vi ret; f(i,0,mx) ret.pb(nu);
	f(i,0,mx) n/=nu;
	ret[mx-1]*=n;
	f(i,0,mx) cout<<ret[i]<<" "; cout<<"\n";
}
void E(){
	int n; cin>>n;
	set<int> vt[n]; f(i,0,n){
		int x,y; cin>>x>>y;
		--x; --y;
		vt[x].insert(y);
		vt[y].insert(x);
	}
	int cnt[n]; f(i,0,n) cnt[i]=1;
	queue<int> q;
	f(i,0,n) if(sz(vt[i])==1) q.push(i);
	while(!q.empty()){
		int lp=q.front(); q.pop();
		int par=*vt[lp].begin();
		cnt[par]+=cnt[lp]; cnt[lp]=0;
		vt[par].erase(vt[par].find(lp));
		if(sz(vt[par])==1) q.push(par);
	} 
	int ret=0;
	f(i,0,n){
		int here=cnt[i]*(cnt[i]-1); here/=2;
		here+=cnt[i]*(n-cnt[i]);
		ret+=here;
	}
	cout<<ret<<"\n";
	
}

vi vt;

void st(int curr,int l,int r,int id,int val){
	if(l==r){
		if(l==id) vt[curr]=val;
		return ;
	}
	if(id<l || id>r) return ;
	int mid=l+r; mid/=2;
	st(2*curr+1,l,mid,id,val);
	st(2*curr+2,mid+1,r,id,val);
	vt[curr]=min(vt[2*curr+1],vt[2*curr+2]);
}

int gt(int curr,int l,int r,int L,int R){
	if(l==r){
		if(l>=L && l<=R) return vt[curr];
		return LLONG_MAX;
	}
	if(R<l || r<L) return LLONG_MAX;
	if(l>=L && r<=R) return vt[curr];
	int mid=l+r; mid/=2;
	int res=gt(2*curr+1,l,mid,L,R);
	res=min(res,gt(2*curr+2,mid+1,r,L,R));
	return res;
}

void solve(){
	int n; cin>>n;
	vt.clear(); int x=1; while(x<n) x*=2;
	f(i,0,2*x-1) vt.pb(0);
	int a[n];
	f(i,0,n){
		cin>>a[i];
		st(0,0,x-1,i,a[i]);
	}
	int pre=-1,mx=-1;
	int re[n]; for(int i=n-1;i>=0;--i) if(i==n-1) re[i]=a[i]; else re[i]=max(re[i+1],a[i]);
	//cout<<n<<"\n";
	//f(i,0,n) cout<<re[i]<< " "; cout<<"\n";
	f(i,0,n){
		mx=max(pre,a[i]);
		//if(mx==pre) continue;
		int low=i+1,high=n-1;
		int poss=-1;
		while(low<=high){
			int mid=low+high; mid/=2;
			if(re[mid]<=mx){
				poss=mid;
				high=mid-1;
			}else low=mid+1;
		}
		//cout<<i<<" "<<poss<<"\n";
		if(poss!=-1){
			if(re[poss]==mx){
				while(poss<n && re[poss]==mx){
					int left=i+1,right=poss-1;	
					if(left<=right){
						int here=gt(0,0,x-1,left,right);
						if(here==mx){
							cout<<"YES\n";
							cout<<i+1<<" "<<right-left+1<<" "<<n-right-1<<"\n";
							return ;
						}else if(here<mx) break; 
					}
					++poss;
				}
			}
		} 
		pre=mx;
	}
	cout<<"NO\n";
}*/


void solve(){
	int n; cin>>n;
	int ret=1; f(i,1,n+1) ret*=i;
	ret/=(n/2);
	ret/=(n/2);
	ret/=2;
	cout<<ret<<"\n";	
}

void input(){
	int t=1; //cin>>t;
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