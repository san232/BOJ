using System;
using System.Text;

class Program
{
    static (int, int)[] a = {
        (10, 20),
        (30, 40),
    };

    static bool BinarySearch(int n)
    {
        int left = 0, right = a.Length - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (a[mid].Item1 <= n && n <= a[mid].Item2)
            {
                return true;
            }
            else if (n < a[mid].Item1)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return false;
    }

    static void Main()
    {
        StringBuilder output = new StringBuilder();
        
        int t = int.Parse(Console.ReadLine());

        for (int i = 0; i < t; i++)
        {
            int n = int.Parse(Console.ReadLine());

            if (n != 1 && n < 906150257)
            {
                output.AppendLine("O");
            }
            else if (n == 1 || BinarySearch(n))
            {
                output.AppendLine("E");
            }
            else
            {
                output.AppendLine("O");
            }
        }

        Console.Write(output.ToString());
    }
}
