## Process this file with automake to produce Makefile.in

noinst_PROGRAMS = wordlover bdc wyabdc getBdcSound verifyfile

INCLUDES = $(HO22BUS_CFLAGS)

wordlover_LDFLAGS = 
wordlover_LDADD = $(HO22BUS_LIBS)
wordlover_SOURCES = wordlover.c

bdc_LDFLAGS = 
bdc_LDADD = $(HO22BUS_LIBS)
bdc_SOURCES = bdc.c

getBdcSound_LDFLAGS = 
getBdcSound_LDADD = $(HO22BUS_LIBS)
getBdcSound_SOURCES = getBdcSound.c

wyabdc_LDFLAGS = 
wyabdc_LDADD = $(HO22BUS_LIBS)
wyabdc_SOURCES = wyabdc.c

verifyfile_LDFLAGS =
verifyfile_LDADD = $(HO22BUS_LIBS)
verifyfile_SOURCES = verifyfile.c


EXTRA_DIST = trans_dic.py aa.c
