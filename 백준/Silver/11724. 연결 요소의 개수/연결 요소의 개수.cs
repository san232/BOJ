using System;
using System.Collections.Generic;

class Program
{
    static List<int>[] graph;
    static bool[] visited;

    static void BFS(int start)
    {
        Queue<int> queue = new Queue<int>();
        queue.Enqueue(start);
        visited[start] = true;

        while (queue.Count > 0)
        {
            int node = queue.Dequeue();
            foreach (int neighbor in graph[node])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    queue.Enqueue(neighbor);
                }
            }
        }
    }

    static void Main()
    {
        string[] input = Console.ReadLine().Split();
        int N = int.Parse(input[0]);
        int M = int.Parse(input[1]);

        graph = new List<int>[N + 1];
        visited = new bool[N + 1];

        for (int i = 1; i <= N; i++)
            graph[i] = new List<int>();

        for (int i = 0; i < M; i++)
        {
            string[] edge = Console.ReadLine().Split();
            int u = int.Parse(edge[0]);
            int v = int.Parse(edge[1]);

            graph[u].Add(v);
            graph[v].Add(u);
        }

        int componentCount = 0;
        for (int i = 1; i <= N; i++)
        {
            if (!visited[i])
            {
                BFS(i);
                componentCount++;
            }
        }

        Console.WriteLine(componentCount);
    }
}
