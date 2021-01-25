//organize and stay in moment - Abhinav IIIT-A
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define f(i,x,n) for(int i=x;i<n;++i)
#define ar array
#define MAXN (int)2e5+5
#define pb push_back
#define ld long double
int mod= 1e9+7;
int mod2=998244353;
int arr[MAXN];
int as;
void input(){
  cin>>as;
  f(i,0,as) cin>>arr[i];
}
int nc2(int n){
	if(n<2)
	return 0;
	int p=n-1;
	if(n&1)
		p/=2;
	else n/=2;
	p*=n;
	return p;
}
bool isPallin(string s){
	int n=s.size();
	f(i,0,n/2)
	if(s[i]!=s[n-i-1])
	return 0;
	return 1;
}
int digit(int n){
	int x=0;
	while(n!=0){
		++x;
		n/=10;
	}
	return x;
}
string longest_prefix_pallin(string s){
	int n=s.size();
	char look = s[0];
	for(int i=n-1;i>=0;--i){
		if(s[i]==look){
			bool poss=1;
			int h=i;
			int l=0;
			while(l<=h){
				if(s[l]!=s[h]){
					poss=0;
					break;
				}
				++l;--h;
			}
			if(poss){
				string ret=s.substr(0,i+1);
				return ret;
			}
		}
	}
//	string pp=s.substr(0,1);
//	return pp;
}
void solve(){
	string s; cin>>s;
    string ans="";
	int n=s.size();
	int l=0,h=n-1;
	while(l<=h && s[l]==s[h])	{
		if(l!=h)
		ans+=s[l];
		++l; --h;
	}
	cout<<ans;
	if(l>h && n&1)
		cout<<s[n/2];
	else{
		string cp=s.substr(l,h-l+1);
		string left=longest_prefix_pallin(cp);
		reverse(cp.begin(),cp.end());
		string right=longest_prefix_pallin(cp);
		if(left.size()>=right.size())
		cout<<left;
		else cout<<right;
	}
	reverse(ans.begin(),ans.end());
	cout<<ans<<"\n";
}
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; t=1; cin>>t;
  while(t--) solve();
  return 0;
}