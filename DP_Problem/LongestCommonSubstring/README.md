http://blog.csdn.net/hackbuteer1/article/details/6686931

子字符串的定义和子序列的定义类似，但要求是连续分布在其他字符串中。比如输入两个字符串BDCABA和ABCBDAB的最长公共字符串有BD和AB，它们的长度都是2。

      最长公共子字符串共有两种解决方法，下面具体说说我的思路

方法一：

     Longest Common Substring和Longest Common Subsequence是有区别的

     X = <a, b, c, f, b, c>

     Y = <a, b, f, c, a, b>

     X和Y的Longest Common Sequence为<a, b, c, b>，长度为4

     X和Y的Longest Common Substring为 <a, b>长度为2

    其实Substring问题是Subsequence问题的特殊情况，也是要找两个递增的下标序列

    <i1, i2, ...ik> 和 <j1, j2, ..., jk>使

     xi1 == yj1

    xi2 == yj2

    ......

    xik == yjk

    与Subsequence问题不同的是，Substring问题不光要求下标序列是递增的，还要求每次

   递增的增量为1， 即两个下标序列为：

   <i, i+1, i+2, ..., i+k-1> 和 <j, j+1, j+2, ..., j+k-1>

    类比Subquence问题的动态规划解法，Substring也可以用动态规划解决，令

    c[i][j]表示Xi和Yi的最大Substring的长度，比如

   X = <y, e, d, f>

   Y = <y, e, k, f>

   c[1][1] = 1

   c[2][2] = 2

   c[3][3] = 0

   c[4][4] = 1

   动态转移方程为：

   如果xi == yj， 则 c[i][j] = c[i-1][j-1]+1

   如果xi ! = yj,  那么c[i][j] = 0

   最后求Longest Common Substring的长度等于

   max{  c[i][j],  1<=i<=n， 1<=j<=m}
