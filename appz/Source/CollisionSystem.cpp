#include "CollisionSystem.h"
#include "timer.h"

//default constructor
CollisionSystem::CollisionSystem()
	:
contactBuffer(NULL),
contactBufferSize(9000000)
{
	if(contactBufferSize)
	{
		contactBuffer = new Contact[contactBufferSize];
	}
}

//default destructor
CollisionSystem::~CollisionSystem()
{
	if(contactBuffer)
	{
		delete [] contactBuffer;
		contactBuffer = NULL;
	}
}

void CollisionSystem::IncreaseBufferTo(const unsigned& size)
{
	if(size > contactBufferSize)
	{
		delete [] contactBuffer;
		contactBuffer = NULL;

		contactBufferSize = size;
		contactBuffer = new Contact[contactBufferSize];
	}
}

void CollisionSystem::Respond(CollisionBody* body1, CollisionBody* body2, Polygonn& poly1, Polygonn& poly2)
{
	//Vector3 right1 = poly2.GetNormal().Cross(body1->velocity);
	//if(right1.IsZero())
	//{
	//	body1->velocity.SetZero();
	//}
	//else
	//{
	//	Vector3 direction1 = right1.Cross(poly2.GetNormal()).Normalized();
	//	body1->velocity = direction1 * direction1.Dot(body1->velocity);
	//}
	//body1->rotationVelocity.SetZero();

	//Vector3 right2 = poly1.GetNormal().Cross(body2->velocity);
	//if(right2.IsZero())
	//{
	//	body2->velocity.SetZero();
	//}
	//else
	//{
	//	Vector3 direction2 = right2.Cross(poly1.GetNormal()).Normalized();
	//	body2->velocity = direction2 * direction2.Dot(body2->velocity);
	//}
	//body2->rotationVelocity.SetZero();
	Vector3 pos = poly1.GetCentre(), pos2 = poly2.GetCentre();

	//Vector3 relativeVelocity = body1->velocity - body2->velocity;
	
	Vector3 normal1(poly1.GetNormal());
	Vector3 normal2(poly2.GetNormal());

	float test = body1->velocity.Dot(normal2);
	if(test < 0)
	{
		body1->velocity -= test * normal2 * 1.5;
		body1->RespondToCollision();
	}
	test = body2->velocity.Dot(normal1);
	if(test < 0)
	{
		body2->velocity -= test * normal1 * 1.5;
		body2->RespondToCollision();
	}
}

//Update function for the interface
void CollisionSystem::UpdateTo(const double& deltaTime, AABBTree* tree)
{
	bool collisionIsDone = false;
			
	Contact* bufferBegin = contactBuffer;
	Contact* bufferEnd = contactBuffer;
	tree->GetContacts(&bufferEnd);

	//std::cout << bufferEnd - bufferBegin << std::endl;

	for(Contact* contact = bufferBegin; contact != bufferEnd; ++contact)
	{
		Polygonn& poly1 = contact->node1->data;
		Polygonn& poly2 = contact->node2->data;

		if(poly1.Intersects(poly2))
		{
			Respond(contact->node1->body, contact->node2->body, poly1, poly2);
						
			if(!collisionIsDone)
			{
				collisionIsDone = true;
				contact->node1->body->Decelerate(deltaTime);
				contact->node2->body->Decelerate(deltaTime);
			}
		}
	}
}