//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        long currSum = 0;
        
        // Process first k sized window
        for(int i = 0; i < K; i++) {
            currSum += Arr[i];
        }
        long maxSum = currSum;
        
        int i = 0;
        int j = K;
        // Process remaing K Sized window
        while(j < N) {
            currSum -= Arr[i];
            currSum += Arr[j];
            i++;
            j++;
            
            maxSum = max(maxSum, currSum);
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