#pragma once
#include "CScript.h"

class CPlayerScript :
    public CScript
{
private:
    float   m_fSpeed;

public:
    virtual void tick() override;

    

    CLONE(CPlayerScript);
public:
    CPlayerScript();
    ~CPlayerScript();
};

