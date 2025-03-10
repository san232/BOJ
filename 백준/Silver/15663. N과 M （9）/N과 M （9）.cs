using System;
using System.Linq;

class Program
{
    static int n, m;
    static int[] arr, res;
    static bool[] chk;

    static void Func(int cnt)
    {
        if (cnt == m)
        {
            Console.WriteLine(string.Join(" ", res));
            return;
        }
        int xx = 0;
        for (int i = 0; i < n; i++)
        {
            if (!chk[i] && arr[i] != xx)
            {
                res[cnt] = arr[i];
                xx = res[cnt];
                chk[i] = true;
                Func(cnt + 1);
                chk[i] = false;
            }
        }
    }

    static void Main()
    {
        var input = Console.ReadLine().Split().Select(int.Parse).ToArray();
        n = input[0];
        m = input[1];
        arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
        res = new int[m];
        chk = new bool[n];
        Array.Sort(arr);
        Func(0);
    }
}
