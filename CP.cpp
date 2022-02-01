// JAI SHREE RAM!!

#include <iostream>
#include <vector>
#include <cmath>
#include <ostream>
#include <list>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <deque>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <string>
using namespace std;

#define ff first 
#define ss second 
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define mid(s,e) (s+(e-s)/2)
#define debug cout<<"HERE---------------"<<endl;
#define ll long long
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef unordered_map<int,int> umi;
typedef map<int,int> mi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;
const int mod = 1000000007;

int modExp(int a, int b, int c){
    if(a==0) return 0;
    if(b==0) return 1;
    long ans;
    if(b%2==0){
        long smallAns=modExp(a,b/2,c);
        ans=(smallAns*smallAns)%c;
    }
    else{
        // Using property (a*b)%c = ((a%c)*(b%c))%c
        long smallAns=modExp(a,b-1,c);
        ans=a%c;
        ans=(ans*smallAns)%c;
    }
    return int((ans+c)%c);
}

vector<int> phi(1e6+1);
void buildEulerPhi(){
    for(int i=1;i<=1e6;i++) phi[i]=i;
    for(int i=2;i<=1e6;i++){
        if(phi[i]==i){
            phi[i]=i-1;
            for(int j=i*2;j<=1e6;j+=i) phi[j]=(phi[j]*(i-1))/i;
        }
    }
}

vector<bool> isPrime(1e6+1, true); 
vector<int> lp(1e6+1,0), hp(1e6+1,0);
void buildSeive(){
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i<=sqrt(1e6);i++){
        if(isPrime[i]==true){
            lp[i]=i; hp[i]=i;
            for(int j=i*i;j<=1e6;j+=i){
                isPrime[j]=false;       
                hp[j]=i;
                if(lp[j]==0) lp[j]=i;
            }
        }
    }
} 

vector<int> primeFactors(int n){
    vector<int> prime_factors;
    while(n>1){
        int prime_factor=lp[n];
        while(n%prime_factor==0) n/=prime_factor;
        prime_factors.push_back(prime_factor);
    }
    return prime_factors;
}

ll gcd(ll a, ll b){
    if (b == 0) return a;
    if(a>b) return gcd(b, a%b);
    else return gcd(a, b%a);
}
ll lcm(ll a, ll b){
    return (a/gcd(a, b))*b;
}

/*------------------------------------------------------------------------------------------------------*/

void solve(){

}   


int main(){   

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 

    int t; cin>>t;
    while(t--) solve();

}
