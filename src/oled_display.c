#include <zephyr.h>
#include <device.h>
#include <drivers/display.h>
#include <zmk/battery.h>
#include <sys/printk.h>

#define DISPLAY_LABEL "SSD1306_128X32"

void update_battery_display(void) {
    struct device *display_dev = device_get_binding(DISPLAY_LABEL);
    if (!display_dev) return;

    int bat = zmk_battery_get_percentage();

    char buf[32];
    snprintf(buf, sizeof(buf), "Bat: %d%%", bat);

    // Write battery string to OLED (line 0)
    display_write(display_dev, buf, 0, 0);
}

void main(void) {
    while (1) {
        update_battery_display();
        k_msleep(5000);  // refresh every 5 seconds
    }
}
