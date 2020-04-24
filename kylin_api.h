#ifndef KYLIN_API_H
#define KYLIN_API_H

#include "so/config.h"

#include <stdio.h>
#include <string.h>
#include <locale.h>

#include <glib.h>
#include <glib/gi18n-lib.h>
#include <gtk/gtk.h>
#include <gst/gst.h>

#include <burner-drive.h>
#include <burner-track-disc.h>
#include <burner-media.h>
#include <burner-medium-monitor.h>
#include <burner-volume.h>

#define KYLIN_MAXNUM_DEVICE 32

typedef struct _KylinDeviceInfo KylinDeviceInfo;

struct _KylinDeviceInfo
{
    char *drive_name;
    char *mountpoint;
};

void kylin_init_gtk(int argc, char *argv[]);

int kylin_get_device_info(KylinDeviceInfo info[]);

void kylin_device_free(KylinDeviceInfo info[], int num);









#endif // KYLIN_API_H
