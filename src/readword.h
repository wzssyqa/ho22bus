#ifndef __RW_READWORD_H__
#define __RW_READWORD_H__

#include "sndserv.h"


class Cwyabdc
{
public:
	gboolean disable;	
	Cwyabdc ();
	~Cwyabdc ();
	void read(const char *word,PLAY_METHOD method);
private:
	bool havedatafile;

};

void readword (const char *word,PLAY_METHOD method=PM_MIX);

#endif
