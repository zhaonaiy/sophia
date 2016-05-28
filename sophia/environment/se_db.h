#ifndef SE_DB_H_
#define SE_DB_H_

/*
 * sophia database
 * sphia.org
 *
 * Copyright (c) Dmitry Simonenko
 * BSD License
*/

typedef struct sedb sedb;

struct sedb {
	so         o;
	uint32_t   created;
	siprofiler rtp;
	sischeme  *scheme;
	si        *index;
	sr        *r;
	sxindex    coindex;
	uint64_t   txn_min;
	uint64_t   txn_max;
};

static inline int
se_dbactive(sedb *o) {
	return si_active(o->index);
}

so   *se_dbnew(se*, char*, int);
so   *se_dbmatch(se*, char*);
so   *se_dbmatch_id(se*, uint32_t);
void *se_dbread(sedb*, sedocument*, sx*, uint64_t, sicache*);
int   se_dbvisible(sedb*, uint64_t);
void  se_dbbind(se*);
void  se_dbunbind(se*, uint64_t);

#endif
