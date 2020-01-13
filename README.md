# Longest-common-subsequence
Recently, I have been learning Algorithm Design and Analysis at https://www.bilibili.com/video/av7134874, the videos are made by Peking University, lectured by professor Qu Wanling（屈婉玲教授）. Here is an implementation of the example of LCS, which is an example for dynamic programming.

function of algorithm: get the LCS of two sequences
input of algorithm: string X and string Y
output of algorithm: LCS

dynamic programming:
subproblem: the first i items of string X and the first j items of string Y (Xi and Yj)
recursive formula:C[i,j]=	0	              i==0 or j==0
	       			or  C[i-1,j-1]+1	          i,j>0,X[i]==Y[j]
				or  max{C[i-1,j],C[i,j-1]}	i,j>0,X[i]!=Y[j]
C[i,j] means that the length of LCS of Xi and Yj
B[i,j] points to the optimal subproblem, there're 3 directions, LEFT,UPPER,LANDU(left and upper).
C and B is one-to-one correspondence.
**When writing code, dealing the relation of tables B and C with the Xi and Yj should be careful, since the No.0 row and column represent the boundary condition of 0-length.

最近在https://www.bilibili.com/video/av7134874 算法设计与分析的课程，北大的屈婉玲教授讲解。
这是最长公共子序列问题的一个实现，利用了动态规划算法思想。

算法功能：确定两序列的最长公共子序列

算法输入：字符串X和字符串Y

算法输出：输出最长公共子序列

动态规划算法：

子问题：字符串X的前i项，字符串Y的前j项

递推方程：C[i,j]=	0	                     i==0 or j==0
	       	or  C[i-1,j-1]+1	          i,j>0,X[i]==Y[j]
		or  max{C[i-1,j],C[i,j-1]}	i,j>0,X[i]!=Y[j]
C[i,j]是子问题Xi和Yj的LCS的长度
标记函数：B[i,j],根据划分子问题时的方向，分LEFT，UPPER，LANDU

**在具体代码实现中，较容易出错的地方在于，B和C的大小为(m+1)x(n+1)，因为对于C第0行和第0列代表长度为0的边界情况
