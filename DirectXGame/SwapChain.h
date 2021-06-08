#pragma once
#pragma once
#include <d3d11.h>

class SwapChain
{
public:
	SwapChain();
	//Initialization of SwapChain for a window
	bool init(HWND hwnd, UINT width, UINT height);
	//Release of the SwapChain
	bool release();
	~SwapChain();
private:
	IDXGISwapChain* m_swap_chain;
};

