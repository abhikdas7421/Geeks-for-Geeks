//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here
        long windowSum = 0;
        long maxSum = 0;
        
        int i = 0;
        int j = 0;
        while(j < K) {
            windowSum += Arr[j];
            j++;
        }
        maxSum = windowSum;
        
        while(j < N) {
            // subtract out of window element
            windowSum -= Arr[i];
            // add new element to windowSum
            windowSum += Arr[j];
            
            i++;
            j++;
            
            maxSum = max(maxSum, windowSum);
        }
        
        return maxSum;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends