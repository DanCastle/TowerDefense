/**
@file Vector2D.cpp
*/

#define _USE_MATH_DEFINES

#include "Vector2D.h"
#include <cmath>
#include <math.h>



Vector2D::Vector2D()  //!< Default consturct, set everything to zero
{
	for (int i=0;i<2;++i){
		data[i]=0;
	}
}

Vector2D::Vector2D(float allValues) //!< Construtor taking a single value and making all component equal to that value
{
	for (int i=0;i<2;++i){
		data[i]=allValues;
	}
}


Vector2D::Vector2D(float x, float y) //!< Constructor taking x,y, and z values
{
	data[0]=x;
	data[1]=y;
}


float Vector2D::angle(Vector2D& other) //!< angle between this vector and other
{
	float cosineTheta = dotProduct(other) / (magnitude() * other.magnitude());
	float theta = acos(cosineTheta);
	
	return theta;
}

float Vector2D::angleDegrees(Vector2D& other) //!< angle between this vector and other
{
	float cosineTheta = dotProduct(other) / (magnitude() * other.magnitude());
	float theta = acos(cosineTheta);
	float thetaDegrees = theta * 180/M_PI;
	
	return thetaDegrees;
}


Vector2D Vector2D::getUnitVector() //!< Returns the unit vector of this vector
{
	float x = getX()/magnitude();
	float y = getY()/magnitude();

	Vector2D unitVector(x,y);
	return unitVector;
}

void Vector2D::setX(float x)
{
	data[0] = x;

	return;
}

void Vector2D::setY(float y)
{
	data[1] = y;

	return;
}

float Vector2D::getX() //!< Returns the X component of this vector 
{
	float x = data[0];
	return x;
}


float Vector2D::getY() //!< Returns the Y component of this vector
{
	float y = data[1];
	return y;
}


float Vector2D::magnitude() //!< Returns the magnitude of this vector
{
	float mag = sqrt((getX()*getX())+(getY()*getY()));
	return mag;
}

Vector2D Vector2D::operator- (const Vector2D& other) //!< Component wise subtraction
{
	float x = getX() - other.data[0];
	float y = getY() - other.data[1];

	Vector2D newVector(x,y);
	return newVector;
}


Vector2D Vector2D::operator+ (const Vector2D& other) //!< Component wise addition
{
	float x = getX() + other.data[0];
	float y = getY() + other.data[1];
	
	Vector2D newVector(x,y);
	return newVector;
}


Vector2D Vector2D::operator* (const Vector2D& other) //!< Component wise multiplication
{
	float x = getX() * other.data[0];
	float y = getY() * other.data[1];

	Vector2D newVector(x,y);
	return newVector;
}

Vector2D Vector2D::operator* (const float scalar) //!< Component wise scalar multiplication
{
	float x = getX()*scalar;
	float y = getY()*scalar;

	Vector2D scaleVector(x,y);
	return scaleVector;
}

float Vector2D::dotProduct(Vector2D& other) //!< Returns the dot product of this vector with other
{
	float i = getX()*other.getX();
	float j = getY()*other.getY();

	float dotProduct = i+j;
	return dotProduct;
}


//Vector2D Vector2D::crossProduct(Vector2D& other) //!< Returns the cross product of this vector with other
//{
//	float x1 = getX();
//	float y1 = getY();
//	float x2 = other.getX();
//	float y2 = other.getY();
//
//	float i = (y1*z2 - y2*z1);
//	float j = (x2*z1 - x1*z2);
//	float k = (x1*y2 - x2*y1);
//
//	Vector2D crossProduct(i,j,k);
//	return crossProduct;
//}

