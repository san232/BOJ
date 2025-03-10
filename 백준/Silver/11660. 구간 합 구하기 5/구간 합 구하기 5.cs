using System;
using System.Text;

class Program
{
    static void Main()
    {
        string[] input = Console.ReadLine().Split();
        int N = int.Parse(input[0]);
        int M = int.Parse(input[1]);

        int[,] table = new int[N + 1, N + 1];
        int[,] prefix = new int[N + 1, N + 1];

        for (int i = 1; i <= N; i++)
        {
            string[] row = Console.ReadLine().Split();
            for (int j = 1; j <= N; j++)
            {
                table[i, j] = int.Parse(row[j - 1]);
                prefix[i, j] = table[i, j] + prefix[i - 1, j] + prefix[i, j - 1] - prefix[i - 1, j - 1];
            }
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < M; i++)
        {
            string[] query = Console.ReadLine().Split();
            int x1 = int.Parse(query[0]);
            int y1 = int.Parse(query[1]);
            int x2 = int.Parse(query[2]);
            int y2 = int.Parse(query[3]);

            int result = prefix[x2, y2] - prefix[x1 - 1, y2] - prefix[x2, y1 - 1] + prefix[x1 - 1, y1 - 1];
            sb.AppendLine(result.ToString());
        }

        Console.Write(sb.ToString());
    }
}
