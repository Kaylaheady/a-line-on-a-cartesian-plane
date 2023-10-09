class Line {
public:
Line();
Line(double);
Line(double, double);
Line(double, double, double);

double GetSlope();
double GetX();
double GetY();

void SetSlope(double m);
void SetX(double x);
void SetY(double y);

Line GetPerpendicular();
void PrintPointSlope();
void PrintSlopeIntercept();
void PrintStandard();
void Intersection(Line);

private:
double xCoord;
double yCoord;
double slope;
const int PRECISION;
double GetYIntercept();
};
