/* ReciteWord - Recite Word Eassily
 * http://reciteword.cosoft.org.cn
 * Copyright (C) 2002-2007 Hu Zheng <huzheng_001@163.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Library General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * Modified by the ReciteWord Team and others 2002-2003.  See the AUTHORS
 * file for a list of people on the ReciteWord Team.  See the ChangeLog
 * files for a list of changes.  These files are distributed with
 * ReciteWord at http://reciteword.cosoft.org.cn.
 */


#ifdef HAVE_CONFIG_H
#  include "config.h"
#endif

#include "reciteword.h"
#include "skin.h"
#include "rwconfig.h"
#include <glib/gi18n.h>
#include "intl.h"
#include <gdk/gdkkeysyms.h>
#include <cstdlib>
#include <ctime>
#include "winform.h"

CReciteWord *g_pReciteWord = NULL;
struct _Skin *Skin = NULL;
extern ConfigFile *usercfgfile;

gchar reciteword_data_dir[256];

void
CReciteWord::PopupRecord (gpointer data)
{
	if (!g_pReciteWord->record_window)
	{
		g_pReciteWord->record_window = new CRecord;
	}
	g_pReciteWord->record_window->show ();
}

void
CReciteWord::PopupOption (gpointer data)
{
	if (!g_pReciteWord->option_window)
	{
		g_pReciteWord->option_window = new COption;
	}
	g_pReciteWord->option_window->show ();
}

void
CReciteWord::PopupHelp (gpointer data)
{
	ho22bus_show_help();
}

void
CReciteWord::PopupAbout (gpointer data)
{
	ho22bus_show_about();
}


void
CReciteWord::PopupDict (gpointer data)
{
	if (!g_pReciteWord->dict_window)
	{
		g_pReciteWord->dict_window = new CDict;
	}
	g_pReciteWord->dict_window->show ();
}

void
CReciteWord::PopupChooseword (void (*ok_func) (), void (*cancel_func) (), struct chooseword_info *info)
{
	if (!g_pReciteWord->chooseword)
	{
		g_pReciteWord->chooseword = new CChooseword;
	}
	g_pReciteWord->chooseword->show (ok_func, cancel_func, info);
}

void
CReciteWord::PopupCollectword ()
{
	if (!g_pReciteWord->collectword)
	{
		g_pReciteWord->collectword = new CCollectword;
	}
	g_pReciteWord->collectword->show ();
}

void
CReciteWord::PopupMark ()
{
	if (!g_pReciteWord->mark)
	{
		g_pReciteWord->mark = new CMark;
	}
	g_pReciteWord->mark->show ();
}

void
CReciteWord::ShowChoosebook ()
{
	if (!g_pReciteWord->choosebook)
	{
		g_pReciteWord->choosebook = new CChoosebook;
	}
	g_pReciteWord->choosebook->show ();
}

void
CReciteWord::ShowFirstRecite_group ()
{
	if (!g_pReciteWord->now_book)
		return;
	if (!g_pReciteWord->firstrecite_group)
	{
		g_pReciteWord->firstrecite_group = new CFirstRecite_group;
	}
	g_pReciteWord->firstrecite_group->show ();
}

void
CReciteWord::ShowFirstRecite_skim ()
{
	if (!g_pReciteWord->now_book)
		return;
	if (!g_pReciteWord->firstrecite_skim)
	{
		g_pReciteWord->firstrecite_skim = new CFirstRecite_skim;
	}
	g_pReciteWord->firstrecite_skim->show ();
}

void
CReciteWord::ShowFirstRecite_test ()
{
	if (!g_pReciteWord->now_book)
		return;
	if (!g_pReciteWord->firstrecite_test)
	{
		g_pReciteWord->firstrecite_test = new CFirstRecite_test;
	}
	g_pReciteWord->firstrecite_test->show ();
}

void
CReciteWord::ShowRevise_group ()
{
	if (!g_pReciteWord->now_book)
		return;
	if (!g_pReciteWord->revise_group)
	{
		g_pReciteWord->revise_group = new CRevise_group;
	}
	g_pReciteWord->revise_group->show ();
}

void
CReciteWord::ShowRevise_test ()
{
	if (!g_pReciteWord->now_book)
		return;
	if (!g_pReciteWord->revise_test)
	{
		g_pReciteWord->revise_test = new CRevise_test;
	}
	g_pReciteWord->revise_test->show ();
}

void
CReciteWord::ShowRevise_skim ()
{
	if (!g_pReciteWord->now_book)
		return;
	if (!g_pReciteWord->revise_skim)
	{
		g_pReciteWord->revise_skim = new CRevise_skim;
	}
	g_pReciteWord->revise_skim->show ();
}

void
CReciteWord::ShowRest ()
{
	if (!g_pReciteWord->now_book)
		return;
	GtkWidget *dialog = gtk_message_dialog_new (GTK_WINDOW(g_pReciteWord->window),
                                 GTK_DIALOG_DESTROY_WITH_PARENT,
                                 GTK_MESSAGE_INFO,
                                 GTK_BUTTONS_CLOSE,
                                 _("Not implement yet!")
                                 );
	gtk_dialog_run (GTK_DIALOG (dialog));
	gtk_widget_destroy (dialog);
}

void
CReciteWord::ShowKnow ()
{
	if (!g_pReciteWord->now_book)
		return;
	if (!g_pReciteWord->know)
	{
		g_pReciteWord->know = new CKnow;
	}
	g_pReciteWord->know->show ();
}

void
CReciteWord::ShowShooting ()
{
	if (!g_pReciteWord->now_book)
		return;
	if (!g_pReciteWord->shooting)
	{
		g_pReciteWord->shooting = new CShooting;
	}
	g_pReciteWord->shooting->show ();
}

void
CReciteWord::ShowTyping ()
{
	if (!g_pReciteWord->now_book)
		return;
	if (!g_pReciteWord->typing)
	{
		g_pReciteWord->typing = new CTyping;
	}
	g_pReciteWord->typing->show ();
}

static gboolean
on_mainwnd_button_press (GtkWidget * window, GdkEventButton * event ,CReciteWord * parent)
{
	if (event->button == 1 && event->type == GDK_BUTTON_PRESS && event->window == parent->window->window && event->y < Skin->reciteword.titlebar_height)
		gtk_window_begin_move_drag(GTK_WINDOW(window),event->button,(gint)event->x_root,(gint)event->y_root,event->time);
	return true;
}

static gboolean
on_mainwnd_scroll (GtkWidget * window, GdkEventScroll * event ,CReciteWord * parent)
{	
	switch (g_pReciteWord->status)
	{
	case STATUS_FIRSTRECITE_GROUP:
		parent->firstrecite_group->do_scroll(event);
		break;
	case STATUS_FIRSTRECITE_SKIM:
		parent->firstrecite_skim->do_scroll(event);
		break;
	case STATUS_FIRSTRECITE_TEST:
		parent->firstrecite_test->do_scroll(event);
		break;
	case STATUS_REVISE_TEST:
		parent->revise_test->do_scroll(event);
		break;
	case STATUS_TYPING:
		parent->typing->do_scroll(event);
		break;
	default:
		break;
	}
	return true;
}

static gboolean
on_mainwnd_key_press_release (GtkWidget * window, GdkEventKey * event ,CReciteWord * parent)
{
	return TRUE;
}

static gint
on_mainwnd_delete_event (GtkWidget * window, GdkEvent *event , CReciteWord * parent)
{
	parent->close ();
	return true;
}

static gboolean
on_menu_bar_enter_notify (GtkWidget * widget, GdkEvent * event,
			  gpointer func_data)
{
	if (!g_pReciteWord->menu)
	{
		g_pReciteWord->menu = new CMenu;
	}
	g_pReciteWord->menu->show ();
	return TRUE;
}

static gboolean
on_window_enter_notify (GtkWidget * widget, GdkEventCrossing * event,
			  gpointer func_data)
{
	// when enter from the left side of the menu,don't close the menu.
	if ((event->x>=Skin->face.menu.x[0])&&(event->x<Skin->face.menu.x[0]+Skin->face.menu.w)&&(event->y >=Skin->face.menu.y[0])&&(event->y <Skin->face.menu.y[0]+Skin->face.menu.h))
		return true;
	if (g_pReciteWord->menu && g_pReciteWord->menu->fixed)
		g_pReciteWord->menu->close();  // both when enter the window and when leave the menu will try to close the menu
	return TRUE;
}

CReciteWord::CReciteWord ()
{
	now_book = NULL;

	window = NULL;
	menu = NULL;
	dict_window = NULL;
	record_window = NULL;
	option_window = NULL;
	choosebook = NULL;
	firstrecite_group = NULL;
	firstrecite_skim = NULL;
	firstrecite_test = NULL;
	revise_group = NULL;
	revise_test = NULL;
	revise_skim = NULL;
	know = NULL;
	shooting = NULL;
	typing = NULL;
	chooseword = NULL;
	collectword = NULL;
	mark = NULL;
}

CReciteWord::~CReciteWord ()
{
	if (menu)
		delete (menu);
	if (dict_window)
		delete (dict_window);
	if (record_window)
		delete (record_window);
	if (option_window)
		delete (option_window);
	if (choosebook)
		delete (choosebook);
	if (firstrecite_group)
		delete (firstrecite_group);
	if (firstrecite_skim)
		delete (firstrecite_skim);
	if (firstrecite_test)
		delete (firstrecite_test);
	if (revise_group)
		delete (revise_group);
	if (revise_test)
		delete (revise_test);
	if (revise_skim)
		delete (revise_skim);
	if (know)
		delete (know);
	if (shooting)
		delete (shooting);
	if (typing)
		delete (typing);
	if (chooseword)
		delete (chooseword);
	if (collectword)
		delete (collectword);
	if (mark)
		delete (mark);
}

void
CReciteWord::init ()
{
	g_pReciteWord->status = STATUS_NORMAL;

	now_zu_index = 0;
	now_zu_wordcount = 25;
	now_zu_words.w = NULL;
	now_zu_words.t = NULL;
	now_zu_words.m = NULL;
	std::srand (std::time (0));
}

void
CReciteWord::create ()
{
	init ();

	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);


	gtk_widget_set_events(window,GDK_SCROLL_MASK);
	gtk_window_set_decorated (GTK_WINDOW (window), FALSE);
	gtk_widget_set_app_paintable(window,TRUE);
	gtk_window_set_resizable(GTK_WINDOW(window),FALSE);
	gtk_widget_set_size_request (window, Skin->reciteword.width, Skin->reciteword.height);
	gtk_window_set_position (GTK_WINDOW (window), GTK_WIN_POS_CENTER);
	gtk_window_set_title (GTK_WINDOW (window), _("ReciteWord"));

	gtk_widget_realize(window);
	skin_load_reciteword (window);
	skin_load_face (window);

	gtk_window_set_icon (GTK_WINDOW(window),Skin->face.icon.p[0]);
	
	tooltips = gtk_tooltips_new ();
	
	fixed = gtk_fixed_new ();
	//gtk_fixed_set_has_window(GTK_FIXED(fixed),TRUE);
	gtk_container_add (GTK_CONTAINER (window), fixed);
	gtk_widget_show (fixed);
	SetBackPixmap (fixed, Skin->face.face.p[0]);

	help_button.create (fixed, Skin->face.help_button.x[0],
			    Skin->face.help_button.y[0], Skin->face.help_button.p[0],
			    Skin->face.help_button.p[1],
			    Skin->face.help_button.p[2], PopupHelp, NULL);
	record_button.create (fixed, Skin->face.record_button.x[0],
			      Skin->face.record_button.y[0],
			      Skin->face.record_button.p[0],
			      Skin->face.record_button.p[1],
			      Skin->face.record_button.p[2], PopupRecord, NULL);
	option_button.create (fixed, Skin->face.option_button.x[0],
			     Skin->face.option_button.y[0],
			     Skin->face.option_button.p[0],
			     Skin->face.option_button.p[1],
			     Skin->face.option_button.p[2], PopupOption, NULL);
	dict_button.create (fixed, Skin->face.dict_button.x[0],
			    Skin->face.dict_button.y[0], Skin->face.dict_button.p[0],
			    Skin->face.dict_button.p[1],
			    Skin->face.dict_button.p[2], PopupDict, NULL);
	about_button.create (fixed, Skin->face.about_button.x[0],
			     Skin->face.about_button.y[0],
			     Skin->face.about_button.p[0],
			     Skin->face.about_button.p[1],
			     Skin->face.about_button.p[2], PopupAbout, NULL);

	GtkWidget *event_box = gtk_event_box_new ();
	gtk_fixed_put (GTK_FIXED (fixed), event_box, Skin->face.menubar.x[0],
		       Skin->face.menubar.y[0]);
	GtkWidget *pixmap_widget = gtk_image_new_from_pixmap (Skin->face.menubar.p[0], NULL);
	gtk_container_add (GTK_CONTAINER (event_box), pixmap_widget);
	gtk_widget_show (pixmap_widget);
	gtk_widget_show (event_box);

	g_signal_connect (G_OBJECT (event_box), "enter_notify_event",
			  G_CALLBACK (on_menu_bar_enter_notify), this);
	g_signal_connect (G_OBJECT (window), "enter_notify_event",
			  G_CALLBACK (on_window_enter_notify), this);

	g_signal_connect (G_OBJECT (window), "button_press_event",
			  G_CALLBACK (on_mainwnd_button_press), this);
	g_signal_connect (G_OBJECT (window), "scroll_event",
			  G_CALLBACK (on_mainwnd_scroll), this);
	g_signal_connect (G_OBJECT (window), "key_press_event",
			  G_CALLBACK (on_mainwnd_key_press_release), this);
  	g_signal_connect (G_OBJECT (window), "key_release_event",
			  G_CALLBACK (on_mainwnd_key_press_release), this);
	g_signal_connect (G_OBJECT (window), "delete_event",
			  G_CALLBACK (on_mainwnd_delete_event), this);
	gtk_widget_show (window);
	gdk_threads_enter();
	gtk_main ();
	gdk_threads_leave();
}

void
CReciteWord::show ()
{
	g_pReciteWord->status = STATUS_NORMAL;
	SetBackPixmap (fixed, Skin->face.face.p[0]);
}

void
CReciteWord::clean ()
{
	switch (status)
	{
	case STATUS_NORMAL:
		break;
	case STATUS_CHOOSEBOOK:
		g_pReciteWord->choosebook->close ();
		break;
	case STATUS_FIRSTRECITE_GROUP:
		g_pReciteWord->firstrecite_group->close ();
		break;
	case STATUS_FIRSTRECITE_SKIM:
		g_pReciteWord->firstrecite_skim->close ();
		break;
	case STATUS_FIRSTRECITE_TEST:
		g_pReciteWord->firstrecite_test->close ();
		break;
	case STATUS_REVISE_GROUP:
		g_pReciteWord->revise_group->close ();
		break;
	case STATUS_REVISE_TEST:
		g_pReciteWord->revise_test->close ();
		break;
	case STATUS_REVISE_SKIM:
		g_pReciteWord->revise_skim->close ();
		break;
	case STATUS_KNOW:
		g_pReciteWord->know->close ();
		break;
	case STATUS_SHOOTING:
		g_pReciteWord->shooting->close ();
		break;
	case STATUS_TYPING:
		g_pReciteWord->typing->close ();
		break;
	default:
		break;
	}
	status = STATUS_NORMAL;
}

void
CReciteWord::destroy ()
{
	if ((menu) && (menu->fixed))
	//if ((menu) && (menu->showing))
	{
		menu->re_continue=false; // going to exit,needn't continue.
		menu->close ();
	}

	clean ();

	if ((dict_window) && (dict_window->showing))
		dict_window->close ();
	if ((record_window) && (record_window->showing))
		record_window->close ();
	if ((option_window) && (option_window->showing))
		option_window->close ();
	
	if ((collectword) && (collectword->window))
		collectword->close ();


	help_button.destroy ();
	record_button.destroy ();
	option_button.destroy ();
	dict_button.destroy ();
	about_button.destroy ();
	gtk_widget_destroy(window);
}

void
CReciteWord::close ()
{
	destroy ();

	if (now_zu_words.w)
	{
		g_free(now_zu_words.w);
		now_zu_words.w = NULL;
	}
	if (now_zu_words.t)
	{
		g_free(now_zu_words.t);
		now_zu_words.t = NULL;
	}
	if (now_zu_words.m)
	{
		g_free(now_zu_words.m);
		now_zu_words.m = NULL;
	}

	close_book();
	conf_save_usr();
	if (usercfgfile)
	{		
		rw_cfg_free (usercfgfile);
		g_free (usercfgfile);
		usercfgfile = NULL;
	}
	gtk_main_quit ();
}

void
CReciteWord::set_now_zu_words(gint zu_index,gint zu_wordcount,gchar **zu_words_w,gchar **zu_words_t,gchar **zu_words_m,gboolean disorder)
{
	now_zu_index =zu_index;
	now_zu_wordcount =zu_wordcount;
	if (now_zu_words.w)
		g_free(now_zu_words.w);
	if (now_zu_words.t)
		g_free(now_zu_words.t);
	if (now_zu_words.m)
		g_free(now_zu_words.m);
	now_zu_words.w = (gchar **) g_malloc(now_zu_wordcount * sizeof(gchar *));
	now_zu_words.t = (gchar **) g_malloc(now_zu_wordcount * sizeof(gchar *));
	now_zu_words.m = (gchar **) g_malloc(now_zu_wordcount * sizeof(gchar *));
	gint i;
	for (i=0;i<now_zu_wordcount;i++)
	{
		now_zu_words.w[i] = zu_words_w[i];
		now_zu_words.t[i] =zu_words_t[i];
		now_zu_words.m[i] =zu_words_m[i];
	}
	if (disorder)
	{
		gint a;
		gchar *tmp;
		for (i=0;i<now_zu_wordcount;i++)
		{
			a = std::rand () % now_zu_wordcount;
			if (a!=i)
			{
				tmp = now_zu_words.w[i];
				now_zu_words.w[i]=now_zu_words.w[a];
				now_zu_words.w[a]=tmp;
				tmp = now_zu_words.t[i];
				now_zu_words.t[i]=now_zu_words.t[a];
				now_zu_words.t[a]=tmp;
				tmp = now_zu_words.m[i];
				now_zu_words.m[i]=now_zu_words.m[a];
				now_zu_words.m[a]=tmp;
			}
		}
	}
}

void
CReciteWord::close_book()
{
	if (now_book)
	{
		if (usercfgfile)
		{
			gint i;
			rw_cfg_read_int (usercfgfile, now_book->bookfilename, "next_zu_index", &i);
			if (i != next_zu_index)
				rw_cfg_write_int (usercfgfile, now_book->bookfilename, "next_zu_index", next_zu_index);
			rw_cfg_read_int (usercfgfile, now_book->bookfilename, "max_zu_index", &i);
			if (i != max_zu_index)
				rw_cfg_write_int (usercfgfile, now_book->bookfilename, "max_zu_index", max_zu_index);	

			rw_cfg_read_int (usercfgfile, now_book->bookfilename, "revise_test_chooseword_by", &i);
			if (i != revise_test_chooseword_info.by)
				rw_cfg_write_int (usercfgfile, now_book->bookfilename, "revise_test_chooseword_by", revise_test_chooseword_info.by);
			rw_cfg_read_int (usercfgfile, now_book->bookfilename, "revise_test_chooseword_zu_index", &i);
			if (i != revise_test_chooseword_info.zu_index)
				rw_cfg_write_int (usercfgfile, now_book->bookfilename, "revise_test_chooseword_zu_index", revise_test_chooseword_info.zu_index);
			rw_cfg_read_int (usercfgfile, now_book->bookfilename, "revise_test_chooseword_scope_start", &i);
			if (i != revise_test_chooseword_info.scope_start)
				rw_cfg_write_int (usercfgfile, now_book->bookfilename, "revise_test_chooseword_scope_start", revise_test_chooseword_info.scope_start);
			rw_cfg_read_int (usercfgfile, now_book->bookfilename, "revise_test_chooseword_scope_count", &i);
			if (i != revise_test_chooseword_info.scope_count)
				rw_cfg_write_int (usercfgfile, now_book->bookfilename, "revise_test_chooseword_scope_count", revise_test_chooseword_info.scope_count);

			rw_cfg_read_int (usercfgfile, now_book->bookfilename, "revise_skim_chooseword_by", &i);
			if (i != revise_skim_chooseword_info.by)
				rw_cfg_write_int (usercfgfile, now_book->bookfilename, "revise_skim_chooseword_by", revise_skim_chooseword_info.by);
			rw_cfg_read_int (usercfgfile, now_book->bookfilename, "revise_skim_chooseword_zu_index", &i);
			if (i != revise_skim_chooseword_info.zu_index)
				rw_cfg_write_int (usercfgfile, now_book->bookfilename, "revise_skim_chooseword_zu_index", revise_skim_chooseword_info.zu_index);
			rw_cfg_read_int (usercfgfile, now_book->bookfilename, "revise_skim_chooseword_scope_start", &i);
			if (i != revise_skim_chooseword_info.scope_start)
				rw_cfg_write_int (usercfgfile, now_book->bookfilename, "revise_skim_chooseword_scope_start", revise_skim_chooseword_info.scope_start);
			rw_cfg_read_int (usercfgfile, now_book->bookfilename, "revise_skim_chooseword_scope_count", &i);
			if (i != revise_skim_chooseword_info.scope_count)
				rw_cfg_write_int (usercfgfile, now_book->bookfilename, "revise_skim_chooseword_scope_count", revise_skim_chooseword_info.scope_count);

			rw_cfg_read_int (usercfgfile, now_book->bookfilename, "shooting_chooseword_by", &i);
			if (i != shooting_chooseword_info.by)
				rw_cfg_write_int (usercfgfile, now_book->bookfilename, "shooting_chooseword_by", shooting_chooseword_info.by);
			rw_cfg_read_int (usercfgfile, now_book->bookfilename, "shooting_chooseword_zu_index", &i);
			if (i != shooting_chooseword_info.zu_index)
				rw_cfg_write_int (usercfgfile, now_book->bookfilename, "shooting_chooseword_zu_index", shooting_chooseword_info.zu_index);
			rw_cfg_read_int (usercfgfile, now_book->bookfilename, "shooting_chooseword_scope_start", &i);
			if (i != shooting_chooseword_info.scope_start)
				rw_cfg_write_int (usercfgfile, now_book->bookfilename, "shooting_chooseword_scope_start", shooting_chooseword_info.scope_start);
			rw_cfg_read_int (usercfgfile, now_book->bookfilename, "shooting_chooseword_scope_count", &i);
			if (i != shooting_chooseword_info.scope_count)
				rw_cfg_write_int (usercfgfile, now_book->bookfilename, "shooting_chooseword_scope_count", shooting_chooseword_info.scope_count);

			rw_cfg_read_int (usercfgfile, now_book->bookfilename, "typing_chooseword_by", &i);
			if (i != typing_chooseword_info.by)
				rw_cfg_write_int (usercfgfile, now_book->bookfilename, "typing_chooseword_by", typing_chooseword_info.by);
			rw_cfg_read_int (usercfgfile, now_book->bookfilename, "typing_chooseword_zu_index", &i);
			if (i != typing_chooseword_info.zu_index)
				rw_cfg_write_int (usercfgfile, now_book->bookfilename, "typing_chooseword_zu_index", typing_chooseword_info.zu_index);
			rw_cfg_read_int (usercfgfile, now_book->bookfilename, "typing_chooseword_scope_start", &i);
			if (i != typing_chooseword_info.scope_start)
				rw_cfg_write_int (usercfgfile, now_book->bookfilename, "typing_chooseword_scope_start", typing_chooseword_info.scope_start);
			rw_cfg_read_int (usercfgfile, now_book->bookfilename, "typing_chooseword_scope_count", &i);
			if (i != typing_chooseword_info.scope_count)
				rw_cfg_write_int (usercfgfile, now_book->bookfilename, "typing_chooseword_scope_count", typing_chooseword_info.scope_count);
		}
		rw_book_free (now_book);
		g_free(now_book);
		now_book=NULL;
	}
}

void
CReciteWord::load_book (gchar *filename)
{
	if (now_book)
	{
		if (!strcmp(filename,now_book->bookfilename))
			return;
		close_book();
	}

	now_book = rw_book_open_file (filename);

	if (now_book)
	{
		rw_cfg_write_string (usercfgfile, "reciteword", "book_file", now_book->bookfilename);
		rw_cfg_read_int (usercfgfile, filename, "next_zu_index", &(g_pReciteWord->next_zu_index));
		rw_cfg_read_int (usercfgfile, filename, "max_zu_index", &(g_pReciteWord->max_zu_index));
		
		rw_cfg_read_int (usercfgfile, filename, "revise_test_chooseword_by", &(g_pReciteWord->revise_test_chooseword_info.by));
		rw_cfg_read_int (usercfgfile, filename, "revise_test_chooseword_zu_index", &(g_pReciteWord->revise_test_chooseword_info.zu_index));
		rw_cfg_read_int (usercfgfile, filename, "revise_test_chooseword_scope_start", &(g_pReciteWord->revise_test_chooseword_info.scope_start));
		rw_cfg_read_int (usercfgfile, filename, "revise_test_chooseword_scope_count", &(g_pReciteWord->revise_test_chooseword_info.scope_count));

		rw_cfg_read_int (usercfgfile, filename, "revise_skim_chooseword_by", &(g_pReciteWord->revise_skim_chooseword_info.by));
		rw_cfg_read_int (usercfgfile, filename, "revise_skim_chooseword_zu_index", &(g_pReciteWord->revise_skim_chooseword_info.zu_index));
		rw_cfg_read_int (usercfgfile, filename, "revise_skim_chooseword_scope_start", &(g_pReciteWord->revise_skim_chooseword_info.scope_start));
		rw_cfg_read_int (usercfgfile, filename, "revise_skim_chooseword_scope_count", &(g_pReciteWord->revise_skim_chooseword_info.scope_count));

		rw_cfg_read_int (usercfgfile, filename, "shooting_chooseword_by", &(g_pReciteWord->shooting_chooseword_info.by));
		rw_cfg_read_int (usercfgfile, filename, "shooting_chooseword_zu_index", &(g_pReciteWord->shooting_chooseword_info.zu_index));
		rw_cfg_read_int (usercfgfile, filename, "shooting_chooseword_scope_start", &(g_pReciteWord->shooting_chooseword_info.scope_start));
		rw_cfg_read_int (usercfgfile, filename, "shooting_chooseword_scope_count", &(g_pReciteWord->shooting_chooseword_info.scope_count));

		rw_cfg_read_int (usercfgfile, filename, "typing_chooseword_by", &(g_pReciteWord->typing_chooseword_info.by));
		rw_cfg_read_int (usercfgfile, filename, "typing_chooseword_zu_index", &(g_pReciteWord->typing_chooseword_info.zu_index));
		rw_cfg_read_int (usercfgfile, filename, "typing_chooseword_scope_start", &(g_pReciteWord->typing_chooseword_info.scope_start));
		rw_cfg_read_int (usercfgfile, filename, "typing_chooseword_scope_count", &(g_pReciteWord->typing_chooseword_info.scope_count));		
	}
	else
	{
		g_print ("load %s error!\n", filename);
	}
}


static gboolean set_reciteword_data_dir(void) {
	strcpy(reciteword_data_dir, HO22BUS_DATA_DIR);
	return false;
}


int main(int argc, char *argv[])
{
	if (set_reciteword_data_dir())
		return 0;

	bindtextdomain (GETTEXT_PACKAGE, HO22BUS_LOCALEDIR);

	bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
	textdomain (GETTEXT_PACKAGE);
	g_thread_init(NULL);
	gtk_set_locale ();

	gtk_init (&argc, &argv);

	gint i;
	gboolean onlyshowdict=FALSE;

	for (i = 1; i < argc; i++)
	{
		if (argv[i][0] == '-')
		{
			/* is an option */
			if (strcmp(argv[i], "-d") == 0)
			{
				onlyshowdict=TRUE;
			}
		}
	}

	g_pReciteWord = new CReciteWord;
	Skin = new struct _Skin;
	if (conf_load_user (onlyshowdict))
	{

		g_print("%s","load setting error!");

		gdk_notify_startup_complete ();
		delete Skin;
		delete g_pReciteWord;
		return 0;
	}
	if (onlyshowdict)
	{
		g_pReciteWord->dict_window = new CDict;
		g_pReciteWord->dict_window->create();
	}
	else
	{
		g_pReciteWord->create ();
	}
	delete Skin;
	delete g_pReciteWord;
	
	return 0;
}
