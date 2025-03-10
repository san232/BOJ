using System;
using System.Text;

class Program
{
    static int N, M;
    static int[] numbers;
    static bool[] visited;
    static int[] selected;
    static StringBuilder sb = new StringBuilder();

    static void Solve(int depth)
    {
        if (depth == M)
        {
            sb.AppendLine(string.Join(" ", selected));
            return;
        }

        for (int i = 0; i < N; i++)
        {
            if (!visited[i])
            {
                visited[i] = true;
                selected[depth] = numbers[i];
                Solve(depth + 1);
                visited[i] = false;
            }
        }
    }

    static void Main()
    {
        string[] input = Console.ReadLine().Split();
        N = int.Parse(input[0]);
        M = int.Parse(input[1]);

        numbers = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
        Array.Sort(numbers); 

        visited = new bool[N];
        selected = new int[M];

        Solve(0);
        Console.Write(sb.ToString());
    }
}
