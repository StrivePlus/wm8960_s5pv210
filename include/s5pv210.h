
//------GPIO------
#define rGPD0CON                 (*(volatile unsigned long *)0xE02000A0)
#define rGPD0DAT                 (*(volatile unsigned long *)0xE02000A4)


#define rGPE0CON                 (*(volatile unsigned long *)0xE02000E0)                                 
#define rGPE0DAT                 (*(volatile unsigned long *)0xE02000E4)  

#define rGPF0CON                 (*(volatile unsigned long *)0xE0200120)
#define rGPF1CON                 (*(volatile unsigned long *)0xE0200140)
#define rGPF2CON                 (*(volatile unsigned long *)0xE0200160)
#define rGPF3CON                 (*(volatile unsigned long *)0xE0200180)

#define rGPH1CON  (*(volatile unsigned long *) 0xE0200C20)
#define rGPH1DAT  (*(volatile unsigned long *) 0xE0200C24)
#define rGPH2CON  (*(volatile unsigned long *) 0xE0200C40)
#define rGPH2DAT  (*(volatile unsigned long *) 0xE0200C44)
#define rGPH3CON  (*(volatile unsigned long *) 0xE0200C60) 

#define rGPJ2CON  (*(volatile unsigned long *) 0xE0200280)
#define rGPJ2DAT  (*(volatile unsigned long *) 0xE0200284)
#define rGPJ2PUD  (*(volatile unsigned long *) 0xE0200288)

#define rGPH3CON  (*(volatile unsigned long *) 0xE0200C60)
#define rGPH3DAT  (*(volatile unsigned long *) 0xE0200C64)
#define rGPH3PUD  (*(volatile unsigned long *) 0xE0200C68)


#define rEXT_INT_0_CON  ( *((volatile unsigned long *)0xE0200E00) )
#define rEXT_INT_1_CON  ( *((volatile unsigned long *)0xE0200E04) )
#define rEXT_INT_2_CON  ( *((volatile unsigned long *)0xE0200E08) )
#define rEXT_INT_3_CON  ( *((volatile unsigned long *)0xE0200E0C) )

#define rEXT_INT_0_MASK  ( *((volatile unsigned long *)0xE0200F00) )
#define rEXT_INT_1_MASK  ( *((volatile unsigned long *)0xE0200F04) )
#define rEXT_INT_2_MASK  ( *((volatile unsigned long *)0xE0200F08) )
#define rEXT_INT_3_MASK  ( *((volatile unsigned long *)0xE0200F0C) )
    
#define rEXT_INT_0_PEND  ( *((volatile unsigned long *)0xE0200F40) )
#define rEXT_INT_1_PEND  ( *((volatile unsigned long *)0xE0200F44) )
#define rEXT_INT_2_PEND  ( *((volatile unsigned long *)0xE0200F48) )
#define rEXT_INT_3_PEND  ( *((volatile unsigned long *)0xE0200F4C) )


//------- exception ------

#define _Exception_Vector	0xD0037400
#define pExcRESET               ( *((volatile unsigned long *)(_Exception_Vector + 0x0)) )
#define pExcUNDEF               ( *((volatile unsigned long *)(_Exception_Vector + 0x4)) )
#define pExcSWI                 ( *((volatile unsigned long *)(_Exception_Vector + 0x8)) )
#define pExcPABORT              ( *((volatile unsigned long *)(_Exception_Vector + 0xc)) )
#define pExcDABORT              ( *((volatile unsigned long *)(_Exception_Vector + 0x10)) )
#define pExcRESERVED            ( *((volatile unsigned long *)(_Exception_Vector + 0x14)) )
#define pExcIRQ                 ( *((volatile unsigned long *)(_Exception_Vector + 0x18)) )
#define pExcFIQ                 ( *((volatile unsigned long *)(_Exception_Vector + 0x1c)) )

//---------- interupt init ----------------------------
#define VIC0_BASE       (0xF2000000)
#define VIC1_BASE       (0xF2100000)
#define VIC2_BASE       (0xF2200000)
#define VIC3_BASE       (0xF2300000)

// VIC0
#define   	rVIC0IRQSTATUS                   ( *((volatile unsigned long *)(VIC0_BASE + 0x00)) )
#define         rVIC0FIQSTATUS                   ( *((volatile unsigned long *)(VIC0_BASE + 0x04)) )
#define         rVIC0RAWINTR                     ( *((volatile unsigned long *)(VIC0_BASE + 0x08)) )
#define         rVIC0INTSELECT                   ( *((volatile unsigned long *)(VIC0_BASE + 0x0c)) )
#define         rVIC0INTENABLE                   ( *((volatile unsigned long *)(VIC0_BASE + 0x10)) )
#define         rVIC0INTENCLEAR                  ( *((volatile unsigned long *)(VIC0_BASE + 0x14)) )
#define         rVIC0SOFTINT                     ( *((volatile unsigned long *)(VIC0_BASE + 0x18)) )
#define         rVIC0SOFTINTCLEAR                ( *((volatile unsigned long *)(VIC0_BASE + 0x1c)) )
#define         rVIC0PROTECTION                  ( *((volatile unsigned long *)(VIC0_BASE + 0x20)) )
#define         rVIC0SWPRIORITYMASK              ( *((volatile unsigned long *)(VIC0_BASE + 0x24)) )
#define         rVIC0PRIORITYDAISY               ( *((volatile unsigned long *)(VIC0_BASE + 0x28)) )

#define         rVIC0VECTADDR                    (VIC0_BASE + 0x100)
#define         rVIC0VECPRIORITY                 ( *((volatile unsigned long *)(VIC0_BASE + 0x200)) )
#define         rVIC0ADDRESS                     ( *((volatile unsigned long *)(VIC0_BASE + 0xf00)) )
#define         rVIC0PERID0                      ( *((volatile unsigned long *)(VIC0_BASE + 0xfe0)) )
#define         rVIC0PERID1                      ( *((volatile unsigned long *)(VIC0_BASE + 0xfe4)) )
#define         rVIC0PERID2                      ( *((volatile unsigned long *)(VIC0_BASE + 0xfe8)) )
#define         rVIC0PERID3                      ( *((volatile unsigned long *)(VIC0_BASE + 0xfec)) )
#define         rVIC0PCELLID0                    ( *((volatile unsigned long *)(VIC0_BASE + 0xff0)) )
#define         rVIC0PCELLID1                    ( *((volatile unsigned long *)(VIC0_BASE + 0xff4)) )
#define         rVIC0PCELLID2                    ( *((volatile unsigned long *)(VIC0_BASE + 0xff8)) )
#define         rVIC0PCELLID3                    ( *((volatile unsigned long *)(VIC0_BASE + 0xffc)) )

#define 		rVIC0VECTADDR16					( *((volatile unsigned long *)(VIC0_BASE + 0x140)) )
#define 		rVIC0VECTADDR17					( *((volatile unsigned long *)(VIC0_BASE + 0x144)) )
#define 		rVIC0VECTADDR18					( *((volatile unsigned long *)(VIC0_BASE + 0x148)) )
#define 		rVIC0VECTADDR19					( *((volatile unsigned long *)(VIC0_BASE + 0x14C)) )
#define         rVIC0VECTADDR21                  ( *((volatile unsigned long *)(VIC0_BASE + 0x154)) )

#define         rVIC0VECTADDR22                  ( *((volatile unsigned long *)(VIC0_BASE + 0x158)) )
#define 		rVIC0VECTADDR24					( *((volatile unsigned long *)(VIC0_BASE + 0x160)) )
#define 		rVIC0VECTADDR25					( *((volatile unsigned long *)(VIC0_BASE + 0x164)) )
#define 		rVIC0VECTADDR26					( *((volatile unsigned long *)(VIC0_BASE + 0x168)) )
#define 		rVIC0VECTADDR27					( *((volatile unsigned long *)(VIC0_BASE + 0x16C)) )

// VIC1
#define         rVIC1IRQSTATUS                   ( *((volatile unsigned long *)(VIC1_BASE + 0x00)) )
#define         rVIC1FIQSTATUS                   ( *((volatile unsigned long *)(VIC1_BASE + 0x04)) )
#define         rVIC1RAWINTR                     ( *((volatile unsigned long *)(VIC1_BASE + 0x08)) )
#define         rVIC1INTSELECT                   ( *((volatile unsigned long *)(VIC1_BASE + 0x0c)) )
#define         rVIC1INTENABLE                   ( *((volatile unsigned long *)(VIC1_BASE + 0x10)) )
#define         rVIC1INTENCLEAR                  ( *((volatile unsigned long *)(VIC1_BASE + 0x14)) )
#define         rVIC1SOFTINT                     ( *((volatile unsigned long *)(VIC1_BASE + 0x18)) )
#define         rVIC1SOFTINTCLEAR                ( *((volatile unsigned long *)(VIC1_BASE + 0x1c)) )
#define         rVIC1PROTECTION                  ( *((volatile unsigned long *)(VIC1_BASE + 0x20)) )
#define         rVIC1SWPRIORITYMASK              ( *((volatile unsigned long *)(VIC1_BASE + 0x24)) )
#define         rVIC1PRIORITYDAISY               ( *((volatile unsigned long *)(VIC1_BASE + 0x28)) )

#define         rVIC1VECTADDR                    (VIC1_BASE + 0x100)
#define         rVIC1VECPRIORITY                 ( *((volatile unsigned long *)(VIC1_BASE + 0x200)) )
#define         rVIC1ADDRESS                     ( *((volatile unsigned long *)(VIC1_BASE + 0xf00)) )
#define         rVIC1PERID0                      ( *((volatile unsigned long *)(VIC1_BASE + 0xfe0)) )
#define         rVIC1PERID1                      ( *((volatile unsigned long *)(VIC1_BASE + 0xfe4)) )
#define         rVIC1PERID2                      ( *((volatile unsigned long *)(VIC1_BASE + 0xfe8)) )
#define         rVIC1PERID3                      ( *((volatile unsigned long *)(VIC1_BASE + 0xfec)) )
#define         rVIC1PCELLID0                    ( *((volatile unsigned long *)(VIC1_BASE + 0xff0)) )
#define         rVIC1PCELLID1                    ( *((volatile unsigned long *)(VIC1_BASE + 0xff4)) )
#define         rVIC1PCELLID2                    ( *((volatile unsigned long *)(VIC1_BASE + 0xff8)) )
#define         rVIC1PCELLID3                    ( *((volatile unsigned long *)(VIC1_BASE + 0xffc)) )

// VIC2
#define         rVIC2IRQSTATUS                   ( *((volatile unsigned long *)(VIC2_BASE + 0x00)) )
#define         rVIC2FIQSTATUS                   ( *((volatile unsigned long *)(VIC2_BASE + 0x04)) )
#define         rVIC2RAWINTR                     ( *((volatile unsigned long *)(VIC2_BASE + 0x08)) )
#define         rVIC2INTSELECT                   ( *((volatile unsigned long *)(VIC2_BASE + 0x0c)) )
#define         rVIC2INTENABLE                   ( *((volatile unsigned long *)(VIC2_BASE + 0x10)) )
#define         rVIC2INTENCLEAR                  ( *((volatile unsigned long *)(VIC2_BASE + 0x14)) )
#define         rVIC2SOFTINT                     ( *((volatile unsigned long *)(VIC2_BASE + 0x18)) )
#define         rVIC2SOFTINTCLEAR                ( *((volatile unsigned long *)(VIC2_BASE + 0x1c)) )
#define         rVIC2PROTECTION                  ( *((volatile unsigned long *)(VIC2_BASE + 0x20)) )
#define         rVIC2SWPRIORITYMASK              ( *((volatile unsigned long *)(VIC2_BASE + 0x24)) )
#define         rVIC2PRIORITYDAISY               ( *((volatile unsigned long *)(VIC2_BASE + 0x28)) )

#define         rVIC2VECTADDR                    (VIC2_BASE + 0x100)
#define         rVIC2VECPRIORITY                 ( *((volatile unsigned long *)(VIC2_BASE + 0x200)) )
#define         rVIC2ADDRESS                     ( *((volatile unsigned long *)(VIC2_BASE + 0xf00)) )
#define         rVIC2PERID0                      ( *((volatile unsigned long *)(VIC2_BASE + 0xfe0)) )
#define         rVIC2PERID1                      ( *((volatile unsigned long *)(VIC2_BASE + 0xfe4)) )
#define         rVIC2PERID2                      ( *((volatile unsigned long *)(VIC2_BASE + 0xfe8)) )
#define         rVIC2PERID3                      ( *((volatile unsigned long *)(VIC2_BASE + 0xfec)) )
#define         rVIC2PCELLID0                    ( *((volatile unsigned long *)(VIC2_BASE + 0xff0)) )
#define         rVIC2PCELLID1                    ( *((volatile unsigned long *)(VIC2_BASE + 0xff4)) )
#define         rVIC2PCELLID2                    ( *((volatile unsigned long *)(VIC2_BASE + 0xff8)) )
#define         rVIC2PCELLID3                    ( *((volatile unsigned long *)(VIC2_BASE + 0xffc)) )

// VIC3
#define         rVIC3IRQSTATUS                   ( *((volatile unsigned long *)(VIC3_BASE + 0x00)) )
#define         rVIC3FIQSTATUS                   ( *((volatile unsigned long *)(VIC3_BASE + 0x04)) )
#define         rVIC3RAWINTR                     ( *((volatile unsigned long *)(VIC3_BASE + 0x08)) )
#define         rVIC3INTSELECT                   ( *((volatile unsigned long *)(VIC3_BASE + 0x0c)) )
#define         rVIC3INTENABLE                   ( *((volatile unsigned long *)(VIC3_BASE + 0x10)) )
#define         rVIC3INTENCLEAR                  ( *((volatile unsigned long *)(VIC3_BASE + 0x14)) )
#define         rVIC3SOFTINT                     ( *((volatile unsigned long *)(VIC3_BASE + 0x18)) )
#define         rVIC3SOFTINTCLEAR                ( *((volatile unsigned long *)(VIC3_BASE + 0x1c)) )
#define         rVIC3PROTECTION                  ( *((volatile unsigned long *)(VIC3_BASE + 0x20)) )
#define         rVIC3SWPRIORITYMASK              ( *((volatile unsigned long *)(VIC3_BASE + 0x24)) )
#define         rVIC3PRIORITYDAISY               ( *((volatile unsigned long *)(VIC3_BASE + 0x28)) )

#define         rVIC3VECTADDR                    (VIC3_BASE + 0x100)
#define         rVIC3VECPRIORITY                 ( *((volatile unsigned long *)(VIC3_BASE + 0x200)) )
#define         rVIC3ADDRESS                     ( *((volatile unsigned long *)(VIC3_BASE + 0xf00)) )
#define         rVIC3PERID0                      ( *((volatile unsigned long *)(VIC3_BASE + 0xfe0)) )
#define         rVIC3PERID1                      ( *((volatile unsigned long *)(VIC3_BASE + 0xfe4)) )
#define         rVIC3PERID2                      ( *((volatile unsigned long *)(VIC3_BASE + 0xfe8)) )
#define         rVIC3PERID3                      ( *((volatile unsigned long *)(VIC3_BASE + 0xfec)) )
#define         rVIC3PCELLID0                    ( *((volatile unsigned long *)(VIC3_BASE + 0xff0)) )
#define         rVIC3PCELLID1                    ( *((volatile unsigned long *)(VIC3_BASE + 0xff4)) )
#define         rVIC3PCELLID2                    ( *((volatile unsigned long *)(VIC3_BASE + 0xff8)) )
#define         rVIC3PCELLID3                    ( *((volatile unsigned long *)(VIC3_BASE + 0xffc)) )





//--------------------- PLL ----------------------------

#define rAPLL_LOCK (*(volatile unsigned int *)0xe0100000)
#define rMPLL_LOCK (*(volatile unsigned int *)0xe0100004)
#define rAPLL_CON0 (*(volatile unsigned int *)0xe0100100)
#define rAPLL_CON1 (*(volatile unsigned int *)0xe0100104)
#define rMPLL_CON  (*(volatile unsigned int *)0xe0100108)
#define rCLK_SRC0  (*(volatile unsigned int *)0xe0100200)
#define rCLK_SRC4  (*(volatile unsigned int *)0xe0100210)
#define rCLK_DIV0  (*(volatile unsigned int *)0xe0100300)
#define rCLK_DIV4  (*(volatile unsigned int *)0xe0100310)
#define rCLK_DIV6  (*(volatile unsigned int *)0xe0100318)




#define rTCFG0  (*(volatile unsigned int *)0xe2500000)
#define rTCFG1  (*(volatile unsigned int *)0xe2500004)
#define rTCON  (*(volatile unsigned int *)0xe2500008)
#define rTCNTB0  (*(volatile unsigned int *)0xe250000C)
#define rTCMPB0  (*(volatile unsigned int *)0xe2500010)
#define rTCNTB4  (*(volatile unsigned int *)0xe250003C)
#define rTCNTB1	 (*(volatile unsigned int *)0xe2500018)
#define rTCMPB1  (*(volatile unsigned int *)0xe250001c)



#define rTINT_CSTAT  (*(volatile unsigned int *)0xe2500044)

//----------- adc ---

#define rTSADCCON0  (*(volatile unsigned int *)0xe1700000)
#define rTSDATX0  (*(volatile unsigned int *)0xe170000C)
#define rCLRINTADC0  (*(volatile unsigned int *)0xe1700018)
#define rADCMUX  (*(volatile unsigned int *)0xe170001C)



//--------------- lcd init ----------------------------
#define rDISPLAY_CONTROL (*(volatile unsigned long *)0xe0107008)

#define rVIDCON0                 (*(volatile unsigned long *)0xF8000000)
#define rVIDCON1                 (*(volatile unsigned long *)0xF8000004)
#define rVIDTCON2                (*(volatile unsigned long *)0xF8000018)
#define rWINCON0                 (*(volatile unsigned long *)0xF8000020)
#define rWINCON2                 (*(volatile unsigned long *)0xF8000028)
#define rSHADOWCON               (*(volatile unsigned long *)0xF8000034)
#define rVIDOSD0A                (*(volatile unsigned long *)0xF8000040)
#define rVIDOSD0B                (*(volatile unsigned long *)0xF8000044)
#define rVIDOSD0C                (*(volatile unsigned long *)0xF8000048)

#define rVIDW00ADD0B0    (*(volatile unsigned long *)0xF80000A0)
#define rVIDW00ADD1B0    (*(volatile unsigned long *)0xF80000D0)
#define rVIDW00ADD2    (*(volatile unsigned long *)0xF8000100)

#define rVIDTCON0                (*(volatile unsigned long *)0xF8000010)
#define rVIDTCON1                (*(volatile unsigned long *)0xF8000014)


// nand init----------------
#define rNFCONF 			( *((volatile unsigned long *)0xB0E00000) )
#define rNFCONT 			( *((volatile unsigned long *)0xB0E00004) )
#define rNFCMMD 			( *((volatile unsigned long *)0xB0E00008) )
#define rNFADDR 			( *((volatile unsigned long *)0xB0E0000C) )
#define rNFDATA 			( *((volatile unsigned long *)0xB0E00010) )
#define rNFSTAT 			( *((volatile unsigned long *)0xB0E00028) )

#define rMP0_1CON 		( *((volatile unsigned long *)0xE02002E0) )
#define rMP0_2CON 		( *((volatile unsigned long *)0xE0200300) )
#define rMP0_3CON 		( *((volatile unsigned long *)0xE0200320) )
#define rMP0_6CON		( *((volatile unsigned long *)0xE0200380) )

/*RTC*/
#define rRTCCON      (*(volatile unsigned long *)   0xe2800040)
#define rBCDSEC      (*(volatile unsigned long *) 	0xe2800070)
#define rBCDMIN      (*(volatile unsigned long *) 	0xe2800074)
#define rBCDHOUR     (*(volatile unsigned long *) 	0xe2800078)
#define rBCDDAY      (*(volatile unsigned long *)   0xe280007C)
#define rBCDDAYWEEK  (*(volatile unsigned long *) 	0xe2800080)
#define rBCDMON      (*(volatile unsigned long *) 	0xe2800084)
#define rBCDYEAR     (*(volatile unsigned long *) 	0xe2800088)

/* IIC */
#define rGPD1CON 			( *((volatile unsigned long *)0xE02000C0) )
#define rGPD1PUD  			( *((volatile unsigned long *)0xE02000C8) )
#define rGPD1DAT 			( *((volatile unsigned long *)0xE02000C4 ) )

/*music*/
#define IISTXD		(*(volatile unsigned int *)0xEEE30010)
#define IISCON  	(*(volatile unsigned int *)0xEEE30000)
// GPIO
#define GPICON  	(*(volatile unsigned int *)0xE0200220)	//IIS Signals

// IIS
#define IISCON  	(*(volatile unsigned int *)0xEEE30000)	//IIS Control
#define IISMOD  	(*(volatile unsigned int *)0xEEE30004)	//IIS Mode
#define IISFIC  	(*(volatile unsigned int *)0xEEE30008)	//IIS FIFO Control
#define IISPSR  	(*(volatile unsigned int *)0xEEE3000C)	//IIS Prescaler
#define IISTXD		(*(volatile unsigned int *)0xEEE30010)	//IIS TXD DATA
#define IISRXD 		(*(volatile unsigned int *)0xEEE30014)	//IIS RXD DATA
#define IISFICS  	(*(volatile unsigned int *)0xEEE30018)	//IIS FIFO Control

#define EPLL_CON0  	(*(volatile unsigned int *)0xe0100110)
#define EPLL_CON1  	(*(volatile unsigned int *)0xe0100114)
#define CLK_SRC0  	(*(volatile unsigned int *)0xE0100200)
#define CLK_CON  	(*(volatile unsigned int *)0xEEE10000)
#define ASS_CLK_DIV  (*(volatile unsigned int *)0xEEE10004)


// IIC GPIO
#define GPD1CON    	(*(volatile unsigned *)0xE02000C0) //Port D1 control
#define GPD1DAT    	(*(volatile unsigned *)0xE02000C4) //Port D1 data
#define GPD1PUD    	(*(volatile unsigned *)0xE02000C8) //Pull-up control D

// IIC SFR
#define I2CCON0  	(*(volatile unsigned *)0xE1800000) //IIC control
#define I2CSTAT0 	(*(volatile unsigned *)0xE1800004) //IIC status
#define I2CADD0  	(*(volatile unsigned *)0xE1800008) //IIC address
#define I2CDS0   	(*(volatile unsigned *)0xE180000C) //IIC data shift
#define I2CLC0   	(*(volatile unsigned *)0xE1800010) //IIC multi-master line control


#define WM8960_DEVICE_ADDR		0x34
