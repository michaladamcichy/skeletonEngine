
class MyVector
{
public:
	double x;
	double y;
	double z=0;
	MyVector();
	MyVector(double inX, double inY, double inZ);
	MyVector(MyPoint A, MyPoint B);
	void define(double inX, double inY, double inZ);
	void defineFromPoints(MyPoint A, MyPoint B);
	double getLength();
	MyVector getVersor();
	void scale(double multiplier);
	void setLength(double inLength);
	MyVector operator + (const MyVector& vector);
	MyVector operator - (const MyVector& vector);
	MyVector operator * (const double& multiplier);
	MyVector operator / (const double& divider);
	MyVector operator += (const MyVector& vector);
	MyVector operator -= (const MyVector& vector);
	MyVector operator *= (const double& multiplier);
	MyVector operator /= (const double& divider);
	void print();
};

MyVector::MyVector()
{
}
MyVector::MyVector(double inX, double inY, double inZ = 0)
{
	x = inX;
	y = inY;
	z = inZ;
}
MyVector::MyVector(MyPoint A, MyPoint B)
{
	x = B.x - A.x;
	y = B.y - A.y;
	z = B.z - A.z;
}
void MyVector::define(double inX, double inY, double inZ = 0)
{
	x = inX;
	y = inY;
	z = inZ;
}
void MyVector::defineFromPoints(MyPoint A, MyPoint B)
{
	x = B.x - A.x;
	y = B.y - A.y;
	z = B.z - A.z;
}
double MyVector::getLength()
{
	return sqrt(x * x + y * y + z * z);
}
MyVector MyVector::getVersor()
{
	double length = getLength();
	return { x / length, y / length, z / length };
}
void MyVector::scale(double multiplier)
{
	x *= multiplier;
	y *= multiplier;
	z *= multiplier;
}
void MyVector::setLength(double inLength)
{
	MyVector versor = getVersor();
	x = versor.x * inLength;
	y = versor.y * inLength;
	z = versor.z * inLength;
}
MyVector MyVector::operator + (const MyVector& vector)
{
	return { this->x + vector.x, this->y + vector.y, this->z + vector.z };
}
MyVector MyVector::operator - (const MyVector& vector)
{
	return { this->x - vector.x, this->y - vector.y, this->z - vector.z };
}
MyVector MyVector::operator * (const double& multiplier)
{
	return { this->x * multiplier, this->y * multiplier, this->z * multiplier };
}
MyVector MyVector::operator / (const double& divider)
{
	return { this->x / divider, this->y / divider, this->z /divider };
}
MyVector MyVector::operator += (const MyVector& vector)
{
	return *this + vector;
}
MyVector MyVector::operator -= (const MyVector& vector)
{
	return *this - vector;
}
MyVector MyVector::operator *= (const double& multiplier)
{
	return *this * multiplier;
}
MyVector MyVector::operator /= (const double& divider)
{
	return *this / divider;
}
void MyVector::print()
{
	if (z == 0)
		printf("(%lf,%lf)", x, y);
	else
		printf("(%lf,%lf,%lf)", x, y, z);
}