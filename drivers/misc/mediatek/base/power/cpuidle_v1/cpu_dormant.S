
        .global write_cntpctl
write_cntpctl:
        .func
        msr	CNTP_CTL_EL0, x0
        ret
        .endfunc

        .global read_cntpctl
read_cntpctl:
        .func
        mrs	x0, CNTP_CTL_EL0
        ret
        .endfunc

        .global read_cpu_id
read_cpu_id:
        .func
        mrs	x0, MPIDR_EL1
        ands	x0, x0, #0xff
        ret
        .endfunc

        .global read_cluster_id
read_cluster_id:
        .func
        mrs	x0, MPIDR_EL1
        lsr	x0, x0, #0x8
        ands	x0, x0, #0xff
        ret
        .endfunc

	.global mt_save_generic_timer
mt_save_generic_timer:
	.func
	mrs	x3, CNTKCTL_EL1
	str	x3, [x0, #0]
	mrs	x2, CNTP_CTL_EL0
	mrs	x3, CNTP_TVAL_EL0
	stp	x2, x3, [x0, #8]
	mrs	x2, CNTV_CTL_EL0
	mrs	x3, CNTV_TVAL_EL0
	stp	x2, x3, [x0, #24]!
        ret
	.endfunc

	.global mt_restore_generic_timer
mt_restore_generic_timer:
	.func
	ldr	x3, [x0, #0]
	msr	CNTKCTL_EL1, x3
	ldp	x2, x3, [x0, #8]
	msr	CNTP_CTL_EL0, x2
	msr	CNTP_TVAL_EL0, x3
	ldp	x2, x3, [x0, #24]
	msr	CNTV_CTL_EL0, x2
	msr	CNTV_TVAL_EL0, x3
        ret
	.endfunc

        .global mt_save_banked_registers
mt_save_banked_registers:
	.func
        ret
	.endfunc

        .global mt_restore_banked_registers
mt_restore_banked_registers:
	.func
        ret
	.endfunc
