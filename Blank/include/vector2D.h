/**
@file Vector2D.h
*/

#ifndef Vector2D_H
#define Vector2D_H

/*! \class Vector2D
    \brief A mathematical Vector
*/

#include <cmath>
#include <cstdlib>

class Vector2D
{
protected:
	float data[2]; //!< Data held by the vector
public:
	Vector2D();  //!< Default consturct, set everything to zero
	Vector2D(float allValues /*!< Value which x, y and z will be set to */); //!< Construtor taking a single value and making all component equal to that value
	Vector2D(float x /*!< Initial x value */, float y /*!< Initial y value */); //!< Constructor taking x,y, and z values
	float angle(Vector2D& other /*!< other vector for calculation */); //!< angle between this vector and other
	float angleDegrees(Vector2D& other /*!< other vector for calculation */); //!< angle between this vector and other
	float dotProduct(Vector2D& other /*!< other vector for calculation */); //!< Returns the dot product of this vector with other
	//Vector2D crossProduct(Vector2D& other /*!< other vector for calculation */); //!< Returns the cross product of this vector with other
	Vector2D getUnitVector(); //!< Returns the unit vector of this vector
	void setX(float x); //!< Sets the X component of this vector
	void setY(float y); //!< Sets the Y component of this vector
	float getX(); //!< Returns the X component of this vector 
	float getY(); //!< Returns the Y component of this vector
	float magnitude(); //!< Returns the magnitude of this vector
	Vector2D operator- (const Vector2D& other /*!< other vector for calculation */); //!< Component wise subtraction
	Vector2D operator+ (const Vector2D& other /*!< other vector for calculation */); //!< Component wise addition
	Vector2D operator* (const Vector2D& other /*!< other vector for calculation */); //!< Component wise multiplication
	Vector2D operator* (const float scalar /*!< Scalar for calculation */); //!< Component wise scalar multiplication
};

#endif Vector2D_H