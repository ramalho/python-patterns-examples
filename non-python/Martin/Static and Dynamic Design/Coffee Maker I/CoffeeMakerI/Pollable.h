// Pollable.h: interface for the Pollable class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_POLLABLE_H__1F22E3A0_1F19_11D3_8F7D_00E09802EAB8__INCLUDED_)
#define AFX_POLLABLE_H__1F22E3A0_1F19_11D3_8F7D_00E09802EAB8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

namespace com_cmindustries_pollable
{
    class Pollable;
};

class com_cmindustries_pollable::Pollable  
{
public:
	Pollable();
	virtual ~Pollable();

    virtual void Init() = 0;
    virtual void Poll() = 0;

};

#endif // !defined(AFX_POLLABLE_H__1F22E3A0_1F19_11D3_8F7D_00E09802EAB8__INCLUDED_)
