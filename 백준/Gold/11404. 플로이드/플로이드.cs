using System;
using System.Linq;

class Program
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int m = int.Parse(Console.ReadLine());
        int INF = 100000 * 100 + 1;

        int[,] dist = new int[n + 1, n + 1];

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == j) dist[i, j] = 0;
                else dist[i, j] = INF;
            }
        }

        for (int i = 0; i < m; i++)
        {
            string[] input = Console.ReadLine().Split();
            int a = int.Parse(input[0]);
            int b = int.Parse(input[1]);
            int c = int.Parse(input[2]);

            dist[a, b] = Math.Min(dist[a, b], c);
        }

        for (int k = 1; k <= n; k++)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (dist[i, k] != INF && dist[k, j] != INF)
                    {
                        dist[i, j] = Math.Min(dist[i, j], dist[i, k] + dist[k, j]);
                    }
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i, j] == INF) Console.Write("0 ");
                else Console.Write(dist[i, j] + " ");
            }
            Console.WriteLine();
        }
    }
}
