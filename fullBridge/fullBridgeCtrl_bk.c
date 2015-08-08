#include	<header.h>
#include	<extern.h>

void epwmFullBridgeEnable()
{
	EALLOW;
	GpioCtrlRegs.GPAMUX1.bit.GPIO0 	= 1;  			// GPIO0	= PWM1A
	GpioCtrlRegs.GPAMUX1.bit.GPIO1 	= 1;  			// GPIO1	= PWM1B
	GpioCtrlRegs.GPAMUX1.bit.GPIO2 	= 1;  			// GPIO2	= PWM2A
	GpioCtrlRegs.GPAMUX1.bit.GPIO3 	= 1;  			// GPIO3	= PWM2B
    EDIS;
}

void epwmFullBridgeDisable()
{
	MAIN_CHARGE_OFF;
	
	EALLOW;
	GpioCtrlRegs.GPAMUX1.bit.GPIO0 	= 0;  // GPIO0 = PWM1A
	GpioCtrlRegs.GPAMUX1.bit.GPIO1 	= 0;  // GPIO1 = PWM1B
	GpioCtrlRegs.GPAMUX1.bit.GPIO2 	= 0;  // GPIO2 = PWM2A
	GpioCtrlRegs.GPAMUX1.bit.GPIO3 	= 0;  // GPIO3 = PWM2B

	GpioDataRegs.GPACLEAR.bit.GPIO0	= 1;  // Set Output
	GpioDataRegs.GPACLEAR.bit.GPIO1	= 1;  // Set Output
	GpioDataRegs.GPACLEAR.bit.GPIO2	= 1;  // Set Output
	GpioDataRegs.GPACLEAR.bit.GPIO3	= 1;  // Set Output
    EDIS;
}

//#define   wn           728.377000097732126420268483356
//#define zeta         0.70710678118654752440084436210485

void initVariFullbridgeCtrl( )
{
	double x1,x2,y1,y2;
    
	Ts = 1.0 / codeSwitFreq;

// for Vdc calc 
	x1 = code_adc_vdc_low;		y1 = code_Vdc_calc_low;
	x2 = code_adc_vdc_high;		y2 = code_Vdc_calc_high;
	VdcScale = ( y2-y1) / ( x2 - x1 );
	VdcOffset = (( y1 * x2 - y2 * x1 )/ (x2- x1));

// for Vout calc 
	x1 = code_adc_Vout_low;		y1 = code_Vout_calc_low;
	x2 = code_adc_Vout_high;	y2 = code_Vout_calc_high;
	VoutScale = ( y2-y1) / ( x2 - x1 );
	VoutOffset = (( y1 * x2 - y2 * x1 )/ (x2- x1));

//--- DAC out

	inv_code_dac_scale_ch1 = 1.0 / code_dac_scale_ch1;
	inv_code_dac_scale_ch2 = 1.0 / code_dac_scale_ch2;
	inv_code_dac_scale_ch3 = 1.0 / code_dac_scale_ch3;
	inv_code_dac_scale_ch4 = 1.0 / code_dac_scale_ch4;

	// �ð� �� �ε���
	gfRunTime=0.0;

	// reference
	reference_in=0.0;
	reference_out=0.0;	// new
	OC_Timer = 0;
	OverCurLimit = code_I_out_ref * 1.2;
}	

#define DEAD_TIME_COUNT			800			// dead time 150Mhz 6usec
//#define DEAD_TIME_COUNT			640			// dead time 150Mhz 4usec
//#define DEAD_TIME_COUNT			480			// dead time 150Mhz 3usec
//#define DEAD_TIME_COUNT			320			// dead time 150Mhz 2usec
//#define DEAD_TIME_COUNT			160			// dead time 150Mhz 1usec

void initEpwmFullBridge()
{  
	EPwm1Regs.ETSEL.bit.INTEN = 0;    		        // Enable INT
	MAX_PWM_CNT = (Uint16)( ( F_OSC * DSP28_PLLCR / codeSwitFreq ) * 0.5 * 0.5);

	EPwm1Regs.TBPRD =  MAX_PWM_CNT;			// Set timer period
	EPwm1Regs.TBPHS.half.TBPHS = 0x0000;           	// Phase is 0
	EPwm1Regs.TBCTR = 0x0000;                      	// Clear counter

	// Setup TBCLK
	EPwm1Regs.TBCTL.bit.PHSDIR = TB_UP;				// Count up
	EPwm1Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN;	// 
	EPwm1Regs.TBCTL.bit.PHSEN = TB_ENABLE;			// 2010.06.21
	EPwm1Regs.TBCTL.bit.HSPCLKDIV = 0;				// Clock ratio to SYSCLKOUT
	EPwm1Regs.TBCTL.bit.CLKDIV = 0;
	EPwm1Regs.TBCTL.bit.SYNCOSEL = TB_CTR_ZERO;        	

	EPwm1Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;		// Load registers every ZERO
	EPwm1Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
	EPwm1Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
	EPwm1Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;   

	EPwm1Regs.CMPA.half.CMPA = MAX_PWM_CNT;
   
	EPwm1Regs.AQCTLA.bit.CAU = AQ_SET;
	EPwm1Regs.AQCTLA.bit.CAD = AQ_CLEAR;
   
	EPwm1Regs.DBCTL.bit.OUT_MODE 	= DB_FULL_ENABLE;

	EPwm1Regs.DBCTL.bit.POLSEL 	= DB_ACTV_HIC;

	EPwm1Regs.DBCTL.bit.IN_MODE 	= DBA_ALL;
	EPwm1Regs.DBRED = DEAD_TIME_COUNT;					// debug set to 4usec
	EPwm1Regs.DBFED = DEAD_TIME_COUNT;

	// Set PWM2   
	EPwm2Regs.TBPRD =  MAX_PWM_CNT;				// Set timer period
	EPwm2Regs.TBCTL.bit.PHSDIR = TB_UP;	// Count up
	EPwm2Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN; 		// Count up
	EPwm2Regs.TBCTL.bit.HSPCLKDIV = 0;       			// Clock ratio to SYSCLKOUT
	EPwm2Regs.TBCTL.bit.CLKDIV = 0;          			// Slow just to observe on the scope

	EPwm2Regs.TBPHS.half.TBPHS = 0x0000;           	// Phase is 0
	EPwm2Regs.TBCTL.bit.PHSEN = TB_ENABLE; 
	EPwm2Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN;        	
	EPwm2Regs.CMPA.half.CMPA = MAX_PWM_CNT;

	EPwm2Regs.AQCTLA.bit.CAU = AQ_SET;             		
	EPwm2Regs.AQCTLA.bit.CAD = AQ_CLEAR;

	EPwm2Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;
	EPwm2Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;		

	EPwm2Regs.DBCTL.bit.IN_MODE = DBA_ALL;
	EPwm2Regs.DBRED = DEAD_TIME_COUNT;
	EPwm2Regs.DBFED = DEAD_TIME_COUNT;
	EPwm2Regs.ETSEL.bit.INTEN = 0;                 	

//-------------

	EPwm1Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO;	// Select INT on Zero event
	EPwm1Regs.ETPS.bit.INTPRD = 1;   // Generate interrupt on the 1st event
	EPwm1Regs.ETCLR.bit.INT = 1;     //  
/*
	EALLOW;
	GpioCtrlRegs.GPAMUX1.bit.GPIO0 	= 1;  // GPIO0 = PWM1A
	GpioCtrlRegs.GPAMUX1.bit.GPIO1 	= 1;  // GPIO1 = PWM1B
	GpioCtrlRegs.GPAMUX1.bit.GPIO2 	= 1;  // GPIO2 = PWM2A
	GpioCtrlRegs.GPAMUX1.bit.GPIO3 	= 1;  // GPIO3 = PWM2B
	EDIS;
*/
	AdcRegs.ADCTRL2.bit.EPWM_SOCA_SEQ1 = 1;// Enable SOCA from ePWM to start SEQ1
	AdcRegs.ADCTRL2.bit.INT_ENA_SEQ1 = 1;  // Enable SEQ1 interrupt (every EOS)
	AdcRegs.ADCTRL3.all = 0x00FE;  // Power up bandgap/reference/ADC circuits

	EPwm1Regs.ETSEL.bit.SOCAEN = 1;   // Enable SOC on A group
	EPwm1Regs.ETSEL.bit.SOCASEL = ET_CTR_ZERO; // ET_CTR_PRD?
	EPwm1Regs.ETPS.bit.SOCAPRD = 1;        // Generate pulse on 1st event

	PieCtrlRegs.PIEIER3.all = M_INT1;	// ePWM
}


void pwmPulseTest()
{
	EPwm1Regs.CMPA.half.CMPA = MAX_PWM_CNT>>1;
	EPwm2Regs.CMPA.half.CMPA = MAX_PWM_CNT>>1;
}

int mode8LoopCtrl( )
{
	int LoopCtrl;
	int trip_code=0;
	int command;
	double ref_in0;

	if( trip_code !=0 ) return trip_code;

	IER &= ~M_INT3;      			// debug for PWM
	initEpwmFullBridge();
	EPwm1Regs.ETSEL.bit.INTEN = 1;	// Enable INT
	IER |= M_INT3;      			// debug for PWM

	gRunFlag =1;
	strncpy(MonitorMsg,"INIT RUN",20);
	gfRunTime = 0.0; 
	LoopCtrl = 1;		

	initVariFullbridgeCtrl();

	gMachineState = STATE_INIT_RUN;
	reference_in = code_testPwmPhase;
	reference_out = codePwmPhaseInit;	
	 
	while(LoopCtrl == 1)
	{
		Nop();		
		if(gPWMTripCode != 0){
			trip_code = gPWMTripCode; LoopCtrl = 0;
			break;
		}
		else if ( ( trip_code = trip_check()) != 0 ){
			LoopCtrl = 0;	break;
		}

		get_command( & command, & ref_in0);					
		analog_out_proc( );
		monitor_proc();

		switch( gMachineState )
		{
		case STATE_READY:
			LoopCtrl = 0;
			break;

		case STATE_INIT_RUN:
			if( command == CMD_STOP){LoopCtrl= 0;}						
			else if( gfRunTime > codeInitTime ){
				strncpy(MonitorMsg," INVERTER RUN       ",20);
				gMachineState = STATE_RUN;
				reference_in = code_testPwmPhase;
				reference_out = codePwmPhaseInit;
			}
			break;

		case STATE_RUN:
			reference_in = code_testPwmPhase;
			if( command == CMD_NULL ) ramp_proc(reference_in, &reference_out);
			else if( command == CMD_STOP ) { 
				strncpy(MonitorMsg," CMD STOP     ",20);
				reference_in = 0.0; 
				gMachineState = STATE_GO_STOP; 
			}
			else if( command == CMD_SPEED_UP ){
				reference_in += 0.05;
				if( reference_in > 1.0 ) reference_in = 1.0;
			}
			else if( command == CMD_SPEED_DOWN ){
				reference_in -= 0.05;
				if( reference_in <= 0 ) reference_in = 0.0;
			}
			else if( command == CMD_START ){
				ramp_proc(reference_in, &reference_out);
			}
			break;

		case STATE_GO_STOP:
			if( command == CMD_START ){
				reference_in = code_testPwmPhase;
				ramp_proc(reference_in, &reference_out);
				gMachineState = STATE_RUN; 
			}
			else{
				reference_in = 0.0; 
				ramp_proc(reference_in, &reference_out);
				if( reference_out < 0.01) {
					gMachineState = STATE_READY; LoopCtrl = 0;
				}
			}
			break;
		}

	} // end of while
	return trip_code;
}		

int testFullBridgeLoopCtrl1( )
{
	int LoopCtrl;
	int trip_code=0;
	int command;
	double ref_in0;

	if( trip_code !=0 ) return trip_code;

	IER &= ~M_INT3;      			// debug for PWM
	initEpwmFullBridge();
	EPwm1Regs.ETSEL.bit.INTEN = 1;	// Enable INT
	IER |= M_INT3;      			// debug for PWM

	gRunFlag =1;
	strncpy(MonitorMsg,"INIT RUN",20);
	gfRunTime = 0.0; 
	LoopCtrl = 1;		

	initVariFullbridgeCtrl();

	gMachineState = STATE_INIT_RUN;
	 
	while(LoopCtrl == 1)
	{
		Nop();		
		if(gPWMTripCode != 0){
			trip_code = gPWMTripCode; LoopCtrl = 0;
			break;
		}
		else if ( ( trip_code = trip_check()) != 0 ){
			LoopCtrl = 0;	break;
		}

		get_command( & command, & ref_in0);					
		analog_out_proc( );
		monitor_proc();

		switch( gMachineState )
		{
		case STATE_INIT_RUN:
			if( command == CMD_STOP){LoopCtrl= 0;}						
			else if( gfRunTime > 10.0 ){
				strncpy(MonitorMsg," INVERTER RUN       ",20);
				gMachineState = STATE_RUN;
			}
			break;

		case STATE_RUN:

			Nop();
			if( command == CMD_NULL ) Nop();
			else if( command == CMD_STOP ) { 
				strncpy(MonitorMsg,"INV GO STOP  ",20);
				reference_in = 0.0; 
				gMachineState = STATE_GO_STOP;
			}
			else if( command == CMD_SPEED_UP ){
				reference_in += 0.05;
				if( reference_in > 1.0 ) reference_in = 1.0;
			}
			else if( command == CMD_SPEED_DOWN ){
				reference_in -= 0.05;
				if( reference_in < -1.0 ) reference_in = -1.0;
			}
			else if( command == CMD_START ){
				Nop();//ramp_proc(reference_in, &reference_out);
			}
			break;

		case STATE_GO_STOP:
			gMachineState = STATE_READY; LoopCtrl = 0;
			break;
		}

		if( command == CMD_STOP ) { 
			LoopCtrl = 0;	gMachineState = STATE_READY;
		}
		else{
			Nop();
		}
	} // end of while
	return trip_code;
}		
	

int pwmPulseTestLoopCtrl( )
{
	int LoopCtrl;
	int trip_code=0;
	int command;
	double ref_in0;

	IER &= ~M_INT3;      // debug for PWM
	initEpwmFullBridge(); 	// debug
	EPwm1Regs.ETSEL.bit.INTEN = 1;    		            // Enable INT
	IER |= M_INT3;      // debug for PWM

	strncpy(MonitorMsg,"INIT_RUN",20);

	LoopCtrl = 1;	gMachineState = STATE_INIT_RUN;		

	test_pulse_count = 0;

	snprintf( gStr1,20,"Start[%4d]Pulse",codeSetPulseNumber);	load_sci_tx_mail_box(gStr1);
//	epwmFullBridgeEnable();
	while(LoopCtrl == 1)
	{
		trip_code = trip_check();
		if( trip_code !=0 ){
			LoopCtrl = 0;
		}
		else if( test_pulse_count >= codeSetPulseNumber){
			LoopCtrl = 0;
		}
		else{
			monitor_proc();
			get_command( & command, & ref_in0);	// Command�� �Է� ���� 
			if( command == CMD_STOP){
				gMachineState = STATE_READY;
				LoopCtrl = 0;
			}
		}						
	}

	epwmFullBridgeDisable();

	snprintf( gStr1,20,"End [%4d]Pulse",codeSetPulseNumber);	load_sci_tx_mail_box(gStr1);

	LoopCtrl=1;
	while(LoopCtrl == 1)
	{
		trip_code = trip_check();
		if( trip_code !=0 ){
			LoopCtrl = 0;
		}
		else{
			monitor_proc();
			get_command( & command, & ref_in0);	// Command�� �Է� ���� 
			if( command != CMD_START){
				gMachineState = STATE_READY;
				LoopCtrl = 0;
			}
		}						
	}
	return trip_code;
}		

int fullBridgeLoopCtrl()
{
	int LoopCtrl;
	int trip_code=0;
	int command;
	double ref_in0;

	if( trip_code !=0 ) return trip_code;

	IER &= ~M_INT3;      			// debug for PWM
	initEpwmFullBridge();
	EPwm1Regs.ETSEL.bit.INTEN = 1;	// Enable INT
	IER |= M_INT3;      			// debug for PWM

	gRunFlag =1;
	strncpy(MonitorMsg,"INIT RUN",20);
	gfRunTime = 0.0; 
	LoopCtrl = 1;		

	initVariFullbridgeCtrl();

	gMachineState = STATE_INIT_RUN;
	 
	while(LoopCtrl == 1)
	{
		Nop();		
		if(gPWMTripCode != 0){
			trip_code = gPWMTripCode; LoopCtrl = 0;
			break;
		}
		else if ( ( trip_code = trip_check()) != 0 ){
			LoopCtrl = 0;	break;
		}

		get_command( & command, & ref_in0);					
		analog_out_proc( );
		monitor_proc();

		if( command == CMD_STOP ) { 
			LoopCtrl = 0;	gMachineState = STATE_READY;
		}
		else{
			Nop();
		}
	} // end of while
	return trip_code;
}		

void simple_width_ctrl(unsigned int * pwm_count)
{
	if( reference_out < codeMinPwmRatio ) * pwm_count = 0;
	else * pwm_count = (unsigned int)( (double)MAX_PWM_CNT * reference_out );
}

void voltage_ctrl(unsigned int * pwm_count)
{

	* pwm_count = (unsigned int)( (double)MAX_PWM_CNT * reference_out );
}

void fullBridgeCtrl()
{


}
//===========================================================================
// End of file.
//===========================================================================

