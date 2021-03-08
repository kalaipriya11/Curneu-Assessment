#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

struct points //Structure for storing the points
{
public:
    double x_point;
    double y_point;
};

struct finddisbtwtwopoints //Structure for finding closest pair of points
{
public:
    double x1_point;
    double y1_point;
    double x2_point;
    double y2_point;
    double disbtwtwopoints;
};

//Function for finding closest pair of points
//arguments = points(data) and their size(n)
void findClosestPair(points data[], int n)
{

    points temp;
    double minimum = 0;
    int value = 0; //looping variable for accessing points in disbtwtwopints
    finddisbtwtwopoints disbtwtwopoints[4950];

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            disbtwtwopoints[value].disbtwtwopoints = sqrt(pow(data[j].x_point - data[i].x_point, 2) + pow(data[j].y_point - data[i].y_point, 2));
            disbtwtwopoints[value].x1_point = data[i].x_point;
            disbtwtwopoints[value].y1_point = data[i].y_point;
            disbtwtwopoints[value].x2_point = data[j].x_point;
            disbtwtwopoints[value].y2_point = data[j].y_point;
            if (i == 0 && j == 1)
            {
                minimum = disbtwtwopoints[0].disbtwtwopoints;
            }
            if (disbtwtwopoints[value].disbtwtwopoints <= minimum)
            {
                minimum = disbtwtwopoints[value].disbtwtwopoints;
            }
            value++;
        }
    }

    for (int i = 0; i < 4950; i++)
    {
        if (disbtwtwopoints[i].disbtwtwopoints == minimum)
        {
            cout << "\n\n\nClosest pair of points are (" << disbtwtwopoints[i].x1_point << "," << disbtwtwopoints[i].y1_point << ") and (" << disbtwtwopoints[i].x2_point << "," << disbtwtwopoints[i].y2_point << ")";
        }
    }
}

int main()
{

    points data[100];
    srand((unsigned)time(NULL));

    for (int i = 0; i < 100; i++)
    {
        data[i].x_point = (float)rand() / RAND_MAX;
        data[i].y_point = (float)rand() / RAND_MAX;
    }

    int n = sizeof(data) / sizeof(data[0]);
    cout << "\nThe Random points are : ";

    for (int i = 0; i < 100; i++)
    {
        cout << "\n(" << data[i].x_point << " , " << data[i].y_point << "),";
    }

    findClosestPair(data, n);
}