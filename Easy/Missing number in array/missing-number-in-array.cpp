//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;




// } Driver Code Ends
// User function template for C++

class Solution{
  public:
    int missingNumber(vector<int>& array, int n) {
        // Your code goes here
        
        int i = 0;
        while(i < n-1) {
            int correct = array[i]-1;
            
            if(correct < n-1 && array[i] != i+1) {
                swap(array[i], array[correct]);
            }
            else {
                i++;
            }
        }
        
        for(int i = 0; i < n-1; i++) {
            if(array[i] == i+1) continue;
            
            return i+1;
        }
        
        return n;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i) cin >> array[i];
        Solution obj;
        cout << obj.missingNumber(array, n) << "\n";
    }
    return 0;
}
// } Driver Code Ends