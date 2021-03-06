#include	"header.h"
#include	"extern.h"

int get_code_information(int address,int cmd , CODE_INFO *  codes)
{	
	switch(address)
	{
    case CODE_I_out_ref:
        strncpy(codes->disp, "I Out Set",40);
        if( cmd == CMD_WRITE_RAM ) code_I_out_ref = codes->code_value;
        set_code_default(10.0,800.0,600.0,code_I_out_ref,0,codes);
        break;

    case CODE_Vout:     //
        strncpy(codes->disp, "Set Vout",40);
        if( cmd == CMD_WRITE_RAM ) code_Vout = codes->code_value;
        set_code_default(0.1,15.0,7.0,code_Vout,0,codes);
        break;

    case CODE_VoutLimit:        // code 3
        strncpy(codes->disp, "Vout Limit",40);
        if( cmd == CMD_WRITE_RAM ) code_VoutLimit = codes->code_value;
        set_code_default(0.1,30.0,10.0,code_VoutLimit,0,codes);
        break;

    case CODE_ovpTime:      // code 4
        strncpy(codes->disp, "OVP time set",40);
        if( cmd == CMD_WRITE_RAM ) code_ovpTime = codes->code_value;
        set_code_default(0.01,9999.0,60.0,code_ovpTime,0,codes);
        break;

    case CODE_OC_Time:     //
        strncpy(codes->disp, "Over C Time",40);
        if( cmd == CMD_WRITE_RAM ) codeOcTime = codes->code_value;
        set_code_default(0.1,60.0,10.0,codeOcTime,0,codes);
        break;

    case CODE_ctrl_mode:    //
        strncpy(codes->disp, "ctrl_mode",40);
        if( cmd == CMD_WRITE_RAM ) code_ctrl_mode = codes->code_value;
        set_code_default(0,10,0,code_ctrl_mode,0,codes);
        break;

    case CODE_PwmPhaseInit:
        strncpy(codes->disp, "Init Pwm Phase Ratio",40);
        if( cmd == CMD_WRITE_RAM ) codePwmPhaseInit = codes->code_value;
        set_code_default(0.0,0.9,0.05,codePwmPhaseInit,0,codes);
        break;

    case CODE_InitTime:
        strncpy(codes->disp, "Init Time [sec]",40);
        if( cmd == CMD_WRITE_RAM ) codeInitTime = codes->code_value;
        set_code_default(0.0,60.0,0.01,codeInitTime,0,codes);
        break;

    case CODE_SetPulseNumber:
        strncpy(codes->disp, "Set Pulse No",40);
        if( cmd == CMD_WRITE_RAM ) codeSetPulseNumber = codes->code_value;
        set_code_default(0,30000,1,codeSetPulseNumber,0,codes);
        break;

    case CODE_testPwmPhase:
        strncpy(codes->disp, "Test Pwm Phase",40);
        if( cmd == CMD_WRITE_RAM ) code_testPwmPhase = codes->code_value;
        set_code_default(0.0,1.0,0.1,code_testPwmPhase,0,codes);
        break;

    case CODE_set_Vdc_on:
        strncpy(codes->disp, "Vdc Set On",40);
        if( cmd == CMD_WRITE_RAM )code_set_Vdc_on = codes->code_value;
        set_code_default(0,1,1,code_set_Vdc_on,0,codes);
        break;

    case CODE_IoutAdcOffset:     // 14
        strcpy(codes->disp, "Iout adc offset");
        if( cmd == CMD_WRITE_RAM ) codeIoutAdcOffset = codes->code_value;
        set_code_default(1500,2500,1830,codeIoutAdcOffset,0,codes);
        break;

    case CODE_IpriAdcOffset:     // 15
        strcpy(codes->disp, "Ipri adc offset");
        if( cmd == CMD_WRITE_RAM ) codeIpriAdcOffset = codes->code_value;
        set_code_default(1500,2500,1830,codeIpriAdcOffset,0,codes);
        break;

    case CODE_IoutScale:     // 16
        strcpy(codes->disp, "set Iout Scale");
        if( cmd == CMD_WRITE_RAM ) codeIoutScale = codes->code_value;
        set_code_default(0.2,3.0,1.0,codeIoutScale,0,codes);
        break;

    case CODE_IpriScale:     // 17
        strcpy(codes->disp, "set Ipri Scale");
        if( cmd == CMD_WRITE_RAM ) codeIpriScale = codes->code_value;
        set_code_default(0.2,3.0,1.0,codeIpriScale,0,codes);
        break;

    case CODE_protect_inhibit_on:
        strncpy(codes->disp, "Protection Off",40);
        if( cmd == CMD_WRITE_RAM ) code_protect_inhibit_on = codes->code_value;
        set_code_default(0,1,0,code_protect_inhibit_on,0,codes);
        break;

//--- graph setting

    case CODE_graphPoint1:
        strncpy(codes->disp, "Graph Point1",20);
        if( cmd == CMD_WRITE_RAM ) codeGraphPoint[0] = codes->code_value;
        set_code_default(0.0,50.0,42.0,codeGraphPoint[0],0,codes);
        break;
    case CODE_graphScale1:
        strncpy(codes->disp, "graph Scale1",20);
        if( cmd == CMD_WRITE_RAM ) codeGraphScale[0] = codes->code_value;
        set_code_default(0.1,500.0,2.0,codeGraphScale[0],0,codes);
        break;
    case CODE_graphOffset1:
        strncpy(codes->disp, "graph Offset1",20);
        if( cmd == CMD_WRITE_RAM ) codeGraphOffset[0] = codes->code_value;
        set_code_default(0.0,10000.0,0.0,codeGraphOffset[0],0,codes);
        break;

    case CODE_graphPoint2:
        strncpy(codes->disp, "Graph Point2",20);
        if( cmd == CMD_WRITE_RAM ) codeGraphPoint[1] = codes->code_value;
        set_code_default(0.0,50.0,27.0,codeGraphPoint[1],0,codes);
        break;
    case CODE_graphScale2:
        strncpy(codes->disp, "graph Scale2",20);
        if( cmd == CMD_WRITE_RAM ) codeGraphScale[1] = codes->code_value;
        set_code_default(0.1,500.0,2.0,codeGraphScale[1],0,codes);
        break;
    case CODE_graphOffset2:
        strncpy(codes->disp, "graph Offset2",20);
        if( cmd == CMD_WRITE_RAM ) codeGraphOffset[1] = codes->code_value;
        set_code_default(0.0,10000.0,0.0,codeGraphOffset[1],0,codes);
        break;

    case CODE_graphPoint3:
        strncpy(codes->disp, "Graph Point3",20);
        if( cmd == CMD_WRITE_RAM ) codeGraphPoint[2] = codes->code_value;
        set_code_default(0.0,50.0,7,codeGraphPoint[2],0,codes);
        break;
    case CODE_graphScale3:
        strncpy(codes->disp, "graph Scale3",20);
        if( cmd == CMD_WRITE_RAM ) codeGraphScale[2] = codes->code_value;
        set_code_default(0.1,500.0,20.0,codeGraphScale[2],0,codes);
        break;
    case CODE_graphOffset3:
        strncpy(codes->disp, "graph Offset3",20);
        if( cmd == CMD_WRITE_RAM ) codeGraphOffset[2] = codes->code_value;
        set_code_default(0.0,10000.0,300.0,codeGraphOffset[2],0,codes);
        break;

    case CODE_graphPoint4:
        strncpy(codes->disp, "Graph Point4",20);
        if( cmd == CMD_WRITE_RAM ) codeGraphPoint[3] = codes->code_value;
        set_code_default(0.0,50.0,35.0,codeGraphPoint[3],0,codes);
        break;
    case CODE_graphScale4:
        strncpy(codes->disp, "graph Scale4",20);
        if( cmd == CMD_WRITE_RAM ) codeGraphScale[3] = codes->code_value;
        set_code_default(0.1,500.0,100.0,codeGraphScale[3],0,codes);
        break;
    case CODE_graphOffset4:
        strncpy(codes->disp, "graph Offset4",20);
        if( cmd == CMD_WRITE_RAM ) codeGraphOffset[3] = codes->code_value;
        set_code_default(0.0,10000.0,0.0,codeGraphOffset[3],0,codes);
        break;

//--- sensor setting
    case CODE_VdcAdcLow:
           strncpy(codes->disp, "adc Vdc low",20);
           if( cmd == CMD_WRITE_RAM ) codeVdcAdcLow = codes->code_value;
           set_code_default(100.0, 3000.0, 1833.0, codeVdcAdcLow,0,codes);
           break;
   case CODE_VdcAdcHigh:
       strncpy(codes->disp, "adc Vdc high",20);
       if( cmd == CMD_WRITE_RAM ) codeVdcAdcHigh = codes->code_value;
       set_code_default(500.0, 4000.0, 2852.0, codeVdcAdcHigh,0,codes);
       break;

   case CODE_VdcCalcLow:
       strncpy(codes->disp, "Vdc calc_low",20);
       if( cmd == CMD_WRITE_RAM ) codeVdcCalcLow = codes->code_value;
       set_code_default(0.0, 500.0, 100.0, codeVdcCalcLow,0,codes);
       break;

   case CODE_VdcCalcHigh:
       strncpy(codes->disp, "Vdc calc_high",20);
       if( cmd == CMD_WRITE_RAM ) codeVdcCalcHigh = codes->code_value;
       set_code_default(50.0,999.0, 549.0,codeVdcCalcHigh,0,codes);
       break;

   case CODE_VoutAdcLow:
      strncpy(codes->disp, "Vout adc low",20);
      if( cmd == CMD_WRITE_RAM ) codeVoutAdcLow = codes->code_value;
      set_code_default(100.0, 3000.0, 1833.0, codeVoutAdcLow,0,codes);
      break;

   case CODE_VoutAdcHigh:
      strncpy(codes->disp, "Vout adc high",20);
      if( cmd == CMD_WRITE_RAM ) codeVoutAdcHigh = codes->code_value;
      set_code_default(500.0, 4000.0, 2852.0, codeVoutAdcHigh,0,codes);
      break;

  case CODE_VoutCalcLow:
      strncpy(codes->disp, "Vout calc_low",20);
      if( cmd == CMD_WRITE_RAM ) codeVoutCalcLow = codes->code_value;
      set_code_default(0.0, 500.0, 100.0, codeVoutCalcLow,0,codes);
      break;

  case CODE_VoutCalcHigh:
      strncpy(codes->disp, "Vout calc_high",20);
      if( cmd == CMD_WRITE_RAM ) codeVoutCalcHigh = codes->code_value;
      set_code_default(50.0,999.0, 549.0,codeVoutCalcHigh,0,codes);
      break;

  case CODE_END:
		return -2;
			
	default:
		return -1;
	}
	return 0;
}

void set_code_default(double min, double max, double defaults, double value,int open_level, CODE_INFO * codes )
{
	codes->type 		= TYPE_float;
	codes->open_level 	= open_level;
	codes->code_min		= min;
	codes->code_max		= max;
	codes->code_default	= defaults;
	codes->code_value 	= value;
}

int check_backup_data()
{
    UNION32 data;
    int check,address,cmd;

    data.dword  = 0.0;
    cmd = CMD_READ_DATA;
    for( address = 0 ; address <= CODE_END; address++){  // code group �� 6��
        check = get_code_information( address, cmd , & code_inform);
        if( !check ){
            Flag_TripDataBackup = 1;
            read_eprom_data( address, & data);
            Flag_TripDataBackup = 0;
            check = check_code_data(address, data );    // check min and max boundary
            if(check)  return -1;
        }
    }
    return 0;
}

void save_backup_data()
{
	UNION32	data;
	int check,address,cmd;
	data.dword  = 0.0;
	cmd = CMD_READ_DATA;
	for( address = 0 ; address <= CODE_END ; address++){
        check = get_code_information( address, cmd , & code_inform);
        if( !check ){
            read_eprom_data( address, & data);
            Flag_TripDataBackup = 1;
            write_code_2_eeprom( address,data);
            Flag_TripDataBackup = 0;
        }
	}
}

void backup_data_load()
{
	UNION32	data;
	int check,address,cmd;
	
	data.dword  = 0.0;
	cmd = CMD_READ_DATA;
    for( address = 0; address <= CODE_END ;address++)
    {
        check = get_code_information( address, cmd , & code_inform);
        if( !check ){
            Flag_TripDataBackup = 1;
            read_eprom_data( address, & data);
            Flag_TripDataBackup = 0;
            write_code_2_eeprom( address,data);
            code_inform.code_value = data.dword;
            cmd = CMD_WRITE_RAM;
            check = get_code_information( address,cmd, & code_inform);
        }
	}
}
double CheckSum()
{
    return 0.0;
}

int SaveDataProc(int addr, double data)
{
	int cmd,i,return_value;
	char SciBuf[30]={0};
	char str[30];
	UNION32 u32data,u32data2;

	return_value = 0;

	cmd = CMD_READ_DATA;

	i = get_code_information( addr,cmd,&code_inform); 

	if( i != 0 ) goto _SAVE_ERROR_INVALID_ADDR;   

	if( addr >= 800 ){

		if( data < 1.22 ) goto _SAVE_ERROR_INVALID_DATA; 
		if( data > 1.24 ) goto _SAVE_ERROR_INVALID_DATA; 
		switch(addr)
		{
		case CODE_Data_Check: 	return_value = check_backup_data();	break;
		case CODE_Data_Backup:
			strncpy(str,"Wait Data Backup\r\n",30);
			load_sci_tx_mail_box(str); delay_msecs(20);
			save_backup_data();
			strncpy(str,"Wait for ErChk\r\n",30);
			load_sci_tx_mail_box(str);  delay_msecs(20);

			break;
		case CODE_Data_Load:
			strncpy(str,"Wait Data Load\r\n",30);
			load_sci_tx_mail_box(str); delay_msecs(20);	
			backup_data_load();
			break;
		case CODE_Data_Init:
			strncpy(str,"Wait Data Init\r\n",30);
			load_sci_tx_mail_box(str); delay_msecs(20);
			init_eprom_data();
			strncpy(str,"Data Init OK\r\n",20);
			load_sci_tx_mail_box(str); delay_msecs(20);
			break;

		default:
			goto _SAVE_ERROR_INVALID_ADDR;
		}
		return return_value;
	}

    if( code_inform.code_min > data ){
        goto _SAVE_ERROR_DATA_UNDER;
    }
    else if( code_inform.code_max < data ){
        goto _SAVE_ERROR_DATA_OVER;
    }
    else {
        u32data.dword = data;
        read_eprom_data( addr, & u32data2);
        if( u32data.dword != u32data2.dword ){
            write_code_2_eeprom( addr, u32data);
            read_eprom_data( addr, & u32data2);

            if( u32data.dword != u32data2.dword ) goto _EEPROM_WRITE_ERROR;

            code_inform.code_value = data;
            cmd = CMD_WRITE_RAM;
            get_code_information( addr,cmd, & code_inform);

            // CheckSum Save
            u32data.dword = CheckSum();
            EepromSaveFlag = 1;
            write_code_2_eeprom(EPROM_ADDR_CHECKSUM, u32data);
            EepromSaveFlag = 0;
            load_sci_tx_mail_box("OK write success\r\n") ;
        }
        else{
            load_sci_tx_mail_box("Equal Data write skipped\r\n");
        }
        return 0;
    }
_SAVE_ERROR_INVALID_ADDR:
//	strcpy(SciBuf, "ADDR");
	strcpy(SciBuf,"Invalid Address\r\n" );
	load_sci_tx_mail_box(SciBuf) ;
	return -1;

_SAVE_ERROR_DATA_UNDER:

//	strcpy(SciBuf, "UNDE");

	strcpy(SciBuf,"data under\r\n" );
	load_sci_tx_mail_box(SciBuf) ;
	return -1;

_SAVE_ERROR_DATA_OVER:
//	strcpy(SciBuf, "OVER");
	strcpy(SciBuf,"data over\r\n" );
	load_sci_tx_mail_box(SciBuf) ;
	return -1;

_SAVE_ERROR_INVALID_DATA:
//	strcpy(SciBuf, "DATA");
	strcpy(SciBuf,"Invalid data\r\n" );
	load_sci_tx_mail_box(SciBuf) ;
	return -1;

_EEPROM_WRITE_ERROR:
//	strcpy(SciBuf, "DATA");
	strcpy(SciBuf,"Eprom wr err\r\n" );
	load_sci_tx_mail_box(SciBuf) ;
	return -1;
}

int init_eprom_data()
{
	UNION32	data,data2;
	int check,address,cmd;
	data.dword  = 0.0;
	cmd = CMD_READ_DATA;
	for( address = 0 ; address < CODE_END ; address++ )
	{
		cmd = CMD_READ_DATA;
		check = get_code_information( address, cmd , & code_inform);
		if( check==0 ){
			data.dword = code_inform.code_default;
			read_eprom_data(address, & data2 );
			if( data.dword != data2.dword)	write_code_2_eeprom( address,data);
			read_eprom_data(address, & data2 );
			if( data.dword != data2.dword){
				load_sci_tx_mail_box("err eprm WR\r\n" );
				delay_msecs(100);
				return -1;
			}	 
			else{
			    code_inform.code_value = data.dword;
			    cmd = CMD_WRITE_RAM;
			    check = get_code_information( address,cmd, & code_inform);
			}
		}
    }
	return 0;
}

void readAllCodes1()
{
    int check;
    int addr,cmd;

    load_scia_tx_mail_box("9:4:901:0.000e+0:");delay_msecs(2);
    load_scia_tx_mail_box("//Read code data:");delay_msecs(2);
    load_scia_tx_mail_box("code  data  Disc:");delay_msecs(2);
    cmd = CMD_READ_DATA;
    for( addr = 0 ; addr <= CODE_END ; addr++){
        check = get_code_information( addr, cmd , & code_inform);
        if( !check ){
            snprintf( gStr1,20,"%4d: ",addr);
            load_scia_tx_mail_box(gStr1);
            delay_msecs(2);
            snprintf( gStr1,20,"%.3e ",code_inform.code_value);
            load_scia_tx_mail_box(gStr1);
            delay_msecs(10);
            load_scia_tx_mail_box(code_inform.disp);

            load_scia_tx_mail_box(" \r\n");delay_msecs(10);
        }
    }
}

void readAllCodes()
{
    int check;
    int addr,cmd;
    char * str;

    scia_tx_end_addr = 0;
    scia_tx_start_addr = 0;
    loadSciaTxMailBox("9:4:901:0.000e+0:"); delay_msecs(5);
    loadSciaTxMailBox("//Read code data:");delay_msecs(5);
    loadSciaTxMailBox("code  data  Disc:");delay_msecs(5);
    for( addr = 0 ; addr <= CODE_END ; addr++){
        check = get_code_information( addr, cmd , & code_inform);
        if( !check ){
            snprintf( str, 6 ,"%4d,",addr); load_scia_tx_mail_box(str);delay_msecs(5);
            snprintf( str,20,"%.3e,",code_inform.code_value);
            load_scia_tx_mail_box(str);delay_msecs(5);
            load_scia_tx_mail_box(code_inform.disp);delay_msecs(5);
            load_scia_tx_mail_box(" : "); delay_msecs(10);
        }
    }
    load_scia_tx_mail_box("endOfReadall.\r\n");
}

//--- end of code_proc.c
