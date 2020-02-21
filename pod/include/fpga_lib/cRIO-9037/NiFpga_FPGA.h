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
static const char* const NiFpga_FPGA_Signature = "32D3162FAD906A553DC9CAB36F77BE49";

typedef enum
{
   NiFpga_FPGA_IndicatorI16_ChassisTemperature = 0x18042,
} NiFpga_FPGA_IndicatorI16;

typedef enum
{
   NiFpga_FPGA_IndicatorI32_samples_taken = 0x18030,
} NiFpga_FPGA_IndicatorI32;

typedef enum
{
   NiFpga_FPGA_IndicatorSgl_distance = 0x18028,
} NiFpga_FPGA_IndicatorSgl;

typedef enum
{
   NiFpga_FPGA_ControlI16_command_mode_curve = 0x18006,
   NiFpga_FPGA_ControlI16_commanded_Torque_LimitToCAN = 0x18022,
   NiFpga_FPGA_ControlI16_directionToCAN = 0x18012,
   NiFpga_FPGA_ControlI16_in_timeToCAN = 0x18026,
   NiFpga_FPGA_ControlI16_inverter_DischargeToCAN = 0x1801A,
   NiFpga_FPGA_ControlI16_inverter_EnableToCAN = 0x18016,
   NiFpga_FPGA_ControlI16_program_enable = 0x18002,
   NiFpga_FPGA_ControlI16_reset_distance = 0x1802E,
   NiFpga_FPGA_ControlI16_speedToCAN = 0x1800A,
   NiFpga_FPGA_ControlI16_speed_Mode_EnableToCAN = 0x1801E,
   NiFpga_FPGA_ControlI16_torqueToCAN = 0x1800E,
} NiFpga_FPGA_ControlI16;

typedef enum
{
   NiFpga_FPGA_ControlU32_ChassisTempDelay = 0x18044,
   NiFpga_FPGA_ControlU32_RTDDelay = 0x18038,
} NiFpga_FPGA_ControlU32;

#endif
