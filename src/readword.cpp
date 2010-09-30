#include "readword.h"
#include "reciteword.h"
#include <cstring>

#ifdef HAVE_CONFIG_H
#  include "config.h"
#endif

extern CReciteWord* g_pReciteWord;


Cwyabdc::Cwyabdc ()
{
}

Cwyabdc::~Cwyabdc ()
{
}

void Cwyabdc::read(const char *word,PLAY_METHOD method)
{
	int n=strlen(word);
	gchar *lowerword = (gchar *)g_malloc(n+1);
	for (int i=0;i<n;i++)
		lowerword[i]= g_ascii_tolower(word[i]);
	lowerword[n] = '\0';
		
	gchar *tmpfn = g_strdup_printf("%c/%s.wav", lowerword[0],lowerword);	
	gchar *fnsysw=g_build_filename(reciteword_data_dir,"TTS",tmpfn,NULL);
	
	gchar *confdir=g_strdup_printf(".%s",PACKAGE);
	gchar *fnuserw=g_build_filename(g_get_home_dir(),confdir,"TTS",tmpfn,NULL);
	
	g_free(tmpfn);
	g_free(confdir);
	
	if (g_file_test(fnuserw, G_FILE_TEST_EXISTS))
		play_file (fnuserw,method);
	else if(g_file_test(fnsysw, G_FILE_TEST_EXISTS))
		play_file (fnsysw,method);
	else{
		gchar *cmd = g_strdup_printf("espeak \"%s\"",lowerword);
		system(cmd);
		g_free(cmd);
	}
	g_free(fnsysw);
	g_free(fnuserw);
	g_free(lowerword);
}

// if use global static class,the class's constructor will run before main(),it means that the constructor run before gtk_init(),
// so,if use any gtk,glib function,i.e. g_printf(),it will make some strange things.it is better not to use global static class
// in gtk program.

//static Cwyabdc wyabdc;  

void
readword (const char *word,PLAY_METHOD method)
{
	if (g_pReciteWord->wyabdc.disable)
		return;
	if (word && word[0]!='\0' && (!strchr(word,' '))) // if the string contain a space character,then no sound.
		g_pReciteWord->wyabdc.read (word,method);
}
