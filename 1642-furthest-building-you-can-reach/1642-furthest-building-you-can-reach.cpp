// class Solution
// {
// public:
//     int furthestBuilding(vector<int> &h, int bricks, int ladders)
//     {
//         priority_queue<int, vector<int>, greater<int>> pq;

//         for (int i = 1; i < h.size(); i++)
//         {
//             int diff = h[i] - h[i - 1];
//             if (diff > 0)
//             {
//                 if (pq.size() < ladders)
//                     pq.push(diff);
//                 else
//                 {
//                     //  Optimize previous ladder use
//                     // int br = diff;
//                     if (pq.top() < diff and !pq.empty())
//                     {
//                         // br = pq.top();
//                         bricks -= pq.top();
//                         pq.pop();
//                         pq.push(diff);
//                     }
//                     else
//                         bricks -= diff;
//                     if (bricks < 0)
//                         return i - 1;
//                     // if (bricks - br >= 0)
//                     //     bricks -= br;
//                     // else
//                     //     return i - 1;
//                 }
//             }
//         }
//         return h.size() - 1;
//     }
// };


class Solution {
public:
    int furthestBuilding(vector<int>& H, int B, int L) {
        int len = H.size() - 1;
        priority_queue<int> pq;
        for (int i = 0; i < len; i++) {
            int diff = H[i+1] - H[i];
            if (diff > 0) {
                if (L) pq.push(-diff), L--;
                else if (!pq.empty() && diff > -pq.top())
                    pq.push(-diff), B += pq.top(), pq.pop();
                else B -= diff;
                if (B < 0) return i;
            }
        }
        return len;
    }
};