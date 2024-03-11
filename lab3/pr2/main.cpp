#include "Canvas.h"

int main() {
    Canvas cvs(64, 64);
    cvs.SetPoint(10, 12, '$');
    cvs.Print();
    cvs.Clear();
    cvs.DrawCircle(20, 16, 6, 'o');
    cvs.Print();
    cvs.Clear();
    cvs.FillCircle(16, 16, 3, '*');
    cvs.Print();
    cvs.Clear();
    cvs.DrawRect(40, 40, 50, 50, '&');
    cvs.Print();
    cvs.Clear();
    cvs.FillRect(20, 5, 30, 15, '#');
    cvs.Print();
    cvs.Clear();
    cvs.DrawLine(12, 13, 60, 48, '^');
    cvs.Print();
    
    return 0;
}
