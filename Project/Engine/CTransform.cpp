#include "pch.h"
#include "CTransform.h"


CTransform::CTransform()
	: CComponent(COMPONENT_TYPE::TRANSFORM)
{
}

CTransform::~CTransform()
{
}

void CTransform::finaltick()
{

}

void CTransform::UpdateData()
{
	// 트랜스폼 바인딩 함수에서 하는일
	// 렌더링하기전에 본인의 좌표를 상수 버퍼에 저장.
}
