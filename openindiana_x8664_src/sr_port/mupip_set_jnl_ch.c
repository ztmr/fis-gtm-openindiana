/****************************************************************
 *								*
 *	Copyright 2001, 2003 Sanchez Computer Associates, Inc.	*
 *								*
 *	This source code contains the intellectual property	*
 *	of its copyright holder(s), and is made available	*
 *	under a license.  If you do not know the terms of	*
 *	the license, please stop and do not read further.	*
 *								*
 ****************************************************************/

#include "mdef.h"

#include "gdsroot.h"
#include "gtm_facility.h"
#include "fileinfo.h"
#include "gdsbt.h"
#include "gdsfhead.h"
#include "filestruct.h"
#include "gdsblk.h"
#include "error.h"
#include "jnl.h"
#include "mupip_exit.h"
#include "mupip_set.h"	/* for mupip_set_jnl_cleanup() prototype */

CONDITION_HANDLER(mupip_set_jnl_ch)
{
	error_def(ERR_MUNOFINISH);

	START_CH
	mupip_set_jnl_cleanup(FALSE);
	PRN_ERROR
	if (SEVERITY == ERROR  ||  SEVERITY == SEVERE)
		mupip_exit(ERR_MUNOFINISH);
	CONTINUE;
}
