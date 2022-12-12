#include "pch.h"
#include "CLevelMgr.h"

#include "CLevel.h"
#include "CLayer.h"
#include "CGameObject.h"
#include "CTransform.h"
#include "CMeshRender.h"
#include "CPlayerScript.h"

#include "CResMgr.h"

CLevelMgr::CLevelMgr()
	: m_pCurLevel(nullptr)
{
}

CLevelMgr::~CLevelMgr()
{
	if (nullptr != m_pCurLevel)
		delete m_pCurLevel;
}

void CLevelMgr::init()
{
	m_pCurLevel = new CLevel;

	// ������Ʈ ����
	CGameObject* pObj = new CGameObject;
	pObj->AddComponent(new CTransform);	// ��ġ��� ������Ʈ
	pObj->AddComponent(new CMeshRender);	// �׸��� ��� ������Ʈ
	pObj->AddComponent(new CPlayerScript);	// �÷��̾� ��ũ��Ʈ ������Ʈ

	// ���ҽ� �Ŵ������� �޽�, ���̴��� ã�ƿͼ� �־��ش�.
	Ptr<CMesh> RectMesh = CResMgr::GetInst()->FindRes<CMesh>(L"RectMesh");
	Ptr<CGraphicsShader> TestShader = CResMgr::GetInst()->FindRes<CGraphicsShader>(L"TestShader");

	pObj->MeshRender()->SetMesh(RectMesh);
	pObj->MeshRender()->SetShader(TestShader);

	m_pCurLevel->AddGameObject(pObj, 0);

	// ������Ʈ2 ����
	pObj = new CGameObject;
	pObj->AddComponent(new CTransform);	// ��ġ��� ������Ʈ
	pObj->AddComponent(new CMeshRender);	// �׸��� ��� ������Ʈ

	pObj->MeshRender()->SetMesh(RectMesh);
	pObj->MeshRender()->SetShader(TestShader);

	m_pCurLevel->AddGameObject(pObj, 1);
}

void CLevelMgr::tick()
{
	m_pCurLevel->tick();
	m_pCurLevel->finaltick();
}

void CLevelMgr::render()
{
	m_pCurLevel->render();
}