// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int minVal(int a, int b)
    {
        int sb = 0;
        int x, B = b;
        
        while (B)
        {
            sb += B % 2;
            B /= 2;
        }
        
        for (int i = 31; i >= 0 and sb; i--)
        {
            if ((1 << i) & a)
            {
                x |= (1 << i);
                sb--;
            }
        }
        
        // cout<<sb<<endl;

        for (int i = 0; (i <= 31) and (sb!=0); i++)
        {
            // cout<<"x & (1 << i) -> "<<int(x & (1 << i))<<endl;
            if ((x & (1 << i)) == 0)
            {
                // cout<<"x->"<<x<<endl;
                x |= (1 << i);
                sb--;
            }
        }
        
        return x;
    }
};




// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}  // } Driver Code Ends