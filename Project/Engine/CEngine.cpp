#include "pch.h"
#include "CEngine.h"

CEngine::CEngine()
	: m_hWnd(nullptr)
{
}

CEngine::~CEngine()
{
}


void CEngine::Init(HWND _hWnd, UINT _iWidth, UINT _iHeight)
{
	// ���� ������ �ڵ�
	m_hWnd = _hWnd;

	// �ػ󵵿� �´� �۾����� ũ�� ����
	RECT rt = { 0, 0, (int)_iWidth, (int)_iHeight};
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, false);
	SetWindowPos(m_hWnd, nullptr, 10, 10, rt.right - rt.left, rt.bottom - rt.top, 0);
	ShowWindow(m_hWnd, true);

}

void CEngine::progress()
{
}
