class Solution:
    def climbStairs(self, n: int) -> int:
        dp = [0]*(n+1)
        dp[0] = 1
        dp[1] = 1 
        i = 0;
        while(True):
            i+=1
            if dp[i]==0:
                dp[i] = dp[i-2] + dp[i-1]
            if i==n:
                return dp[i]