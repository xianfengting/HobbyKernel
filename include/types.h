#ifndef INCLUDE_TYPES_H_
#define INCLUDE_TYPES_H_

#ifndef NULL
    #define NULL 0
#endif

/*
#ifndef TRUE
    #define TRUE  1
    #define FALSE 0
#endif
*/
typedef char bool;
#define TRUE ((bool) 1)
#define FALSE ((bool) 0)

typedef unsigned long long uint64_t;
typedef          long long int64_t;
typedef unsigned int       uint32_t;
typedef          int       int32_t;
typedef unsigned short     uint16_t;
typedef          short     int16_t;
typedef unsigned char      uint8_t;
typedef          char      int8_t;

#endif  // INCLUDE_TYPES_H_

