/*!
 * \file channels.h
 * \brief All channels used by 'canopus'
 *  It's each board's responsability to implement them and initialize them before use.
 */
#ifndef _CANOPUS_BOARD_CHANNELS_H
#define _CANOPUS_BOARD_CHANNELS_H
#include <canopus/drivers/channel.h>
#include <canopus/drivers/device_driver.h>
#include <canopus/drivers/gyroscope.h>

//! \defgroup fpga_channels FPGA channels
/*! General platform use */
//! @{
extern const channel_t *const ch_fpga_ctrl;
extern const channel_t *const ch_fpga_spi;
//! @}

//! \defgroup cdh_channels CDH channels
//! @{
extern const channel_t *const ch_umbilical_in;  /* x.25 pkt in */
extern const channel_t *const ch_umbilical_out; /* x.25 pkt out, console out */
extern const channel_t *const ch_lithium;       /* x.25 pkt in/out */
//! @}

//! \defgroup payload_channels PAYLOAD channels
//! @{
extern const channel_t *const ch_svip_power;
extern const channel_t *const ch_nanowheel;

extern const channel_t *const ch_fpga_hub;
extern const channel_t *const ch_fpga_slave;
extern const channel_t *const ch_startracker;

//! @}

//! \defgroup power_channels POWER channels
//! @{
extern const channel_t *const ch_eps;
extern const channel_t *const ch_ina_pd3v3;
extern const channel_t *const ch_ina_pd5v;
extern const channel_t *const ch_ina_pd12v;
extern const channel_t *const ch_switches;
extern const channel_t *const ch_octopus_gpio;
extern const channel_t *const ch_octopus_adc;
//! @}

extern const channel_t memory_channel_0; /* simusat at least */

/* nanomind only channels (not yet simulated) */
extern const channel_t *const ch_magnetometer_0;
extern const channel_t *const ch_magnetometer_1;
extern const channel_t *const ch_adis;

/* devices? */
extern const gyroscope_t *const gyroscope_0;

extern xSemaphoreHandle xSemaphore_imu_dready;

#endif /* _CANOPUS_BOARD_CHANNELS_H */
