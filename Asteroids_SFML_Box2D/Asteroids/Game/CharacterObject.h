#pragma once
#include "engine\gameobject.h"
//#include "MoveIndicator.h"

/**
 * This is an example class that shows how to extend the GameObject class. All the GameObject sub-classes MUST follow this structure.
 * All GameObject sub-class MUST have these following function implemented.
 * 1) Collided
 * 2) Start
 * 3) Update
 * 4) GetType
 *
 * And the Public Constructors
 * 1) The Default Constructor ClassName():GameObject(){}
 * And one of the 2 GameObject Complete Constructors. Either the Complete Object Constructor or the Text rendering Constructor if its a UI Object. This Example uses the Complete Constructor.
 * 2) ClassName(string objectName, Engine* _Main, bool dynamic, bool physicsBody, Vector2 &_Position, string _TextureName, bool _IsSprite, int _Rows, int _Columns) : GameObject(objectName, _Main, dynamic, physicsBody, _Position, _TextureName, _IsSprite, _Rows, _Columns) {}
 *
 * You can add any number of public and private member variables and functions to your GameObject sub-classes based on you object's requirements, 
 * just as long as you do not remove the above mentioned required member functions.
 */
class CharacterObject :public GameObject
{
	/**
	 * The BeginContact function is called by the physics engine when this object starts colliding with another object.
	 * This is were you should write how your object should handle collisions with various objects.
	 * 
	 * @param		object		The object this object is colliding with.
	 */
	virtual void BeginContact(GameObject* object);

	/**
	 * The EndContact function is called by the physics engine when this object stops colliding with another object.
	 * This is were you should write how your object should handle post collision actions with various objects.
	 *
	 * @param		object		The object this object stopped colliding with.
	 */
	virtual void EndContact(GameObject* object);

	/**
	 * This is where you initialize your object's member variables and set your default or initial values.
	 * This is called by the engine right after your object is created.
	 */
	virtual void Start();

	/**
	 * The Update function is called by the engine each frame as long as this object is alive in the game.
	 * This is where you define your object's behaviour rules.
	 *
	 * @param		frameNumber			The current frame number
	 */
	virtual void Update(unsigned long frameNumber);

	/**
	 * This function should always return the name of your class.
	 *
	 * @return		The name of the object's class.
	 */
	virtual string GetType();
public:
	/**
	 * The default Constructor. It always forwards the call to its super class GameObject 's Default Constructor
	 * Note: Make Sure that it always forwards the call to the GameObject's constructor using the  : GameObject(){} syntax
	 */
	CharacterObject() : GameObject()
	{
		left		= false;
		right		= false;
		up			= false;
		down		= false;
		upleft		= false;
		upright		= false;
		downleft	= false;
		downright	= false;
		IsPlayer	= false;

		x_MoveOffset = 0;
		y_MoveOffset = 0;

		NextLocation = Vector2(0.0f,0.0f);
		hasAnotherLocation = false;
	}

	/**
	 * The Complete Object Constructor. This object is created with an initial texture, physics body if stated, etc. This is your typical GameObject constructor that creates your regular object.
	 * It always forwards the call its equivalent super class constructor using the  : GameObject(...){} syntax
	 * Note: Make Sure that it always forwards the call to the GameObject's constructor using the  : GameObject(...){} syntax
	 */
	CharacterObject(string objectName, Engine* _Main, bool dynamic, bool physicsBody, Vector2 &_Position, string _TextureName, bool _IsSprite, int _Rows, int _Columns) : GameObject(objectName, _Main, dynamic, physicsBody, _Position, _TextureName, _IsSprite, _Rows, _Columns) 
	{
		left		= false;
		right		= false;
		up			= false;
		down		= false;
		upleft		= false;
		upright		= false;
		downleft	= false;
		downright	= false;
		IsPlayer	= false;

		x_MoveOffset = 0;
		y_MoveOffset = 0;

		NextLocation = Vector2(0.0f,0.0f);
		hasAnotherLocation = false;
	}

	/**
	 * This is called by the engine when an object receives a Touch Input o click input
	 *
	 * @param		_Param		The point in the world where the press event took place
	 */
	virtual void OnPointerPressed(Vector2 _Point);

	/**
	 * This is called by the engine when an object receives an UnTouch Input or UnClick input
	 *
	 * @param		_Param		The point in the world where the press event took place
	 */
	virtual void OnPointerReleased(Vector2 _Point);

	/**
	 * Is called by the engine when this object receives Drag input via 'Touch and Drag' or 'Click and Drag'.
	 *
	 * @param		_Point		the current touch point in the world, updated each frame until touch/click is released
	 */
	virtual void OnPointerMoved(Vector2 _Point);

	/**
	 *
	 */
	virtual void MoveToPoint(Vector2 _MovePoint, float SpeedLimit);

	/**
	 *
	 */
	virtual void SetOrientation(Vector2 _MovePoint);

	/**
	 *
	 */
	virtual void SetStateTextureWithOrientation();

	/**
	 *
	 */
	virtual void GetNearestWayPoint(Vector2 _FromPoint, Vector2 &point1, Vector2 &point2);

	/**
	 *
	 */
	virtual float GetDistance(Vector2 _Point1, Vector2 Point2);

	/**
	 * Fires a ray from the object's position to the given position. 
	 * It then checks for all the objects within the ray with the tag given.
	 * If it finds an object with a matching tag withing the ray, it returns true or else returns false
	 *
	 * @param		_PointToCast		The pint in the world to cast the ray
	 * @param		Tag					The Tag value to check against the objects
	 * @return							true = if objects found in ray, false = no objects in ray
	 */
	bool RayCast(Vector2 _PointToCast, string Tag);


	bool right;
	bool left;
	bool up;
	bool down;
	bool upright;
	bool upleft;
	bool downright;
	bool downleft;

	bool IsPlayer;

	int x_MoveOffset;
	int y_MoveOffset;
	bool hasAnotherLocation;
	Vector2 NextLocation;
	Vector2 CurrentDestination;
	Vector2 FinalDestination;

	//MoveIndicator* moveIndicator;

	//void SetMoveIndicator(MoveIndicator* indicator){moveIndicator = indicator;}
};

