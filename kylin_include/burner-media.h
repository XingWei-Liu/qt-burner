/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 8; tab-width: 8 -*- */
/*
 * Libburner-media
 * Copyright (C) Philippe Rouquier 2005-2009 <bonfire-app@wanadoo.fr>
 *
 * Libburner-media is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * The Libburner-media authors hereby grant permission for non-GPL compatible
 * GStreamer plugins to be used and distributed together with GStreamer
 * and Libburner-media. This permission is above and beyond the permissions granted
 * by the GPL license by which Libburner-media is covered. If you modify this code
 * you may extend this exception to your version of the code, but you are not
 * obligated to do so. If you do not wish to do so, delete this exception
 * statement from your version.
 * 
 * Libburner-media is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Library General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to:
 * 	The Free Software Foundation, Inc.,
 * 	51 Franklin Street, Fifth Floor
 * 	Boston, MA  02110-1301, USA.
 */
 
#ifndef _BURN_MEDIA_H
#define _BURN_MEDIA_H

#include <glib.h>

G_BEGIN_DECLS

/**
 * Some needed information about the library
 */

#define LIBBURNER_MEDIA_VERSION_MAJOR						\
	3
#define LIBBURNER_MEDIA_VERSION_MINOR						\
	0
#define LIBBURNER_MEDIA_VERSION_MICRO						\
	0
#define LIBBURNER_MEDIA_AGE							\
	302
#define LIBBURNER_MEDIA_INSTALL							\
	"/home/adams/workspace/kylin-burner/kylin-burner-3.0.6/__install"

/**
 * To start and stop the library
 */

void
burner_media_library_start (void);

void
burner_media_library_stop (void);

GOptionGroup *
burner_media_get_option_group (void);

/**
 * Errors
 */

GQuark burner_media_quark (void);

/**
 * BURNER_MEDIA_ERROR:
 *
 * The GQuark used for BurnerMediaError
 */
#define BURNER_MEDIA_ERROR burner_media_quark()

/**
 * BurnerMediaError:
 *
 * Error codes returned by libburner-media
 *
 */
typedef enum {
	BURNER_MEDIA_ERROR_NONE,
	BURNER_MEDIA_ERROR_GENERAL,
	BURNER_MEDIA_ERROR_IMAGE_INVALID,
} BurnerMediaError;

/**
 * BurnerMedia:
 *
 * This enum allows one to define all characteristics for a media (closed, writable, ...)
 * and identify all types of optical media.
 *
 */
typedef enum {
	BURNER_MEDIUM_UNSUPPORTED		= -2,
	BURNER_MEDIUM_BUSY			= -1,
	BURNER_MEDIUM_NONE			= 0,

	/* types */
	BURNER_MEDIUM_FILE			= 1,

	BURNER_MEDIUM_CD			= 1 << 1,

	BURNER_MEDIUM_DVD			= 1 << 2,

	BURNER_MEDIUM_BD			= 1 << 3,

	/* subtype for DVD and BD types */
	BURNER_MEDIUM_DUAL_L			= 1 << 4,

	/* DVD and DVD DL subtypes */
	BURNER_MEDIUM_RAM			= 1 << 5,
	BURNER_MEDIUM_PLUS			= 1 << 6,
	BURNER_MEDIUM_SEQUENTIAL		= 1 << 7,
	BURNER_MEDIUM_RESTRICTED		= 1 << 8,	/* DVD-RW only */

	/* DVD-R dual layer only subtype */
	BURNER_MEDIUM_JUMP			= 1 << 9,

	/* BD subtypes */
	BURNER_MEDIUM_RANDOM			= 1 << 10,
	BURNER_MEDIUM_SRM			= 1 << 11,
	BURNER_MEDIUM_POW			= 1 << 12,	/* This is Pseudo OverWrite */

	/* discs attributes */
	BURNER_MEDIUM_REWRITABLE		= 1 << 14,
	BURNER_MEDIUM_WRITABLE			= 1 << 15,
	BURNER_MEDIUM_ROM			= 1 << 16,

	/* status of the disc */
	BURNER_MEDIUM_BLANK			= 1 << 17,
	BURNER_MEDIUM_CLOSED			= 1 << 18,
	BURNER_MEDIUM_APPENDABLE		= 1 << 19,

	/* Only used for DVD+RW, DVD-RW restricted */
	BURNER_MEDIUM_UNFORMATTED		= 1 << 20,

	BURNER_MEDIUM_PROTECTED		= 1 << 21,
	BURNER_MEDIUM_HAS_DATA			= 1 << 22,
	BURNER_MEDIUM_HAS_AUDIO		= 1 << 23,
} BurnerMedia;

#define BURNER_MEDIUM_CDROM		(BURNER_MEDIUM_CD|		\
					 BURNER_MEDIUM_ROM)
#define BURNER_MEDIUM_CDR		(BURNER_MEDIUM_CD|		\
					 BURNER_MEDIUM_WRITABLE)
#define BURNER_MEDIUM_CDRW		(BURNER_MEDIUM_CD|		\
					 BURNER_MEDIUM_REWRITABLE)
#define BURNER_MEDIUM_DVD_ROM		(BURNER_MEDIUM_DVD|		\
					 BURNER_MEDIUM_ROM)
#define BURNER_MEDIUM_DVDR		(BURNER_MEDIUM_DVD|		\
					 BURNER_MEDIUM_SEQUENTIAL|	\
					 BURNER_MEDIUM_WRITABLE)
#define BURNER_MEDIUM_DVDRW		(BURNER_MEDIUM_DVD|		\
					 BURNER_MEDIUM_SEQUENTIAL|	\
					 BURNER_MEDIUM_REWRITABLE)
#define BURNER_MEDIUM_DVDRW_RESTRICTED	(BURNER_MEDIUM_DVD|		\
					 BURNER_MEDIUM_REWRITABLE|	\
					 BURNER_MEDIUM_RESTRICTED)
#define BURNER_MEDIUM_DVDR_DL		(BURNER_MEDIUM_DVD|		\
					 BURNER_MEDIUM_DUAL_L|		\
					 BURNER_MEDIUM_WRITABLE|	\
					 BURNER_MEDIUM_SEQUENTIAL)
#define BURNER_MEDIUM_DVDR_JUMP_DL	(BURNER_MEDIUM_DVD|		\
					 BURNER_MEDIUM_DUAL_L|		\
					 BURNER_MEDIUM_WRITABLE|	\
					 BURNER_MEDIUM_JUMP)
#define BURNER_MEDIUM_DVDR_PLUS	(BURNER_MEDIUM_DVD|		\
					 BURNER_MEDIUM_WRITABLE|	\
					 BURNER_MEDIUM_PLUS)
#define BURNER_MEDIUM_DVDRW_PLUS	(BURNER_MEDIUM_DVD|		\
					 BURNER_MEDIUM_REWRITABLE|	\
					 BURNER_MEDIUM_PLUS)
#define BURNER_MEDIUM_DVDR_PLUS_DL	(BURNER_MEDIUM_DVD|		\
					 BURNER_MEDIUM_DUAL_L|		\
					 BURNER_MEDIUM_WRITABLE|	\
					 BURNER_MEDIUM_PLUS)
#define BURNER_MEDIUM_DVDRW_PLUS_DL	(BURNER_MEDIUM_DVD|		\
					 BURNER_MEDIUM_DUAL_L|		\
					 BURNER_MEDIUM_REWRITABLE|	\
					 BURNER_MEDIUM_PLUS)

#define BURNER_MEDIUM_DVD_RAM		(BURNER_MEDIUM_DVD|		\
					 BURNER_MEDIUM_RAM)

/* BD types all exist in BD-R(E) DL as well */
#define BURNER_MEDIUM_BD_ROM		(BURNER_MEDIUM_BD|		\
					 BURNER_MEDIUM_ROM)
#define BURNER_MEDIUM_BDR_SRM		(BURNER_MEDIUM_BD|		\
					 BURNER_MEDIUM_SRM|		\
					 BURNER_MEDIUM_WRITABLE)
#define BURNER_MEDIUM_BDR_SRM_POW	(BURNER_MEDIUM_BD|		\
					 BURNER_MEDIUM_POW|		\
					 BURNER_MEDIUM_SRM|		\
					 BURNER_MEDIUM_WRITABLE)

/* This seems to be a really rare mode for BD-R */
#define BURNER_MEDIUM_BDR_RANDOM	(BURNER_MEDIUM_BD|		\
					 BURNER_MEDIUM_WRITABLE|	\
					 BURNER_MEDIUM_RANDOM)
/* This is always RANDOM write */
#define BURNER_MEDIUM_BDRE		(BURNER_MEDIUM_BD|			\
					 BURNER_MEDIUM_REWRITABLE)



#define BURNER_MEDIUM_VALID(media)	((media) != BURNER_MEDIUM_NONE	&&	\
					 (media) != BURNER_MEDIUM_BUSY	&&	\
					 (media) != BURNER_MEDIUM_UNSUPPORTED)


#define BURNER_MEDIUM_TYPE(media)	((media) & 0x003F)
#define BURNER_MEDIUM_ATTR(media)	((media) & 0x1C000)
#define BURNER_MEDIUM_STATUS(media)	((media) & 0xE0000)
#define BURNER_MEDIUM_SUBTYPE(media)	((media) & 0x1FC0)
#define BURNER_MEDIUM_INFO(media)	((media) & 0xFE0000)

#define BURNER_MEDIUM_IS(media, type)	(((media)&(type))==(type))

/* These behave like random writable:
 * they can be appendable or closed, rewritable or writable */
#define BURNER_MEDIUM_RANDOM_WRITABLE(media)					\
	(BURNER_MEDIUM_IS (media, BURNER_MEDIUM_DVDRW_PLUS) ||		\
	 BURNER_MEDIUM_IS (media, BURNER_MEDIUM_DVDRW_RESTRICTED) ||		\
	 BURNER_MEDIUM_IS (media, BURNER_MEDIUM_DVD_RAM) || 			\
	 BURNER_MEDIUM_IS (media, BURNER_MEDIUM_BDR_RANDOM) ||		\
	 BURNER_MEDIUM_IS (media, BURNER_MEDIUM_BDR_SRM_POW) ||		\
	 BURNER_MEDIUM_IS (media, BURNER_MEDIUM_BDRE))


G_END_DECLS

#endif /* _BURN_MEDIA_H */

 

