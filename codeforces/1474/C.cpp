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

int cnt[mxn];

void solve(){
	int n; cin>>n;
	vi vt(2*n); f(i,0,2*n) cin>>vt[i];
	sort(all(vt));
	for(int here=2*n-2;here>=0;--here){
		f(i,0,2*n) cnt[vt[i]]++;
		int x= vt[2*n-1] + vt[here];
		bool done=0;
		vi rem; int j=2*n-1;
		f(ops,0,n){
			while(j>=0 && cnt[vt[j]]==0) --j;
			rem.pb(vt[j]); rem.pb(x-vt[j]);
			cnt[vt[j]]--; cnt[x-vt[j]]--;
			if((cnt[vt[j]]<0) || (cnt[x-vt[j]]<0)){
				cnt[vt[j]]=0;
				cnt[x-vt[j]]=0;
				break;
			}
			x = max(vt[j],x-vt[j]);
			if(ops==(n-1)) done=1;
		}
		f(i,0,2*n) cnt[vt[i]]=0;
		if(done){
			cout<<"YES\n";
			cout<<rem[0]+rem[1]<<"\n";
			for(int ii=0;ii<sz(rem);ii+=2) cout<<rem[ii]<<" "<<rem[ii+1]<<"\n";	
			return ;
		}
	}
	cout<<"NO\n";
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