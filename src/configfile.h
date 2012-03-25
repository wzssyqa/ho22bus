#ifndef __RW_CONFIGFILE_H__
#define __RW_CONFIGFILE_H__

#include <glib.h>
#include <time.h>


	typedef struct
	{
		gchar *key;
		gchar *value;
	}
	ConfigLine;

	typedef struct
	{
		gchar *name;
		GList *lines;
	}
	ConfigSection;


	typedef struct
	{
		GList *sections;
		gchar *cfgfilename;
		gboolean changed;
	}
	ConfigFile;

	ConfigFile *rw_cfg_new (void);
	ConfigFile *rw_cfg_open_file (const char * filename);
	gboolean rw_cfg_write_file (ConfigFile * cfg, const char * filename);
	void rw_cfg_free (ConfigFile * cfg);

	gboolean rw_cfg_read_string (ConfigFile * cfg, const char * section,
				     const char * key, gchar ** value);
	gboolean rw_cfg_read_int (ConfigFile * cfg, const char * section,
				  const char * key, gint * value);
	gboolean rw_cfg_read_long (ConfigFile * cfg, const char * section,
				  const char * key, glong * value);
	gboolean rw_cfg_read_time (ConfigFile * cfg, const char * section,
				   const char * key, time_t * value);
	gboolean rw_cfg_read_boolean (ConfigFile * cfg, const char * section,
				      const char * key, gboolean * value);
	void rw_cfg_write_string (ConfigFile * cfg, const char * section,
				  const char * key, const char * value);
	void rw_cfg_write_int (ConfigFile * cfg, const char * section, const char * key,
			       gint value);
	void rw_cfg_write_long (ConfigFile * cfg, const char * section, const char * key,
			       glong value);
	void rw_cfg_write_time (ConfigFile * cfg, const char * section,
				const char * key, time_t value);
	void rw_cfg_write_boolean (ConfigFile * cfg, const char * section,
				   const char * key, gboolean value);

	void rw_cfg_rename_section (ConfigFile * cfg, const char * section,
				    const char * section_name);
	void rw_cfg_remove_key (ConfigFile * cfg, const char * section,
				const char * key);
	void rw_cfg_remove_section (ConfigFile * cfg, const char * section);

#endif
