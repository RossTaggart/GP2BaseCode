#pragma once

//The header file for the renderer interface
#include "../Renderer/Renderer.h"
#include <D3D10.h>
#include <D3DX10.h>
#include <Windows.h>



//#include <xnamath.h>

//D3D10Renderer implements the Renderer interface
class D3D10Renderer:public IRenderer
{
public:
	D3D10Renderer();
	~D3D10Renderer();
	//notice these have the same signature as the pure methods
	//in the interface
	bool init(void *pWindowHandle,bool fullScreen);
	void clear(float r,float g,float b,float a);
	void present();
	void render();
private:
	bool createDevice(HWND pWindowHandle,int windowWidth, int windowHeight,
bool fullScreen);
	bool createInitialRenderTarget(int windowWidth, int windowHeight);

	//temp for the exercise
	bool loadEffectFromMemory(const char *pMem);
	bool loadEffectFromFile(const char *pFilename);
	bool createBuffer();
	bool creatVertexLayout();
private:
	//D3D10 stuff
	ID3D10Device * m_pD3D10Device;
	IDXGISwapChain * m_pSwapChain;
	ID3D10RenderTargetView * m_pRenderTargetView;
	ID3D10DepthStencilView * m_pDepthStencelView;
	ID3D10Texture2D *m_pDepthStencilTexture;

	//for the exercise
	//Effect
	ID3D10Effect * m_pTempEffect;
	ID3D10EffectTechnique*  m_pTempTechnique;

	//Buffer
	ID3D10Buffer * m_pTempBuffer;

	//Vertex Layout
	ID3D10InputLayout*      m_pTempVertexLayout;

	//Variables for Camera
	//XMMATRIX  m_World;
	//XMMATRIX  m_View;
	//XMMATRIX  m_Projection;

};