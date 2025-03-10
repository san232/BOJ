using System;
using System.Collections.Generic;

class Program
{
    static void Main()
    {
        string[] input = Console.ReadLine().Split();
        int N = int.Parse(input[0]);
        int K = int.Parse(input[1]);

        if (N >= K)
        {
            Console.WriteLine(N - K);
            return;
        }

        int[] visited = new int[100001];
        Queue<int> queue = new Queue<int>();

        queue.Enqueue(N);
        visited[N] = 1;

        while (queue.Count > 0)
        {
            int current = queue.Dequeue();

            foreach (int next in new int[] { current * 2, current - 1, current + 1 })
            {
                if (next >= 0 && next <= 100000 && visited[next] == 0)
                {
                    visited[next] = visited[current] + (next == current * 2 ? 0 : 1);
                    queue.Enqueue(next);
                }
            }
        }

        Console.WriteLine(visited[K] - 1);
    }
}
