#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Position
{
    int x;
    int y;
};

int solveMaze(int *matrix, int x, int y, struct Position *path, int i)
{
    if (x > 7 || x < 0 || y > 7 || y < 0)
    {
        return 0;
    }
    if (matrix[y * 8 + x] == 1)
    {
        return 0;
    }
    if (x == y && y == 7)
    {
        struct Position pos = {x, y};
        path[i] = pos;
        cout << "found path" << endl;
        return 1;
    }
    int a = solveMaze(matrix, x + 1, y, path, i + 1) || solveMaze(matrix, x, y + 1, path, i + 1) ? 1 : 0;
    if (a)
    {
        struct Position pos = {x, y};
        path[i] = pos;
    }
    return a;
}
int main()
{
    struct Position path[1000];
    int matrix[8][8] = {
        {0, 0, 0, 0, 1, 0, 0, 0},
        {0, 1, 1, 0, 0, 0, 0, 0},
        {0, 1, 1, 0, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0}};
    if (solveMaze((int *)matrix, 0, 0, path, 0))
    {
        int i = 1;
        if (path[1].y == 0 && path[1].x == 1)
        {
            cout << "(0,1)->(0,0)->";
        }
        while (path[i].x != 7 || path[i].y != 7)
        {

            cout << "(" << path[i].x << "," << path[i].y << ") ->";
            i++;
        }
        cout << " (7, 7)" << endl;
    }
    else
    {
        cout << "no path founded" << endl;
    }
    return 0;
}