#include "vector.h"
using namespace std;
using namespace vector;
int main()
{
    const int numberOfPlane = 6;
    double time = 1;
    Point startingPoint(0, 0, 0);
    Vector a(0.5, 0.25, 0.25);
    Plane arr[numberOfPlane]{ Plane(0,0,1,0), Plane(0,0,-1,1), Plane(0,1,0,0), Plane(1,0,0,0), Plane(-1,0,0,1), Plane(0,-1,0,1) };
    Point k;
    Point finishPoint = startingPoint;
    const double speed = a.GetLenght();
    Vector lenght(0, 0, 0);
    Point array[2];
    int IDplanesToWhichThisPointBelongs[2][3];
    while (true)
    {
        startingPoint = finishPoint;
        int n = 0;
        int m = 0;
        for (int j = 0; j < 2; j++)
            for (int p = 0; p < 3; p++)
                IDplanesToWhichThisPointBelongs[j][p] = -1;
        for (int i = 0; i < numberOfPlane; i++)
        {
            if (!(ThePointBelongsToThePlane(arr[i], startingPoint)))
            {
                k = IntersectionPointOfTheVectorAndThePlane(arr[i], a, startingPoint);
                if ((k.GetX() >= 0 && k.GetX() <= 1) && (k.GetY() >= 0 && k.GetY() <= 1) && (k.GetZ() >= 0 && k.GetZ() <= 1))
                {
                    if (n == 0)
                    {
                        array[n] = k;
                        IDplanesToWhichThisPointBelongs[n++][m++] = i;
                    }
                    else if (n > 0 && array[0].GetX() == k.GetX() && array[0].GetY() == k.GetY() && array[0].GetZ() == k.GetZ())
                    {
                        IDplanesToWhichThisPointBelongs[0][m++] = i;
                        n++;
                    }
                    else
                    {
                        array[1] = k;
                        IDplanesToWhichThisPointBelongs[1][n - m] = i;
                        n++;
                    } 
                }
            }
        }
        if (n - m == 0)
        {
            finishPoint = array[0];
            Vector c(0, 0, 0);
            c = ConstructionOfVectorByTwoPoints(startingPoint, finishPoint);
            if (time <= (c.GetLenght() / speed))
            {
                double ratio = time / (c.GetLenght() / speed);
                finishPoint = FindingPointBetweenTwoOthersThroughRatio(startingPoint, finishPoint, ratio);
                finishPoint.Print();
                break;
            }
            if (n == 1)
                a = ReflectedVectorFromThePlane(a, arr[IDplanesToWhichThisPointBelongs[0][0]]);
            else if (n == 2)
                a = ReflectedVectorFromTheLine(a, arr[IDplanesToWhichThisPointBelongs[0][0]], arr[IDplanesToWhichThisPointBelongs[0][1]]);
            else
                a = ReflectedVectorFromThePoint(a);
        }
        else
        {
            Vector c(0, 0, 0);
            c = ConstructionOfVectorByTwoPoints(startingPoint, array[0]);
            double initialLength = c.GetLenght();
            double coeefficient = (max(a.GetX(), max(a.GetY(), a.GetZ()))) * 1000;
            Point d(startingPoint.GetX() + a.GetX() / coeefficient, startingPoint.GetY() + a.GetY() / coeefficient, startingPoint.GetZ() + a.GetZ() / coeefficient);
            c = ConstructionOfVectorByTwoPoints(d, array[0]);
            if (initialLength > c.GetLenght())
            {
                finishPoint = array[0];
                if (time <= initialLength / speed)
                {
                    double ratio = time / (initialLength / speed);
                    finishPoint = FindingPointBetweenTwoOthersThroughRatio(startingPoint, finishPoint, ratio);
                    finishPoint.Print();
                    break;
                }
                if (m == 1)
                    a = ReflectedVectorFromThePlane(a, arr[IDplanesToWhichThisPointBelongs[0][0]]);
                else if (m == 2)
                    a = ReflectedVectorFromTheLine(a, arr[IDplanesToWhichThisPointBelongs[0][0]], arr[IDplanesToWhichThisPointBelongs[0][1]]);
                else
                    a = ReflectedVectorFromThePoint(a);
            }
            else
            {
                finishPoint = array[1];
                c = ConstructionOfVectorByTwoPoints(startingPoint, finishPoint);
                if (time <= c.GetLenght() / speed)
                {
                    double ratio = time / (c.GetLenght() / speed);
                    finishPoint = FindingPointBetweenTwoOthersThroughRatio(startingPoint, finishPoint, ratio);
                    finishPoint.Print();
                    break;
                }
                if (n - m == 1)
                    a = ReflectedVectorFromThePlane(a, arr[IDplanesToWhichThisPointBelongs[1][0]]);
                else if (n - m == 2)
                    a = ReflectedVectorFromTheLine(a, arr[IDplanesToWhichThisPointBelongs[1][0]], arr[IDplanesToWhichThisPointBelongs[1][1]]);
                else
                    a = ReflectedVectorFromThePoint(a);
            }
        }
        lenght = ConstructionOfVectorByTwoPoints(startingPoint, finishPoint);
        time -= lenght.GetLenght() / speed;
    }
    return 0;
}