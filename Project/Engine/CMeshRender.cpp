#include "pch.h"
#include "CMeshRender.h"

#include "CTransform.h"

CMeshRender::CMeshRender()
	: CComponent(COMPONENT_TYPE::MESHRENDER)
	, m_pMesh(nullptr)
	, m_pMtrl(nullptr)
{
}

CMeshRender::~CMeshRender()
{
}

void CMeshRender::finaltick()
{
}

void CMeshRender::render()
{
	// 메쉬나 메터리얼을 지정안했다면 출력 X
	if (nullptr == m_pMesh || nullptr == m_pMtrl)
		return;

	// Transform 에 UpdateData 요청 (위치값 레지스터b0에 세팅하라고 요청)
	Transform()->UpdateData();

	m_pMtrl->UpdateData();		// Material 값 바인딩
	m_pMesh->render();			// 출력할 메쉬정하고 출력


}
