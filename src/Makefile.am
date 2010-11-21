## Process this file with automake to produce Makefile.in
SUBDIRS= modules skins win32

bin_PROGRAMS = ho22bus

INCLUDES =							\
	$(HO22BUS_CFLAGS)						\
	-DHO22BUS_DATA_DIR=\""$(datadir)/$(PROGRAM_NAME)"\"		\
	-DHO22BUS_LOCALEDIR=\""$(prefix)/$(DATADIRNAME)/locale"\"

ho22bus_LDFLAGS = 

ho22bus_LDADD = 				\
	$(HO22BUS_LIBS)			

ho22bus_SOURCES = 			\
	bookfile.cpp			\
	bookfile.h			\
	choosebook.cpp	\
	choosebook.h	\
	rwconfig.cpp		\
	rwconfig.h		\
	configfile.cpp 		\
	configfile.h 		\
	chooseword.cpp 			\
	chooseword.h 			\
	collectword.cpp			\
	collectword.h			\
	dict.cpp			\
	dict.h			\
	firstrecite.cpp 			\
	firstrecite.h 			\
	firstrecite_test.cpp 			\
	firstrecite_test.h 			\
	intl.h			\
	mark.cpp		\
	mark.h			\
	menu.cpp 			\
	menu.h 			\
	mydict.cpp		\
	mydict.h		\
	reciteword.cpp			\
	reciteword.h			\
	record.cpp		\
	record.h		\
	revise.cpp		\
	revise.h		\
	revise_test.cpp	\
	revise_test.h	\
	readword.cpp		\
	readword.h		\
	know.cpp		\
	know.h		\
	option.cpp option.h	\
	shooting.cpp			\
	shooting.h			\
	skin.cpp			\
	skin.h			\
	sound.cpp			\
	sound.h			\
	sndserv.cpp		\
	sndserv.h		\
	typing.cpp		\
	typing.h		\
	widget.cpp		\
	widget.h		\
	winform.cpp		\
	winform.h

EXTRA_DIST =
