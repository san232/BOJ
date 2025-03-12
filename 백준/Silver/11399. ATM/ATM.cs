using System;
using System.Linq;

class Program
{
    static void Main()
    {
        int N = int.Parse(Console.ReadLine());
        int[] P = Console.ReadLine().Split().Select(int.Parse).ToArray();
        
        Array.Sort(P);

        int total = 0;
        int sum = 0;

        foreach (int time in P)
        {
            sum += time;
            total += sum;
        }

        Console.WriteLine(total);
    }
}
