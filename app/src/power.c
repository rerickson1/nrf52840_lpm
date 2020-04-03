#include <zephyr.h>
#include <power.h>

static void shutdown_console_uart(void)
{
	struct device *uart_dev;
	uart_dev = device_get_binding(CONFIG_UART_CONSOLE_ON_DEV_NAME);
	int rc = device_set_power_state(uart_dev, DEVICE_PM_OFF_STATE, NULL,
					NULL);
	if (rc) {
		printk("Error disabling console UART peripheral (%d)\n", rc);
	}
}

static void startup_console_uart(void)
{
	struct device *uart_dev;
	uart_dev = device_get_binding(CONFIG_UART_CONSOLE_ON_DEV_NAME);
	int rc = device_set_power_state(uart_dev, DEVICE_PM_ACTIVE_STATE, NULL,
					NULL);
	if (rc) {
		printk("Error enabling console UART peripheral (%d)\n", rc);
	}
}

/*
 * Application defined function for doing any target specific operations
 * for low power entry.
 */
void sys_pm_notify_power_state_entry(enum power_states state)
{
	switch (state) {
	case SYS_POWER_STATE_SLEEP_1:
		printk("--> Entering SYS_POWER_STATE_SLEEP_1 state.\n");
		shutdown_console_uart();
		k_cpu_idle();
		break;
	default:
		printk("Unsupported power state %u\n", state);
		break;
	}
}

/*
 * Application defined function for doing any target specific operations
 * for low power exit.
 */
void sys_pm_notify_power_state_exit(enum power_states state)
{
	switch (state) {
	case SYS_POWER_STATE_SLEEP_1:
		startup_console_uart();
		printk("<-- Exited SYS_POWER_STATE_SLEEP_1 state.\n");
		break;

	default:
		printk("Unsupported power state %u\n", state);
		break;
	}
}
