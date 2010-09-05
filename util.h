/*
 * util.h
 * Copyright (C) 2010 Adrian Perez <aperez@igalia.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef __util_h__
#define __util_h__

#include <sys/types.h>
#define DMON_GID_COUNT 76

struct uidgid_s {
    uid_t    uid;
    gid_t    gid;
    unsigned ngid;
    gid_t    gids[DMON_GID_COUNT];
};
typedef struct uidgid_s uidgid_t;

#define UIDGID { 0, 0, 0, {0} }

/* uid[:gid[:gid...]] */
int parse_uidgids (char*, uidgid_t*);

int name_to_uidgid (const char*, uid_t*, gid_t*);
int name_to_gid (const char*, gid_t*);

void fd_cloexec (int);
void safe_sleep (unsigned);
int  interruptible_sleep (unsigned);
void die (const char*, ...);

void __dprintf (const char*, ...);

#ifdef DEBUG_TRACE
# define dprint(_x)  __dprintf _x
#else
# define dprint(_x)  ((void)0)
#endif /* DEBUG_TRACE */

#endif /* !__util_h__ */

/* vim: expandtab shiftwidth=4 tabstop=4
 */
