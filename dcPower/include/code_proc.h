#ifndef		__CODE_PROC_H_
#define		__CODE_PROC_H_	

#define TYPE_INTEGER        0
#define TYPE_float          1

// #define SWITCH_FREQ			2500	// 090920
// #define SWITCH_FREQ			1750	// 090920

#define CODE_I_out_ref					0
#define CODE_Vout						1
#define CODE_VoutLimit					2
#define CODE_ovpTime                    3
#define CODE_OC_Time                    4
#define CODE_PwmPhaseInit				5
#define CODE_InitTime					6

#define CODE_ctrl_mode					10
#define CODE_SetPulseNumber				11
#define CODE_testPwmPhase				12
#define CODE_set_Vdc_on					13
#define CODE_IoutAdcOffset              14
#define CODE_IpriAdcOffset              15
#define CODE_IoutScale                  16
#define CODE_IpriScale                  17
#define CODE_protect_inhibit_on         18

#define CODE_graphPoint1              21
#define CODE_graphScale1              22
#define CODE_graphOffset1             23

#define CODE_graphPoint2              26
#define CODE_graphScale2              27
#define CODE_graphOffset2             28

#define CODE_graphPoint3              31
#define CODE_graphScale3              32
#define CODE_graphOffset3             33

#define CODE_graphPoint4              36
#define CODE_graphScale4              37
#define CODE_graphOffset4             38

#define CODE_VdcAdcLow                  41
#define CODE_VdcAdcHigh                 42
#define CODE_VdcCalcLow                 43
#define CODE_VdcCalcHigh                44

#define CODE_VoutAdcLow                  46
#define CODE_VoutAdcHigh                 47
#define CODE_VoutCalcLow                 48
#define CODE_VoutCalcHigh                49

#define CODE_END                        50

#define CODE_Data_Check                     800
#define CODE_Data_Backup                    801
#define CODE_Data_Load                      802
#define CODE_Data_Init                      803
#define CODE_get_adc_offset                 804
#define CODE_get_adc_vdc_low                805
#define CODE_get_adc_vdc_high               806
//--- end of code address


struct CODE_INFO_DEFINE {
	int		type;	
	int	  	open_level	;
	double	code_min ;
	double	code_max ;
	double 	code_default;
	double	code_value;
	char   disp[40];
};
typedef struct CODE_INFO_DEFINE CODE_INFO;
#endif
