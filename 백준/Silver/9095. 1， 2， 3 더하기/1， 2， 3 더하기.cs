using System;

namespace BOJ
{
    class Program
    {
        static void Main()
        {
            int T = int.Parse(Console.ReadLine());
            int[] dp = new int[12];
            dp[1] = 1;
            dp[2] = 2;
            dp[3] = 4;

            for (int i = 4; i <= 11; i++)
            {
                dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
            }

            for (int t = 0; t < T; t++)
            {
                int n = int.Parse(Console.ReadLine());
                Console.WriteLine(dp[n]);
            }
        }
    }


}
