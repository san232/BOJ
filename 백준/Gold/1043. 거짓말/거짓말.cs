using System;
using System.Collections.Generic;

class Program
{
    static int[] parent;

    static int Find(int x)
    {
        if (parent[x] != x)
            parent[x] = Find(parent[x]);
        return parent[x];
    }

    static void Union(int a, int b)
    {
        a = Find(a);
        b = Find(b);
        if (a != b)
            parent[b] = a;
    }

    static void Main()
    {
        string[] nm = Console.ReadLine().Split();
        int n = int.Parse(nm[0]); // 사람 수
        int m = int.Parse(nm[1]); // 파티 수

        parent = new int[n + 1];
        for (int i = 1; i <= n; i++)
            parent[i] = i;

        string[] truthInput = Console.ReadLine().Split();
        int t = int.Parse(truthInput[0]);
        HashSet<int> truthSet = new HashSet<int>();

        for (int i = 1; i <= t; i++)
            truthSet.Add(int.Parse(truthInput[i]));

        List<List<int>> parties = new List<List<int>>();

        for (int i = 0; i < m; i++)
        {
            string[] line = Console.ReadLine().Split();
            int count = int.Parse(line[0]);
            List<int> party = new List<int>();

            for (int j = 1; j <= count; j++)
                party.Add(int.Parse(line[j]));

            for (int j = 1; j < count; j++)
                Union(party[0], party[j]);

            parties.Add(party);
        }

        HashSet<int> truthRoots = new HashSet<int>();
        foreach (int person in truthSet)
            truthRoots.Add(Find(person));

        int result = 0;
        foreach (var party in parties)
        {
            bool canLie = true;
            foreach (var person in party)
            {
                if (truthRoots.Contains(Find(person)))
                {
                    canLie = false;
                    break;
                }
            }

            if (canLie)
                result++;
        }

        Console.WriteLine(result);
    }
}
