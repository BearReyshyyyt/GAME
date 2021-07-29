#pragma once
#include <Windows.h>

class Window
{
public:
	Window();
	// initialize window
	bool init();
	bool broadcast();
	// release the window
	bool release();
	bool isRun();

	RECT getClientWindowRect();
	void setHWND(HWND hwnd);

	//Events
	virtual void onCreate();
	virtual void onUpdate(); 
	virtual void onDestroy();
	virtual void onFocus();
	virtual void onKillFocus();


	~Window(); 
protected:
	HWND m_hwnd;
	bool m_is_run;
};

