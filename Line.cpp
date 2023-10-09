#include "line.h"
#include<iostream>
#include<iomanip>
using namespace std;
Line::Line() : PRECISION(1000) {
xCoord = 0;
yCoord = 0;
slope = 1;
}
Line::Line(double m) : PRECISION(1000) {
xCoord = 0;
yCoord = 0;
slope = m;
}
Line::Line(double m, double y) : PRECISION(1000) {
xCoord = 0;
yCoord = y;
slope = m;
}
Line::Line(double x, double y, double m) : PRECISION(1000) {
xCoord = x;
yCoord = y;
slope = m;
}
double Line::GetSlope() {
return slope;
}
double Line::GetX() {
return xCoord;
}
double Line::GetY() {
return yCoord;
}
void Line::SetSlope(double m) {
slope = m;
}
void Line::SetX(double x) {
xCoord = x;
}
void Line::SetY(double y) {
yCoord = y;
}
Line Line::GetPerpendicular() {
return Line(xCoord, yCoord, -(1/slope));
}
void Line::PrintPointSlope() {
cout << fixed << showpoint << setprecision(2);
cout << "y - " << yCoord << " = " << slope << "(x - " << xCoord << ")\n";
}
void Line::PrintSlopeIntercept() {
cout << "y = " << slope << "x + " << GetYIntercept() << endl;
}
void Line::PrintStandard() {
//based on slope intercept form, we can derive these coefficients, which might be
fractional:
double A = -slope;
double B = 1;
double C = GetYIntercept();
int newA = (int)(A * PRECISION);
//cout << "newA: " << newA << endl;
int newB = (int)(B * PRECISION);
//cout << "newB: " << newB << endl;
int newC = (int)(C * PRECISION);
//cout << "newC: " << newC << endl;
while(1){
double tempA = newA / 10.0;
//cout << "tempA: " << tempA << endl;
double tempB = newB / 10.0;
//cout << "tempB: " << tempB << endl;
double tempC = newC / 10.0;
//cout << "tempC: " << tempC << endl;
if((tempA != 0 && (tempA / (int)tempA) != 1)
|| (tempB != 0 && (tempB / (int)tempB) != 1)
|| (tempC != 0 && (tempC / (int)tempC) != 1)
) {
break;
}
//cout << "UPDATING..." << endl;
newA = tempA;
newB = tempB;
newC = tempC;
}
cout << newA << "x + " << newB << "y = " << newC << endl;
}
void Line::Intersection(Line otherLine) {
double x = (otherLine.GetYIntercept() - GetYIntercept()) / (GetSlope() -
otherLine.GetSlope());
double y = slope * (x) + GetYIntercept();
cout << "(" << x << ", " << y << ")" << endl;
}
double Line::GetYIntercept() {
return -(slope*xCoord) + yCoord;
}
