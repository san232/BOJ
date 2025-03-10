using System;

class Program
{
    static void Main()
    {
        string[] input = Console.ReadLine().Split();
        int N = int.Parse(input[0]);
        int K = int.Parse(input[1]);

        int[] dp = new int[K + 1];

        for (int i = 0; i < N; i++)
        {
            string[] item = Console.ReadLine().Split();
            int W = int.Parse(item[0]);
            int V = int.Parse(item[1]);

            for (int w = K; w >= W; w--)
            {
                dp[w] = Math.Max(dp[w], dp[w - W] + V);
            }
        }

        Console.WriteLine(dp[K]);
    }
}
