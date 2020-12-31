
#ifndef MTK_DRM_DDP_COMP_H
#define MTK_DRM_DDP_COMP_H

#include <linux/io.h>

struct device;
struct device_node;
struct drm_crtc;
struct drm_device;
struct mtk_plane_state;

enum mtk_ddp_comp_type {
	MTK_DISP_OVL,
	MTK_DISP_RDMA,
	MTK_DISP_WDMA,
	MTK_DISP_COLOR,
	MTK_DISP_AAL,
	MTK_DISP_GAMMA,
	MTK_DISP_UFOE,
	MTK_DSI,
	MTK_DPI,
	MTK_DISP_PWM,
	MTK_DISP_MUTEX,
	MTK_DISP_OD,
	MTK_DISP_BLS,
	MTK_DDP_COMP_TYPE_MAX,
};

enum mtk_ddp_comp_id {
	DDP_COMPONENT_AAL,
	DDP_COMPONENT_COLOR0,
	DDP_COMPONENT_COLOR1,
	DDP_COMPONENT_DPI0,
	DDP_COMPONENT_DSI0,
	DDP_COMPONENT_DSI1,
	DDP_COMPONENT_GAMMA,
	DDP_COMPONENT_OD,
	DDP_COMPONENT_OVL0,
	DDP_COMPONENT_OVL1,
	DDP_COMPONENT_PWM0,
	DDP_COMPONENT_PWM1,
	DDP_COMPONENT_RDMA0,
	DDP_COMPONENT_RDMA1,
	DDP_COMPONENT_RDMA2,
	DDP_COMPONENT_UFOE,
	DDP_COMPONENT_WDMA0,
	DDP_COMPONENT_WDMA1,
	DDP_COMPONENT_BLS,
	DDP_COMPONENT_ID_MAX,
};

struct mtk_ddp_comp;

struct mtk_ddp_comp_funcs {
	void (*config)(struct mtk_ddp_comp *comp, unsigned int w,
		       unsigned int h, unsigned int vrefresh);
	void (*start)(struct mtk_ddp_comp *comp);
	void (*stop)(struct mtk_ddp_comp *comp);
	void (*enable_vblank)(struct mtk_ddp_comp *comp, struct drm_crtc *crtc);
	void (*disable_vblank)(struct mtk_ddp_comp *comp);
	void (*layer_on)(struct mtk_ddp_comp *comp, unsigned int idx);
	void (*layer_off)(struct mtk_ddp_comp *comp, unsigned int idx);
	void (*layer_config)(struct mtk_ddp_comp *comp, unsigned int idx,
			     struct mtk_plane_state *state);
};

struct mtk_ddp_comp_driver_data {
	enum mtk_ddp_comp_type comp_type;
	bool do_shadow_reg;
	union {
		struct ovl {
			unsigned int addr_offset;
			unsigned int fmt_rgb565;
			unsigned int fmt_rgb888;
		} ovl;
		unsigned int rdma_fifo_pseudo_size;
		unsigned int color_offset;
	};
};

struct mtk_ddp_comp {
	struct clk *clk;
	void __iomem *regs;
	int irq;
	struct device *larb_dev;
	enum mtk_ddp_comp_id id;
	const struct mtk_ddp_comp_funcs *funcs;
	struct mtk_ddp_comp_driver_data *data;
};

static inline void mtk_ddp_comp_config(struct mtk_ddp_comp *comp,
				       unsigned int w, unsigned int h,
				       unsigned int vrefresh)
{
	if (comp->funcs && comp->funcs->config)
		comp->funcs->config(comp, w, h, vrefresh);
}

static inline void mtk_ddp_comp_start(struct mtk_ddp_comp *comp)
{
	if (comp->funcs && comp->funcs->start)
		comp->funcs->start(comp);
}

static inline void mtk_ddp_comp_stop(struct mtk_ddp_comp *comp)
{
	if (comp->funcs && comp->funcs->stop)
		comp->funcs->stop(comp);
}

static inline void mtk_ddp_comp_enable_vblank(struct mtk_ddp_comp *comp,
					      struct drm_crtc *crtc)
{
	if (comp->funcs && comp->funcs->enable_vblank)
		comp->funcs->enable_vblank(comp, crtc);
}

static inline void mtk_ddp_comp_disable_vblank(struct mtk_ddp_comp *comp)
{
	if (comp->funcs && comp->funcs->disable_vblank)
		comp->funcs->disable_vblank(comp);
}

static inline void mtk_ddp_comp_layer_on(struct mtk_ddp_comp *comp,
					 unsigned int idx)
{
	if (comp->funcs && comp->funcs->layer_on)
		comp->funcs->layer_on(comp, idx);
}

static inline void mtk_ddp_comp_layer_off(struct mtk_ddp_comp *comp,
					  unsigned int idx)
{
	if (comp->funcs && comp->funcs->layer_off)
		comp->funcs->layer_off(comp, idx);
}

static inline void mtk_ddp_comp_layer_config(struct mtk_ddp_comp *comp,
					     unsigned int idx,
					     struct mtk_plane_state *state)
{
	if (comp->funcs && comp->funcs->layer_config)
		comp->funcs->layer_config(comp, idx, state);
}

int mtk_ddp_comp_get_id(struct device_node *node,
			enum mtk_ddp_comp_type comp_type);
int mtk_ddp_comp_init(struct device *dev, struct device_node *comp_node,
		      struct mtk_ddp_comp *comp, enum mtk_ddp_comp_id comp_id,
		      const struct mtk_ddp_comp_funcs *funcs);
int mtk_ddp_comp_register(struct drm_device *drm, struct mtk_ddp_comp *comp);
void mtk_ddp_comp_unregister(struct drm_device *drm, struct mtk_ddp_comp *comp);

#endif /* MTK_DRM_DDP_COMP_H */
