
#ifndef __MT_MACH_DBG_H
#define __MT_MACH_DBG_H

unsigned int *mt_save_dbg_regs(unsigned int *p, unsigned int cpuid);
void mt_restore_dbg_regs(unsigned int *p, unsigned int cpuid);
void mt_copy_dbg_regs(int to, int from);

#endif  /* ! __MT_MACH_DBG_H */
