#pragma once

#include "Engine.h"
#include "BasicMath.h"
#include <string>
#include <list>
#include "Box2D.h"
#include "Layer.h"
#include "TextureManager.h"
#include "Texture.h"


class Engine;
class Layer;
class TextureManager;

struct TextureEntry;

using namespace std;

/**
 * An enum that defines the types of coordinates
 */
enum Coordinate
{
	Local, /** Local coordinates specific to the object */
	Global /** Global or world coordinates */
};

/**
 * An enum that defines the types or shapes of the Collision body or the collider
 */
enum ColliderType
{
	BoxCollider		/** Box/Rectangular shaped collider */
};


/**
 * The GameObject class is by far the Most Important class in the entire engine. The engine is extremely "Game-Object Oriented Engine". This means, 
 * that the engine expects almost everything in the game to either be a GameObject or a sub-class of GameObject. This does not mean that you cannot
 * directly use SFML etc, to draw or implement your elements, but the engine will not know how to handle them or be able to apply physics to them
 * unless you explicitly specify(program) how they should be handled.
 *
 * NOTE: It is strongly recommended that the user always uses GameObjects or create sub-classes of GameObject to create the in game elements/objects.
 */
class GameObject
{
protected:
	/**
	 * Name of the object
	 */
	string name;

	/**
	 * Tag of the object. Used Heavily for searching an object and for checking collisions with a group of different game objects
	 */
	string tag;

	/**
	 * Screen width
	 */
    int	widthScreen;

	/**
	 * Screen height
	 */
    int	heightScreen;

	/**
	 * Is this object a physics body
	 */
	bool isPhyxBody;

	/**
	 * Is this object a dynamic physics body
	 */
	bool dynamic;
	
	/**
	 * Screen Offset in x-axis. Used for drawing the objects in the coordinate system of Box2D(Origin at (0,0))
	 */
	float offsetX;

	/**
	 * Screen Offset in x-axis. Used for drawing the objects in the coordinate system of Box2D(Origin at (0,0))
	 */
	float offsetY;

	/**
	 * Screen x-axis position of the texture/sprite, in pixels. 
	 */
 	float drawPositionX; 

	/**
	 * Screen x-axis position of the texture/sprite, in pixels
	 */
	float drawPositionY;

	/**
	 * x-axis scale of the texture
	 */
	float xDrawScale;

	/**
	 * y-axis scale of the texture
	 */
	float yDrawScale;

	/**
	 * x-axis collision scale
	 */
	float xCollisionScale;

	/**
	 * y-axis collision scale
	 */
	float yCollisionScale;

	/**
	 * The original width of the first texture
	 */
	float originalWidth;

	/**
	 * The original height of the first texture
	 */
	float originalHeight;

	/**
	 * the current angle of rotation of the object
	 */
	float32 angle;

	/**
	 * The point in the world where touch happened on this object. Note that an object can cover an area of more than one point.
	 */
	Vector2 touchPoint;


	/**
	 * An iterator for traversing the TextureHolder list
	 */
	list<TextureEntry *>::iterator textureIterator;

	/**
	 * The current texture of the object
	 */
	Texture* currentTexture;
	
	/**
	 * A list that stores all the textures/spritesheets of this object
	 */
	list<TextureEntry *> textureHolder;

	/**
	 * The current shape of the collider
	 */
	ColliderType colliderType;

public:

	float meterToPixel; //50 pixels to a meter

	/**
	 * The Object's Id
	 */
	//int objectId;

	/**
	 * Is this object active in the physics world. If not do not simulate physics
	 */
	bool isActive;

	/**
	 * The collision body or the collider of this object
	 */
	b2Body*	collisionBox;	

	/**
	 * The index value of the object's layer
	 */
	int layer;

	/**
	 * The current position of the object
	 */
	Vector2	position;

	/**
	 * Reference of the Engine class object
	 */
	Engine* engineRef;


	/**
	 * Is this Object Destroyed. Used to avoid rendering or updating an object that has been Destroyed.
	 */
	bool isDestroyed;

	/**
	 * Is Pointer Pressed on this object.
	 */
	//bool pointerPressed;

	/**
	 * If true, then the texture is rotated along with the collider. 
	 */
	bool rotateTextureWithPhysics;

	/**
	 * Default Constructor
	 */
	GameObject();

	/**
	 * Full GameObject: Creates a gameobject that has a default texture/spritesheet to start with 
	 * 
	 * @param		objectName			Unique Name or Identifier of this game object
	 * @param		engineRef			Reference of the Engine/Game class. Required for drawing the string to the screen
	 * @param		dynamic				is this object a dynamic physics body
	 * @param		physicsBody			is this object a physics body
	 * @param		&position			The on-screen position of the game object or text
	 * @param		textureName			Name of the texture file
	 * @param		isSprite			Is this texture a sprite
	 * @param		rows				No. of rows in sprite
	 * @param		columns				No.	of coloums in sprite
	 */
	GameObject(string objectName, Engine* engineRef, bool dynamic, bool physicsBody, Vector2 &position, string textureName, bool isSprite, int rows, int columns);

	/**
	 * Sets the Gravity offset for this game object
	 * @param		gravity			The offset value of this objects gravity
	 */
	void SetGravity(float gravity);	

	/**
	 * This function is called by the engine each frome on every gameobject alive in the game
	 *
	 * @param		m_d2dContext		A reference to the Direct2D device context, used by the engine to render the game object
	 */
	void Render(sf::RenderWindow* renderer);

	/**
	 * This is a virtual function that should be implemented by the GameObject sub-classes.
	 * The Update function of each active gameobject is called by the engine before the Render function
	 *
	 * @param		frameNumber		The value of the current frame
	 */
	virtual void Update(unsigned long frameNumber){}

	/**
	 * This is a virtual function that should be implemented by the GameObject sub-classes.
	 * The Start function of each gameobject is called by the engine immediately after the gameobject is created.
	 * Use this function to initialize your gameobjects and their members. Do NOT use the constructors of your sub-classes for initializing
	 * your game objects.
	 */
	virtual void Start() {}

	/**
	 * This is a virtual function that should be implemented by the GameObject sub-classes.
	 * The Engine calls the Collided function when it detects collision between this gameobject and another gameobject in the game
	 *
	 * @param		collisionObject			The game object that this object collided with
	 */
	virtual void BeginContact(GameObject* object){}

	/**
	 * This is a virtual function that should be implemented by the GameObject sub-classes.
	 * The Engine calls the Collided function when it detects collision between this gameobject and another gameobject in the game
	 *
	 * @param		collisionObject			The game object that this object collided with
	 */
	virtual void EndContact(GameObject* object){}

	/**
	 * This is a virtual function that should be implemented by the GameObject sub-classes
	 *
	 * @return		Name of the class
	 */
	virtual string GetType() { return "GameObject"; }

	/**
	 * This is called by the current level when an object receives a click input
	 *
	 * @param		point		The point in the world where the click event took place
	 */
	virtual void OnPointerPressed(Vector2 point){}

	/**
	 * Is called by the current level when this object receives Drag input or sometimes simply 
	 * when mouse is moved according to gameplay.
	 *
	 * @param		point		the current mouse point in the world, updated each frame until
	 */
	virtual void OnPointerMoved(Vector2 point){}

	/**
	 * Is called by the current level when this object receives input Click-Release.
	 *
	 * @param		point		the current point in the world where click was released.
	 */
	virtual void OnPointerReleased(Vector2 point){}

	/**
	 * Adds a force to the game object in x-axis and y-axis to the specified coordinate system.
	 *
	 * @param		x				force in x-axis
	 * @param		y				force in y-axis
	 * @param		rotCoords		Coordinates to add force to. Global or Local
	 */
	void AddForce (float x,float y, Coordinate rotCoords);

	/**
	 * Adds a force to the game object in x-axis and y-axis to the specified coordinate system.
	 *
	 * @param		direction		A Vector2 object that holds x,y values. Adds force in the x and y axis based on the x and y values of the Vector2 object	
	 * @param		rotCoords		Coordinates to add force to. Global or Local
	 */
	void AddForce(Vector2 direction, Coordinate rotCoords);

	/**
	 * Translates or moves the gameobject in the given direction of the specified coordinate system.
	 *
	 * @param		direction		The Direction or offset to move the object to. Ex: (2,3) -> moves the object 2 units on the x- axis and 3 units in the y-axis
	 * @param		rotCoords		Coordinates to translate the object in. Global or Local
	 */
	void Translate(Vector2 direction, Coordinate rotCoords);

	/**
	 * Translates or moves the gameobject in the given direction of the specified coordinate system.
	 * 
	 * @param		x						units in x-axis to translate/move the object 
	 * @param		y						units in y-axis to translate/move the object
	 * @param		rotCoords		Coordinates to translate the object in. Global or Local
	 */
	void Translate(float x,float y, Coordinate rotCoords);


	/**
	 * Sets the Position of the game object to the specified point in the game world
	 *
	 * @param		&Point		The point to set the game object's position to.
	 */
	void SetPosition(Vector2 &Point);

	/**
	 * Sets the Position of the game object to the specified point in the game world
	 *
	 * @param		x		The x-axis position to set the game object's position to.
	 * @param		y		The y-axis position to set the game object's position to.
	 */
	void SetPosition(float x,float y);

	/**
	 * Returns a Vector2 object containing the current velocity of the game object
	 *
	 * @return		The current velocity of the object
	 */
	Vector2 GetVelocity();

	/**
	 * Returns the normalized velocity as a float
	 *
	 * @return		The normalized value of the velocity vector
	 */
	float GetVelocitySize();

	/**
	 * Sets the objects linear velocity to (x,y)
	 *
	 * @param		x		x-axis velocity
	 * @param		y		y-axis velocity
	 */
	void SetVelocity(float x,float y);	

	/**
	 * This function returns the current angle of the game object in degrees
	 *
	 * @return Rotation angle of the game object
	 */
	float GetRotationAngle();

	/**
	 * Rotates the object by an angle offset specified in degrees. 
	 * Ex: If the angle already has a rotation of 25 degrees, and we call Rotate(90) on it, it add 90 degrees to the current rotation.
	 * So the object will know have a Rotation of 115 degrees
	 *
	 * @param		angle		angle offset to add to the current rotation.
	 */
	void Rotate(float angle);

	/**
	 * Sets the rotation of the object to the given angle. This function sets the rotation of the object to the specified rotaion
	 * irrespective of its previous rotation angle
	 *
	 * @param		angle		angle in degrees to set the object's rotaion to.
	 */
	void SetRotation(float angle);

	/**
	 * Fixes and unfixes the rotaion of the game object. 
	 * Fixing the rotation makes sure that physics does not effect the rotaion of the object.
	 * For example, colliding with some object, will not effect the rotation of this object if the rotation of this object is fixed.
	 * Note: You can still use the SetRotation and Rotate functions to manually modify the rotations of this object.
	 * 
	 * @param		newFix		true = fix rotation, false = un-fix rotation
	 */
	void FixRotation(bool newFix);

	/**
	 * Sets and unsets the physics body simulation of this object.
	 *
	 * @param		newPhyx		true = simulate physics, false = do not simulate physics
	 */
	void SetPhysicsBody(bool newPhyx);

	/**
	 * Sets the physics body to a dynamyc or static body
	 *
	 * @param		newDynamic		true = dynamic body, false = static body
	 */
	void SetDynamicBody(bool newDynamic);

	/**
	 * Gives your object a tag. This allows you to group different objects of the same type to different groups.
	 *
	 * @param		changeTo		The string value to set as the object's Tag
	 */
	void SetTag(string changeTo);

	/**
	 * Gives your object a unique identifier.
	 * Note: No two objects in your game can have the same name. If you give 2 or more objects the same name,
	 * the engine will append an integer to the end of the name. This will make it hard for you to access your objects
	 * using their names. Always try to give your objects unique names.
	 *
	 * @param		changeTo		The new string value to give to your object's Name
	 */
	void SetName(string changeTo);

	/**
	 * Returns the unique name of this object.
	 * @return		Name of the object
	 */
	string GetName();

	/**
	 * Returns the tag name of this object.
	 * @return		Tag of the object
	 */
	string GetTag();

	/**
	 * Sets the friction of the game object.
	 *
	 * @param		_Friction		The amount of friction to apply to this object
	 */
	void SetFriction(float friction);

	/**
	 * Sets a density to the game object
	 *
	 * @param		_Density		FThe amount of density to apply to this object
	 */
	void SetDensity(float density);

	/**
	 * Makes this physics body into a trigger. A trigger only logically collides with other objects, but not physically.
	 * This means that it allows the engine to call the Collided function on the gameobjects involved in a collision, but the
	 * objects themselves are not physycally effected by a collision.
	 *
	 * @param		_Trigger		true = makes the object a trigger, false = makes the object a normal physics body.
	 */
	void SetTrigger(bool trigger);

	/**
	 * Returns whether or not this object is a trigger
	 *
	 * @return		true if object is a trigger, false if object is not a trigger
	 */
	bool IsATrigger(){return collisionBox->GetFixtureList()->IsSensor();}

	/**
	 * Add a texture to the object's list of textures
	 *
	 * @param		textureName			Filename of the new texture to add
	 * @param		isSprite			is this texture an animated sprite
	 * @param		rows				How many Rows does this texture have
	 * @param		columns			How Many Columns does this texture have
	 */
	void AddTexture(string textureName, bool isSprite, int rows, int columns);	

	static void DeleteTexture(string textureName, int textureId);

	/**
	 * Sets the current texture of the object to the specified texture.
	 *
	 * @param		textureName		Filename of the texture to set
	 */
	void SetTexture(string textureName);

	/**
	 * Plays the animation of the current texture if it has any animation, that is if it is a sprite sheet
	 */
	void PlaySpriteTexture();

	/**
	 * Pauses animating the current sprite/texture
	 */
	void PauseSpriteTexture();

	/**
	 * Resumes playing the animation of the current sprite/texture
	 */
	void ResumeSpriteTexture();

	/**
	 * Sets the texture/spritesheet's frame to the default frame. i.e., the 0 frame
	 */
	void SetTextureFrame();

	/**
	 * Sets the texture/spritesheet's frame to the specified frame.
	 *
	 * @param		_FrameNumber		The frame to set the spritesheet/texture to.	
	 */
	void SetTextureFrame(int frameNumber);

	/**
	 * Sets the animation speed or frame rate of your sprite sheet.
	 *
	 * @param		_Speed		Speed of the animation
	 */
	void SetAnimationSpeed(float speed);

	/**
	 * Given the index of the current frame of the spritesheet.
	 *
	 * @return		The current frame
	 */
	int GetCurrentTextureFrame();

	/**
	 * Gets the name of the current texture/spritesheet
	 *
	 * @return		Name of the Current texture
	 */
	string GetTextureName();

	/**
	 * Returns whether or not the current texture's ani ation is playing or not
	 *
	 * @return		true = playing animation, false = not playing animation
	 */
	bool IsPlayingTexture();
	
	/**
	 * Compares the object's tag with the parameter.
	 *
	 * @param		TestTo		the string value to compare the tag with
	 * @return		true = match, false = no match
	 */
	bool CompareTag(string testAgainst);

	/**
	 * Compares the object's Name with the parameter.
	 *
	 * @param		TestTo		the string value to compare the Name with
	 * @return		true = match, false = no match
	 */
	bool CompareName(string testAgainst);

	/**
	 * Returns whether this object is a dynamic body or not.
	 *
	 * @return		true = dynamic body, false = static body
	 */
	bool IsDynamic(){return dynamic;}

	/**
	 * Returns whether or not this object is a physics body or not
	 *
	 * @return		true = is a physics body, false = is not a physics body.
	 */
	bool IsPhysicsBody(){return isPhyxBody;}

	/**
	 * Returns the layer for the specified index
	 *
	 * @param		layer		Index of the layer to get.
	 * @return		The layer at index mentioned
	 */
	Layer* GetLayer(int layer);

	/**
	 * Gets the layer in which this object is in
	 *
	 * @return		The layer of this object
	 */
	Layer* GetMyLayer();

	/**
	 * Destroys the object
	 */
	void Destroy();

	/**
	 * Called after the Destroy gets executed. Releases any memory resources this object uses.
	 */
	void OnDestroy();


	/**
	 * Applies a damping value to the  velocity of the object
	 */
	void SetDamping(float damping);

	/**
	 * Applies a damping value to the  velocity of the object
	 */
	void SetAngularDamping(float damping);

	Texture* GetCurrentTexture(){return currentTexture;}
};
