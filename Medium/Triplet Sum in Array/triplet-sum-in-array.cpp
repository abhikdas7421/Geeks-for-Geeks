//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool twoSum(int arr[], int si, int n, int target) {
        int i = si;
        int j = n-1;
        
        while(i < j) {
            if(arr[i]+arr[j] == target) return true;
            else if(arr[i]+arr[j] > target) j--;
            else i++;
        }
        
        return false;
    }
    
    bool find3Numbers(int A[], int n, int X)
    {
        //Your Code Here
        sort(A, A+n);
        
        for(int i = 0; i < n-2; i++) {
            
            int n1 = A[i];
            int target = X-n1;
            
            if(twoSum(A, i+1, n, target)) return true;
        }
        
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends