#ifdef HAVE_CONFIG_H
#  include "config.h"
#endif

#include <glib.h>
#include "reciteword.h"
#include "winform.h"

void ho22bus_show_help(void){
	gchar *htindex=g_build_filename(reciteword_data_dir,"../doc",PACKAGE,"index.html",NULL);
	gchar *cmd=g_strdup_printf("xdg-open %s",htindex);
	system(cmd);
	g_free(htindex);
	g_free(cmd);
}

void ho22bus_show_about(void){
	const gchar *authors[]={"YunQiang Su <wzssyqa@gmail.com>",
		 _("forked from reciteword by Hu Zheng http://reciteword.cosoft.org.cn/"),
		 NULL
		};

	const gchar *artists[]={"Bu Weiming <buweiming@163.com>",NULL};
	const gchar *documenters[]={NULL};
	const gchar *comments=NULL;
	const gchar *copyright=N_("Copyright Contributors of h022bus");
	const gchar *license="GPLv3";
	const gchar *logo_icon_name=PACKAGE;
	const gchar *program_name=PACKAGE;
	const gchar *translator_credits=N_("translator-credits");
	const gchar *version=VERSION;
	const gchar *website=PACKAGE_URL;
	
	g_print("%s\n",logo_icon_name);

	gtk_show_about_dialog(NULL,
			"authors", authors,
			"artists", artists,
			"documenters", documenters,
			"comments", comments,
			"copyright", copyright,
			"license", license,
			"logo-icon-name", logo_icon_name,
			"program-name", program_name,
			"translator-credits", translator_credits,
			"version", version,
			"website", website,
			NULL
	);
}
