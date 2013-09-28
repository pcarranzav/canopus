/*!	\file command.h
 *  \brief Commands and related definitions
 *
 *	This file includes all possible CDH commands for each subsystem.
 *	It also defines interfaces to declare command handlers.
 */
#ifndef __COMMAND_H__
#define __COMMAND_H__

#ifndef _CANOPUS_SUBSYSTEM_H_
# error this "file can only be included by <canopus/subsystem.h>"
#endif

struct subsystem_t;

//! \defgroup command_indexes Command definitions and array indexes
//! @{

//! Basic commands
enum ss_cmd_e {
	SS_CMD_GET_NAME = 0,
	SS_CMD_GET_TELEMETRY_BEACON,
	SS_CMD_GET_TELEMETRY_BEACON_SHORT,
	SS_CMD_RUN_TEST,
	SS_CMD_GET_TELEMETRY_BEACON_ASCII,

	SS_CMD_SS_START = 0x20 //!< Specific subsystem commands' first index
};

//! PLATFORM subsystem commands
enum ss_cmd_platform_e {
    SS_CMD_PM_SET_MODE = SS_CMD_SS_START,
    SS_CMD_PM_SOFT_RESET_SYSTEM,
    SS_CMD_PM_GET_VERSION,
    SS_CMD_PM_WATCHDOG_ENABLE ,
    SS_CMD_PM_WATCHDOG_DISABLE,
    SS_CMD_PM_SET_DEBUGLEVEL,
    SS_CMD_PM_DUMP_RUNTIME_STATS,
    SS_CMD_PM_UART_CONNECT,
    SS_CMD_PM_ADC_VREF_STATS,
    SS_CMD_PM_ADC_MEASURE_PANELS,
    SS_CMD_PM_GET_ON_BOARD_TIME,
    SS_CMD_PM_SET_ON_BOARD_TIME,
    SS_CMD_PM_GET_FPGA_TICKS,
    SS_CMD_PM_UART_DISCONNECT,
};

//! MEMORY subsystem commands
enum ss_cmd_memory_e {
	SS_CMD_MM_MEMORY_READ = SS_CMD_SS_START,
	SS_CMD_MM_MEMORY_WRITE,
	SS_CMD_MM_MEMORY_CALL,
	SS_CMD_MM_MEMORY_COPY,

	SS_CMD_MM_FLASH_SECTOR_ERASE,
	SS_CMD_MM_FLASH_WRITE,
	SS_CMD_MM_FLASH_SECTOR_WRITE_FROM_MEMORY,
	SS_CMD_MM_FLASH_PATCH,

    SS_CMD_MM_NVRAM_SAVE_ALL,
	SS_CMD_MM_NVRAM_RELOAD,
	SS_CMD_MM_NVRAM_READ,
	SS_CMD_MM_NVRAM_PATCH,

	SS_CMD_MM_MEMORY_READ_LONG,
	SS_CMD_MM_MEMORY_READ_CHUNKED,

    SS_CMD_MM_MEMORY_INFO,
    SS_CMD_MM_NVRAM_SAVE_PARTIAL,

    SS_CMD_MM_MEMORY_COMP_INIT,
    SS_CMD_MM_MEMORY_DECOMPRESS,
    SS_CMD_MM_MEMORY_COMPRESS,
    SS_CMD_MM_MEMORY_DECOMPRESS_Z,
    SS_CMD_MM_MEMORY_COMPRESS_Z,

    SS_CMD_MM_FLASH_WRITE_FROM_MEMORY,
    SS_CMD_MM_MD5,
    SS_CMD_MM_MEMSET,
    SS_CMD_MM_BITMAP,
    SS_CMD_MM_NVRAM_ERASE,
    SS_CMD_MM_NVRAM_FORMAT,
    SS_CMD_MM_MEMORY_COMPRESS_BCL_LZ77,
    SS_CMD_MM_MEMORY_DECOMPRESS_BCL_LZ77,
};

//! CDH subsystem commands
enum ss_cmd_cdh_e {
	SS_CMD_CDH_DELAY_BEACON = SS_CMD_SS_START,

	SS_CMD_CDH_RADIO_SET_TX_POWER,
	SS_CMD_CDH_RADIO_SET_BEACON_INTERVAL,
	SS_CMD_CDH_RADIO_SET_BEACON_DATA,
	SS_CMD_CDH_RADIO_GET_CONFIG,
	SS_CMD_CDH_RADIO_SET_CONFIG,
	SS_CMD_CDH_RADIO_FLASH_CONFIG,
	SS_CMD_CDH_RADIO_SEND_FRAME,
	SS_CMD_CDH_RADIO_GET_TELEMETRY,
	SS_CMD_CDH_RADIO_SEND_FRAME_AT_BPS,
	SS_CMD_CDH_RADIO_SET_TX_BPS,
	SS_CMD_CDH_RADIO_SET_RX_BPS,
	SS_CMD_CDH_RADIO_NOOP,
	SS_CMD_CDH_RADIO_RESET,

	SS_CMD_CDH_ANTENNA_GET_TEMPERATURE,
	SS_CMD_CDH_ANTENNA_GET_STATUS_FULL,
	SS_CMD_CDH_ANTENNA_RESET,
	SS_CMD_CDH_ANTENNA_ARM,
	SS_CMD_CDH_ANTENNA_DISARM,
	SS_CMD_CDH_ANTENNA_DEPLOY,
	SS_CMD_CDH_ANTENNA_DEPLOY_WITH_OVERRIDE,
	SS_CMD_CDH_ANTENNA_DEPLOY_CANCEL,
	SS_CMD_CDH_ANTENNA_DEPLOY_INHIBIT,

	SS_CMD_CDH_COUNTDOWN_DELAY,
	SS_CMD_CDH_RADIO_RECONFIGURE,

	SS_CMD_CDH_SAMPLE_BEACON,
	SS_CMD_CDH_SAMPLE_MEMORY,
	SS_CMD_CDH_SAMPLE_FLASH_WHEN_DONE,
	SS_CMD_CDH_SAMPLE_RETRIEVE,

	SS_CMD_CDH_DELAYED_COMMAND,
	SS_CMD_CDH_DELAYED_COMMAND_LIST,
	SS_CMD_CDH_DELAYED_COMMAND_DISCARD,

	SS_CMD_GET_SEEN_AX25_CALLS,
};

//! AOCS subsystem commands
enum ss_cmd_aocs_e {
    SS_CMD_AOCS_Z_AXIS_DISABLED = SS_CMD_SS_START,
	SS_CMD_AOCS_SET_DETUMBLING_GAIN,
	SS_CMD_AOCS_SET_DETUMBLING_MODE,
	SS_CMD_AOCS_GET_MODE,
	SS_CMD_AOCS_SET_MODE,
	SS_CMD_AOCS_PWM_INIT,
	SS_CMD_AOCS_PWM_ENABLE_CHANNEL,
	SS_CMD_AOCS_PWM_DISABLE_CHANNEL,
	SS_CMD_AOCS_PWM_SET_DUTY_CHANNEL,
	SS_CMD_AOCS_NO_MTQ_ACTUATE,
	SS_CMD_AOCS_SET_DEFAULT_CONTROLLER_FREQUENCY,
	SS_CMD_AOCS_SET_CURRENT_CONTROLLER_FREQUENCY,
	SS_CMD_AOCS_LOG_TO_BUFFER,
	SS_CMD_AOCS_GET_BUFFER,
	SS_CMD_AOCS_GET_ADC,
	SS_CMD_AOCS_CACA,
	SS_CMD_AOCS_IMU_READ,
	SS_CMD_AOCS_IMU_WRITE,
	SS_CMD_AOCS_SET_MAGCAL_MATRIX,
	SS_CMD_AOCS_RESTART_SAMPLER,
	SS_CMD_AOCS_CONFIGURE_SAMPLER,
};

//! POWER subsystem commands
enum ss_cmd_power_e {
	SS_CMD_POWER_HARD_RESET_SYSTEM = SS_CMD_SS_START,
	SS_CMD_POWER_EPS_GET_ALL_ADC_RAW,
	SS_CMD_POWER_TURN_ON_SWITCH,
	SS_CMD_POWER_TURN_OFF_SWITCH,
	SS_CMD_POWER_SET_MATRIX_KEY,
	SS_CMD_EPS_RESET,
	SS_CMD_POWER_SET_ALL_SWITCHES,
	SS_CMD_INA_GET_TELEMETRY,
	SS_CMD_INA_RESET,
	SS_CMD_EPS_FAST_SAMPLE,
};

//! PAYLOAD subsystem commands
enum ss_cmd_payload_e {
	SS_CMD_PAYLOAD_CHUB_TEST_ALL = SS_CMD_SS_START,
	SS_CMD_PAYLOAD_DELAY,

	SS_CMD_PAYLOAD_OVERO_EXEC_SIMPLE,
    SS_CMD_PAYLOAD_OVERO_EXEC_PAGED,
    SS_CMD_PAYLOAD_OVERO_EXEC_PAGED_TO_MEMORY,
    SS_CMD_PAYLOAD_OVERO_UPLOAD_FROM_MEMORY,

    SS_CMD_PAYLOAD_OVERO_BOOTUP,
    SS_CMD_PAYLOAD_OVERO_LOGIN,
    SS_CMD_PAYLOAD_OVERO_TEST_1,
    SS_CMD_PAYLOAD_OVERO_HALT,
    SS_CMD_PAYLOAD_OVERO_TEST_2,

    SS_CMD_OCTOPUS_GPIO_SET,
    SS_CMD_OCTOPUS_GPIO_GET,
    SS_CMD_OCTOPUS_ADC_GET,

    SS_CMD_INA_R2R_SWEEP,
    SS_CMD_UART_TRANSACT,
    SS_CMD_COMMHUB_REGISTER_READ,
    SS_CMD_COMMHUB_REGISTER_WRITE,
    SS_CMD_UART_TRANSACT_LONG,

    SS_CMD_START_EXPERIMENT,
    SS_CMD_END_EXPERIMENT,
    SS_CMD_GET_LAST_RESULTS,
    SS_CMD_SET_EXPERIMENTS_ENABLED,
    SS_CMD_NEXT_EXPERIMENT,

    SS_CMD_SVIP_TRANSACT,
};

//! THERMAL subsystem commands
enum ss_cmd_thermal_e {
	SS_CMD_THERMAL_SET_MATRIX_KEY = SS_CMD_SS_START,
	SS_CMD_THERMAL_GET_STATUS,
};
//! @}

//! Command handler data type
typedef retval_t(*ss_command_handler_t)(const struct subsystem_t *self, frame_t * frame_in, frame_t * frame_out, uint32_t sequence_number);

retval_t ss_cmd_get_name(const struct subsystem_t *self, frame_t * iframe, frame_t * oframe);
retval_t ss_get_telemetry_beacon(const struct subsystem_t *self, frame_t * oframe, uint32_t seqnum);
retval_t ss_get_telemetry_beacon_short(const struct subsystem_t *self, frame_t * oframe, uint32_t seqnum);
retval_t ss_get_telemetry_beacon_ascii(const struct subsystem_t *self, frame_t * oframe, uint32_t seqnum);
retval_t ss_cmd_run_test(const struct subsystem_t *self, frame_t * iframe, frame_t * oframe);

//! Declare a command handler (inside a subsystem's command list)
/*!
 * 	\param cmd_id Command id (index in \ref command_indexes)
 * 	\param cmd_handler Handler for this command
 *
 */
#define DECLARE_COMMAND(cmd_id, cmd_handler, cmd_name, cmd_description, cmd_args_format, cmd_ans_format)\
   [cmd_id] = (ss_command_handler_t)&cmd_handler

//! Declare a subsystem's basic commands (start, telemetry beacons, get name and test)
/*!
 * 	\param telemetryFormat Format (data type) for SS_CMD_GET_TELEMETRY_BEACON command
 * 	\param shortTelemetryFormat Format (data type) for SS_CMD_GET_TELEMETRY_BEACON_SHORT command
 */
#define DECLARE_BASIC_COMMANDS(telemetryFormat, shortTelemetryFormat)	\
	ARRAY_INITIALIZE_DEFAULT_VALUE(SS_CMD_SS_START, ss_command_handler_t), \
	DECLARE_COMMAND(SS_CMD_GET_NAME, ss_cmd_get_name, "name", "Get subsystem name", "", "name:str"),	\
	DECLARE_COMMAND(SS_CMD_GET_TELEMETRY_BEACON, cmd_get_telemetry_beacon, "telemetry", "Retrieves a telemetry report from the sybsystem", "", telemetryFormat),	\
	DECLARE_COMMAND(SS_CMD_GET_TELEMETRY_BEACON_SHORT, cmd_get_telemetry_beacon_short, "shortRelemetry", "Retrieves a very short telemetry report from the sybsystem", "", shortTelemetryFormat),	\
	DECLARE_COMMAND(SS_CMD_GET_TELEMETRY_BEACON_ASCII, cmd_get_telemetry_beacon_ascii, "asciiTelemetry", "Retrieves an ascii telemetry, mainly for HAM operators", "", "message:str"),	\
	DECLARE_COMMAND(SS_CMD_RUN_TEST, ss_cmd_run_test, "run", "Run one cmockery test", "test:u32", "failed:u8")

#endif	/* __COMMAND_H__ */

