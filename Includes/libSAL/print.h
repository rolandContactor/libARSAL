/**
 * @file libSAL/print.h
 * @brief This file contains headers about debug print abstraction layer
 * @date 06/01/2012
 * @author frederic.dhaeyer@parrot.com
 */
#ifndef _SAL_PRINT_H_
#define _SAL_PRINT_H_
#include <time.h>

/**
 * @brief Output level
 */
typedef enum
{
    PRINT_ERROR,    /**< The error level, print on release and debug mode */
    PRINT_WARNING,  /**< The error level, print on release and debug mode */
    PRINT_DEBUG,    /**< The error level, print on debug mode only */
    PRINT_MAX,      /**< The maximum of enum, do not use !*/
} ePRINT_LEVEL;

/**
 * @brief Table to display prefix about error, warning or debug messages.
 */
extern const char *sal_prefix_table[];

/**
 * @brief print a specific output (i.e. "[ERR] TAG |121545444:main:10 - My debug log")
 */
#define SAL_PRINT(level, tag, format, ...)   sal_print(level, tag, "%d:%s:%d - " format, time (NULL), __FUNCTION__, __LINE__, ##__VA_ARGS__)

/**
 * @brief Convert a formatted output.
 *
 * @param level The level of output format
 * @param format output format
 * @retval On success, sal_print() returns the number of characters printed. Otherwise, it returns a negative value.
 */
int sal_print(ePRINT_LEVEL level, const char *tag, const char *format, ...);

#endif // _SAL_PRINT_H_
