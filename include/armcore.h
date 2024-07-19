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

 

#endif