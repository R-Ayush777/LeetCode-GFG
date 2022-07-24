**Intuition**
We only need to care the start point and the end point.
​
```
s ----- n
1 --------------------- n
1 --------------------- n
1 ----- e
```
​
​
**Explanation**
<br>
If start <= end, return the range [start, end].
<br>
If end < start, return the range [1, end] + range [start, n].
​
​
**Complexity**
Time O(N)
Space O(N)
​
