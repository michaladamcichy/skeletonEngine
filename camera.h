#pragma once
class Camera
{
private:
	int width, height, length;
	MyPoint A, B, C, D, S;
public:
	Camera();
	Camera(double width, double height, double length, MyVector initialTranslaton);
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
}