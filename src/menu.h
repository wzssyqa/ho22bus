#ifndef __MENU_H__
#define __MENU_H__

#include <gtk/gtk.h>
#include "widget.h"

class CMenuButton
{
     public:
	GtkWidget *button;
	void (*runfunc) (const gpointer);
	gpointer funcdata;
	void do_clicked();
	void destroy();
	
	CMenuButton();
	~CMenuButton();
};

class CMenu
{
      protected:
	CMenuButton quit_button;

      public:
	GtkWidget *fixed;
	
	GtkWidget *menu;

	CMenuButton choosebook_button;
	CMenuButton firstrecite_button;
	CMenuButton revise_button;
	CMenuButton rest_button;
	CMenuButton know_button;
	CMenuButton shooting_button;
	CMenuButton typing_button;
	gboolean re_continue;


	  CMenu ();
	 ~CMenu ();

	void show ();
	void close ();
	void make_pause();
	void make_continue();
};

#endif
