//{ Driver Code Starts
// A C++ program to find if there is a zero sum
// subarray
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        //Your code here
        for(int i = 1; i < n; i++) {
            arr[i] += arr[i-1];
        }
        
        unordered_map<int, int> mp;
        mp[0]++;
        
        for(int i = 0; i < n; i++) {
            int x = arr[i]-0;
            if(mp.find(x) != mp.end()) {
                return true;
            }
            else {
                mp[arr[i]]++;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    Solution obj;
	    	if (obj.subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}
// } Driver Code Ends