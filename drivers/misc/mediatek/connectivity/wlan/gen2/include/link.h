
#ifndef _LINK_H
#define _LINK_H


#include "gl_typedef.h"

/* May cause page fault & unalignment issue (data abort) */
#define INVALID_LINK_POISON1    ((VOID *) 0x00100101)
/* Used to verify that nonbody uses non-initialized link entries. */
#define INVALID_LINK_POISON2    ((VOID *) 0x00100201)

/* Simple Doubly Linked List Structures - Entry Part */
typedef struct _LINK_ENTRY_T {
	struct _LINK_ENTRY_T *prNext, *prPrev;
} LINK_ENTRY_T, *P_LINK_ENTRY_T;

/* Simple Doubly Linked List Structures - List Part */
typedef struct _LINK_T {
	P_LINK_ENTRY_T prNext;
	P_LINK_ENTRY_T prPrev;
	UINT_32 u4NumElem;
} LINK_T, *P_LINK_T;

struct LINK_MGMT {
	LINK_T rUsingLink;
	LINK_T rFreeLink;
};



#if 0				/* No one use it, temporarily mark it for [Lint - Info 773] */
#define LINK_ADDR(rLink)        { (P_LINK_ENTRY_T)(&(rLink)), (P_LINK_ENTRY_T)(&(rLink)), 0 }

#define LINK_DECLARATION(rLink) \
	struct _LINK_T rLink = LINK_ADDR(rLink)
#endif

#define LINK_INITIALIZE(prLink) \
	do { \
		((P_LINK_T)(prLink))->prNext = (P_LINK_ENTRY_T)(prLink); \
		((P_LINK_T)(prLink))->prPrev = (P_LINK_ENTRY_T)(prLink); \
		((P_LINK_T)(prLink))->u4NumElem = 0; \
	} while (0)

#define LINK_MGMT_INIT(prLinkMgmt) \
	do { \
		LINK_INITIALIZE(&((struct LINK_MGMT *)prLinkMgmt)->rUsingLink); \
		LINK_INITIALIZE(&((struct LINK_MGMT *)prLinkMgmt)->rFreeLink); \
	} while (0)

#define LINK_MGMT_GET_ENTRY(prLinkMgmt, prEntry, EntryType, memType) \
	do { \
		LINK_REMOVE_HEAD(&((struct LINK_MGMT *)prLinkMgmt)->rFreeLink, \
			prEntry, EntryType*); \
		if (!prEntry) \
			prEntry = kalMemAlloc(sizeof(EntryType), memType); \
	} while (0)

#define LINK_MGMT_UNINIT(prLinkMgmt, EntryType, memType) \
	do { \
		EntryType *prEntry = NULL; \
		P_LINK_T prFreeList = &((struct LINK_MGMT *)prLinkMgmt)->rFreeLink; \
		P_LINK_T prUsingList = &((struct LINK_MGMT *)prLinkMgmt)->rUsingLink; \
		LINK_REMOVE_HEAD(prFreeList, prEntry, EntryType *); \
		while (prEntry) { \
			kalMemFree(prEntry, memType, sizeof(EntryType)); \
			LINK_REMOVE_HEAD(prFreeList, prEntry, EntryType *); \
		} \
		LINK_REMOVE_HEAD(prUsingList, prEntry, EntryType *); \
		while (prEntry) { \
			kalMemFree(prEntry, memType, sizeof(EntryType)); \
			LINK_REMOVE_HEAD(prUsingList, prEntry, EntryType *); \
		} \
	} while (0)

#define LINK_ENTRY_INITIALIZE(prEntry) \
	do { \
		((P_LINK_ENTRY_T)(prEntry))->prNext = (P_LINK_ENTRY_T)NULL; \
		((P_LINK_ENTRY_T)(prEntry))->prPrev = (P_LINK_ENTRY_T)NULL; \
	} while (0)

#define LINK_ENTRY_INVALID(prEntry) \
	do { \
		((P_LINK_ENTRY_T)(prEntry))->prNext = (P_LINK_ENTRY_T)INVALID_LINK_POISON1; \
		((P_LINK_ENTRY_T)(prEntry))->prPrev = (P_LINK_ENTRY_T)INVALID_LINK_POISON2; \
	} while (0)

#define LINK_ENTRY_IS_VALID(prEntry) \
	(((P_LINK_ENTRY_T)(prEntry))->prNext != (P_LINK_ENTRY_T)NULL && \
		((P_LINK_ENTRY_T)(prEntry))->prNext != (P_LINK_ENTRY_T)INVALID_LINK_POISON1 && \
		((P_LINK_ENTRY_T)(prEntry))->prPrev != (P_LINK_ENTRY_T)NULL && \
		((P_LINK_ENTRY_T)(prEntry))->prPrev != (P_LINK_ENTRY_T)INVALID_LINK_POISON2)

#define LINK_IS_EMPTY(prLink)           (((P_LINK_T)(prLink))->prNext == (P_LINK_ENTRY_T)(prLink))

#define LINK_IS_INVALID(prLink)         (((P_LINK_T)(prLink))->prNext == (P_LINK_ENTRY_T)NULL)

#define LINK_IS_VALID(prLink)           (((P_LINK_T)(prLink))->prNext != (P_LINK_ENTRY_T)NULL)

#define LINK_ENTRY(ptr, type, member)   ENTRY_OF(ptr, type, member)

/* Insert an entry into a link list's head */
#define LINK_INSERT_HEAD(prLink, prEntry) \
	{ \
		linkAdd(prEntry, prLink); \
		((prLink)->u4NumElem)++; \
	}

/* Append an entry into a link list's tail */
#define LINK_INSERT_TAIL(prLink, prEntry) \
	{ \
		linkAddTail(prEntry, prLink); \
		((prLink)->u4NumElem)++; \
	}

/* Peek head entry, but keep still in link list */
#define LINK_PEEK_HEAD(prLink, _type, _member) \
	( \
		LINK_IS_EMPTY(prLink) ? \
		(_type *)NULL : LINK_ENTRY((prLink)->prNext, _type, _member) \
	)

/* Peek tail entry, but keep still in link list */
#define LINK_PEEK_TAIL(prLink, _type, _member) \
	( \
		LINK_IS_EMPTY(prLink) ? \
		(_type *)NULL : LINK_ENTRY((prLink)->prPrev, _type, _member) \
	)

/* Get first entry from a link list */
#define LINK_REMOVE_HEAD(prLink, prEntry, _P_TYPE) \
	{ \
		ASSERT(prLink); \
		if (LINK_IS_EMPTY(prLink)) { \
			prEntry = (_P_TYPE)NULL; \
		} \
		else { \
			prEntry = (_P_TYPE)(((P_LINK_T)(prLink))->prNext); \
			linkDel((P_LINK_ENTRY_T)prEntry); \
			((prLink)->u4NumElem)--; \
		} \
	}

#define LINK_REMOVE_KNOWN_ENTRY(prLink, prEntry) \
	{ \
		ASSERT(prLink); \
		ASSERT(prEntry); \
		linkDel((P_LINK_ENTRY_T)prEntry); \
		((prLink)->u4NumElem)--; \
	}

/* Iterate over a link list */
#define LINK_FOR_EACH(prEntry, prLink) \
	for (prEntry = (prLink)->prNext; \
		prEntry != (P_LINK_ENTRY_T)(prLink); \
		prEntry = (P_LINK_ENTRY_T)prEntry->prNext)

/* Iterate over a link list backwards */
#define LINK_FOR_EACH_PREV(prEntry, prLink) \
	for (prEntry = (prLink)->prPrev; \
		prEntry != (P_LINK_ENTRY_T)(prLink); \
		prEntry = (P_LINK_ENTRY_T)prEntry->prPrev)

/* Iterate over a link list safe against removal of link entry */
#define LINK_FOR_EACH_SAFE(prEntry, prNextEntry, prLink) \
	for (prEntry = (prLink)->prNext, prNextEntry = prEntry->prNext; \
		prEntry != (P_LINK_ENTRY_T)(prLink); \
		prEntry = prNextEntry, prNextEntry = prEntry->prNext)

/* Iterate over a link list of given type */
#define LINK_FOR_EACH_ENTRY(prObj, prLink, rMember, _TYPE) \
	for (prObj = LINK_ENTRY((prLink)->prNext, _TYPE, rMember); \
		&prObj->rMember != (P_LINK_ENTRY_T)(prLink); \
		prObj = LINK_ENTRY(prObj->rMember.prNext, _TYPE, rMember))

/* Iterate backwards over a link list of given type */
#define LINK_FOR_EACH_ENTRY_PREV(prObj, prLink, rMember, _TYPE) \
	for (prObj = LINK_ENTRY((prLink)->prPrev, _TYPE, rMember);  \
		&prObj->rMember != (P_LINK_ENTRY_T)(prLink); \
		prObj = LINK_ENTRY(prObj->rMember.prPrev, _TYPE, rMember))

/* Iterate over a link list of given type safe against removal of link entry */
#define LINK_FOR_EACH_ENTRY_SAFE(prObj, prNextObj, prLink, rMember, _TYPE) \
	for (prObj = LINK_ENTRY((prLink)->prNext, _TYPE, rMember),  \
				prNextObj = LINK_ENTRY(prObj->rMember.prNext, _TYPE, rMember); \
		&prObj->rMember != (P_LINK_ENTRY_T)(prLink); \
		prObj = prNextObj, \
		prNextObj = LINK_ENTRY(prNextObj->rMember.prNext, _TYPE, rMember))


/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
static inline VOID __linkAdd(IN P_LINK_ENTRY_T prNew, IN P_LINK_ENTRY_T prPrev, IN P_LINK_ENTRY_T prNext)
{
	prNext->prPrev = prNew;
	prNew->prNext = prNext;
	prNew->prPrev = prPrev;
	prPrev->prNext = prNew;

}				/* end of __linkAdd() */

/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
static inline VOID linkAdd(IN P_LINK_ENTRY_T prNew, IN P_LINK_T prLink)
{
	__linkAdd(prNew, (P_LINK_ENTRY_T) prLink, prLink->prNext);

}				/* end of linkAdd() */

/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
static inline VOID linkAddTail(IN P_LINK_ENTRY_T prNew, IN P_LINK_T prLink)
{
	__linkAdd(prNew, prLink->prPrev, (P_LINK_ENTRY_T) prLink);

}				/* end of linkAddTail() */

/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
static inline VOID __linkDel(IN P_LINK_ENTRY_T prPrev, IN P_LINK_ENTRY_T prNext)
{
	prNext->prPrev = prPrev;
	prPrev->prNext = prNext;

}				/* end of __linkDel() */

/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
static inline VOID linkDel(IN P_LINK_ENTRY_T prEntry)
{
	__linkDel(prEntry->prPrev, prEntry->prNext);

	LINK_ENTRY_INITIALIZE(prEntry);

}				/* end of linkDel() */

/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
static inline VOID linkMove(IN P_LINK_ENTRY_T prEntry, IN P_LINK_T prLink)
{
	__linkDel(prEntry->prPrev, prEntry->prNext);
	linkAdd(prEntry, prLink);

}				/* end of linkMove() */

/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
static inline VOID linkMoveTail(IN P_LINK_ENTRY_T prEntry, IN P_LINK_T prLink)
{
	__linkDel(prEntry->prPrev, prEntry->prNext);
	linkAddTail(prEntry, prLink);

}				/* end of linkMoveTail() */

#endif /* _LINK_H */
