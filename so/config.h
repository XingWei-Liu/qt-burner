/* config.h.  Generated from config.h.in by configure.  */
/* config.h.in.  Generated from configure.ac by autoheader.  */


#define HAVE_CONFIG_H

/* define if you want to build cdrdao plugins */
#define BUILD_CDRDAO 1

/* define if you want to build cdrkit plugins */
#define BUILD_CDRKIT 1

/* define if you want to build cdrtools plugins */
/* #undef BUILD_CDRTOOLS */

/* define if you want to build growisofs plugins */
#define BUILD_GROWISOFS 1

/* define if you want to build inotify */
#define BUILD_INOTIFY 1

/* define if you want to build libburnia plugins */
#define BUILD_LIBBURNIA 1

/* define if you want to build playlist pane */
#define BUILD_PLAYLIST 1

/* define if you want to build preview pane */
#define BUILD_PREVIEW 1

/* define if you want to use search pane */
#define BUILD_SEARCH 1

/* define if you want to use search pane */
#define BUILD_TRACKER 1

/* major version */
#define BURNER_MAJOR_VERSION 3

/* minor version */
#define BURNER_MINOR_VERSION 0

/* sub version */
#define BURNER_SUB 0

/* version */
#define BURNER_VERSION 3.0.0

/* always defined to indicate that i18n is enabled */
#define ENABLE_NLS 1

/* Package name for gettext */
#define GETTEXT_PACKAGE "burner"

/* Define the location where the catalogs will be installed */
#define GNOMELOCALEDIR "/usr/share/locale"

/* Have AppIndicator */
#define HAVE_APP_INDICATOR 1

/* Define to 1 if you have the `bind_textdomain_codeset' function. */
#define HAVE_BIND_TEXTDOMAIN_CODESET 1

/* Define to 1 if you have the <camlib.h> header file. */
/* #undef HAVE_CAMLIB_H */

/* Define to 1 if you have the Mac OS X function CFLocaleCopyCurrent in the
   CoreFoundation framework. */
/* #undef HAVE_CFLOCALECOPYCURRENT */

/* Define to 1 if you have the Mac OS X function CFPreferencesCopyAppValue in
   the CoreFoundation framework. */
/* #undef HAVE_CFPREFERENCESCOPYAPPVALUE */

/* Define to 1 if you have the `dcgettext' function. */
#define HAVE_DCGETTEXT 1

/* Define to 1 if you have the <dlfcn.h> header file. */
#define HAVE_DLFCN_H 1

/* Define if the GNU gettext() function is already present or preinstalled. */
#define HAVE_GETTEXT 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define if your <locale.h> file defines LC_MESSAGES. */
#define HAVE_LC_MESSAGES 1

/* Define to 1 if you have the <locale.h> header file. */
#define HAVE_LOCALE_H 1

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define to 1 if the system has the type `scsireq_t'. */
/* #undef HAVE_SCSIREQ_T */

/* Define to 1 if the system has the type `sg_io_hdr_t'. */
#define HAVE_SG_IO_HDR_T 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if the system has the type `struct uscsi_cmd'. */
/* #undef HAVE_STRUCT_USCSI_CMD */

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Unity launcher support */
#define HAVE_UNITY 1

/* Define to the sub-directory where libtool stores uninstalled libraries. */
#define LT_OBJDIR ".libs/"

/* Name of package */
#define PACKAGE "burner"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT ""

/* Define the PACKAGE_DATA_DIR. */
#define PACKAGE_DATA_DIR "/usr/share/"

/* Location of package locale files */
#define PACKAGE_LOCALE_DIR "/usr/share/locale"

/* Define to the full name of this package. */
#define PACKAGE_NAME "burner"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "burner 3.0.0"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "burner"

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to the version of this package. */
#define PACKAGE_VERSION "3.0.0"

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Version number of package */
#define VERSION "3.0.0"

/* Enable large inode numbers on Mac OS X 10.5.  */
#ifndef _DARWIN_USE_64_BIT_INODE
# define _DARWIN_USE_64_BIT_INODE 1
#endif

/* Number of bits in a file offset, on hosts where this is settable. */
/* #undef _FILE_OFFSET_BITS */

/* Define for large files, on AIX-style hosts. */
/* #undef _LARGE_FILES */
