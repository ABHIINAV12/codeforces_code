#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
using namespace __gnu_pbds;
using namespace std;
#define int long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define f(i,x,n) for(int i=x;i<(int)n;++i)
#define vpii vector<int>
#define vi vector<int>
#define mpii map<pair<int,int>,int>
#define mpivpii map<int,vector<pair<int,int>>>
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define sz(x) x.size()
#define mpi map<int,int>
#define vvi vector<vector<int>>
#define vvvi vector<vvi>
ld pie=3.141592653589;
int mod=1e9+7;
int mod1=998244353;


int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};


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


void EE(int a, int b, int& x, int& y)
{
    if(a%b == 0)
    {
        x=0;
        y=1;
        return;
    }
    EE(b,a%b,x,y);
    int temp = x;
    x = y;
    y = temp - y*(a/b);
}

int inverse(int a, int m)
{
    int x,y;
    EE(a,m,x,y);
    if(x<0) x += m;
    return x;
}

void facto(){
  fact[0]=1;
  f(i,1,2005) {fact[i]=i*fact[i-1]; fact[i]%=mod;}
  f(i,0,2005) infact[i]=inverse(fact[i],mod); 
}

int nck (int n,int k){
  if(k<0 || k>n) return 0;
  int ret=fact[n]; ret*=infact[k]; ret%=mod;
  ret*=infact[n-k]; ret%=mod;
  return ret;
}

void toutient(int n) {
    vector<int> phi(n + 1);
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
        phi[i] = i - 1;

    for (int i = 2; i <= n; i++)
        for (int j = 2 * i; j <= n; j += i)
              phi[j] -= phi[i];
	cout<<phi[n];
}


struct Node {
        int val, count;
        Node* left;
        Node* right;
        Node(int val, int count) : val(val), count(count), left(NULL), right(NULL) {}
        ~Node() {
            delete left;
            delete right;
        }
    };
    
    // return the smaller number count
    int insertNode(Node*& node, int val, int go_to_right) {
        if (!node) {
            node = new Node(val, 0);
            return go_to_right;
        }
        // if larger than current node, move the right, but you also need to add all left before return
        if (val > node->val) {
            return node->count + insertNode(node->right, val, go_to_right + 1);
        } else {
            // update the smaller count
            node->count++;
            return insertNode(node->left, val, go_to_right);
        }
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        
        Node* root = NULL;
        
        for (int i = n-1; i >= 0; i--) {
            res[i] = insertNode(root, nums[i], 0);
        }
        
        return res;
    }


void solve(){
	int n; cin>>n;
	ld p; cin>>p; p/=100;
	ld dp[n+1]={0}; dp[0]=1;
	f(i,1,n+1){
		dp[i]+=(i>=2 ? dp[i-2]*p: 0);
		dp[i]+=(i>=3 ? dp[i-3]*(1-p): 0);
	}
	cout<<fixed<<setprecision(10)<<dp[n]<<"\n";
}

bool ft(int n){
	int s=0;
	while(n!=0){
		s+=n%10;
		n/=10;
	}
	return (s%4==0);
}

bool comp(pii a,pii b){
	if(a.ff==b.ff) return a.ss<=b.ss;
	else return a.ff<=b.ff;
}
priority_queue<pii,vector<pii>, function<bool(pii,pii)>> pq(comp);

void interact(){
	int n; cin>>n;
	int pre[n];
	f(i,1,n){
		cout<<"? "<<"1 "<<i+1<<endl;
		int x; cin>>x;
		pre[i]=x;
	}
	cout<<"? "<<"2 "<<n<<endl;
	int x; cin>>x;
	cout<<"! ";
	int ans[n]; ans[0]=pre[n-1]-x;
	for(int i=n-1;i>=2;--i) ans[i]=pre[i]-pre[i-1];
	ans[1]=pre[1]-ans[0];
	f(i,0,n) cout<<ans[i]<<" ";
	cout<<endl;
}

int ans;

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int t; cin>>t;
	while(t--){
		int n,k; cin>>n>>k;
		if(n==1 || n==2) cout<<"1\n";
		else{
			n-=2;
			n=(n+k-1)/k;
			cout<<n+1<<"\n";
		}
	}
	return 0;
}
