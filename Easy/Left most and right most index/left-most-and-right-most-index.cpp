//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    long leftMost(vector<long long>& nums, long long target) {
        long pos = -1, start = 0, end = nums.size()-1;
        
        while(start <= end) {
            long mid = start + (end-start)/2;
            
            if(nums[mid] == target) {
                pos = mid;
                end = mid-1;
            }
            else if(target < nums[mid]) {
                end = mid-1;
            }
            else if(target > nums[mid]) {
                start = mid+1;
            }
        }
        
        return pos;
    }
    
    long rightMost(vector<long long>& nums, long long target) {
        long pos = -1, start = 0, end = nums.size()-1;
        
        while(start <= end) {
            long mid = start + (end-start)/2;
            
            if(nums[mid] == target) {
                pos = mid;
                start = mid+1;
            }
            else if(target < nums[mid]) {
                end = mid-1;
            }
            else if(target > nums[mid]) {
                start = mid+1;
            }
        }
        
        return pos;
    }
    
    public:
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        // code here
        long leftMostIdx = leftMost(v, x);
        
        long rightMostIdx = -1;
        if(leftMostIdx != -1) {
            rightMostIdx = rightMost(v, x);
        }
        
        return {leftMostIdx, rightMostIdx};
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}

// } Driver Code Ends