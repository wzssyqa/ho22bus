#include "sndserv.h"
#include "reciteword.h"
#include <cstdio>
#include <cstdlib>


extern CReciteWord* g_pReciteWord;

CSndserv::CSndserv()
{
	canplay=true;
}

CSndserv::~CSndserv()
{
}

void
CSndserv::play(const gchar *filename)
{
}

void play_file(const char *filename,PLAY_METHOD method)
{
	if ((!g_pReciteWord->sndserv.canplay)||(g_pReciteWord->sndserv.disable))
		return;

	
	
	switch (method)
	{
		case PM_MIX:
		{
			gchar *command=g_strdup_printf("aplay -q -B 1 %s &",filename);
			system(command);
			g_free(command);
			break;
		}
		case PM_STOP_PRE:   // it is hard to done,may need write my own esd_play_file.
		{
			break;
		}
		case PM_AFTER_PRE:  // use GThreadPool can do this,but,it does seems very useful before PM_STOP_PRE is done.
		{
			//GThreadPool *threadpool;
			
			break;
		}
	}
}
