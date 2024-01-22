//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string s)
{
    // your code here
    if(s.size()%2 != 0) return -1;
    stack<char> st;
    
    for(auto ch:s) 
    {
        if(ch == '{')
        {
            st.push(ch);
        }
        else 
        {
            if(!st.empty() && st.top() == '{') 
            {
                st.pop();
            }
            else 
            {
                st.push(ch);
            }
        }
    }
    
    if(st.empty()) 
    {
        return 0;
    }
    else if(st.size()%2 != 0) 
    {
        return -1;
    }
   
   int count = 0;
   char top1;
   char top2;
   while(!st.empty())
   {
       top1 = st.top();
       st.pop();
       top2 = st.top();
       st.pop();
       
       if(top1 == top2)
       {
           count += 1;
       }
       else if(top1 != top2)
       {
           count += 2;
       }
   }
   
   return count;
}