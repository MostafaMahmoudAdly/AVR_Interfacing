

#ifndef _BIT_MATH_H_
#define _BIT_MATH_H_


#define SET_BIT(VAR,BITNO)  ( (VAR) |=  ( 1 <<(BITNO) ) )
#define CLR_BIT(VAR,BITNO)  ( (VAR) &= ~( 1 <<(BITNO) ) )
#define TOG_BIT(VAR,BITNO)  ( (VAR) ^=  (1 <<(BITNO)  ) )
#define GET_BIT(VAR,BITNO)  ( ( (VAR) >> BITNO) & 0x01  )


#define SET_PORT(VAR,PORT)  ( (VAR) |=  (PORT)  )



#endif
