using System;

class Program
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        const int MOD = 10007;

        if (n == 1)
        {
            Console.WriteLine(1);
            return;
        }

        int[] dp = new int[n + 1];
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++)
        {
            dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
        }

        Console.WriteLine(dp[n]);
    }
}
