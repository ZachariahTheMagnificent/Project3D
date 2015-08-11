#include "CollisionBody.h"
#include "MyMath.h"
#include "VoxelOctree.h"
/****************************************************************************/
/*!
\file CollisionBody.cpp
\author Muhammad Shafik Bin Mazlinan
\par email: cyboryxmen@yahoo.com
\brief
A class used to represent a physical body
*/
/****************************************************************************/
CollisionBody::CollisionBody(DrawOrder* draw, float mass, float bounce, float staticFriction, float kineticFriction)
	:
draw(draw),
mass(mass),
bounce(bounce),
staticFriction(staticFriction),
kineticFriction(kineticFriction),
deceleration(0),
mesh(NULL),
soundSys(NULL)
{
}

void CollisionBody::RespondToCollision()
{
	if(soundSys)
	{
		soundSys->playSound("hitsound");
	}
}

CollisionBody::~CollisionBody()
{
}

void CollisionBody::SetTerminalVelocityTo(float terminal)
{
	terminalVelocity = abs(terminal);
}

void CollisionBody::UpdateForcesTo(const double deltaTime)
{
	std::vector<Force>::iterator force = forces.begin();
	while(force != forces.end())
	{
		force->UpdateTo(deltaTime);
		if(force->isDead())
		{
			force = forces.erase(force);
		}
		else
		{
			++force;
		}
	}
}

void CollisionBody::UpdateVelocity(const double deltaTime)
{
	Vector3 acceleration = GetAcceleration();
	velocity += acceleration * deltaTime;
	CapVelocityToTerminal();
}

void CollisionBody::UpdateTo(const double deltaTime)
{
	draw->transform.translate += velocity * deltaTime;
	draw->transform.rotate.yaw += rotationVelocity.x * deltaTime;
	draw->transform.rotate.pitch += rotationVelocity.y * deltaTime;
	draw->transform.rotate.roll += rotationVelocity.z * deltaTime;
	UpdateForcesTo(deltaTime);
}

void CollisionBody::TempUpdateTo(const double deltaTime)
{
	draw->transform.translate += velocity * deltaTime;
	draw->transform.rotate.yaw += rotationVelocity.x * deltaTime;
	draw->transform.rotate.pitch += rotationVelocity.y * deltaTime;
	draw->transform.rotate.roll += rotationVelocity.z * deltaTime;
}

bool CollisionBody::IsCollidingWith(CollisionBody* body)
{
	return true;
}

int CollisionBody::GetDiameter() const
{
	return 0;
}

Mtx44 CollisionBody::GetMatrix() const
{
	return draw->GetMatrix();
}

void CollisionBody::ApplyFriction()
{
	velocity *= (1 - staticFriction);
}

void CollisionBody::GainMomentumFrom(CollisionBody* draw, Vector3 momentumGain)
{
	AddForce(momentumGain);
	draw->AddForce(-momentumGain);
	//velocity += momentumGain / mass;
	//draw->velocity -= momentumGain / mass;
}

void CollisionBody::LoseMomentumTo(CollisionBody* draw, Vector3 momentumLost)
{
	AddForce(-momentumLost);
	draw->AddForce(momentumLost);
	//velocity -= momentumLost / mass;
	//draw->velocity += momentumLost / draw->mass;
}

void CollisionBody::AddForce(Vector3 force)
{
	Force actualForce;
	actualForce.SetLifespanTo(0);
	actualForce.SetVector(force);
	forces.push_back(actualForce);
}

void CollisionBody::AddForce(Force force)
{
	forces.push_back(force);
}

Vector3 CollisionBody::GetAcceleration()
{
	Vector3 acceleration;
	for(std::vector<Force>::iterator force = forces.begin(); force != forces.end(); force++)
	{
		if(mass)
		{
			acceleration += force->GetVector() / mass;
		}
	}
	return acceleration;
}

void CollisionBody::Decelerate(double deltaTime)
{
	float length = velocity.Length();
	if(length <= deceleration*deltaTime)
		velocity.SetZero();
	else
		velocity = velocity.Normalized() * (length - deceleration*deltaTime);
}

void CollisionBody::SetDecelerationTo(float decelerate)
{
	deceleration = abs(decelerate);
}

Vector3 CollisionBody::GetMomentum()
{
	return velocity * mass;
}

void CollisionBody::SetMomentumTo(Vector3 momentum)
{
	//if the object has zero mass, it is unaffected by force but can still be moved by it's velocity. Setting it's velocity to zero when colliding with other objects should stop it from going through them.
	if(mass == 0)
	{
		velocity.SetZero();
	}
	else
	{
		velocity = momentum / mass;
		CapVelocityToTerminal();
	}
}

void CollisionBody::CapVelocityToTerminal()
{
	float lenSqrd = velocity.LengthSquared();
	if(lenSqrd > terminalVelocity*terminalVelocity)
	{
		velocity.Normalize() *= terminalVelocity;
		if(Math::IsNegative(lenSqrd))
		{
			velocity *= -1;
		}
	}
}

float CollisionBody::GetKinetic()
{
	return 0.5f * mass * velocity.Length() * velocity.Length();
}

float CollisionBody::GetMaxX() const
{
	return 0;
}

float CollisionBody::GetMinX() const
{
	return 0;
}

float CollisionBody::GetMaxY() const
{
	return 0;
}

float CollisionBody::GetMinY() const
{
	return 0;
}

float CollisionBody::GetMaxZ() const
{
	return 0;
}

float CollisionBody::GetMinZ() const
{
	return 0;
}