<h2><a href="https://leetcode.com/problems/domino-and-tromino-tiling/">790. Domino and Tromino Tiling</a></h2><h3>Medium</h3><hr><div><p>You have two types of tiles: a <code>2 x 1</code> domino shape and a tromino shape. You may rotate these shapes.</p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/15/lc-domino.jpg" style="width: 362px; height: 195px;">
<p>Given an integer n, return <em>the number of ways to tile an</em> <code>2 x n</code> <em>board</em>. Since the answer may be very large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/15/lc-domino1.jpg" style="width: 500px; height: 226px;">
<pre><strong>Input:</strong> n = 3
<strong>Output:</strong> 5
<strong>Explanation:</strong> The five different ways are show above.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 1
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
</ul>
</div>


<hr><br>

# Solution Approach 
- dp[i] denotes the number of ways to tile an 2 * (i + 1) board, note that dp is 0-indexed.
Intuitively, dp[0] = 1 and dp[1] = 2
- dpa[i] denotes the number of ways to tile an 2 * i board and 1 more square left below(or above symmetrically).
	- Intuitively, dpa[0] = 0 and dpa[1] = 1
	- I just explained the case where in i-th column, 2nd row is filled. But it should be noted that the two cases(the other is in i-th column, 1st row is filled) are symmetric and the numbers are both dpa[i], you may imagine dpb[i] = dpa[i] for the second case where i-th column 1st row is filled.
![image](https://user-images.githubusercontent.com/78534043/170425384-018d06eb-614a-483b-9eb3-ae51442d5a22.png)
![image](https://user-images.githubusercontent.com/78534043/170425402-4ebd69dd-0907-403c-8355-f9adcd08fc7a.png)
![image](https://user-images.githubusercontent.com/78534043/170425429-2bb73320-2ad5-4282-ac58-21179d2c8bd9.png)

## Python/Python3

```
class Solution(object):
    def numTilings(self, n):
        dp = [1, 2, 5] + [0] * n
        for i in range(3, n):
            dp[i] = (dp[i - 1] * 2 + dp[i - 3]) % 1000000007
        return dp[n - 1]
```
<br>

```
class Solution(object):
    def numTilings(self, n):
        dp, dpa = [1, 2] + [0] * n, [1] * n
        for i in range(2, n):
            dp[i] = (dp[i - 1] + dp[i - 2] + dpa[i - 1] * 2) % 1000000007
            dpa[i] = (dp[i - 2] + dpa[i - 1]) % 1000000007
        return dp[n - 1]
```
