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
	int n,k; cin>>n>>k;
	string s; cin>>s;
	int su[n+1],p1[n+1],p2[n+1]; su[0]=p1[0]=p2[0]=0;
	f(i,1,n+1){
		if(s[i-1]=='+'){
			su[i]=su[i-1]+1;
		}else{
			su[i]=su[i-1]-1;
		}
		p1[i]=max(p1[i-1],su[i]);
		p2[i]=min(p2[i-1],su[i]);
	}
	
	int s1[n+1],s2[n+1],sb[n+1]; sb[n]=s1[n]=s2[n]=su[n];
	for(int i=n-1;i>=0;--i){
		if(s[i]=='+')
			sb[i]=sb[i+1]-1;
		else 
			sb[i]=sb[i+1]+1;
		s1[i]=max(s1[i+1],sb[i]);
		s2[i]=min(s2[i+1],sb[i]);
	}	
	
	while(k--){
		int l,r; cin>>l>>r;
		if(l==1 || r==n){
			if(l==1 && r==n){
				cout<<"1\n";
			}else if(l==1){
				cout<<s1[r]-s2[r]+1<<"\n";
			}else{
				cout<<p1[l-1]-p2[l-1]+1<<"\n";
			}
		}else{
			int mx=p1[l-1],mn=p2[l-1];
			mx=max(mx,s1[r]+su[l-1]-su[r]);
			mn=min(mn,s2[r]+su[l-1]-su[r]);
			cout<<mx-mn+1<<"\n";
		}
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