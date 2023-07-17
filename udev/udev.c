#include <libudev.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>

int main(void){
    struct udev *udev;
    struct udev_enumerate *enumerate;
    struct udev_list_entry *devices, *dev_list_entry;
    struct udev_device *dev;

    /* create the udev object */

    udev= udev_new();
    if(!udev){
        printf("Can't create udev\n");
        exit(1);
    }

    /* create a list of the devices in the tty subsystem */
    enumerate = udev_enumerate_new(udev);
    udev_enumerate_add_match_subsystem(enumerate, "tty");
    udev_enumerate_scan_devices(enumerate);
    devices = udev_enumerate_get_list_entry(enumerate);

    /* for each item enumerated, print out its information */
    udev_list_entry_foreach(dev_list_entry, devices){
        const char *path;

        /* get the filename of the /sys entry for the device
        and create a udev_device object(dev) representing it */
        path = udev_list_entry_get_name(dev_list_entry);
        dev = udev_device_new_from_syspath(udev, path);

        printf("Device node path: %s\n", udev_device_get_devnode(dev));

        /* The device pointed to by dev contains information about the tty
        device. In order to get inormaiton about the USB device, get the 
        parent device with subsystem/devtype pair of "usb"/"usb_device". This
        will be several levels up the tree, but the function will find it. */

        dev = udev_device_get_parent_with_subsystem_devtype(
            dev,
            "usb",
            "usb_device"
        );
        if(!dev){
            // printf("Unable to find parent usb device.");
            // exit(1);
            continue;
        }

        printf(" VID/PID: %s %s\n",
            udev_device_get_sysattr_value(dev, "idVendor"),
            udev_device_get_sysattr_value(dev, "idProduct"));
        printf(" %s\n %s\n",
            udev_device_get_sysattr_value(dev, "manufacturer"),
            udev_device_get_sysattr_value(dev, "product"));
        printf(" serial: %s\n",
            udev_device_get_sysattr_value(dev, "serial"));
        udev_device_unref(dev);
    }

    udev_enumerate_unref(enumerate);

    udev_unref(udev);

    return 0;
}