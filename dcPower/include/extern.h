#ifndef		__VARIABLES_
#define		__VARIABLES_

extern int ctrlMode;
extern double dbTs;
extern double ctrlKp;
extern double ctrlKi;

extern int dayRun;
extern int hourRun;
extern int secRun;

#if USE_GRAPH
extern int graphCount;
extern int y1_data[GRAPH_NUMBER];
extern int y2_data[GRAPH_NUMBER];
#endif

// extern char monitOut[61];

extern char monitOut1[30];
extern char monitOut2[30];
extern char monitOut3[30];
extern char monitOut4[30];

extern float nativeI_out;
extern float nativeI_pri;
extern float nativeI2nd;
extern float nativeI3rd;

//--- PI control variable
extern double ctrlError;
extern double ctrlIntegral;
extern double preIntegral;
extern double phaseShiftRatio;

extern int code_run_input_select;

extern int adcIpri;
extern int adcIout;
extern int adcVout;
extern int adcVdc;

extern float nativeIout;
extern float nativeIpri;
extern float nativeVout;
extern float nativeVdc;

extern float Pout;
extern float Ipri;
extern float Iout;
extern float Vout;

extern float OC_Timer;
extern float ovpTimer;		// 2014.1016

extern float monitor[5];
extern int debug_count;
extern int test_pulse_count;

extern int convert_state;
extern unsigned int igbt_fault_input;
extern unsigned int digital_input;

extern unsigned int DIGITAL_INPUT_START;
extern float  DCLINK_LIMIT;
extern float  UNDER_DC_LINK_LIMIT;

extern int timer0_count;

// hjkim
//'all pass Filter

//''''''''''''''''''''''''''
#define  DF(x_in, x_in1, x_in2, y_out, y_out1, y_out2, b1, b2, a0, a1, a2) \
            (y_out) = - (b1)*(y_out1) - (b2)*(y_out2) + (a0)*(x_in) + (a1)*(x_in1) + (a2)*(x_in2); \
            (y_out2) = (y_out1); \
            (y_out1) = (y_out); \
            (x_in2) = (x_in1); \
            (x_in1) = (x_in)

extern unsigned int Fault_Code;

extern int init_charge_flag;
extern float lpfIoutIn[3], lpfIoutOut[3],lpfIoutK[4];
extern float lpfVoutIn[3], lpfVoutOut[3],lpfVoutK[4];
extern float lpfVdcIn[3],  lpfVdcOut[3], lpfVdcK[4];

extern unsigned int Fault_Code;
extern float * dac_point[200];

extern int scib_rx_msg_flag;
extern int scic_rx_msg_flag;

extern float analog_ref_a;
extern float analog_ref_b;

extern float phaseVref;
extern float VdcScale;
extern float VdcOffset;

extern float VoutScale;
extern float VoutOffset;

extern float ref_time;	// 2009.10.28

extern CODE_INFO code_inform;
extern union PROTECT_FLAG protect_reg;
extern char TripMessage[25];
// PWM
extern float	DutyRatio[3];
extern Uint16 DutyCount[3];
extern float 	gfRunTime;
extern float	Ts;
extern float	inv_Ts;
extern int timer0_count;
// Ref.
extern float   refer_in0;
extern float	reference_in;
extern float	reference_out;
extern float	Vdc;
// Sci.c
extern char gStr1[50];
extern char gStr2[10];
extern int gSciInFlag;
extern int scia_rx_msg_flag;
extern char gSciaRxBuf[SCIA_RX_BUF_MAX+1];
extern char gSciaTxBuf[SCIA_TX_BUF_MAX+1];

extern int gMachineState;
extern int	gPWMTripCode;
extern int adc_result[4];
extern int giAdcVdc	;

extern TRIP_INFO TripInfo;
extern TRIP_INFO TripInfoNow;

extern int gTripFlag;
extern Uint16	MAX_PWM_CNT;
extern char MonitorMsg[30];
extern int gRunFlag;
extern int gTripSaveFlag;
extern float OverCurLimit;
extern int EepromSaveFlag;
extern int Flag_TripDataBackup;

extern float	inv_code_dac_scale_ch1;
extern float	inv_code_dac_scale_ch2;
extern float	inv_code_dac_scale_ch3;
extern float	inv_code_dac_scale_ch4;

extern float code_adc_vdc_low;          // 710
extern float code_adc_vdc_high;     // 711
extern float code_Vdc_calc_low;     // 712
extern float code_Vdc_calc_high;        // 713

extern float code_adc_Vout_low;     // 715
extern float code_adc_Vout_high;        // 716
extern float code_Vout_calc_low;        // 717
extern float code_Vout_calc_high;       // 718

extern float codeVdcOffset;         // 410
extern float codeVdcSpan;               // 411
extern float codeVoutOffset;            // 412
extern float codeVoutSpan;          // 413
//============================================
//   CODE variable 
//============================================
extern float code_I_out_ref;	    // 0
extern float code_Vout;             // 1
extern float code_VoutLimit;	    // 2
extern float code_ovpTime;		    // 3
extern float codeOcTime;           // 4
extern float codePwmPhaseInit;	    // 5
extern float codeInitTime;		    // 6

extern float code_ctrl_mode;        // 10
extern float codeSetPulseNumber;	// 11
extern float code_testPwmPhase;		// 12
extern float code_set_Vdc_on;       // 13
extern float codeIoutAdcOffset;     // 14
extern float codeIpriAdcOffset;     // 15
extern float codeIoutScale;         // 16
extern float codeIpriScale;         // 17
extern float code_protect_inhibit_on;   // 18

extern float Is_Max_Coeff;				// 206
extern float code_OC_time;				// 207

///////////////////////////


extern float code_Ki;					// 510
extern float code_Kp;					// 511
extern float code_integLimit;			// 512
extern float code_phaseMax;			// 513


extern float Data_Check;				// 800
extern float Data_Backup;				// 801
extern float Data_Load;				// 802
extern float Data_Init;				// 803
//***********************************************************
#endif

