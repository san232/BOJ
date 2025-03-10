using System;
using System.Text;

class Program
{
    static int N, M;
    static StringBuilder sb = new StringBuilder();

    static void Solve(int start, int depth, int[] selected)
    {
        if (depth == M)
        {
            sb.AppendLine(string.Join(" ", selected));
            return;
        }

        for (int i = start; i <= N; i++)
        {
            selected[depth] = i;
            Solve(i + 1, depth + 1, selected);
        }
    }

    static void Main()
    {
        string[] input = Console.ReadLine().Split();
        N = int.Parse(input[0]);
        M = int.Parse(input[1]);

        Solve(1, 0, new int[M]);
        Console.Write(sb.ToString());
    }
}
