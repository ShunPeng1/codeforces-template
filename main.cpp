#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <queue>
#include <string>
#include <stack>
#include <bitset>
#include <deque>
#include <list>
using namespace std;


typedef unsigned int unit;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef unordered_map<int, int> umii;
typedef unordered_map<ll, ll> umll;
typedef unordered_map<string, int> umsi;
typedef map<string, int> omsi;
typedef map<int, int> omii;
typedef map<ll, ll> omll;
typedef unordered_set<ll> usll;
typedef unordered_set<string> uss;
typedef unordered_set<pll> uspll;
typedef set<ll> osll;
typedef set<string> oss;
typedef set<pll> ospll;

#define INF 2147483647
#define INFLL 9223372036854775807
#define MOD1 1000000007
#define MOD9 998244353

#define FOR(i,a,n) for(ll i=a ; i<n ; i++)
#define FORR(i,n,a) for(ll i=a-1 ; i>=n ; i--)
#define FOREACH(x, c) for(auto &(x): (c) )

#define ALL(x) (x).begin(),(x).end()
#define FROM(arr,x,y) ((arr).begin()+x), ((arr).begin()+y)

#define pub push_back
#define pob pop_back
#define mp make_pair

#define fi first
#define se second

#define endl '\n'
#define ENDL cout<<'\n'
#define YES cout<<"YES"
#define NO cout<<"NO"


template <typename T> bool SortReverse(T& a, T& b) {
    return a > b;
}

template <typename T> void getVector(vector <T>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

template <typename T> void here(T something) {
    static int i = 1;
    cout << "here" << " " << something << " : " << i++ << endl;
}

template <typename T> T gcd(T a, T b) {
    if (a == 0 || b == 0)
        return 0;
    else if (a == b)
        return a;
    else if (a > b)
        return gcd(a - b, b);
    else return gcd(a, b - a);
}

template <typename T> T lcm(T a, T b)
{
    return (a * b) / gcd(a, b);
}

bool isPalindrome(string s) {
    FOR(i, 0, s.size() / 2) {
        if (s[i] != s[s.size() - i - 1]) return false;
    }
    return true;
}


struct Combination {
    vll factorial;
    vll inverseFactorial;
    ll n;

    static ll power(ll num, ll powerOf)
    {
        ll res = 1;
        while (powerOf) {
            if (powerOf & 1)
                res = (res * num) % MOD1;
            powerOf >>= 1;
            num = (num * num) % MOD1;
        }
        return res;
    }

    ll nCr(ll n, ll r)
    {
        if (n < 0 || r < 0 || n < r)
            return 0;
        ll ans = (factorial[n] * ((inverseFactorial[r] * inverseFactorial[n - r]) % MOD1)) % MOD1;
        return ans;
    }

    Combination(ll n)
    {
        this->n = n;
        factorial.resize(n + 1, 0);
        inverseFactorial.resize(n + 1, 0);

        factorial[0] = 1;
        for (ll i = 1; i <= n; i++)
            factorial[i] = (factorial[i - 1] * i) % MOD1;
        inverseFactorial[n] = power(factorial[n], MOD1 - 2);
        for (ll i = n - 1; i >= 0; i--)
            inverseFactorial[i] = (inverseFactorial[i + 1] * (i + 1)) % MOD1;
    }
};

struct Node {
    int i;
    int x;
    int y;
    int z;
};


bool NodeSort1(Node& a, Node& b) {
    if (a.x != b.x) return a.x < b.x;
    else return a.i < b.i;
}

bool NodeSort2(Node& a, Node& b) {
    if (a.i != b.i) return a.i < b.i;
    else return a.x < b.x;
}

bool MySort1(pii& a, pii& b) {
    if (a.se != b.se) return a.se < b.se;
    else return a.fi < b.fi;
}

bool MySort2(pii& a, pii& b) {
    if (a.se != b.se) return a.se > b.se;
    else return a.fi < b.fi;
}

//bool visited[1000000];
//vector < vector<int>> adj(500, vector<int>(500,0));
void DFS1(vi& visited, vvll& adj, ll verticeID
    , ll& size
    , vll &arr
    //, ll& n
   // , ll& result
) {
    // Mark the current node as visited 
    visited[verticeID] = 1;
    //cout << verticeID << endl;

    size = min(size, arr[verticeID]);


    for (auto itr = adj[verticeID].begin(); itr != adj[verticeID].end(); itr++) {
        if (!visited[*itr]) {
            //size++;
            DFS1(visited, adj, *itr, size, arr);
        }

    }

};

void DFS2(vector<vll> &visited, ll x, ll y
    //, ll& size
    //, ll& n
    , ll& result
    //, ll& findX
    //, ll& findY
) {

    if(visited[x][y] == 1){
        result += 1;
    }
    // Mark the current node as visited 
    visited[x][y] = -1;
    //cout <<"("<<x<<" , "<<y<<") = "<< visited[x][y] << endl;
    
    
    if(visited[x+1][y]>=0) DFS2(visited,x+1,y,result/*, findX, findY);*/);
    if(visited[x][y+1]>=0) DFS2(visited,x,y+1,result/*, findX, findY);*/);
    if(visited[x-1][y]>=0) DFS2(visited,x-1,y,result/*, findX, findY);*/);
    if(visited[x][y-1]>=0) DFS2(visited,x,y-1,result/*, findX, findY);*/);

};



void solve(int& t, int& testcase) {
    ll n = 1, m = 0, p = 0, q = 0, k = 0;
    string s, s1, s2;
    ll TOT = 0, RES = 0, SUM = 0;
    ll MAXV = -INF, MINV = INF;

    ll num1 = 0, num2 = 0, num3 = 0, num4 = 0;
    bool isP = 0, isP1 = 0, isP2 = 0;


    cin >> n;
    cin >> m;
    //cin >> p;
    //cin >> q;
    //cin >> s;
    //cin >> k;
    //cin >> s1;
    //cin >> s2;
   
    
    vector<vector <ll>> visited(n+2,vector<ll>(m+2,0));
    FOR(i,0,n+2){
        visited[i][0] = -1;
        visited[i][m+1] = -1;
    }
    FOR(i,0,m+2){
        visited[0][i] = -1;
        visited[n+1][i] = -1;
    }
    

    FOR(i,0 , n){
        cin>>s;
        FOR(j,0,m){
            if(s[j] == '#'){
                visited[i+1][j+1] = -1;
            }
            else if(s[j] == 'C'){
                visited[i+1][j+1] = 1;
            }
        }
    }
    ll res = 0;
    FOR(i,1, n+1){
        FOR(j,1,m+1){
            ll numberOfClassroom = 0;
            if(visited[i][j]==0){
                DFS2(visited, i,j,numberOfClassroom);
                visited[i][j]=-1;
            }
            res = max(res,numberOfClassroom );

        }
    }
    cout<<res;
    
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    int testcase = 1;
    cin >> testcase;
    //cout.flush();
    for (int t = 1; t < testcase + 1; t++) {
        solve(t, testcase);
        cout << endl;
    }

    return 0;
}
