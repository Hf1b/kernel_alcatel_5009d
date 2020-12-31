
#ifndef _CNM_TIMER_H
#define _CNM_TIMER_H



#undef MSEC_PER_SEC
#define MSEC_PER_SEC                    1000
#undef USEC_PER_MSEC
#define USEC_PER_MSEC                   1000
#define USEC_PER_TU                     1024	/* microsecond */

#define MSEC_PER_MIN                    (60 * MSEC_PER_SEC)

#define MGMT_MAX_TIMEOUT_INTERVAL       ((UINT_32)0x7fffffff)

#define WAKE_LOCK_MAX_TIME              5	/* Unit: sec */

#if (WAKE_LOCK_MAX_TIME >= OBSS_SCAN_MIN_INTERVAL)
#error WAKE_LOCK_MAX_TIME is too large
#endif

typedef VOID(*PFN_MGMT_TIMEOUT_FUNC) (P_ADAPTER_T, ULONG);

typedef struct _TIMER_T {
	LINK_ENTRY_T rLinkEntry;
	OS_SYSTIME rExpiredSysTime;
	UINT_16 u2Minutes;
	UINT_16 u2Reserved;
	ULONG ulData;
	PFN_MGMT_TIMEOUT_FUNC pfMgmtTimeOutFunc;
} TIMER_T, *P_TIMER_T;



/* Check if time "a" is before time "b" */
#define TIME_BEFORE_64bit(a, b)       (a < b)

#define TIME_BEFORE(a, b)        ((UINT_32)((UINT_32)(a) - (UINT_32)(b)) > 0x7fffffff)


#define TIME_AFTER(a, b)         TIME_BEFORE(b, a)

#define SYSTIME_TO_SEC(_systime)            ((_systime) / KAL_HZ)
#define SEC_TO_SYSTIME(_sec)                ((_sec) * KAL_HZ)

/* The macros to convert second & millisecond */
#define MSEC_TO_SEC(_msec)                  ((_msec) / MSEC_PER_SEC)
#define SEC_TO_MSEC(_sec)                   ((UINT_32)(_sec) * MSEC_PER_SEC)

/* The macros to convert millisecond & microsecond */
#define USEC_TO_MSEC(_usec)                 ((_usec) / USEC_PER_MSEC)
#define MSEC_TO_USEC(_msec)                 ((UINT_32)(_msec) * USEC_PER_MSEC)

/* The macros to convert TU & microsecond, TU & millisecond */
#define TU_TO_USEC(_tu)                     ((_tu) * USEC_PER_TU)
#define TU_TO_MSEC(_tu)                     USEC_TO_MSEC(TU_TO_USEC(_tu))

/* The macros to convert TU & & OS system time, round up by 0.5 */
#define TU_TO_SYSTIME(_tu)                  MSEC_TO_SYSTIME(TU_TO_MSEC(_tu))
#define SYSTIME_TO_TU(_systime)             \
	((SYSTIME_TO_USEC(_systime) + ((USEC_PER_TU / 2) - 1)) / USEC_PER_TU)

/* The macros to convert OS system time & microsecond */
#define SYSTIME_TO_USEC(_systime)           (SYSTIME_TO_MSEC(_systime) * USEC_PER_MSEC)

/* The macro to get the current OS system time */
#define GET_CURRENT_SYSTIME(_systime_p)     {*(_systime_p) = kalGetTimeTick(); }

/* The macro to copy the system time */
#define COPY_SYSTIME(_destTime, _srcTime)   {(_destTime) = (_srcTime); }

/* The macro to get the system time difference between t1 and t2 (t1 - t2) */

/* The macro to check for the expiration, if TRUE means _currentTime >= _expirationTime */
#define CHECK_FOR_EXPIRATION(_currentTime, _expirationTime) \
	(((UINT_32)(_currentTime) - (UINT_32)(_expirationTime)) <= 0x7fffffffUL)

/* The macro to check for the timeout */
#define CHECK_FOR_TIMEOUT(_currentTime, _timeoutStartingTime, _timeout) \
	CHECK_FOR_EXPIRATION((_currentTime), ((_timeoutStartingTime) + (_timeout)))

/* The macro to set the expiration time with a specified timeout *//* Watch out for round up. */
#define SET_EXPIRATION_TIME(_expirationTime, _timeout) \
	{ \
	    GET_CURRENT_SYSTIME(&(_expirationTime)); \
	    (_expirationTime) += (OS_SYSTIME)(_timeout); \
	}

#define timerRenewTimer(adapter, tmr, interval) \
	timerStartTimer(adapter, tmr, interval, (tmr)->function, (tmr)->data)

#define MGMT_INIT_TIMER(_adapter_p, _timer, _callbackFunc) \
	timerInitTimer(_adapter_p, &(_timer), (ULONG)(_callbackFunc))

VOID cnmTimerInitialize(IN P_ADAPTER_T prAdapter);

VOID cnmTimerDestroy(IN P_ADAPTER_T prAdapter);

VOID
cnmTimerInitTimer(IN P_ADAPTER_T prAdapter, IN P_TIMER_T prTimer, IN PFN_MGMT_TIMEOUT_FUNC pfFunc, IN ULONG ulData);

VOID cnmTimerStopTimer(IN P_ADAPTER_T prAdapter, IN P_TIMER_T prTimer);

VOID cnmTimerStartTimer(IN P_ADAPTER_T prAdapter, IN P_TIMER_T prTimer, IN UINT_32 u4TimeoutMs);

VOID cnmTimerDoTimeOutCheck(IN P_ADAPTER_T prAdapter);

static inline INT_32 timerPendingTimer(IN P_TIMER_T prTimer)
{
	ASSERT(prTimer);

	return prTimer->rLinkEntry.prNext != NULL;
}

#endif /* _CNM_TIMER_H */
