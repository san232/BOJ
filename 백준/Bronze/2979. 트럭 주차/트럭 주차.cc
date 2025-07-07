#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int a, b, c;
    std::cin >> a >> b >> c;

    std::vector<int> timeCount(101, 0);

    for (int i = 0; i < 3; ++i)
    {
        int start, end;
        std::cin >> start >> end;
        for (int t = start; t < end; ++t)
        {
            timeCount[t]++;
        }
    }

    int totalCost = 0;
    for (int t = 1; t <= 100; ++t)
    {
        int trucks = timeCount[t];
        if (trucks == 1)
            totalCost += a * 1;
        else if (trucks == 2)
            totalCost += b * 2;
        else if (trucks == 3)
            totalCost += c * 3;
    }

    std::cout << totalCost << std::endl;
}
