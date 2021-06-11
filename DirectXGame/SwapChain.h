#pragma once
#pragma once
#include <d3d11.h>

class DeviceContext;

class SwapChain
{
public:
	SwapChain();
	//Initialization of SwapChain for a window
	bool init(HWND hwnd, UINT width, UINT height);
	bool present(bool vsync);
	//Release of the SwapChain
	bool release();
	~SwapChain();
private:
	IDXGISwapChain* m_swap_chain;
	ID3D11RenderTargetView * m_rtv;
private:
	friend class DeviceContext;
};

