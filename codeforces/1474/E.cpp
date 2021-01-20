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
 

void solve(){
	int n; cin>>n;
	if(n&1){
		vi x;
		int bg=n/2; 
		int curr=1; f(i,0,bg){
			x.pb(curr);
			++curr;
		}
		int ed= curr; ++curr;
		int fr= curr; ++curr;
		f(i,0,bg-1){
			x.pb(curr); ++curr;
		}
		int sc=(n-1)*(n-1);
		int here=n-2; int add=0;
		f(i,0,bg-1){
			add+=here*here;
			--here;
		}
		sc+=2*add; sc+=here*here;
		cout<<sc<<"\n";
		cout<<fr<<" "; for(auto it : x) cout<<it<<" "; cout<<ed<<"\n";
		cout<<n-1<<"\n";
		int last=n; int mid=n/2;
		f(i,0,bg) {
			cout<<mid+1<<" "<<last<<"\n"; --mid;
		}
		int tmp=n/2; tmp+=2;
		f(i,0,bg-1){
			cout<<tmp<<" "<<"1\n";
			++tmp;
		}
		cout<<"1 "<<last<<"\n";
	}else{
		vi x;
		int bg=n/2; --bg;
		int curr=1; f(i,0,bg){
			x.pb(curr);
			++curr;
		}
		int ed= curr; ++curr;
		int fr= curr; ++curr;
		f(i,0,bg){
			x.pb(curr); ++curr;
		}
		int sc=(n-1)*(n-1);
		int here=n-2; int add=0;
		f(i,0,bg){
			add+=here*here;
			--here;
		}
		sc+=2*add;
		cout<<sc<<"\n";
		cout<<fr<<" "; for(auto it : x) cout<<it<<" "; cout<<ed<<"\n";
		cout<<n-1<<"\n";
		int last=n; int mid=n/2;
		f(i,0,bg) {
			cout<<mid<<" "<<last<<"\n"; --mid;
		}
		int tmp=n/2; tmp+=1;
		f(i,0,bg){
			cout<<tmp<<" "<<"1\n";
			++tmp;
		}
		cout<<"1 "<<last<<"\n";
	}
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