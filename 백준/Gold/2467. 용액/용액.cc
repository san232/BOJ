#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> solution(n);

    for (int i = 0; i < n; ++i)
    {
        std::cin >> solution[i];
    }

    int left = 0;
    int right = n - 1;
    int bestSum = std::numeric_limits<int>::max();
    int bestLeft = solution[left];
    int bestRight = solution[right];

    while (left < right)
    {
        int sum = solution[left] + solution[right];
        int absSum = std::abs(sum);

        if (absSum < std::abs(bestSum))
        {
            bestSum = sum;
            bestLeft = solution[left];
            bestRight = solution[right];
            if (bestSum == 0)
            {
                break;
            }
        }

        if (sum < 0)
        {
            ++left;
        }
        else
        {
            --right;
        }
    }

    if (bestLeft < bestRight)
    {
        std::cout << bestLeft << " " << bestRight << std::endl;
    }
    else
    {
        std::cout << bestRight << " " << bestLeft << std::endl;
    }

    return 0;
}
