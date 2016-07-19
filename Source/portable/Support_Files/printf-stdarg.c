#include <stdarg.h>
#include "x86_support.h"

int printf(const char *format, ...)
{
        /*va_list args;
        
        va_start( args, format );
        return print( 0, format, args );*/
        
        unsigned int i;
        for (i = 0; format[i] != '\0'; i++) vScreenPutchar(format[i]);
}

int sprintf(char *out, const char *format, ...)
{
        /*va_list args;
        
        va_start( args, format );
        return print( &out, format, args );*/
        
        unsigned int i;
        for (i = 0; format[i] != '\0'; i++) vScreenPutchar(format[i]);
}


int snprintf( char *buf, unsigned int count, const char *format, ... )
{
        /*va_list args;
        
        ( void ) count;
        
        va_start( args, format );
        return print( &buf, format, args );*/
        
        unsigned int i;
        for (i = 0; format[i] != '\0'; i++) vScreenPutchar(format[i]);
}