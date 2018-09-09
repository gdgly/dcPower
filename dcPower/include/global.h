#ifndef		__GLOBAL_VARIABLES_
#define		__GLOBAL_VARIABLES_

#if USE_GRAPH
int graphCount=0;
int y1_data[GRAPH_NUMBER];
int y2_data[GRAPH_NUMBER];
#endif

char monitOut1[30];
char monitOut2[30];
char monitOut3[30];
char monitOut4[30];

float under_volt_set;
float nativeI_out;
float nativeI_pri;
//--- PI control
float ctrlError;
float ctrlIntegral;
float preIntegral;
float phaseShiftRatio;

int code_run_input_select;
float OC_Timer;
float ovpTimer;

float nativeIout;
float nativeIpri;
float nativeVout;
float nativeVdc;

float Pout;
float Ipri;
float Iout;
float Vout;

int adcIpri;
int adcIout;
int adcVout;
int adcVdc;

float monitor[5]={0.0};
int debug_count;
int test_pulse_count;

unsigned int igbt_fault_input;
unsigned int digital_input;

int timer0_count;

unsigned int debug1;
int init_charge_flag = 0;

int scib_rx_msg_flag = 0;
int scic_rx_msg_flag = 0;

float analog_ref_a;
float analog_ref_b;
//---
float * dac_point[200];
float dac_ch0_unit_count_value;
float dac_ch1_unit_count_value;
float dac_ch2_unit_count_value;
float dac_ch3_unit_count_value;

float	inv_code_dac_scale_ch1;
float	inv_code_dac_scale_ch2;
float	inv_code_dac_scale_ch3;
float	inv_code_dac_scale_ch4;
//===================

int dayRun ;
int hourRun ;
int secRun;

float phaseVref;
float VdcScale;
float VdcOffset;
float VoutScale;
float VoutOffset;

float ref_time;
CODE_INFO code_inform = {0,0,0,0,0,0,{0}};

union PROTECT_FLAG protect_reg;

int terminal_input_state;

// PWM
float	DutyRatio[3];
Uint16 DutyCount[3];

float	Ts;
float	inv_Ts;
float 	gfRunTime=0;
int timer0_count;
float	Vdc=0.0;
float	Vs_max=0.0;

float refer_in0;
float	reference_in=0.0;
float	reference_out=0.0;
//--- Sci.c
char gStr1[50] = {0};
char gStr2[10] = {0};
int gSciInFlag;
char gSciaRxBuf[SCIA_RX_BUF_MAX+1];
char gSciaTxBuf[SCIA_TX_BUF_MAX+1];
int gMachineState=0;
int	gPWMTripCode;
int adc_result[4]={0};
int	giAdcVdc	;
TRIP_INFO TripInfo = {0,0,0,0,0," No Trip Data       "};
TRIP_INFO TripInfoNow = {0,0,0,0,0," No Trip Data       "};

int gTripFlag = 0;
Uint16	MAX_PWM_CNT;

char MonitorMsg[30]={0};

int gRunFlag=0;
int gTripSaveFlag=0;
int EepromSaveFlag = 0;
int Flag_TripDataBackup = 0;
float OverCurLimit;

float codeVdcOffset;
float codeVdcSpan;
float codeVoutOffset;
float codeVoutSpan;

float code_Ki;
float code_Kp;
float code_integLimit;
float code_phaseMax;

float codeVdcOffset;
float codeVdcSpan;
float codeVoutOffset;
float codeVoutSpan;

float code_adc_vdc_low;
float code_adc_vdc_high;
float code_Vdc_calc_low;
float code_Vdc_calc_high;

float code_adc_Vout_low;
float code_adc_Vout_high;
float code_Vout_calc_low;
float code_Vout_calc_high;

int code_protect_uv_off = 0;
int code_protect_ov_off = 0;
int code_protect_Iadc_off = 0;
int code_protect_over_I_off = 0;
int code_protect_IGBT_off =0;
int code_protect_ex_trip_off=0;

//============================================
//   CODE variable 
//============================================
float code_I_out_ref;        // 0
float code_Vout;             // 1
float code_VoutLimit;        // 2
float code_ovpTime;          // 3
float codeOcTime;            // 4
float codePwmPhaseInit;      // 5
float codeInitTime;          // 6

float code_ctrl_mode;        // 10
float codeSetPulseNumber;    // 11
float code_testPwmPhase;     // 12
float code_set_Vdc_on;       // 13
float codeIoutAdcOffset;     // 14
float codeIpriAdcOffset;     // 15
float codeIoutScale;         // 16
float codeIpriScale;         // 17
float code_protect_inhibit_on;   // 18

float Data_Check;				// 800
float Data_Backup;				// 801
float Data_Load;				// 802
float Data_Init;				// 803
//=====================================================
#endif

