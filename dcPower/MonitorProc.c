#include	<header.h>
#include	<extern.h>

void monitorPrint( char * str, float argIn)
{
    float fTemp1;
    int temp;

    if(argIn > 999.9){
        str[0] = str[1] = str[2] = str[4] = '9';
        str[3] = '.';
    }
    else if(argIn < 0){
        str[0] = str[1] = str[2] = str[4] = ' ';
        str[3] = '.'; str[0] = '-';
    }
    else{
        if( argIn < 0.0) fTemp1 = 0.0;
        else  fTemp1 = floor(argIn*10 +0.5);
        temp = (int)( fTemp1 );
        str[4] = temp % 10 + '0';
        str[3] = '.';
        str[2] = ( temp % 100 )  / 10 + '0';
        str[1] = (( temp % 1000) / 100) + '0';
        str[0] = ( temp / 1000 ) + '0';
        if(str[0] == '0'){
            str[0] =' ';
            if(str[1]=='0') str[1] = ' ';
        }
    }
    str[5]=',';
}

void monitor_proc()     // need_edit
{
    int temp1,temp2,temp3;

    temp1 = (int)( floor (Iout + 0.5));
    temp2 = (int)(Vout);
    temp3 = ((int)(Vout * 10.0)) % 10;
    snprintf( monitOut2,25,"\x02 1Io =%dA : Vo = %2d.%1dV\x03\r\n",temp1,temp2,temp3);

    temp1 = (int)(Pout/1000);
    temp2 = ((int)(Pout / 100.0)) % 10;
    temp3 = (int)( floor (Vdc + 0.5));
    snprintf( monitOut3,25,"\x02 2Po =%03d.%1dkW : Vdc= %03dV\x03\r\n",temp1,temp2,temp3);

    strncpy(monitOut4,"\x02 3Dong Ho P.E.     \x03\r\n",25);

    switch(gMachineState){
        case STATE_POWER_ON:
            strncpy(monitOut1,"\x02 0[POWER ON] wait ...\x03\r\n",25);
            break;

        case STATE_READY:
            strncpy(monitOut1,"\x02 0[READY]  DongHoP.E.\x03\r\n",25);
            break;

        case STATE_TRIP:
            snprintf( monitOut1,29,"\x02 0[TRIP %03d] DongHo P.E.\x03\r\n",TripInfoNow.CODE);

            temp1 = (int)( floor (TripInfoNow.CURRENT+0.5));
            temp2 = (int)(TripInfoNow.VOUT);
            temp3 = ((int)(TripInfoNow.VOUT * 10.0)) % 10;
            snprintf( monitOut2,25,"\x02 1Io =%dA : Vo = %2d.%1dV \x03\r\n",temp1,temp2,temp3);

            temp1 = (int)(TripInfoNow.DATA);

            if( (temp1 > 999 )||(temp1 < 0)) temp1 = 999;

            temp2 = (int)( floor (TripInfoNow.VDC + 0.5));
            if( (temp2 > 999 ) || ( temp2 < 0)) temp2 = 999;

            snprintf( monitOut3,25,"\x02 2eDATA=%03d:eVdc=%03dV\x03\r\n",temp1,temp2);

            snprintf( monitOut4,25,"\x02 3%s \x03\r\n",TripInfoNow.MSG);
            break;

        case STATE_INIT_RUN:
            strncpy(monitOut1,"\x02 0[INIT    ] DongHo P.E.\x03\r\n",25);
            break;

        case STATE_GO_STOP:
            strncpy(monitOut1,"\x02 0[GO READY] DongHo P.E.\x03\r\n",25);
            break;
        case STATE_RUN:
            strncpy(monitOut1,"\x02 0[RUN     ] DongHo P.E.\x03\r\n",25);
            break;

        default:
            strncpy(monitOut1,"\x02 0[SYERR ] DongHo P.E.\x03\r\n",25);
            break;
    }
}

void GetInputMark(char * str)
{
	strncpy(str,"xxxx",20);			// debug
}
//--- End of file.
