class SegmentTree {
    vector<int> segTree;
    inline static int n;
public:
    SegmentTree(int n) : segTree(4*n) { this -> n = n; }
    /* // not required here since we are starting with an empty tree here
	void build(vector<int>& nums, int i, int l, int r) {
        if(l == r) segTree[i] = nums[l];                   // can't split further - assign corresponding index of segTree as nums[l]
        else {
            int mid = (l + r) / 2;                         // divide array into two halves (left and right child of current node of segment tree)
            build(nums, 2*i, l, mid);                      // calculate result for left child
            build(nums, 2*i + 1, mid + 1, r);              // calculate result for right child
            segTree[i] = segTree[2*i] + segTree[2*i + 1];  // merge result into parent - parent val = sum of left & right child
        }
    }	*/
    void update(int x, int i = 1, int l = 0, int r = n-1) {
        if(l == r) segTree[i]++;                           // update segTree index holding segment [x]
        else{
            int mid = (l + r) >> 1;
            if(x <= mid) update(x, i*2, l, mid);           // if node holding [x] lies in left child, recurse for it
            else update(x, i*2 + 1, mid + 1, r);           // other wise recurse the right child
            segTree[i] = segTree[i*2] + segTree[i*2 + 1];  // child nodes got updated - so parent need to be updated  
        }
    }
    int query(int xr, int xl = 0, int i = 1, int l = 0, int r = n-1) {
        if(xl > xr) return 0;
        if(xl == l and xr == r) return segTree[i];  // case - 1
        int mid = (l + r) / 2;
		// case - 2 and 3
		// Here, we are picking min(right, mid) & max(left, mid+1) to ensure that [left, right] is always subrange of [l, r] for recursive call 
		// otherwise base condition would never be reached in some cases
        return query(min(xr, mid), xl, 2*i, l, mid) + query(xr, max(xl, mid+1), 2*i+1, mid+1, r);
    }
};
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        const int MAX = 1e4+1;   // max range
        for_each(begin(nums), end(nums), [](int& n){n += MAX;});  // converting range from [-10^4,10^4] to [0,2*10^4]
        SegmentTree T(2*MAX);
        for(int i = size(nums)-1; ~i; i--) 
            T.update(nums[i]),
            nums[i] = T.query(nums[i]-1);        
        return nums;
    }
};