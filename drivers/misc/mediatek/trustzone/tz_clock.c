

#include <linux/module.h>
#include <linux/types.h>
#include <linux/clk.h>

#include "tz_cross/trustzone.h"
#include "trustzone/kree/system.h"
#include "kree_int.h"

#ifdef CONFIG_OF
TZ_RESULT KREE_ServEnableClock(u32 op, u8 uparam[REE_SERVICE_BUFFER_SIZE])
{
	struct ree_service_clock *param = (struct ree_service_clock *)uparam;
	struct clk *clk = mtee_clk_get(param->clk_name);

	if (clk == NULL) {
		pr_warn("can not find clk %s\n", param->clk_name);
		return TZ_RESULT_ERROR_GENERIC;
	}

	clk_prepare_enable(clk);

	return TZ_RESULT_SUCCESS;
}

TZ_RESULT KREE_ServDisableClock(u32 op, u8 uparam[REE_SERVICE_BUFFER_SIZE])
{
	struct ree_service_clock *param = (struct ree_service_clock *)uparam;
	struct clk *clk = mtee_clk_get(param->clk_name);

	if (clk == NULL) {
		pr_warn("can not find clk %s\n", param->clk_name);
		return TZ_RESULT_ERROR_GENERIC;
	}

	clk_disable_unprepare(clk);

	return TZ_RESULT_SUCCESS;
}
#else
TZ_RESULT KREE_ServEnableClock(u32 op, u8 uparam[REE_SERVICE_BUFFER_SIZE])
{
/*	struct ree_service_clock *param = (struct ree_service_clock *)uparam; */
	TZ_RESULT ret = TZ_RESULT_ERROR_GENERIC;
/*	int rret; */

/*	rret = enable_clock(param->clk_id, param->clk_name); */
/*	if (rret < 0) */
/*		ret = TZ_RESULT_ERROR_GENERIC; */

	return ret;
}

TZ_RESULT KREE_ServDisableClock(u32 op, u8 uparam[REE_SERVICE_BUFFER_SIZE])
{
/*	struct ree_service_clock *param = (struct ree_service_clock *)uparam; */
	TZ_RESULT ret = TZ_RESULT_ERROR_GENERIC;
/*	int rret; */

/*	rret = disable_clock(param->clk_id, param->clk_name); */
/*	if (rret < 0) */
/*		ret = TZ_RESULT_ERROR_GENERIC; */

	return ret;
}
#endif
