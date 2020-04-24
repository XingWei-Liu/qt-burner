
#include "kylin_api.h"

void kylin_init_gtk(int argc, char *argv[])
{
        g_thread_init (NULL);
        g_type_init ();

        gtk_init (&argc, &argv);
        burner_burn_library_start (&argc, &argv);
}

int kylin_get_device_info(KylinDeviceInfo info[])
{
    BurnerMediumMonitor *monitor;
    GSList *drives;
    GSList *iter;
    int num=0;

    monitor = burner_medium_monitor_get_default();
    drives = burner_medium_monitor_get_drives (monitor, BURNER_DRIVE_TYPE_ALL_BUT_FILE);
    for (iter = drives; iter; iter = iter->next)
    {
        if(num >=KYLIN_MAXNUM_DEVICE)
            return num;

        BurnerDrive *drive;
        BurnerMedium *medium;

        drive = iter->data;
        info[num].drive_name = burner_drive_get_display_name (drive);

        medium = burner_drive_get_medium (drive);
        info[num].mountpoint = burner_volume_get_mount_point (BURNER_VOLUME (medium), NULL);
        num++;
    }
    return num;
}

void kylin_device_free(KylinDeviceInfo info[], int num)
{
    int i;
    for(i=0; i<num; i++)
    {
        if(info[i].drive_name)
            free(info[i].drive_name);

        if(info[i].mountpoint)
            free(info[i].mountpoint);
    }
}



#if 0
gchar *drive_name;
gchar *mountpoint;

mountpoint = burner_volume_get_mount_point (BURNER_VOLUME (medium), NULL);
printf("mountpoint :%s \n", mountpoint) ;

if (!mountpoint)
    continue;
g_free (mountpoint);

printf("drive_name :%s \n", drive_name) ;

printf("--------------------- \n");
drive_name = burner_drive_get_display_name (drive);

gchar *tmp;
tmp = burner_drive_get_device(drive);
printf("burner_drive_get_device :%s \n", tmp) ;

tmp = burner_drive_get_block_device(drive);
printf("burner_drive_get_block_device :%s \n", tmp) ;

tmp = burner_drive_get_bus_target_lun_string(drive);
printf("burner_drive_get_bus_target_lun_string :%s \n", tmp) ;

tmp = burner_drive_get_udi(drive);
printf("burner_drive_get_udi :%s \n", tmp) ;

#endif


