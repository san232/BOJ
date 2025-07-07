#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string input;
    std::cin >> input;

    std::vector<int> alphabetCount(26, 0);

    for (char ch : input)
    {
        int index = (int)(ch - 'a');
        alphabetCount[index]++;
    }

    for (int i = 0; i < 26; ++i)
    {
        std::cout << alphabetCount[i];
        if (i < 25)
            std::cout << " ";
    }
    std::cout << std::endl;

    return 0;
}
