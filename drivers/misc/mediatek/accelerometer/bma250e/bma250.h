#ifndef BMA250_H
#define BMA250_H

#include <linux/ioctl.h>

#define BMA250_I2C_SLAVE_WRITE_ADDR		0x30

	 /* BMA222 Register Map  (Please refer to BMA150 Specifications) */
#define BMA250_REG_DEVID				0x00
#define BMA250_FIXED_DEVID			0x03
#define BMA250E_FIXED_DEVID			0xF9
#define BMA250_REG_OFSX				0x16
#define BMA250_REG_OFSX_HIGH			0x1A
#define BMA250_REG_BW_RATE			0x10
#define BMA250_BW_MASK				0x1f
#define BMA250_BW_200HZ				0x0d
#define BMA250_BW_100HZ				0x0c
#define BMA250_BW_50HZ				0x0b
#define BMA250_BW_25HZ				0x0a
#define BMA250_REG_POWER_CTL		0x11
#define BMA250_REG_DATA_FORMAT		0x0f
#define BMA250_RANGE_MASK			0x0f
#define BMA250_RANGE_2G				0x03
#define BMA250_RANGE_4G				0x05
#define BMA250_RANGE_8G				0x08
#define BMA250_REG_DATAXLOW			0x02
#define BMA250_REG_DATA_RESOLUTION	0x14
#define BMA250_MEASURE_MODE			0x80
#define BMA250_SELF_TEST				0x32
#define BMA250_SELF_TEST_AXIS_X		0x01
#define BMA250_SELF_TEST_AXIS_Y		0x02
#define BMA250_SELF_TEST_AXIS_Z		0x03
#define BMA250_SELF_TEST_POSITIVE	0x00
#define BMA250_SELF_TEST_NEGATIVE	0x04
#define BMA250_INT_REG_1				0x16
#define BMA250_INT_REG_2				0x17
#define BMA250_EEPROM_CTL_REG       0x33
#define BMA250_RESERVED_REG_1       0x3E
#define BMA250E_RESERVED_REG_1      0x3B

#define BMA250_SUCCESS						0
#define BMA250_ERR_I2C						-1
#define BMA250_ERR_STATUS					-3
#define BMA250_ERR_SETUP_FAILURE			-4
#define BMA250_ERR_GETGSENSORDATA			-5
#define BMA250_ERR_IDENTIFICATION			-6



#define BMA250_BUFSIZE				256

/*----------------------------------------------------------------------------*/
#define BMA250_AXIS_X          0
#define BMA250_AXIS_Y          1
#define BMA250_AXIS_Z          2
#define BMA250_AXES_NUM        3
#define BMA250_DATA_LEN        6
#define BMA250_DEV_NAME        "BMA250"

/*----------------------------------------------------------------------------*/
enum CUST_ACTION {
	BMA250_CUST_ACTION_SET_CUST = 1,
	BMA250_CUST_ACTION_SET_CALI,
	BMA250_CUST_ACTION_RESET_CALI
};
/*----------------------------------------------------------------------------*/
struct BMA250_CUST {
	uint16_t action;
};
/*----------------------------------------------------------------------------*/
struct BMA250_SET_CUST {
	uint16_t action;
	uint16_t part;
	int32_t data[0];
};
/*----------------------------------------------------------------------------*/
struct BMA250_SET_CALI {
	uint16_t action;
	int32_t data[BMA250_AXES_NUM];
};
/*----------------------------------------------------------------------------*/
union BMA250_CUST_DATA {
	uint32_t data[10];
	struct BMA250_CUST cust;
	struct BMA250_SET_CUST setCust;
	struct BMA250_SET_CALI setCali;
	struct BMA250_CUST resetCali;
};
/*----------------------------------------------------------------------------*/


#endif
