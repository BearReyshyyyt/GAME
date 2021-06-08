#include <iostream>
#include "GraphicsEngine.h"
#include "SwapChain.h"

GraphicsEngine::GraphicsEngine()
{
}

bool GraphicsEngine::init()
{
	// array of drivers
	D3D_DRIVER_TYPE driver_types[]=
	{
		 D3D_DRIVER_TYPE_HARDWARE,
		 D3D_DRIVER_TYPE_WARP,
		 D3D_DRIVER_TYPE_REFERENCE
	};
	// the langth of the driver array
	UINT num_driver_types = ARRAYSIZE(driver_types);

	D3D_FEATURE_LEVEL feature_levels[] =
	{
		D3D_FEATURE_LEVEL_11_0
	};
			
	UINT num_feature_levels = ARRAYSIZE(feature_levels);

	// initialize the result of the driver result to 0 so if not found we can detect it
	HRESULT res = 0;

	// a loop to loop through the drivers
	for (UINT driver_type_index = 0; driver_type_index < num_driver_types;) {
		
		// each time look for a matching driver
		res = D3D11CreateDevice(NULL, driver_types[driver_type_index], NULL, NULL, feature_levels,
			num_feature_levels, D3D11_SDK_VERSION, &m_d3d_device, &m_feature_level, &m_imm_context);

		// if we find a match immediately stop since we found the best one possible
		if (SUCCEEDED(res)) {
			break;
		}
		// check next driver
		std::cout << "checking next driver" << std::endl;
			++driver_type_index;
	}

	// if no match was found then return false
	if (FAILED(res)) {
		std::cout << "this happened" << std::endl;
		return false;
	}


	m_d3d_device->QueryInterface(__uuidof(IDXGIDevice), (void**)&m_dxgi_device);
	m_dxgi_device->GetParent(__uuidof(IDXGIAdapter), (void**)&m_dxgi_adapter);
	m_dxgi_adapter->GetParent(__uuidof(IDXGIFactory), (void**)&m_dxgi_factory);
	
	return true;
}


bool GraphicsEngine::release()
{ 
	m_dxgi_device->Release();
	m_dxgi_adapter->Release();
	m_dxgi_factory->Release();

	m_imm_context->Release();
	m_d3d_device->Release(); 
	return true;
}

GraphicsEngine::~GraphicsEngine()
{
}

SwapChain * GraphicsEngine::createSwapChain()
{
	return new SwapChain();
}


GraphicsEngine * GraphicsEngine::get()
{
	static GraphicsEngine engine;
	return &engine;
}
