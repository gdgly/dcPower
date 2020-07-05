#include	<header.h>
#include	<extern.h>

void readPwmTripInputState( int * digitalInput, int * pwmTrip ){

    int pwm, in;

    pwm = in = 0;

    if( PWM0_HIGH_FAULT == 0) pwm += 1;
    if( PWM0_LOW_FAULT == 0) pwm += 2;
    if( PWM1_HIGH_FAULT == 0) pwm += 4;
    if( PWM1_LOW_FAULT == 0) pwm += 8;

    if( EX_TRIP_INPUT   == 0)   in += 1;
    if( RUN_INPUT == 0)         in += 2;

    * digitalInput  = in;
    * pwmTrip       = pwm;
}

void fault_reset()
{
	Nop();
	asm (" .ref _c_int00"); // ;Branch to start of boot.asm in RTS library
	asm (" LB _c_int00"); // ;Branch to start of boot.asm in RTS library
}

void input_ext_fault_a_proc()
{
	trip_recording( TRIP_EXT_A, gfRunTime,"TRIP EXT A: RT "); //TRIP EXT A: runtime save
	gPWMTripCode = TRIP_EXT_A;
}

void digital_input_proc(int * cmd, double * ref )
{
	if( RUN_INPUT == 0 ){
	    delay_msecs(10);
	    if( RUN_INPUT == 0 ){
	        * cmd = CMD_START; //FWD LOW
	        * ref = 1.0;
	    } else {
	        * cmd = CMD_STOP; * ref = 0.0;
	    }
	}
	else { * cmd = CMD_STOP; * ref = 0.0;}
}

//=====================
// Digital Out Proc
//======================

void digitalOutProc()		// debug
{
	if( gMachineState == STATE_TRIP ){
		MAIN_CHARGE_OFF;		// ���� ���� on 
		TRIP_OUT_ON;
	}
	else if( gMachineState == STATE_RUN ){
		MAIN_CHARGE_ON;		// ���� ���� on 
		TRIP_OUT_OFF;
	}
	else if(gMachineState == STATE_READY){
		MAIN_CHARGE_ON;		// ���� ���� on 
		TRIP_OUT_OFF;
	}
	else{
		TRIP_OUT_OFF;
	}
}
//---------------------------------
// end of file
//----------------------------------
