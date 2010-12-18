#include "reciteword.h"
#include "menu.h"
#include "skin.h"

extern CReciteWord *g_pReciteWord;
extern struct _Skin *Skin;


static gboolean
on_menu_leave_notify (GtkWidget * widget, GdkEventCrossing * event, CMenu * parent)
{
	//GDK_NOTIFY_ANCESTOR enter main window or "button press" on the menu.
	//GDK_NOTIFY_VIRTUAL enter mainwindow from the button which inside the menu or "button press" on the button which inside menu.
	//GDK_NOTIFY_INFERIOR  enter button which inside the menu
	//GDK_NOTIFY_NONLINEAR leave menu and outside the window,or leave menu,into widget which in main window
	//GDK_NOTIFY_NONLINEAR_VIRTUAL leave menu and outside the window from the button which inside the menu,or leave menu,into widget which in main window
	if (event->mode==GDK_CROSSING_NORMAL) //event happen because mouse move,not because button press.
	{
		if (((event->detail==GDK_NOTIFY_ANCESTOR) || (event->detail==GDK_NOTIFY_VIRTUAL))
			||(((event->detail==GDK_NOTIFY_NONLINEAR) || (event->detail==GDK_NOTIFY_NONLINEAR_VIRTUAL))&&(event->x>0))
		)
			parent->close ();
	}
	return true;
}

static void on_menu_choosebook_clicked (gpointer data)
{
	g_pReciteWord->menu->close ();
	g_pReciteWord->clean ();
	g_pReciteWord->ShowChoosebook ();
}

static void on_menu_firstrecite_clicked (gpointer data)
{
	g_pReciteWord->menu->close ();
	g_pReciteWord->clean ();
	g_pReciteWord->ShowFirstRecite_group ();
}

static void on_menu_revise_clicked (gpointer data)
{
	g_pReciteWord->menu->close ();
	g_pReciteWord->clean ();
	g_pReciteWord->ShowRevise_group ();
}

static void on_menu_rest_clicked (gpointer data)
{
	g_pReciteWord->menu->close ();
	g_pReciteWord->clean ();
	g_pReciteWord->ShowRest ();
}

static void on_menu_know_clicked (gpointer data)
{
	g_pReciteWord->menu->close ();
	g_pReciteWord->clean ();
	g_pReciteWord->ShowKnow ();
}

static void on_menu_shooting_clicked (gpointer data)
{
	g_pReciteWord->menu->close ();
	g_pReciteWord->clean ();
	g_pReciteWord->ShowShooting ();
}

static void on_menu_typing_clicked (gpointer data)
{
	g_pReciteWord->menu->close ();
	g_pReciteWord->clean ();
	g_pReciteWord->ShowTyping ();
}

static void on_menu_quit_clicked (gpointer data)
{
	g_pReciteWord->close ();
}

CMenuButton::CMenuButton(){
	;
}

CMenuButton::~CMenuButton(){
	;
}

void CMenuButton::destroy(){
	gtk_widget_destroy(button);
}

void CMenuButton::do_clicked(){
//	if (playsnd)
		playsound (SND_BUTTONDOWN);
	(*(runfunc)) (funcdata);
}

static void append_menuitem(CMenuButton &menubutton,char *string,GtkWidget *menu, void (*func) (gpointer), gpointer data){
	menubutton.button= gtk_menu_item_new_with_label(string);
	g_signal_connect(G_OBJECT(menubutton.button), "activate",G_CALLBACK(func), data);
	gtk_menu_shell_append(GTK_MENU_SHELL(menu), menubutton.button);
	menubutton.runfunc=func;
	menubutton.funcdata=data;
	gtk_widget_show(menubutton.button);
}

CMenu::CMenu ()
{
	fixed = NULL;
	menu = NULL;
				
}

CMenu::~CMenu ()
{

}

void CMenu::close ()
{
	if (!menu)
		return;
	make_continue();
	menu=NULL;
	choosebook_button.destroy();
	firstrecite_button.destroy();
	revise_button.destroy();
	rest_button.destroy();
	know_button.destroy();
	shooting_button.destroy();
	typing_button.destroy();
	quit_button.destroy();	
	
	fixed = NULL;
}

void CMenu::show ()
{

	if (menu){
		gtk_menu_popup (GTK_MENU(menu), NULL, NULL, NULL, NULL,0, 0);
		return;
	}
	
	menu=gtk_menu_new();
	
	append_menuitem(choosebook_button,_("_Choose Book"), menu, on_menu_choosebook_clicked,NULL);
	append_menuitem(firstrecite_button,_("_First Recite"), menu, on_menu_firstrecite_clicked,NULL);
	append_menuitem(revise_button,_("_Revise"), menu, on_menu_revise_clicked,NULL);
	append_menuitem(shooting_button,_("_Shooting"), menu, on_menu_shooting_clicked,NULL);
	append_menuitem(typing_button,_("_Typing"), menu, on_menu_typing_clicked,NULL);
	append_menuitem(rest_button,_("R_est"), menu, on_menu_rest_clicked,NULL);
	append_menuitem(know_button,_("Kno_w"), menu, on_menu_know_clicked,NULL);
	append_menuitem(quit_button,_("_Quit"), menu, on_menu_quit_clicked,NULL);
	
	gtk_menu_popup (GTK_MENU(menu), NULL, NULL, NULL, NULL,0, 0);
	
	playsound (SND_MENUSHOW);
	make_pause();
	return;
}

void CMenu::make_pause ()
{
	re_continue=false;
	switch (g_pReciteWord->status)
	{
	case STATUS_FIRSTRECITE_SKIM:
		if (g_pReciteWord->firstrecite_skim->started)
		{
			g_pReciteWord->firstrecite_skim->pause_button.do_clicked (false);
			re_continue=true;
		}
		break;
	case STATUS_FIRSTRECITE_TEST:
		if (g_pReciteWord->firstrecite_test->started)
		{
			g_pReciteWord->firstrecite_test->pause_button.do_clicked (false);
			re_continue=true;
		}
		break;
	case STATUS_REVISE_TEST:
		if (g_pReciteWord->revise_test->started)
		{
			g_pReciteWord->revise_test->pause_button.do_clicked (false);
			re_continue=true;
		}
		break;
	case STATUS_REVISE_SKIM:
		if (g_pReciteWord->revise_skim->started)
		{
			g_pReciteWord->revise_skim->pause_button.do_clicked (false);
			re_continue=true;
		}
		break;
	case STATUS_SHOOTING:
		if (g_pReciteWord->shooting->started)
		{
			g_pReciteWord->shooting->pause_button.do_clicked (false);
			re_continue=true;
		}
		break;
	case STATUS_TYPING:
		if (g_pReciteWord->typing->started)
		{
			g_pReciteWord->typing->pause_button.do_clicked (false);
			re_continue=true;
		}
		break;
	default:
		break;
	}
}

void CMenu::make_continue ()
{
	if (!re_continue)
		return;
	switch (g_pReciteWord->status)
	{
	case STATUS_FIRSTRECITE_SKIM:
			g_pReciteWord->firstrecite_skim->pause_button.do_clicked (false);
		break;
	case STATUS_FIRSTRECITE_TEST:
			g_pReciteWord->firstrecite_test->pause_button.do_clicked (false);
		break;
	case STATUS_REVISE_TEST:
			g_pReciteWord->revise_test->pause_button.do_clicked (false);
		break;
	case STATUS_REVISE_SKIM:
			g_pReciteWord->revise_skim->pause_button.do_clicked (false);
		break;
	case STATUS_SHOOTING:
			g_pReciteWord->shooting->pause_button.do_clicked (false);
		break;
	case STATUS_TYPING:
			g_pReciteWord->typing->pause_button.do_clicked (false);
		break;
	default:
		break;
	}
}
