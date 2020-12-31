
#ifndef __MT6397_RTC_MISC_H__
#define __MT6397_RTC_MISC_H__

#ifdef CONFIG_MT6397_MISC
extern void mtk_misc_mark_fast(void);
extern void mtk_misc_mark_recovery(void);
extern bool mtk_misc_low_power_detected(void);
extern bool mtk_misc_crystal_exist_status(void);
extern int mtk_misc_set_spare_fg_value(u32 val);
extern u32 mtk_misc_get_spare_fg_value(void);
#else
#define mtk_misc_mark_fast()			do {} while (0)
#define mtk_misc_mark_recovey()			do {} while (0)
#define mtk_misc_low_power_detected()		do {} while (0)
#define mtk_misc_crystal_exist_status()		do {} while (0)
#define mtk_misc_set_spare_fg_value(val)	do {} while (0)
#define mtk_misc_get_spare_fg_value()		do {} while (0)
#endif
#endif /* __MT6397_RTC_MISC_H__ */

