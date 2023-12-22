//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	void pushZerosToEnd(int arr[], int size) {
	    // code here
	    int i = 0, j = 0;
	    int n = size-1;
	    
	    while(j <= n) {
	        if(arr[i] != 0) {
	            if(j <= i) {
	                j++;
	            }
	            i++;
	        }
	        else if(arr[j] == 0) {
	            j++;
	        }
	        else {
	            swap(arr[i], arr[j]);
	            i++;
	            j++;
	        }
	    }
	}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.pushZerosToEnd(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends