#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> grid;
void draw_triangle(int n, int y, int x) {
    if (n == 3) {
        grid[y][x] = '*';
        grid[y + 1][x - 1] = '*';
        grid[y + 1][x + 1] = '*';
        grid[y + 2][x - 2] = '*';
        grid[y + 2][x - 1] = '*';
        grid[y + 2][x] = '*';
        grid[y + 2][x + 1] = '*';
        grid[y + 2][x + 2] = '*';
        return;
    }

    int next_n = n / 2;
    draw_triangle(next_n, y, x);
    draw_triangle(next_n, y + next_n, x - next_n);
    draw_triangle(next_n, y + next_n, x + next_n);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    grid.assign(n, std::string(2 * n - 1, ' '));

    draw_triangle(n, 0, n - 1);

    for (int i = 0; i < n; ++i) {
        std::cout << grid[i] << "\n";
    }

    return 0;
}
