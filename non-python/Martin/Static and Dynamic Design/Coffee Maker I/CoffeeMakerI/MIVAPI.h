// MIVAPI.h: interface for the MIVAPI class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MIVAPI_H__0A683ACD_1E56_11D3_8F7D_00E09802EAB8__INCLUDED_)
#define AFX_MIVAPI_H__0A683ACD_1E56_11D3_8F7D_00E09802EAB8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


namespace com_cmindustries_m4_api
{
    class API;
};

class com_cmindustries_m4_api::API  
{
public:
	API();
	virtual ~API();

    enum WarmerPlateStatus {potNotEmpty, potEmpty, warmerEmpty};
    enum BoilerStatus      {boilerEmpty, boilerNotEmpty};
    enum BrewButtonStatus  {brewButtonPushed, brewButtonNotPushed};
    enum BoilerHeaterState {boilerOn, boilerOff};
    enum WarmerState       {warmerOn, warmerOff};
    enum IndicatorState    {indicatorOn, indicatorOff};
    enum ReliefValveState  {valveOpen, valveClosed};

    virtual WarmerPlateStatus GetWarmerPlateStatus() const = 0;
    virtual BoilerStatus      GetBoilerStatus() const = 0;
    virtual BrewButtonStatus  GetBrewButtonStatus() const = 0;

    virtual void SetBoilerState(BoilerHeaterState) = 0;
    virtual void SetWarmerState(WarmerState) = 0;
    virtual void SetIndicatorState(IndicatorState) = 0;
    virtual void SetReliefValveState(ReliefValveState) = 0;
};

#endif // !defined(AFX_MIVAPI_H__0A683ACD_1E56_11D3_8F7D_00E09802EAB8__INCLUDED_)
