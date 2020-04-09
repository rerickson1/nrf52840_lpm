#include <zephyr.h>

#define BUSY_WAIT_TIME_SECONDS 5
#define BUSY_WAIT_TIME (BUSY_WAIT_TIME_SECONDS * 1000000)
#define SLEEP_TIME_SECONDS 15

/* Application main Thread */
void main(void)
{
	printk("\n\n*** Power Management Demo on %s ***\n\n", CONFIG_BOARD);

	while (1) {
		printk("App busy waiting for %d seconds\n",
		       BUSY_WAIT_TIME_SECONDS);
		k_busy_wait(BUSY_WAIT_TIME);
		printk("App sleeping for %d seconds\n", SLEEP_TIME_SECONDS);
		k_sleep(K_SECONDS(SLEEP_TIME_SECONDS));
	}

	printk("Exiting main()\n");
	return;
}