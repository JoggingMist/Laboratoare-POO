#include "Canvas.h"
#include <iostream>
#include <fstream>
using namespace std;

Canvas::Canvas(int width,int height)
{
	Width = width;
	Height = height;

    //Initializare matrice dinamic
    CANVAS = new char* [Height];
    for (int i = 0; i < Height; ++i)
        CANVAS[i] = new char[Width];

    this->Clear();
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
    for (int i = y - ray; i <= y + ray; i++)
    {
        for (int j = x - ray; j <= x + ray; j++)
        {
            if (abs(ray * ray - (i - y) * (i - y) - (j - x) * (j - x)) <= abs(x - ray))
            {
                CANVAS[i][j] = ch;
            }
                
        }
    }
}

void Canvas::DrawElipse(int x, int y, int ray1, int ray2, char ch)
{
    for (int i = y - ray2; i <= y + ray2; i++)
    {
        for (int j = x - ray1; j <= x + ray1; j++)
        {
            if(abs( (i-y)*(i-y)*ray1*ray1  + (j-x)*(j-x)*ray2*ray2 - ray1 * ray1 * ray2 * ray2 ) < 100)
                CANVAS[i][j] = ch;
        }
    }
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
    for (int i = y - ray; i <= y + ray; i++)
    {
        for (int j = x - ray; j <= x + ray; j++)
        {
            if (ray*ray>(i-y)* (i - y)+ (j - x)* (j - x))
                CANVAS[i][j] = ch;
        }
    }
}
void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
    for (int j = left; j <= right; ++j)
    {
        CANVAS[top][j] = ch;
        CANVAS[bottom][j] = ch;
    }

    for (int i = top; i <= bottom; ++i)
    {
        CANVAS[i][left] = ch;
        CANVAS[i][right] = ch;
    }
}
void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
    for (int i = top; i <= bottom;++i)
        for (int j = left; j <= right; ++j)
            CANVAS[i][j] = ch;
}
void Canvas::SetPoint(int x, int y, char ch)
{
    CANVAS[y][x] = ch;
}
void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
    double dx = x2 - x1;
    double dy = y2 - y1;
    double d = abs(dy / dx);
    double error = 0;
    int y = y1;
    for (int x = x1; x <= x2; x++)
    {
        CANVAS[x][y] = ch;
        error += d;
        if (error >= 0.5)
        {
            y = y + ((d > 0) ? d - d + 1 : d + d - 1) * 1;
            error = error - 1.0;
        }
    }
}
void Canvas::Print()
{
    ofstream f("file.txt");
    for (int i = 0; i < Height; ++i)
    {
        for (int j = 0; j < Width; ++j)
        {
            f << CANVAS[i][j] << " ";
        }
        f << endl;
    }
    f.close();
}
void Canvas::Clear()
{
    for (int i = 0; i < Height; ++i)
        for (int j = 0; j < Width; ++j)
            CANVAS[i][j] = EmptyPoint;
}