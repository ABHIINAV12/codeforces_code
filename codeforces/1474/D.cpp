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
 
bool ck(vi a){
	int n=sz(a);
	f(i,1,n){
		if(a[i]<a[i-1]) return 0;
		a[i]-=a[i-1];
		a[i-1]=0;
	}
	return a.back() == 0;
} 

void solve(){
	int n; cin>>n;
	vi vt(n); f(i,0,n) cin>>vt[i]; 
	if(ck(vt)){
		cout<<"YES\n";
		return ;
	}
	reverse(all(vt));
	if(ck(vt)){
		cout<<"YES\n";
		return ;
	}
	if(n==1){
		cout<<"NO\n";
		return ;
	}
	swap(vt[0],vt[1]);
	if(ck(vt)){
		cout<<"YES\n";
		return ;
	}
	swap(vt[0],vt[1]);
	
	swap(vt[n-1],vt[n-2]);
	if(ck(vt)){
		cout<<"YES\n";
		return ;
	}
	swap(vt[n-1],vt[n-2]);
	
	vi pre(n),suff(n),tmp=vt;
	pre[0]=vt[0]; 
	
	f(i,1,n){
		if(tmp[i]<tmp[i-1] || pre[i-1]==-1){
			pre[i]=-1;
			continue;
		}
		tmp[i]-=tmp[i-1];
		pre[i]=tmp[i];
		tmp[i-1]=0;
	}
	tmp=vt; suff[n-1]=tmp[n-1];
	
	for(int i=n-2;i>=0;--i){
		if(tmp[i]<tmp[i+1] || suff[i+1]==-1){
			suff[i]=-1;
			continue;
		}
		tmp[i]-=tmp[i+1];
		tmp[i+1]=0;
		suff[i]=tmp[i];
	}
	
	f(i,1,n-2){
		if(pre[i-1]==-1 || suff[i+2]==-1) continue;
		tmp={pre[i-1],vt[i+1],vt[i],suff[i+2]};
		if(ck(tmp)){
			cout<<"YES\n";
			return ;
		}
	}
	
	cout<<"NO\n";
	return ;
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
	

*/