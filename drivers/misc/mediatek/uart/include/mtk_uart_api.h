
#ifndef __MTK_UART_EXPORTED_API__
#define __MTK_UART_EXPORTED_API__

int request_uart_to_sleep(void);
int request_uart_to_wakeup(void);

void mtk_uart_dump_reg(char *s);
int mtk_uart_dump_timeout_cnt(void);

void stop_log(void);
void dump_uart_history(void);

#endif /* __MTK_UART_EXPORTED_API__ */
