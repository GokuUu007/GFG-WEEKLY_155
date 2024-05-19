//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    
    using ll = long long;
    
    long long maxAlternatingSubstring(int N, string s) {
    
        if (N == 1) {
            return 3;
        }
        
        s += '7';
    
        vector<int> from(N, 1);
        for (int i = N - 2; i >= 0; --i) {
            if (s[i] != s[i + 1]) {
                from[i] += from[i + 1];
            }
        }
        
        if (from[0] == N) {
            return (N + 1) * 1LL * (N + 2) / 2;
        }
        
        vector<int> till(N + 1, 1);
        for (int i = 1; i < N; ++i) {
            if (s[i] != s[i - 1]) {
                till[i] += till[i - 1];
            }
        }
            
        ll tot = 0, max_ = 0;
        char p = s[0];
        for (int i = 0, l = 1; i < N; ++i) {
            if (p == s[i]) {
                l = 1;
            } else {
                l += 1;
            }
            p = s[i];
            tot += l;
        }
        
        
        auto sum = [&] (int x) {
            return x * 1LL * (x + 1) / 2;
        };
        
        for (int i = 0; i + 1 < N; ++i) {
            if (s[i] == s[i + 1]) {
                ll new_l = till[i] + from[i + 1] + 1;
                ll new_max = tot - sum(till[i]) - sum(from[i + 1]) + sum(new_l);
                max_ = max(max_, new_max);
            }
        }
        
        return max_;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int N;
        cin >> N;

        string S;
        cin >> S;

        Solution obj;
        long long res = obj.maxAlternatingSubstring(N, S);

        cout << res << endl;
    }
}

// } Driver Code Ends
