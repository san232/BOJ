using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BOJ
{
    using System;
    using System.Linq;

    class Program
    {
        static void Main()
        {
            int[] input = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int N = input[0], M = input[1];

            int[] trees = Console.ReadLine().Split().Select(int.Parse).ToArray();

            int low = 0;
            int high = trees.Max();
            int result = 0;

            while (low <= high)
            {
                int mid = (low + high) / 2;
                long totalWood = 0;

                foreach (int tree in trees)
                {
                    if (tree > mid)
                        totalWood += tree - mid;
                }

                if (totalWood >= M)
                {
                    result = mid;
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }

            Console.WriteLine(result);
        }
    }

}
