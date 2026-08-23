#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>

#define LED0_PIN 22

static const struct device *const gpio0 =
	DEVICE_DT_GET(DT_NODELABEL(gpio0));

int main()
{
	int ret;

	if (!device_is_ready(gpio0)) {
		return 0;
	}

	ret = gpio_pin_configure(gpio0, LED0_PIN, GPIO_OUTPUT_INACTIVE);
	if (ret < 0) {
		return 0;
	}

	while (true) {
		gpio_pin_toggle(gpio0, LED0_PIN);
		k_msleep(1000);
	}

	return 0;
}