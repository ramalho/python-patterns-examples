#ifndef GUID_A0346CE1_2AD4_11d3_8F7E_00E09802EAB8
#define GUID_A0346CE1_2AD4_11d3_8F7E_00E09802EAB8


// CofeeMaker
// Context class for the Coffee Maker Finite State Machine.
//

namespace com_cmindustries_coffeeMakerFSM
{
    class CoffeeMaker;
};

class com_cmindustries_coffeeMakerFSM::CoffeeMaker
{
public:
    virtual ~CoffeeMaker() {}

    // Action functions.
    virtual void HwsStart() = 0;
    virtual void VessStart() = 0;
    virtual void UiDone() = 0;
    virtual void HwsDone() = 0;
    virtual void VessDone() = 0;
    virtual void UiComplete() = 0;
    virtual void HwsComplete() = 0;
    virtual void VessComplete() = 0;
    virtual void HwsPause() = 0;
    virtual void HwsResume() = 0;

    // utility functions
    virtual void FSMError(const char*, const char*) = 0;
};

#endif // GUID_A0346CE1_2AD4_11d3_8F7E_00E09802EAB8