#include <cmath>
#include <iostream>

#include "Canvas.h"

Canvas::Canvas(int width, int height)
    : lin(height)
    , col(width)
{
    canvas = new char*[lin];
    for (unsigned i = 0; i < lin; i++) {
        canvas[i] = new char[col];
    }

    for (int i = 0; i < lin; i++) {
        for(int j = 0; j < col; j++) {
            canvas[i][j] = ' ';
        }
    }
}
Canvas::~Canvas() {
    for (unsigned i = 0; i < lin; i++) {
        delete[] canvas[i];
    }
    delete[] canvas;
}
void Canvas::DrawCircle(int x, int y, int ray, char ch) {
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            double velocity_d = sqrt((x - i) * (x - i) + (y - j) * (y - j));
            int velocity = std::round(velocity_d);
            if (velocity == ray) {
                canvas[i][j] = ch;
            }
        }
    }
}
void Canvas::FillCircle(int x, int y, int ray, char ch) {
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            int velocity = sqrt((x - i) * (x - i) + (y - j) * (y - j));
            if (velocity <= ray) {
                canvas[i][j] = ch;
            }
        }
    }
}
void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
    for (int i = left; i < right; i++) {
        canvas[bottom][i] = ch;
        canvas[top][i] = ch;
    }
    for (int j = top; j < bottom; j++) {
        canvas[j][left] = ch;
        canvas[j][right] = ch;
    }
}
void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
    for (int i = left; i <= right; i++) {
        for (int j = top; j <= bottom; j++) {
            canvas[i][j] = ch;
        }
    }
}
void Canvas::SetPoint(int x, int y, char ch) {
    canvas[x][y] = ch;
}
void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int d = 2 * dy - dx;
    int y = y1;

    for (int x = x1; x <= x2; x++) {
        canvas[x][y] = ch;
        if (d > 0) {
            y++;
            d = d - 2 * dx;
        }
        d = d + 2 * dy;
    }
}
void Canvas::Print() {
    for (int i = 0; i < lin; i++) {
        for(int j = 0; j < col; j++) {
            std::cout << canvas[i][j];
        }
        std::cout << "\n";
    }
}
void Canvas::Clear() {
    for (int i = 0; i < lin; i++) {
        for(int j = 0; j < col; j++) {
            canvas[i][j] = ' ';
        }
    }
}
