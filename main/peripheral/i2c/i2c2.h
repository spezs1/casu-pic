/*! \file i2c2.h
 * \brief Declaration of functions and variables used for working with i2c2.
 */
 
#ifndef I2C2_H
#define	I2C2_H

#if defined(__PIC24F__)
#include <p24Fxxxx.h>
#elif defined(__dsPIC33F__)
#include <p33Fxxxx.h>
#elif defined(__dsPIC33E__)
#include <p33Exxxx.h>
#endif

#include <Generic.h>

/*! I2C address of the dsPIC 
 */
#define I2C2_CASU_ADD 0x11

/*! Size of the buffers used for transmitting (tx) and receiving data (rx). 
 */
#define BUFF_SIZE 64
/*! Wait time in number of simple while loop cycles. Used for i2c fault diagnostic.
 */

#define FFT_BUFF 256

#define BUFF_SIZE_ACC 512

#define WAIT_TIME 100

#define I2C1_DEBUG 1

#define OUT_MEAS_DATA_NUM 55

// msg ids
#define MSG_RESET_ID 1
#define MSG_CAL_ID 2
#define MSG_REF_VIBE_ID 3
#define MSG_REF_LED_ID 4
#define MSG_REF_TEMP_ID 5
#define MSG_REF_PROXY_ID 6
#define MSG_MEASUREMENT_FAST_ID 11
#define MSG_MEASUREMENT_SLOW_ID 12
#define MSG_MEASUREMENT_ACC_ID 13


#define IN_RESET_DATA_NUM 2
#define IN_CAL_DATA_NUM 13
#define IN_VIBE_REF_DATA_NUM 4
#define IN_LED_REF_DATA_NUM 4
#define IN_TEMP_REF_DATA_NUM 3
#define IN_PROXY_REF_DATA_NUM 2
#define IN_MSG_MEASUREMENT_REQUEST_NUM 2

extern UINT8 msg_id;
extern UINT16 msg_rec_bytes;
extern UINT8 msg_status;
extern UINT8 i2cStarted;

/*! Buffer for incoming data (rx buffer).
 */
extern UINT8 i2c2_rx_buff[BUFF_SIZE];

/*! Buffer for outgoing data (tx buffer).
 */
extern UINT8 i2c2_tx_buff[BUFF_SIZE];
extern UINT8 i2c2_tx_buff_fast[BUFF_SIZE];
extern UINT8 i2c2_tx_buff_acc[BUFF_SIZE_ACC];
extern UINT8 i2c2_tx_ready;

extern void updateReferences(UINT8 msg_id);
extern void updateCalibrationData();

/*! \brief Function initializes i2c2 module as a slave device.
 *
 * @param address Address of the i2c2 module used as a slave device.
 * @param int_priority Priority of i2c2 interrupt routine used for exchanging data with master.
 * @return Device successfully configured and initialized.
 */
UINT8 I2C2SlaveInit(UINT8 address, UINT8 int_priority);

#endif	/* I2C2_H */

