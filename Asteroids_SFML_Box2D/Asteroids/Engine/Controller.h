#pragma once
#include "Engine.h"
#include <string>

using namespace std;

class Engine;
class GameObject;

/**
 * The controller class listens to all the input events and calls the relevant delegate functions in response to those inputs.
 */
class Controller
{
    Controller();

	/** 
	 * Initializes the controls supported by this controller.
	 * Sets up the event listeners for inputs.
	 *
	 * @param		window			A reference to the main application window
	 * @param		newMain			A reference to the gam's Engine class
	 */
    //void Initialize(_In_ Windows::UI::Core::CoreWindow^ window, Engine* newMain);

protected:
	/**
	 * Fired when a pointer press, 'Tap'/'Click', event occurs
	 *
	 * @param		sender			Object that fired the event
	 * @param		args			Type of event
	 */
	//void OnPointerPressed(_In_ Windows::UI::Core::CoreWindow^ sender,_In_ Windows::UI::Core::PointerEventArgs^ args);

	/**
	 * Fired when a pointer released, 'UnTap'/'Click-released', event occurs
	 *
	 * @param		sender			Object that fired the event
	 * @param		args			Type of event
	 */
	//void OnPointerReleased( _In_ Windows::UI::Core::CoreWindow^ sender,_In_ Windows::UI::Core::PointerEventArgs^ args);

	/**
	 * Fired when a pointer moved, ' Tap and Drag'/'Click and Drag', event occurs
	 *
	 * @param		sender			Object that fired the event
	 * @param		args			Type of event
	 */
	//void OnPointerMoved( _In_ Windows::UI::Core::CoreWindow^ sender,_In_ Windows::UI::Core::PointerEventArgs^ args);

#ifdef MOVELOOKCONTROLLER_TRACE
    void DebugTrace(const wchar_t *format, ...);
#endif

private:
    void     ResetState();
    void     UpdateGameController();

	/** A reference to the game's Engine class */
	Engine*    main;
	/** A flag variable that indicates whether the pointer is pressed or not */
	bool			m_PointerPress;
	GameObject*		m_PressedObject;
};
//----------------------------------------------------------------------
