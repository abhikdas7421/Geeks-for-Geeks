//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    static bool cmp(vector<int> &a, vector<int> &b) {
        return a[2] < b[2];
    }

    
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        
        vector<vector<int>> meetings;
        
        for(int i = 0; i < N; i++) {
            vector<int> meeting{i+1, S[i], F[i]};
            
            meetings.push_back(meeting);
        }
        
        sort(meetings.begin(), meetings.end(), cmp);
        
        vector<int> ans;
        ans.push_back(meetings[0][0]);
        int prevEndTime = meetings[0][2];
        
        for(int i = 1; i < N; i++) {
            
            if(meetings[i][1] > prevEndTime) {
                ans.push_back(meetings[i][0]);
                prevEndTime = meetings[i][2];
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends