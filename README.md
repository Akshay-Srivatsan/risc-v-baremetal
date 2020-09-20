# Baremetal RISC-V
## Requirements
Hardware:
- HiFive1 Rev B

Software:
- riscv64-unknown-elf-gcc
- riscv64-unknown-elf-binutils
- SEGGER J-Link Commander (JLinkExe) (optional)

Note: this has only been tested on Linux (64-bit, 5.8.8) so far.  Let me know if you get it working on BSD, macOS, or Windows.

## Instructions
1. Install the required software as mentioned above (consult the Getting Started Guide provided by SiFive for help with this).
    - You don't need to install or compile the Freedom E SDK, you just need the compiler, binutils, and the flashing tool (JLink).  The flashing tool is optional (you can flash via .hex file without it), but it makes life easier.
2. cd into `hello`
3. Connect the HiFive1 RevB via USB.  Ensure that a new USB Mass Storage Device named "HiFive" appears.
4. run `make`
5. If you installed JLinkExe, run `make flash`
    - if JLinkExe asks if you want to update the firmware on your board, go ahead and accept (it'll prompt you every time you upload until you do)
6. If you did not install JLinkExe, export the `RISCV_MOUNT` environment variable to be the location at which your HiFive device mounted (probably under /media or /Volumes somewhere), then run `make install`.
4. You should see the onboard RGB LED (pins 19, 21, and 22) cycle between #FFFF0, #00FFFF, and #FF00FF.  If you use a serial monitor to view UART0's output, you should see it print "Hello, World!" on every reset.

## Available Demos
1. blink
    - cycles the RGB LED
    - assembly-only, position-independent code
    - .bin only, needs JLinkExe
2. hello
    - prints "Hello, World!" over UART0
    - cycles the RGB LED, using the system timer for accurate timing
    - mostly C, includes working memory map
    - includes both .bin for flashing with JLinkExe and .hex for USB MSD flashing

## Resources
[HiFive1 Rev B](https://www.sifive.com/boards/hifive1-rev-b)

[FE310-G002 Manual](https://sifive.cdn.prismic.io/sifive%2F9ecbb623-7c7f-4acc-966f-9bb10ecdb62e_fe310-g002.pdf)

[Getting Started Guide](https://sifive.cdn.prismic.io/sifive%2F4f5a7851-1b52-463b-a293-f352036bc809_hifive1b-getting-started-guide_v1.1.pdf)

