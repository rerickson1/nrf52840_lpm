# nrf52840_lpm
nRF52840 low power mode example with Zephyr

## Checkout and Build
```
west init -m https://github.com/rerickson1/nrf52840_lpm.git
west update
west build -b nrf52840_pca10056 -d nrf52840_lpm/build nrf52840_lpm/app
```
