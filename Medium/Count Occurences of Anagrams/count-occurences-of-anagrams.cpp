//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	    int count = 0;
	    
	    vector<int> hash(26, 0);
	    for(int i = 0; i < pat.size(); i++) {
	        int idx = pat[i]-'a';
	        hash[idx]++;
	    }
	    
	    vector<int> currHash(26, 0);
	    for(int i = 0; i < pat.size(); i++) {
	        int idx = txt[i]-'a';
	        currHash[idx]++;
	    }
	    
	    if(hash == currHash) count++;
	    
	    int i = 0;
	    int j = pat.size();
	    
	    while(j < txt.size()) {
	        // remove outof bound char
	        int idx1 = txt[i]-'a';
	        currHash[idx1]--;
	        
	        // enter new char
	        int idx2 = txt[j]-'a';
	        currHash[idx2]++;
	        
	        // update window
	        i++;
	        j++;
	        
	        // chech if new window is anagram of pat
	        if(hash == currHash) {
	            count++;
	        }
	    }
	    
	    return count;
	    
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends