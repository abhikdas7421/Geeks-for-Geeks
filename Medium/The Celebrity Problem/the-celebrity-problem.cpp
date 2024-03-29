//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int> st;
        for(int i = 0; i < n; i++) {
            st.push(i);
        }
        
        while(st.size() != 1) {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            
            if(M[a][b] == 1) {
                st.push(b);
            }
            else if(M[b][a] == 1) {
                st.push(a);
            }
        }
        
        int a = st.top(); st.pop();
        // Check last element knows anyone
        for(int i = 0; i < n; i++) {
            if(M[a][i] == 1) {
                return -1;
            }
        }
        
        // check everyone knows last element
        for(int i = 0; i < n; i++) {
            if(i != a && M[i][a] == 0) {
                return -1;
            }
        }
        
        return a;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends