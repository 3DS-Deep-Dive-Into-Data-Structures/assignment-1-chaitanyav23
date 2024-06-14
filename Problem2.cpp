#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> solve( vector<ll>& q, ll n, ll x){
	vector<ll> p;
	vector<pair<ll,ll>> q_i;
	for(ll i=0;i<n;i++){ q_i.push_back({q[i],i+1});}
	sort(q_i.begin(),q_i.end());
	for(ll i=0;i<n-2;++i){
		ll l=i+1,r=n-1;
		while(l<r){
			ll y=q_i[i].first+q_i[l].first+q_i[r].first;
			if(y==x){
				p.push_back(q_i[i].second);
				p.push_back(q_i[l].second);
				p.push_back(q_i[r].second);
				return p;
				}
			else if(y<x) l++; 
			else r--;
			}
	}
	return p;
}
int main(){
	ll n,x;
	cin>>n>>x;
	vector<ll> q(n);
	for(ll i=0;i<n;i++){ cin>>q[i];}
//	sort(q.begin(),q.end());
	vector<ll> p=solve(q,n,x);
	if(p.size()==3) {for(ll i=0;i<3;i++) {cout<<p[i]<<" ";}
	}
	else cout<< "IMPOSSIBLE";
	return 0;
}
