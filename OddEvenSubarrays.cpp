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
        vector<int> maxSum(int n, int l, int r, vector<int> &a) {
    
        vector<int> ogsum = a;
        partial_sum(begin(ogsum), end(ogsum), begin(ogsum));
    
        for (auto &x : a)
            x = abs(x);
    
        vector<int> first(n), second(n);
        for (int i = 0; i < n; ++i) {
            first[i] = (i & 1 ? a[i] : -a[i]) + (i > 0 ? first[i - 1] : 0);
            second[i] = (i & 1 ? -a[i] : a[i]) + (i > 0 ? second[i - 1] : 0);
        }
    
        int max_k = 0, max_sum = -1e9;
        for (int k = l; k <= r; ++k) {
            int m = 2 * k;
            for (int i = 0; i + m <= n; ++i) {
                int cur_sum = 0;
    
                if (i & 1) {
                    cur_sum += second[i + m / 2 - 1] - (i > 0 ? second[i - 1] : 0);
                } else {
                    cur_sum += first[i + m / 2 - 1] - (i > 0 ? first[i - 1] : 0);
                }
    
    
                if ((m / 2) & 1) {
                    if ((i + m / 2) & 1) {
                        cur_sum += second[i + m - 1] - second[i + m / 2 - 1];
                    } else {
                        cur_sum += first[i + m - 1] - first[i + m / 2 - 1];
                    }
                } else {
                    if ((i + m / 2) & 1) {
                        cur_sum += first[i + m - 1] - first[i + m / 2 - 1];
                    } else {
                        cur_sum += second[i + m - 1] - second[i + m / 2 - 1];
                    }
                }
    
                int new_sum = ogsum[n - 1] - (ogsum[i + m - 1] - (i > 0 ? ogsum[i - 1] : 0)) + cur_sum;
                
                if (max_sum < new_sum) {
                    max_k = k, max_sum = new_sum;
                }
            }
        }
    
        return {max_k, max_sum};
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int l;
        scanf("%d", &l);

        int r;
        scanf("%d", &r);

        vector<int> arr(n);
        Array::input(arr, n);

        Solution obj;
        vector<int> res = obj.maxSum(n, l, r, arr);

        Array::print(res);
    }
}

// } Driver Code Ends
