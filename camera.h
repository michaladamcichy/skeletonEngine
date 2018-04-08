#pragma once
class Camera
{
private:
	int width, height, length;
	MyPoint A, B, C, D, S;
	MyPlane plain;
public:
	Camera();
	Camera(double width, double height, double length, MyVector initialTranslaton);
	MyPlane& getPlain();
	MyPoint getA();
	MyPoint getB();
	MyPoint getC();
	MyPoint getD();
	MyPoint getS();
	~Camera();
};

Camera::Camera()
{
}
Camera::~Camera()
{
}
Camera::Camera(double inWidth, double inHeight, double inLength, MyVector initialTranslation = { 0,0,0 })
{
	width = inWidth;
	height = inHeight;
	length = inLength;

	A.define(width / 2, length, height / 2);
	trans(A, initialTranslation);
	B.define(-width / 2, length, height / 2);
	trans(B, initialTranslation);
	C.define(width / 2, length, -height / 2);
	trans(C, initialTranslation);
	D.define(-width / 2, length, -height / 2);
	trans(D, initialTranslation);
	S.define(0, 0, 0);
	trans(S, initialTranslation);

	plain.define(A, B, C);
}
MyPlane& Camera::getPlain()
{
	return plain;
}
MyPoint Camera::getA()
{
	return A;
}
MyPoint Camera::getB()
{
	return B;
}
MyPoint Camera::getC()
{
	return C;
}
MyPoint Camera::getD()
{
	return D;
}
MyPoint Camera::getS()
{
	return S;
}