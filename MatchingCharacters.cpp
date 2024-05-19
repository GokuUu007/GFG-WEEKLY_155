//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    vector<int> matchingCnt(int n, vector<string>& X) {
        
        int MAXN = 0;
        for (auto &s : X) {
            MAXN = max(MAXN, int(s.size()));
        }
        
        vector<vector<int>> dp(MAXN, vector<int>(26));
        
        for (auto &s : X) {
            for (int p = 0; p < int(s.size()); ++p) {
                dp[p][s[p] - 'a'] += 1;
            }
        } 
        
        vector<int> answer;
        for (auto &s : X) {
            int cur = 0;
            for (int p = 0; p < int(s.size()); ++p) {
                cur += max(0, --dp[p][s[p] - 'a']);
            }
            answer.push_back(cur);
        }
        
        return answer;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);
        vector<string> X(n);
        for (int i = 0; i < n; ++i)
            cin >> X[i];

        Solution obj;
        vector<int> res = obj.matchingCnt(n, X);

        Array::print(res);
    }
}

// } Driver Code Ends
