//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    
    using ll = long long;
    
    long long firstContact(int n, int m) {
        ll lcm = n * 1LL * m / __gcd(n, m);
        return lcm;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int m;
        scanf("%d", &m);

        Solution obj;
        long long res = obj.firstContact(n, m);

        cout << res << endl;
    }
}

// } Driver Code Ends
