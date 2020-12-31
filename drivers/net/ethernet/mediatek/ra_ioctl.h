
#ifndef _RAETH_IOCTL_H
#define _RAETH_IOCTL_H

#define RAETH_MII_READ                  0x89F3
#define RAETH_MII_WRITE                 0x89F4
#define RAETH_ESW_REG_READ              0x89F1
#define RAETH_ESW_REG_WRITE             0x89F2
#define RAETH_MII_READ_CL45             0x89FC
#define RAETH_MII_WRITE_CL45            0x89FD
#define REG_ESW_MAX                     0xFC

struct rt3052_esw_reg {
	unsigned int off;
	unsigned int val;
};

struct ra_mii_ioctl_data {
	unsigned int phy_id;
	unsigned int reg_num;
	unsigned int val_in;
	unsigned int val_out;
	unsigned int port_num;
	unsigned int dev_addr;
	unsigned int reg_addr;
};

#endif
