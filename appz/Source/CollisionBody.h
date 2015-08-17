#pragma once
#include "Force.h"
#include "Sound.h"
#include "DrawOrder.h"
#include "AABBTree.h"
/****************************************************************************/
/*!
\file CollisionBody.h
\author Muhammad Shafik Bin Mazlinan
\par email: cyboryxmen@yahoo.com
\brief
A class used to represent a physical body
*/
/****************************************************************************/

/****************************************************************************/
/*!
Class CollisionBody:
\brief
Used to represent a physical body
*/
/****************************************************************************/
class CollisionBody
{
public:
	CollisionBody(DrawOrder* draw = NULL, float mass = 0, float bounce = 0, float staticFriction = 0, float kineticFriction = 0);
	~CollisionBody();
	void SetTerminalVelocityTo(float terminal);
	void UpdateForcesTo(const double deltaTime);
	void UpdateVelocity(const double deltaTime);
	void UpdateTo(const double deltaTime);
	void TempUpdateTo(const double deltaTime);
	void ApplyFriction();
	void GainMomentumFrom(CollisionBody* draw, Vector3 momentumGain);
	void LoseMomentumTo(CollisionBody* draw, Vector3 momentumLost);
	void AddForce(Vector3 force);
	void AddForce(Force force);
	Vector3 GetAcceleration();
	Vector3 GetMomentum();
	void SetMomentumTo(Vector3 momentum);
	void CapVelocityToTerminal();
	float GetKinetic();
	int GetDiameter() const;
	float GetMaxX() const;
	float GetMinX() const;
	float GetMaxY() const;
	float GetMinY() const;
	float GetMaxZ() const;
	float GetMinZ() const;
	Mtx44 GetMatrix() const;
	bool IsCollidingWith(CollisionBody* body);
	void Decelerate(double deltaTime);
	void SetDecelerationTo(float decelerate);
	void RespondToCollision();

	Vector3 rotationVelocity;
	DrawOrder* draw;
	Mesh* mesh;
	Vector3 velocity;
	float mass;
	float bounce;
	float staticFriction;
	float kineticFriction;

	AABBTree tree;
	Sound* soundSys;
private:
	float deceleration;
	float terminalVelocity;
	std::vector<Force> forces;
};