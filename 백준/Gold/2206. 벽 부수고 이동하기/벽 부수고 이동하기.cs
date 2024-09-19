using System;
using System.Collections.Generic;

class Program
{
    static int[] dx = { -1, 1, 0, 0 };
    static int[] dy = { 0, 0, -1, 1 };
    static int[,,] maze;

    struct Node
    {
        public int Broken;
        public int X;
        public int Y;

        public Node(int broken, int x, int y)
        {
            Broken = broken;
            X = x;
            Y = y;
        }
    }

    static int BFS(int N, int M)
    {
        Queue<Node> q = new Queue<Node>();
        q.Enqueue(new Node(0, 0, 0));

        while (q.Count > 0)
        {
            Node current = q.Dequeue();
            int broken = current.Broken;
            int x = current.X;
            int y = current.Y;

            if (x == N - 1 && y == M - 1)
                return maze[N - 1, M - 1, broken] + 1;

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                    continue;

                if (maze[nx, ny, 0] == 1 && broken == 0) // 벽일 때
                {
                    if (maze[nx, ny, broken + 1] == 0) // 아직 방문하지 않았으면
                    {
                        maze[nx, ny, broken + 1] = maze[x, y, broken] + 1;
                        q.Enqueue(new Node(1, nx, ny));
                    }
                }
                else if (maze[nx, ny, 0] == 0) // 벽이 아닐 때
                {
                    if (maze[nx, ny, broken] == 0) // 아직 방문하지 않았으면
                    {
                        maze[nx, ny, broken] = maze[x, y, broken] + 1;
                        q.Enqueue(new Node(broken, nx, ny));
                    }
                }
            }
        }
        return -1;
    }

    static void Main(string[] args)
    {
        string[] input = Console.ReadLine().Split();
        int N = int.Parse(input[0]);
        int M = int.Parse(input[1]);

        maze = new int[N, M, 2];

        for (int i = 0; i < N; i++)
        {
            string line = Console.ReadLine();
            for (int j = 0; j < M; j++)
            {
                maze[i, j, 0] = line[j] - '0';
            }
        }

        Console.WriteLine(BFS(N, M));
    }
}
