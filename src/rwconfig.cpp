#ifdef HAVE_CONFIG_H
#  include "config.h"
#endif

#include <stdlib.h>
#include "rwconfig.h"
#include "skin.h"
#include "reciteword.h"
#include <glib/gi18n.h>
#include <cstdio>
#include <sys/stat.h>
#include <cstring>

#define DEFAULT_SKIN_DIR "en"

extern CReciteWord *g_pReciteWord;

ConfigFile *usercfgfile = NULL;

static void
conf_init ()
{
	struct stat st;
	gchar *rw_dir;

	rw_dir = g_strdup_printf("%s/.%s", g_get_home_dir(),PACKAGE);
	if (stat (rw_dir, &st))
		mkdir (rw_dir,00755);
	g_free(rw_dir);
	rw_dir = g_strdup_printf("%s/.%s/books",g_get_home_dir(),PACKAGE);
	if (stat (rw_dir, &st))
		mkdir (rw_dir,00755);
	g_free(rw_dir);
}

static void
user_init (gchar * user_file)
{
	struct stat st;
	FILE *file;
	if (stat (user_file, &st))
	{
		if ((file = fopen (user_file, "wb")) == NULL)
			return;
		fprintf (file,"[reciteword]\nskin=" DEFAULT_SKIN_DIR "\n");

		fprintf (file,"use_custom_font=1\nnormal_english_font=Monospace 10\nbig_english_font=Monospace 20\n");
	
		fprintf (file,"[chooseword]\ndisorder=1\n");
		fprintf (file,"[dict]\nrtsearch=1\nreadword=1\n");
		fprintf (file,"[firstrecite_group]\ndisorder=1\n");
		fprintf (file,"[firstrecite_skim]\nreadword=1\nshowphonetic=1\nshowmeanlater=1\n");
		fprintf (file,"[firstrecite_test]\nshowmean_1=1\nreadword_1=1\nsndeffect_1=1\nshowmean_2=1\nsndeffect_2=1\n");
		fprintf (file,"[revise_group]\ndisorder=1\nmax_revise_times=6\n");
		fprintf (file,"[revise_test]\nshowmean_1=1\nreadword_1=1\nshowphonetic_1=1\nsndeffect_1=1\nshowmean_2=1\nsndeffect_2=1\n");
		fprintf (file,"[revise_skim]\nreadword=1\nshowmean=1\nanimate=1\n");
		fprintf (file,"[shooting]\nreadword=1\nshowmean=1\nshowword=1\nshotsnd=1\n");
		fprintf (file,"[typing]\nreadword=1\nshowmean=1\nsndeffect=1\nshowfingering=1\n");
		fclose (file);
	}
}

int
conf_load_user (gboolean onlyshowdict)
{
	gchar *ab, str[256];
	gchar *filename;

	conf_init ();

	filename = g_strdup_printf("%s/.%s",g_get_home_dir(),PACKAGE);

	strcpy(g_pReciteWord->userpath,filename); //set the reciteword user's path.	
	g_free(filename);
	
	sprintf (str, "%s"G_DIR_SEPARATOR_S"my.cfg", g_pReciteWord->userpath);
	user_init (str);
	
	usercfgfile = rw_cfg_open_file (str);
	if (!usercfgfile)
	{
		g_print ("load file \"%s\" error!\n", str);
		return TRUE;
	}
	
	strncpy(str,_("en. Note:translate it to your locale, like en or zh_CN. Only this word."),256);	
	
	if (skin_load_info (str)) //load skin info fail
	{
		if (strcmp (str, DEFAULT_SKIN_DIR) == 0)
		{
			rw_cfg_free (usercfgfile);
			g_free (usercfgfile);
			usercfgfile = NULL;
			return TRUE;
		}
		else // if it is not the default skin,try default skin when failed.
		{
			if (skin_load_info (DEFAULT_SKIN_DIR))
			{
				rw_cfg_free (usercfgfile);
				g_free (usercfgfile);
				usercfgfile = NULL;
				return TRUE;
			}
			else //load default skin succeed.
			{
				filename = g_build_filename(reciteword_data_dir, "skins", DEFAULT_SKIN_DIR, "gtkrc", NULL);
				gtk_rc_parse (filename);
				g_free(filename);
			}
		}
	}
	else  // load skin succeed.
	{
		filename = g_build_filename(reciteword_data_dir, "skins", str, "gtkrc", NULL);
		gtk_rc_parse (filename);
		g_free(filename);
	}
	
	rw_cfg_read_boolean (usercfgfile, "reciteword", "disable_sound", &(g_pReciteWord->sndserv.disable));
	rw_cfg_read_boolean (usercfgfile, "reciteword", "disable_soundevent", &(g_pReciteWord->soundevent.disable));
	rw_cfg_read_boolean (usercfgfile, "reciteword", "disable_readword", &(g_pReciteWord->wyabdc.disable));
	
	gboolean use_custom_font;
	rw_cfg_read_boolean (usercfgfile, "reciteword", "use_custom_font", &use_custom_font);
	if (use_custom_font)
	{
		gchar *bb;
		if (rw_cfg_read_string (usercfgfile, "reciteword", "local_language_font", &bb))
		{
			gchar *aa;
			aa = g_strdup_printf("style \"custom-font\" { font_name= \"%s\" }\nclass \"GtkWidget\" style \"custom-font\"\n",bb);
			gtk_rc_parse_string(aa);
			g_free(bb);
			g_free(aa);
		}
	}
	
	if (onlyshowdict)  //needn't load book when only show dict window.
		return FALSE;
	if (rw_cfg_read_string (usercfgfile, "reciteword", "book_file", &ab))
	{
		g_pReciteWord->load_book(ab);
		g_free (ab);
	}
	
	return FALSE;
}

void conf_save_usr ()
{
	if ((usercfgfile)&&(usercfgfile->changed))
	{
		if (rw_cfg_write_file(usercfgfile,usercfgfile->cfgfilename))
		{
			usercfgfile->changed = false;
		}
		else
		{
			g_print("Write file \"%s\" failed!\n",usercfgfile->cfgfilename);
		}
	}
}
