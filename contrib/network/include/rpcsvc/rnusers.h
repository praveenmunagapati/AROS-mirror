/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _RNUSERS_H_RPCGEN
#define _RNUSERS_H_RPCGEN

#define RPCGEN_VERSION	199506

#include <rpc/rpc.h>

/*
 * The following structures are used by version 2 of the rusersd protocol.
 * They were not developed with rpcgen, so they do not appear as RPCL.
 */

#define 	RUSERSVERS_ORIG 1	/* original version */
#define	RUSERSVERS_IDLE 2
#define	MAXUSERS 100

/*
 * This is the structure used in version 2 of the rusersd RPC service.
 * It corresponds to the utmp structure for BSD sytems.
 */

#define RNUSERS_MAXUSERLEN 8
#define RNUSERS_MAXLINELEN 8
#define RNUSERS_MAXHOSTLEN 16

struct ru_utmp {
	char	*ut_line;		/* tty name */
	char	*ut_name;		/* user id */
	char	*ut_host;		/* host name, if remote */
	int	ut_time;		/* time on */
};
typedef struct ru_utmp rutmp;

struct utmparr {
	struct ru_utmp **uta_arr;
	int uta_cnt;
};
typedef struct utmparr utmparr;
int xdr_utmparr();

struct utmpidle {
	struct ru_utmp ui_utmp;
	unsigned ui_idle;
};

struct utmpidlearr {
	struct utmpidle **uia_arr;
	int uia_cnt;
};
typedef struct utmpidlearr utmpidlearr;
int xdr_utmpidlearr();

#define RUSERSVERS_1 ((u_long)1)
#define RUSERSVERS_2 ((u_long)2)
#ifndef RUSERSPROG
#define RUSERSPROG ((u_long)100002)
#endif
#ifndef RUSERSPROC_NUM
#define RUSERSPROC_NUM ((u_long)1)
#endif
#ifndef RUSERSPROC_NAMES
#define RUSERSPROC_NAMES ((u_long)2)
#endif
#ifndef RUSERSPROC_ALLNAMES
#define RUSERSPROC_ALLNAMES ((u_long)3)
#endif


#endif /* !_RNUSERS_H_RPCGEN */
