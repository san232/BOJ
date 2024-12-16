using System;
using System.IO;

class Program
{
    static int w_cnt = 0, b_cnt = 0;
    static int[,] B;

    static void Main(string[] args)
    {
        using (var reader = new StreamReader(Console.OpenStandardInput()))
        using (var writer = new StreamWriter(Console.OpenStandardOutput()))
        {
            int n = int.Parse(reader.ReadLine());
            B = new int[n, n];
            
            for (int i = 0; i < n; i++)
            {
                var line = reader.ReadLine().Split();
                for (int j = 0; j < n; j++)
                {
                    B[i, j] = int.Parse(line[j]);
                }
            }

            DivConq(0, 0, n);

            writer.WriteLine(w_cnt);
            writer.WriteLine(b_cnt);
        }
    }

    static void DivConq(int x, int y, int N)
    {
        int tmp_cnt = 0;

        for (int i = x; i < x + N; i++)
        {
            for (int j = y; j < y + N; j++)
            {
                if (B[i, j] == 1)
                {
                    tmp_cnt++;
                }
            }
        }

        if (tmp_cnt == 0)
        {
            w_cnt++;
        }
        else if (tmp_cnt == N * N)
        {
            b_cnt++;
        }
        else
        {
            int half = N / 2;
            DivConq(x, y, half);
            DivConq(x + half, y, half);
            DivConq(x, y + half, half);
            DivConq(x + half, y + half, half);
        }
    }
}
