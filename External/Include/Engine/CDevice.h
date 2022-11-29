#pragma once
class CDevice
	: public CSingleton<CDevice>
{
private:
	HWND					m_hWnd;

	ID3D11Device*			m_Device;	// GPU �޸� �Ҵ�
	ID3D11DeviceContext*	m_Context;	// GPU ����, ������, ���� ����

	IDXGISwapChain*			m_SwapChain;

	ID3D11Texture2D*		m_RTTex;
	ID3D11RenderTargetView* m_RTV;

	ID3D11Texture2D*		m_DSTex;
	ID3D11DepthStencilView* m_DSV;

	D3D11_VIEWPORT			m_ViewPort;

public:
	int Init(HWND _hWnd);

public:
	CDevice();
	~CDevice();
};
