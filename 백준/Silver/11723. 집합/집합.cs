using System;
using System.Text;

class Program
{
    static void Main()
    {
        int M = int.Parse(Console.ReadLine());
        int S = 0; // 비트마스킹을 위한 변수
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < M; i++)
        {
            string[] input = Console.ReadLine().Split();
            string command = input[0];

            if (command == "add")
            {
                int x = int.Parse(input[1]) - 1;
                S |= (1 << x);
            }
            else if (command == "remove")
            {
                int x = int.Parse(input[1]) - 1;
                S &= ~(1 << x);
            }
            else if (command == "check")
            {
                int x = int.Parse(input[1]) - 1;
                sb.AppendLine((S & (1 << x)) != 0 ? "1" : "0");
            }
            else if (command == "toggle")
            {
                int x = int.Parse(input[1]) - 1;
                S ^= (1 << x);
            }
            else if (command == "all")
            {
                S = (1 << 20) - 1;
            }
            else if (command == "empty")
            {
                S = 0;
            }
        }

        Console.Write(sb.ToString());
    }
}
