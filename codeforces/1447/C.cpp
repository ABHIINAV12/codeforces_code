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
}

int dp[1010][1010];
vector<pair<int,int>>  grp[1011];
int n;
void dik(int s){
	f(i,0,n) dp[s][i]=LLONG_MAX;
	dp[s][s]=0;
   priority_queue <int, vector<int>, greater<int>> q;
    q.push(s);
    while(!q.empty()){
    	int lp=q.top(); q.pop();
    	for(auto it : grp[lp]){
    		if(dp[s][it.ff]>dp[s][lp]+it.ss){
    			dp[s][it.ff]=dp[s][lp]+it.ss;
    			q.push(it.ff);
			}
		}
	}
}

void solve(){
	int m,k; cin>>n>>m>>k;
	int dp[n][n]; f(i,0,n) f(j,0,n) dp[i][j]=INT_MAX;
	f(i,0,n) dp[i][i]=0;
	int edge[m][2]; f(i,0,m){
		int x,y; cin>>x>>y; --x; --y;
		int w; cin>>w;
		grp[x].pb({y,w});
		grp[y].pb({x,w});
		dp[x][y]=w; dp[y][x]=w;
		edge[i][0]=x; edge[i][1]=y;
	}
	int to[k],from[k]; f(i,0,k){
		int x,y; cin>>x>>y;
		--x; --y;
		to[i]=x; from[i]=y;
	}
	f(i,0,n) dik(i);
	int ret=LLONG_MAX;
	f(i,0,m){
		int here=0;
		f(j,0,k){
			int tp=dp[from[j]][to[j]];
			tp=min(tp,dp[from[j]][edge[i][0]]+dp[edge[i][1]][to[j]]);
			tp=min(tp,dp[from[j]][edge[i][1]]+dp[edge[i][0]][to[j]]);
			here+=tp;
		}
		//cout<<here<<"\n";
		ret=min(ret,here);
	}
	cout<<ret<<"\n";
}


void solve(){
	 int n; cin>>n;
	 vpii vt; f(i,0,n){
	 	int x,y; cin>>x>>y;
	 	vt.pb({x,y});
	 }
	 sort(all(vt));
	 int curr=0,dest=0;
	 int ret=0;
	 f(i,0,n){
	 	if(i==0){
	 		++ret;
	 		dest=vt[i].ss;
	 	}else if(i==(n-1)){
	 		int pass=vt[i].ff-vt[i-1].ff;
	 		int to_do=abs(dest-curr);
	 		if(to_do<=pass){
	 			curr=dest;
	 			dest=vt[i].ss;
	 			++ret;
	 		}else{
	 			if(dest<curr){
	 				curr-=pass;
	 			}else{
	 				curr+=pass;
	 			}
	 			int next=(10ll*(INT_MAX))-vt[i].ff;
	 			int add=0;
	 			if(curr<dest){
	 				int reach=min(dest,curr+next);
	 				if(vt[i].ss>=curr && vt[i].ss <=reach) add=1;
	 			}else{
	 				int reach=max(dest,curr-next);
	 				if(vt[i].ss>=reach && vt[i].ss<=curr) add=1;
	 			}
	 			ret+=add;
	 		}
	 	}else{
	 		int pass=vt[i].ff-vt[i-1].ff;
	 		int to_do=abs(dest-curr);
	 		if(to_do<=pass){
	 			curr=dest;
	 			dest=vt[i].ss;
	 			++ret;
	 		}else{
	 			if(dest<curr){
	 				curr-=pass;
	 			}else{
	 				curr+=pass;
	 			}
	 			int next=vt[i+1].ff-vt[i].ff;
	 			int add=0;
	 			if(curr<dest){
	 				int reach=min(dest,curr+next);
	 				if(vt[i].ss>=curr && vt[i].ss <=reach) add=1;
	 			}else{
	 				int reach=max(dest,curr-next);
	 				if(vt[i].ss>=reach && vt[i].ss<=curr) add=1;
	 			}
	 			ret+=add;
	 		}
	 	}
	 }
	 cout<<ret<<"\n";
}


void solve(){
	int x1,y1; cin>>x1>>y1;
	int x2,y2; cin>>x2>>y2;
	int n; cin>>n;
	string s; cin>>s;
	int r=x2-x1;
	int u=y2-y1;
	if(r==0 || u==0){
		if(r==0){
			if(u>0){
				int cnt=0; f(i,0,n) cnt+=s[i]=='U'; cnt*=2;
				if(cnt==0){
					cout<<-1<<"\n";
					return ;
				}
				int full = u/cnt;
				int moves=full*n;
				int rem=u-full*cnt;
				f(i,0,n) if(s[i]=='U'){
					rem-=2;
					++moves;
					if(rem<=0) break;
				}else moves++;
				cout<<moves<<"\n";
			}else{
				u*=-1;
				int cnt=0; f(i,0,n) cnt+=s[i]=='D'; cnt*=2;
				if(cnt==0){
					cout<<-1<<"\n";
					return ;
				}
				int full = u/cnt;
				int moves=full*n;
				int rem=u-full*cnt;
				f(i,0,n) if(s[i]=='D'){
					rem-=2;
					++moves;
					if(rem<=0) break;
				}else moves++;
				cout<<moves<<"\n";
			}
		}else{
			if(r>0){
				int cnt=0; f(i,0,n) cnt+=s[i]=='R'; cnt*=2;
				if(cnt==0){
					cout<<-1<<"\n";
					return ;
				}
				int full = r/cnt;
				int moves=full*n;
				int rem=r-full*cnt;
				f(i,0,n) if(s[i]=='R'){
					rem-=2;
					++moves;
					if(rem<=0) break;
				}else moves++;
				cout<<moves<<"\n";
			}else{
				r*=-1;
				int cnt=0; f(i,0,n) cnt+=s[i]=='L'; cnt*=2;
				if(cnt==0){
					cout<<-1<<"\n";
					return ;
				}
				int full = r/cnt;
				int moves=full*n;
				int rem=r-full*cnt;
				f(i,0,n) if(s[i]=='L'){
					rem-=2;
					++moves;
					if(rem<=0) break;
				}else moves++;
				cout<<moves<<"\n";
			}
		}
	}else{
		if(u>0 && r>0){
			int c1=0,c2=0;
			f(i,0,n) if(s[i]=='U') ++c1; else if(s[i]=='R') ++c2;
			c1*=2; c2*=2;
			if(c1==0 || c2==0){
				cout<<-1<<"\n";
				return ;
			}
			int full=max(u/c1,r/c2);
			u-=full*c1; r-=full*c2;
			int moves=full*n;
			f(i,0,n) {
				if(s[i]=='U') u-=2;
				if(s[i]=='R') r-=2;
				++moves;
				if(u<=0 && r<=0) break;
			}
			cout<<moves<<"\n";
			return ;
		}else if(u<0 && r>0){
			u*=-1; int c1=0,c2=0;
			f(i,0,n) if(s[i]=='D') ++c1; else if(s[i]=='R') ++c2;
			c1*=2; c2*=2;
			if(c1==0 || c2==0){
				cout<<-1<<"\n";
				return ;
			}
			int full=max(u/c1,r/c2);
			int moves=full*n;
			u-=full*c1; r-=full*c2;
			f(i,0,n){
				if(s[i]=='D') u-=2;
				if(s[i]=='R') r-=2;
				++moves;
				if(u<=0 && r<=0) break; 
			}
			cout<<moves<<"\n";
			return ;
		}else if(u>0 && r<0){
			r*=-1; int c1=0,c2=0;
			f(i,0,n) if(s[i]=='U') ++c1; else if(s[i]=='L') ++c2;
			c1*=2; c2*=2;
			if(c1==0 || c2==0){
				cout<<-1<<"\n";
				return ;
			}
			int full=max(u/c1,r/c2);
			int moves=full*n;
			u-=full*c1; r-=full*c2;
			f(i,0,n){
				if(s[i]=='U') u-=2;
				if(s[i]=='L') r-=2;
				++moves;
				if(u<=0 && r<=0) break; 
			}
			cout<<moves<<"\n";
			return ;
		}else{
			u*=-1; r*=-1; int c1=0,c2=0;
			f(i,0,n) if(s[i]=='D') ++c1; else if(s[i]=='L') ++c2;
			c1*=2; c2*=2;
			if(c1==0 || c2==0){
				cout<<-1<<"\n";
				return ;
			}
			int full=max(u/c1,r/c2);
			int moves=full*n;
			u-=full*c1; r-=full*c2;
			f(i,0,n){
				if(s[i]=='D') u-=2;
				if(s[i]=='L') r-=2;
				++moves;
				if(u<=0 && r<=0) break; 
			}
			cout<<moves<<"\n";
			return ;
		}
	}
}

void solve(){
	int n,k; cin>>n>>k;
	string s,t; cin>>s>>t;
	int fre[26]={0};
	int sre[26]={0};
	f(i,0,n) fre[s[i]-'a']++;
	f(i,0,n) sre[t[i]-'a']++;
	f(i,0,26){
		if(fre[i]>=sre[i]){
			int add=fre[i]-sre[i];
			if(add%k!=0) {
				cout<<"No\n";
				return ;
			}
			if(i!=25) fre[i+1]+=add;
		}else{
			cout<<"No\n";
			return ;
		}
	}
	cout<<"Yes\n";
	return ;
}

void solve(){
	int d,k; cin>>d>>k;
	int tp=d*d; tp/=2; tp/=(k*k);
	tp=sqrt(tp);
	int np=tp+1;
	int dis=(np*np*k*k) + (tp*tp*k*k);
	d*=d;
	if(dis<=d){
		cout<<"Ashish\n";
	}else cout<<"Utkarsh\n";
}


void solve(){
	int n; cin>>n;
	int x[n+5]={0};
	mpi mp;
	++mp[x[1]];
	int idx=-1;
	f(i,2,n+1){
		cout<<"XOR 1 "<<i<<endl;
		cin>>x[i];
		++mp[x[i]];
		if(mp[x[i]]>=2){
			 idx=i;
		}
	}
	if(idx!=-1){
		if(x[1]==x[idx]){
			cout<<"AND 1 "<<idx<<endl;
			int req; cin>>req;
			f(i,1,n+1) x[i]^=req;
			cout<<"! ";
			f(i,1,n+1) cout<<x[i]<<" ";
			cout<<endl;
			return ;
		}else{
			int f=-1,l=idx;
			f(i,1,n+1) if(x[i]==x[idx]){
				f=i;
				break;
			}
			cout<<"AND "<<f<<" "<<l<<endl;
			int num; cin>>num;
			cout<<"XOR 1 "<<f<<endl;
			int ano; cin>>ano;
			int req=(ano^num);
			f(i,1,n+1) x[i]^=req;
			cout<<"! ";
			f(i,1,n+1) cout<<x[i]<<" ";
			cout<<endl;
			return ;
		}
	}else{
		int ipx=-1;
		f(i,1,n+1) if(x[i]==(n-1)){
			ipx=i;
			break;
		}
		assert(ipx!=-1);
		int three=-1;
		f(i,2,n+1) if(i!=ipx){
			three=i;
			break;
		}
		int a1ipx,aipxthree,a1three; 
		a1ipx=0;
		cout<<"AND "<<ipx<<" "<<three<<endl;
		cin>>aipxthree;
		cout<<"AND 1 "<<three<<endl;
		cin>>a1three;
		a1ipx*=2; aipxthree*=2; a1three*=2;
		int req=a1ipx+aipxthree+a1three;
		req+=x[ipx]+x[three]+(x[ipx]^x[three]);
		req-=2*(x[ipx]^x[three]); req-=2*aipxthree;
		req/=2; 
		cout<<"! ";
		f(i,1,n+1) x[i]^=req;
		f(i,1,n+1) cout<<x[i]<<" ";
		cout<<endl;	
	}
	return ;
}

void F(){
	int n,m; cin>>n>>m;
	int a[n][m]; f(i,0,n) f(j,0,m) cin>>a[i][j];
	int diag[n+m-1]={0};
	f(i,0,n)
		f(j,0,m) diag[i+j]^=a[i][j];
	int state=0;
	f(i,0,n+m-1) if(diag[i]!=0) state=1;
	if(state) cout<<"Ashish\n";
	else cout<<"Jeel\n";
}*/

void solve(){
	int n; cin>>n;
	cout<<n-1<<"\n";
	f(i,1,n)
		cout<<i+1<<" ";
	cout<<"\n";
}

void B(){
	int n,m; cin>>n>>m;
	int cnt=0,s=0; n*=m;
	int mn=LLONG_MAX;
	f(i,0,n) {
		int x; cin>>x;
		if(x<0){
			++cnt;
			x*=-1;
		}
		s+=x;
		mn=min(mn,x);
	}	
	if(cnt&1) cout<<s-2*mn<<"\n";
	else cout<<s<<"\n";
}


void C(){
	int n,w; cin>>n>>w;
	vpii vt; f(i,0,n){
		int x; cin>>x;
		vt.pb({x,i+1});
	}
	sort(all(vt));
	int low=w+1; low/=2;
	int curr=0,l=0,r=0;
	while(r<n){
		curr+=vt[r++].ff;
		if(curr>=low && curr<=w){
			cout<<r-l<<"\n";
			f(j,l,r) cout<<vt[j].ss<<" "; cout<<"\n";
			return ;
		}
		if(curr>w){
			while(curr>w && l<r){
				curr-=vt[l++].ff;
			}
			if(curr>=low && curr<=w){
				cout<<r-l<<"\n";
				f(j,l,r) cout<<vt[j].ss<<" "; cout<<"\n";
				return ;
			}
		}
	}
	cout<<-1<<"\n";
}

void input(){
	int t=1; cin>>t;
	f(T,1,t+1)
		C(); 
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