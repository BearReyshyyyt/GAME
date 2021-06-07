#pragma once
#include <d3d11.h>

class GraphicsEngine
{
public:
	GraphicsEngine();
	// Initailize the Graphics engine and 
	bool init();
	// release all the resouces loaded
	bool release();
	~GraphicsEngine();
public:
	static GraphicsEngine* get();

private:
	ID3D11Device* m_d3d_device; 
	D3D_FEATURE_LEVEL m_feature_level;
	ID3D11DeviceContext* m_imm_context;
};

