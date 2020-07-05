#include	<header.h>
#include	<extern.h>

/* current */
#define SCOPE_Iout          0
#define SCOPE_Ipri          1
#define SCOPE_Vdc           2
#define SCOPE_Vout          3
#define SCOPE_Power         4

/* voltage */
#define SCOPE_AdcIout      5
#define SCOPE_AdcIpri      6
#define SCOPE_AdcVdc       7
#define SCOPE_AdcVout      8

void setScopePoint()
{
    scopePoint[SCOPE_Iout]    = &Iout;
    scopePoint[SCOPE_Ipri]    = &Ipri;
    scopePoint[SCOPE_Vdc]     = &Vdc;
    scopePoint[SCOPE_Vout]    = &Vout;
    scopePoint[SCOPE_Power]   = &Pout;

    scopePoint[SCOPE_AdcIout] = &dAdcIout;
    scopePoint[SCOPE_AdcIpri] = &dAdcIpri;
    scopePoint[SCOPE_AdcVdc]  = &dAdcVdc;
    scopePoint[SCOPE_AdcVout] = &dAdcVout;
}

//--- end of file
