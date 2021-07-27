#pragma once
class InputListener
{
public:
	InputListener()
	{

	}
	~InputListener()
	{

	}

	//KEYBOARD PURE VIRTUAL CALLBACK FUNCTIONS
	virtual void onKeyDown(int key) = 0; 
	virtual void onKeyUp(int key) = 0; 


};

