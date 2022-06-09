#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
struct VectorHash
{
    size_t operator()(const std::vector<int> &v) const
    {
        std::hash<int> hasher;
        size_t seed = 0;
        for (int i : v)
        {
            seed ^= hasher(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};

// struct Slope
// {
//     double slope;
//     Slope(int val) : slope(val) {}
//     bool canExtend(vector<int> start, vector<int> final)
// {
//     double tslope;
//     if ((final[0] - start[0]) == 0)
//     {
//         tslope = __DBL_MAX__;
//     }
//     else
//     {

//         tslope = (final[1] - start[1]) / (final[0] - start[0]);
//     }
//     return tslope==this->slope;
// }
// };
double calSlope(vector<int> start, vector<int> final)
{
    double tslope;
    if ((final[0] - start[0]) == 0)
    {
        tslope = __DBL_MAX__;
    }
    else
    {

        tslope = (final[1] - start[1]) * 1.0 / (final[0] - start[0]);
    }
    return tslope;
}
int maxPoints(vector<vector<int>> &points)
{
    int n = points.size();
    int tmax = 0;
    for (int i = 0; i < n; i++)
    {
        unordered_map<double, unordered_set<vector<int>, VectorHash>> hm;
        for (int j = i + 1; j < n; j++)
        {
            double slope = calSlope(points[i], points[j]);
            if (hm.count(slope))
            {
                hm[slope].insert(points[i]);
                hm[slope].insert(points[j]);
            }
            else
            {
                hm[slope] = {};
                hm[slope].insert(points[i]);
                hm[slope].insert(points[j]);
            }
        }
        int cmax = 1;
        for (auto k : hm)
        {
            int tsize = k.second.size();
            cmax = max(cmax, tsize);
        }
        tmax = max(tmax, cmax);
    }

    return tmax;
}
int main()
{
    vector<vector<int>> points = {{1, 86}, {8, -69}, {-46, -19}, {-4, -99}, {27, 77}, {82, 36}, {-64, -45}, {-32, 10}, {51, 21}, {-43, 94}, {-90, 7}, {96, 85}, {33, -38}, {35, 62}, {51, 14}, {-48, 64}, {-56, 75}, {42, 27}, {-72, 81}, {-99, 55}, {13, -67}, {51, 69}, {99, 22}, {10, -89}, {-6, -92}, {-16, -37}, {-62, -34}, {-5, 60}, {-96, 98}, {49, -94}, {21, -57}, {-30, 55}, {-50, 31}, {35, -11}, {-74, 95}, {-88, 91}, {-6, -58}, {-64, -9}, {9, 55}, {-69, 53}, {-45, 60}, {-92, -2}, {37, -97}, {38, -66}, {26, -84}, {-4, 61}, {10, -30}, {-5, -89}, {93, -67}, {-80, -61}, {-86, -44}, {-60, -17}, {96, 84}, {97, 27}, {-88, -27}, {-15, -78}, {25, 5}, {79, -33}, {25, 9}, {-44, 68}, {-53, -68}, {35, -44}, {81, -44}, {99, 63}, {84, 94}, {-64, -58}, {55, -97}, {-48, 49}, {48, 32}, {70, 95}, {58, 92}, {1, -51}, {77, 14}, {-26, -73}, {59, -83}, {-29, 68}, {75, -44}, {-68, 61}, {-99, -74}, {93, -25}, {-37, -81}, {-99, 7}, {88, 24}, {16, -32}, {-32, -35}, {-31, -5}, {-96, -48}, {82, -89}, {89, 86}, {1, -95}, {57, 92}, {-71, 79}, {19, -89}, {2, 92}, {2, -57}, {40, 58}, {98, 68}, {72, 44}, {59, -42}, {38, 71}, {-72, 36}, {-21, 46}, {72, 67}, {-35, 47}, {65, -81}, {71, 15}, {26, -91}, {57, -10}, {-16, 36}, {-61, 71}, {45, 37}, {86, 38}, {-63, -14}, {10, -77}, {-23, -50}, {-47, -86}, {100, -67}, {-21, 78}, {43, -67}, {43, -66}, {6, 7}, {-78, 7}, {82, 28}, {47, 31}, {3, -67}, {-95, 53}, {57, 74}, {17, 58}, {9, 5}, {-72, 89}, {45, -75}, {-63, -11}, {97, -86}, {57, 51}, {96, 63}, {-8, -74}, {36, -34}, {-38, -14}, {84, 21}, {-74, -73}, {-100, -1}, {-32, -37}, {89, -55}, {-44, 6}, {58, -67}, {35, -43}, {1, 6}, {30, -10}, {100, -9}, {-69, -67}, {36, -67}, {100, -91}, {18, 30}, {45, -98}, {-16, -91}, {-67, 71}, {-51, 29}, {70, -9}, {64, -18}, {80, -100}, {59, -84}, {1, 36}, {96, 48}, {-96, 7}, {48, 71}, {-79, 17}, {4, 21}, {-84, 93}, {81, 38}, {-85, 22}, {-94, 21}, {18, -65}, {1, 14}, {-45, 6}, {96, 33}, {4, -75}, {-46, -86}, {-84, 62}, {-5, -29}, {78, 55}, {-71, -13}, {-81, -57}, {85, -50}, {-85, 84}, {-62, -65}, {72, 44}, {67, 44}, {50, -67}, {21, -99}, {-15, -63}, {-83, -50}, {-69, -4}, {68, 31}, {1, -81}, {91, 46}, {19, 7}, {-54, -67}, {51, 70}, {-67, -41}, {51, -41}};
    cout << maxPoints(points);
    return 0;
}
