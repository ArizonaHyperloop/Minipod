/*
 * Generated with the FPGA Interface C API Generator 18.0.0
 * for NI-RIO 18.0.0 or later.
 */

#ifndef __NiFpga_FPGA_h__
#define __NiFpga_FPGA_h__

#ifndef NiFpga_Version
   #define NiFpga_Version 1800
#endif

#include "NiFpga.h"

/**
 * The filename of the FPGA bitfile.
 *
 * This is a #define to allow for string literal concatenation. For example:
 *
 *    static const char* const Bitfile = "C:\\" NiFpga_FPGA_Bitfile;
 */
#define NiFpga_FPGA_Bitfile "NiFpga_FPGA.lvbitx"

/**
 * The signature of the FPGA bitfile.
 */
static const char* const NiFpga_FPGA_Signature = "DDE3AEC80DD359FE328D865430A7DF7C";

typedef enum
{
   NiFpga_FPGA_IndicatorBool_pwm0_signal = 0x1800E,
} NiFpga_FPGA_IndicatorBool;

typedef enum
{
   NiFpga_FPGA_IndicatorI32_samples_taken = 0x1801C,
} NiFpga_FPGA_IndicatorI32;

typedef enum
{
   NiFpga_FPGA_IndicatorSgl_distance = 0x18014,
} NiFpga_FPGA_IndicatorSgl;

typedef enum
{
   NiFpga_FPGA_ControlBool_pwm0_enable = 0x18002,
} NiFpga_FPGA_ControlBool;

typedef enum
{
   NiFpga_FPGA_ControlI16_reset_distance = 0x1801A,
} NiFpga_FPGA_ControlI16;

typedef enum
{
   NiFpga_FPGA_ControlSgl_distance_per_tape = 0x18020,
   NiFpga_FPGA_ControlSgl_pwm0_duty_cycle = 0x18008,
   NiFpga_FPGA_ControlSgl_pwm0_frequency = 0x18004,
} NiFpga_FPGA_ControlSgl;

#endif
