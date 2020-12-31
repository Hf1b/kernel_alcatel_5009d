
#ifndef __DDP_PWM_MUX_H__
#define __DDP_PWM_MUX_H__

int disp_pwm_set_pwmmux(unsigned int clk_req);

int disp_pwm_clksource_enable(int clk_req);

int disp_pwm_clksource_disable(int clk_req);

bool disp_pwm_mux_is_osc(void);

#if defined(CONFIG_ARCH_MT6757)
void disp_pwm_ulposc_cali(void);

void disp_pwm_ulposc_query(char *debug_output);
#endif

#endif
