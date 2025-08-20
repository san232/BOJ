#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
    int r, c;
};

int N, M;
vector<Point> houses;
vector<Point> chickens;
vector<Point> selected_chickens;
int min_city_chicken_dist = 2147483647;

int calculate_distance(Point p1, Point p2) {
    return abs(p1.r - p2.r) + abs(p1.c - p2.c);
}

void calculate_city_chicken_dist() {
    int current_city_dist = 0;
    for (const auto& house : houses) {
        int single_house_dist = 2147483647;
        for (const auto& chicken : selected_chickens) {
            single_house_dist = min(single_house_dist, calculate_distance(house, chicken));
        }
        current_city_dist += single_house_dist;
    }
    min_city_chicken_dist = min(min_city_chicken_dist, current_city_dist);
}

void find_combinations(int start_index) {
    if (selected_chickens.size() == M) {
        calculate_city_chicken_dist();
        return;
    }

    for (int i = start_index; i < chickens.size(); ++i) {
        selected_chickens.push_back(chickens[i]);
        find_combinations(i + 1);
        selected_chickens.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int val;
            cin >> val;
            if (val == 1) {
                houses.push_back({i, j});
            } else if (val == 2) {
                chickens.push_back({i, j});
            }
        }
    }

    find_combinations(0);

    cout << min_city_chicken_dist << endl;

    return 0;
}
