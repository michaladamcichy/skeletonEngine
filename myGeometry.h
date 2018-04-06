#include<myMath.h>
#include<myPoint.h>
#include<myVector.h>
#include<myLine.h>

double pointPointDistance(MyPoint A, MyPoint B)
{
return sqrt( (A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y) + (A.z - B.z)*(A.z - B.z));
}