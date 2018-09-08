#include	<header.h>
#include	<extern.h>

void monitor_proc()     // need_edit
{
    int temp1,temp2,temp3,temp4;
    static int count = 0;

    count = (count < 998 ) ? count + 1 : 0;

    temp1 = (int)( floor (Vout));
    temp2 = ((int)(Vout * 10.0)) % 10;

    temp3 = (int)(Pout/1000);
    temp4 = ((int)(Pout / 100.0)) % 10;

    sprintf( monitOut2,"\x02 1Vo=%02d.%01dV:Po=%02d.%01dkW\x03\r\n",temp1,temp2,temp3,temp4);
    strcpy( monitOut3,"\x02 2                    \x03\r\n");
    sprintf( monitOut4,"\x02 3                 %3d\x03\r\n",count);


    switch(gMachineState){
        case STATE_POWER_ON:
            strncpy(monitOut1,"\x02 0[POWER ON] wait ...\x03\r\n",25);
            break;

        case STATE_READY:

            temp1 = (int)(floor(Iout+0.5));
            sprintf(monitOut1,"\x02 0[READY] Io=%3d[A]  \x03\r\n",temp1);
            break;

        case STATE_TRIP:

            temp1 = (int)(floor(Iout+0.5));
            sprintf( monitOut1,"\x02 0[TRIP %03d] Io=%3d[A]\x03\r\n",TripInfoNow.CODE,temp1);

            temp1 = (int)( floor (TripInfoNow.CURRENT+0.5));
            temp2 = (int)(TripInfoNow.VOUT);
            temp3 = ((int)(TripInfoNow.VOUT * 10.0)) % 10;
            sprintf( monitOut2,"\x02 1AT =%03dA : AT =%02d.%1dV \x03\r\n",temp1,temp2,temp3);

            temp1 = (int)(TripInfoNow.DATA);
            if( (temp1 > 999 )||(temp1 < 0)) temp1 = 999;

            temp2 = (int)( floor (TripInfoNow.VDC + 0.5));
            if( (temp2 > 999 ) || ( temp2 < 0)) temp2 = 999;

            sprintf( monitOut3,"\x02 2data=%03d: AT=%03dV\x03\r\n",temp1,temp2);
            sprintf( monitOut4,"\x02 3Er:%s%03d\x03\r\n",TripInfoNow.MSG,count);
            break;

        case STATE_INIT_RUN:
            strncpy(monitOut1,"\x02 0[INIT    ] DongHo P.E.\x03\r\n",25);
            break;

        case STATE_GO_STOP:
            temp1 = (int)(floor(Iout+0.5));
            sprintf(monitOut1,"\x02 0[GO STOP] Io:%03d[A]\x03\r\n",temp1);
            break;
        case STATE_RUN:

            temp1 = (int)(floor(Iout+0.5));
            sprintf(monitOut1,"\x02 0[RUN] Io:%03d[A]\x03\r\n",temp1);
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
