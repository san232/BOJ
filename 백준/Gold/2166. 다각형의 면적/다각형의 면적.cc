#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

int main()
{
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> points(n);

    for (int i = 0; i < n; ++i)
    {
        std::cin >> points[i].first >> points[i].second;
    }

    long long sum1 = 0;
    long long sum2 = 0;

    for (int i = 0; i < n; ++i)
    {
        int j = (i + 1) % n;
        sum1 += (long long)(points[i].first) * points[j].second;
        sum2 += (long long)(points[i].second) * points[j].first;
    }

    double area = std::abs(sum1 - sum2) / 2.0;

    std::cout << std::fixed << std::setprecision(1) << area << std::endl;
}
