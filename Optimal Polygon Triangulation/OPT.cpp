#include<bits/stdc++.h>
#include<iostream>
#define MAX FLT_MAX
using namespace std;

// Struct to store point coordinates
struct Point
{
    int x;
    int y;
};

// Function to return minimum of two floats
float minVal(float a, float b)
{
    return (a<b?a:b);
}

// Function to calculate distance between three points
float calcDist(Point points[], int i, int j, int k)
{
    float ans, a, b, c;
    ans=0;
    a=(points[i].x-points[j].x)*(points[i].x-points[j].x);
    b=(points[i].y-points[j].y)*(points[i].y-points[j].y);
    a=a+b;
    a=sqrt(a);
    ans=ans+a;
    a=(points[j].x-points[k].x)*(points[j].x-points[k].x);
    b=(points[j].y-points[k].y)*(points[j].y-points[k].y);
    a=a+b;
    a=sqrt(a);
    ans=ans+a;
    a=(points[i].x-points[k].x)*(points[i].x-points[k].x);
    b=(points[i].y-points[k].y)*(points[i].y-points[k].y);
    a=a+b;
    a=sqrt(a);
    ans=ans+a;
    return ans;
}

int main()
{
    int numPoints;
    cout << "Input the number of points: ";
    cin >> numPoints;

    // Array to store point coordinates
    Point points[numPoints];

    // Read in point coordinates
    for(int i=0; i<numPoints; i++) {
        cout << "Input the value of x for point " << i+1 << ": ";
        cin >> points[i].x;
        cout << "Input the value of y for point " << i+1 << ": ";
        cin >> points[i].y;
    }

    // Initialize DP array and variables
    int n=sizeof(points)/sizeof(points[0]);
    float dp[n][n];
    int gap, i, j, k;

    // Calculate minimum triangle
    for(gap=0; gap<n; gap++) {
        for(i=0; i<n-gap; i++) {
            j=i+gap;
            if(gap<2) {
                dp[i][j]=0;
            } else {
                dp[i][j]=MAX;
                for(k=i+1; k<j; k++) {
                    dp[i][j]=minVal(dp[i][j], dp[i][k]+dp[k][j]+calcDist(points, i, j, k));
                }
            }
        }
    }

    // Print result
    cout << dp[0][n-1] << endl;
}
