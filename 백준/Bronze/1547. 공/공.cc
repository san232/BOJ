#include <iostream>

int main()
{
    int swapCount;
    std::cin >> swapCount;

    int ballPos = 1;

    for (int i = 0; i < swapCount; ++i)
    {
        int x, y;
        std::cin >> x >> y;
        if (ballPos == x)
            ballPos = y;
        else if (ballPos == y)
            ballPos = x;
    }

    std::cout << ballPos << std::endl;
}
