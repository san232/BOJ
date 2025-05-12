using System;
using System.Collections.Generic;
using System.Text;

class Program
{
    static void Main()
    {
        int t = int.Parse(Console.ReadLine());

        for (int i = 0; i < t; i++)
        {
            string p = Console.ReadLine().Replace("RR", "");
            int n = int.Parse(Console.ReadLine());
            string input = Console.ReadLine();

            List<int> array = n == 0 ? new List<int>() : new List<int>(Array.ConvertAll(input.Substring(1, input.Length - 2).Split(','), int.Parse));

            if (p.Count(x => x == 'D') > n)
            {
                Console.WriteLine("error");
                continue;
            }

            bool isReversed = false;
            int left = 0, right = 0;

            foreach (char cmd in p)
            {
                if (cmd == 'R')
                {
                    isReversed = !isReversed;
                }
                else if (cmd == 'D')
                {
                    if (isReversed)
                    {
                        right++;
                    }
                    else
                    {
                        left++;
                    }
                }
            }

            array = array.GetRange(left, array.Count - left - right);

            if (isReversed)
            {
                array.Reverse();
            }

            StringBuilder outputBuilder = new StringBuilder();
            outputBuilder.Append("[").Append(string.Join(",", array)).Append("]");
            Console.WriteLine(outputBuilder.ToString());
        }
    }
}
