#ifndef BIT_MATH_H
#define BIT_MATH_H

#define BIT_SET(ADDRESS,BIT) (ADDRESS |= (1<<BIT))
#define BIT_CLEAR(ADDRESS,BIT) (ADDRESS &= ~(1<<BIT))
#define BIT_CHECK(ADDRESS,BIT) (ADDRESS & (1<<BIT))
#define BIT_FLIP(ADDRESS,BIT) (ADDRESS ^= (1<<BIT))


#endif