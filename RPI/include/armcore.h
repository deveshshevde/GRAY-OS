#ifndef _ARMCORE_H
#define _ARMCORE_H


/*
    * Reference mannual link :
    * https://yurichev.com/mirrors/ARMv8-A_Architecture_Reference_Manual_(Issue_A.a).pdf
    * PAGE 2025

*/
/* ARM SYSTEM REGISTERS */
#define SCR_EL1_RES1                ((1<<28) | (1<<29) | (1<<23) | (1<<22) | (1<<11) | (1<<20))
#define SCR_EE_LITTLE_ENDIAN        (0<<25)
#define SCR_EE_BIG_ENDIAN           (1<<25)

#define SCR_EOE_LITTLE_ENDIAN       (0<<25)
#define SCR_EOE_BIG_ENDIAN          (1<<25)

#define SCR_INSTRCTION_CACHE_EN     (1<<12)
#define SCR_DATA_CACHE_EN           (1<<2)

#define SCR_INSTRCTION_CACHE_DIS    (0<<12)
#define SCR_DATA_CACHE_DIS          (0<<2)

#define SCR_MMU_DISABLED            (0 << 0)
#define SCR_MMU_ENABLED             (1 << 0)

#define SCR_VALUE_MMU_DISABLED	(SCR_EL1_RES1 | SCR_EE_LITTLE_ENDIAN | SCR_INSTRCTION_CACHE_EN | SCR_INSTRCTION_CACHE_DIS | SCR_MMU_DISABLED)
#define SCR_VALUE_MMU_ENABLED	(SCR_EL1_RES1 | SCR_EE_LITTLE_ENDIAN | SCR_INSTRCTION_CACHE_EN | SCR_INSTRCTION_CACHE_DIS | SCR_MMU_ENABLED)

/*
    * Dont know why i am adding this register
*/

#define HCR_VALUE			(1<<31)

/*
    * FOR EL3
    * Other register should me added  
*/

#define SECURE_CONFIG_RESER   ((1<<5) | (1<<4))
#define SECURE_CONFIG_RW	  (1 << 10)
#define SECURE_CONFIG_NS	  (1 << 0)
#define SCR_VALUE	    	   (SECURE_CONFIG_RESER | SECURE_CONFIG_RW | SECURE_CONFIG_NS)


#define SPSR_MASK_ALL 		(7 << 6)
#define SPSR_EL1h			(5 << 0)
#define SPSR_VALUE			(SPSR_MASK_ALL | SPSR_EL1h)

#endif