//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N) {
        
        unordered_set<int> s;
        for(int i = 0; i < N; i++) {
            s.insert(arr[i]);
        }
        
        int maxLen = INT_MIN;
        for(int i = 0; i < N; i++) {
            
            if(s.find(arr[i]-1) == s.end()) {
                int x = arr[i];
                int count = 1;
                
                while(s.find(x+1) != s.end()) {
                    x++;
                    count++;
                }
                
                maxLen = max(maxLen, count);
            }
        }
        
        return maxLen;      
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends