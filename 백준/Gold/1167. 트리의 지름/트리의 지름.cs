using System;
using System.Collections.Generic;

class Program
{
    static List<(int, int)>[] tree;
    static bool[] visited;
    static int maxDistance = 0;
    static int farthestNode = 0;

    static void Main()
    {
        int V = int.Parse(Console.ReadLine());

        tree = new List<(int, int)>[V + 1];
        for (int i = 1; i <= V; i++)
        {
            tree[i] = new List<(int, int)>();
        }

        for (int i = 0; i < V; i++)
        {
            string[] input = Console.ReadLine().Split();
            int node = int.Parse(input[0]);

            for (int j = 1; j < input.Length - 1; j += 2)
            {
                int adjacentNode = int.Parse(input[j]);
                int distance = int.Parse(input[j + 1]);
                tree[node].Add((adjacentNode, distance));
            }
        }

        visited = new bool[V + 1];
        DFS(1, 0);

        visited = new bool[V + 1];
        maxDistance = 0;
        DFS(farthestNode, 0);

        Console.WriteLine(maxDistance);
    }

    static void DFS(int node, int distance)
    {
        visited[node] = true;

        if (distance > maxDistance)
        {
            maxDistance = distance;
            farthestNode = node;
        }

        foreach (var (nextNode, nextDistance) in tree[node])
        {
            if (!visited[nextNode])
            {
                DFS(nextNode, distance + nextDistance);
            }
        }
    }
}
