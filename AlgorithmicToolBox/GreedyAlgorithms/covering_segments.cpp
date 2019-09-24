
#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

struct Segment {
    int start;
    int end;
};

std::vector<int> optimal_points(std::vector<Segment> &segments) {
    std::vector<int> points;
    std::vector<int> list_of_points;
    //write your code here

    std::sort(segments.begin(), segments.end(), [](const Segment &a, const Segment &b) { return a.end < b.end; });
    int i = 0;
    int n = segments.size();
    while (i < n) {
        int right = segments[i].end;
        list_of_points.push_back(right);

        while (i < n && segments[i].start <= right && right <= segments[i].end) {
            i++;
        }

    }
    for (size_t j = 0; j < list_of_points.size(); ++j) {
        points.push_back(list_of_points[j]);
    }
    return points;
}


/*
int main() {
    int n;
    std::cin >> n;

    std::vector<Segment> segments(n);


    for (size_t i = 0; i < segments.size(); ++i) {
        std::cin >> segments[i].start >> segments[i].end;
    }

    std::vector<int> points = optimal_points(segments);
    std::cout << points.size() << "\n";
    for (size_t i = 0; i < points.size(); ++i) {
        std::cout << points[i] << " ";
    }
}*/
