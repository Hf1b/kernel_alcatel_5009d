
#ifndef __GESTURE_H__
#define __GESTURE_H__


#include <linux/wakelock.h>
#include <linux/interrupt.h>
#include <linux/miscdevice.h>
#include <linux/platform_device.h>
#include <linux/input.h>
#include <linux/workqueue.h>
#include <linux/slab.h>
#include <linux/module.h>
#include <hwmsensor.h>
#include <hwmsen_dev.h>


#define GESTURE_TAG		            "<GESTURE> "
#define GESTURE_FUN(f)		        pr_warn(GESTURE_TAG"%s\n", __func__)
#define GESTURE_ERR(fmt, args...)	pr_warn(GESTURE_TAG"%s %d : "fmt, __func__, __LINE__, ##args)
#define GESTURE_LOG(fmt, args...)	pr_warn(GESTURE_TAG fmt, ##args)
#define GESTURE_VER(fmt, args...)   pr_warn(GESTURE_TAG"%s: "fmt, __func__, ##args)


#define	OP_GESTURE_ENABLE		0X02

#define GESTURE_VALUE_MAX (32767)
#define GESTURE_VALUE_MIN (-32768)
#define GESTURE_STATUS_MIN (0)
#define GESTURE_STATUS_MAX (64)
#define GESTURE_DIV_MAX (32767)
#define GESTURE_DIV_MIN (1)

#define GESTURE_MAX_SUPPORT  16

typedef enum {
	GESTURE_DEACTIVATE,
	GESTURE_ACTIVATE,
	GESTURE_SUSPEND,
	GESTURE_RESUME
} ges_state_e;

struct ges_control_path {
	int (*open_report_data)(int open);	/* open data rerport to HAL */
};

struct ges_data_path {
	int (*get_data)(int *value, int *status);
};

struct ges_init_info {
	char *name;
	int (*init)(void);
	int (*uninit)(void);
};

struct ges_data {
	struct hwm_sensor_data ges_data;
	int data_updata;
};

struct ges_drv_obj {
	void *self;
	int polling;
	int (*ges_operate)(void *self, uint32_t command, void *buff_in, int size_in,
			    void *buff_out, int size_out, int *actualout);
};

struct ges_data_control_context {
	struct ges_control_path ges_ctl;
	struct ges_data_path ges_data;
	bool is_active_data;
	bool is_active_nodata;
	bool is_batch_enable;
};

struct ges_context {
	struct input_dev *idev;
	struct miscdevice mdev;
	struct work_struct report;
	struct mutex ges_op_mutex;
	atomic_t wake;		/*user-space request to wake-up, used with stop */
	atomic_t trace;
	struct timer_list notify_timer;

	atomic_t early_suspend;
	atomic_t suspend;

	struct ges_data drv_data;
	struct ges_data_control_context ctl_context[GESTURE_MAX_SUPPORT];

};

typedef enum {
	inpocket	  = 0,
	stationary	  = 1,
	max_gesture   = GESTURE_MAX_SUPPORT,
} gesture_index_table;

int HandleToIndex(int handle);
extern int ges_notify(int handle);
extern int ges_driver_add(struct ges_init_info *obj, int handle);
extern int ges_register_control_path(struct ges_control_path *ctl, int handle);
extern int ges_register_data_path(struct ges_data_path *data, int handle);

#endif
