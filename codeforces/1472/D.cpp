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

int mod=1e9+7;

int lcm(int a,int b){
	int g=__gcd(a,b);
	a*=b; a/=g;
	return a;
}

const int mxn = 203000;
vi a1,a2;

void solve(){
	int n; cin>>n;
	a1.clear(); a2.clear();
	f(i,0,n) {
		int x; cin>>x;
		if(x%2==0) a1.pb(x);
		else a2.pb(x);
	}
	sort(all(a1)); sort(all(a2));
	reverse(all(a1)); reverse(all(a2));
	int tu=0,s=0,ss=0;
	int n1=sz(a1),n2=sz(a2),id1=0,id2=0;
	f(i,0,n){
		if(id1==n1){
			if(tu==0){
			 	++id2;	
			}else{
			 	ss+=a2[id2];
			 	++id2;
			}
		}else if(id2==n2){
			if(tu==0){
			 	s+=a1[id1];
			 	++id1;
			}else{
			 	++id1;
			}
		}else{
			if(tu==0){
			 	if(a1[id1]>=a2[id2]){
			 		s+=a1[id1];
			 		++id1;
				 }else{
				 	++id2;
				 }
			}else{
			 	if(a2[id2]>=a1[id1]){
			 		ss+=a2[id2];
			 		++id2;
				 }else{
				 	++id1;
				 }
			}
		}
		tu=1-tu;
	}
	if(s>ss) cout<<"Alice\n";
	else if(ss>s) cout<<"Bob\n";
	else cout<<"Tie\n";	
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
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases