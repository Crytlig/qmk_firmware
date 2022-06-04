MCU = atmega32u4

# Bootloader selection
BOOTLOADER = atmel-dfu

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE  = yes   # Enable Bootmagic Lite
CONSOLE_ENABLE 	  = no    # Console for debug
COMMAND_ENABLE 	  = no    # Commands for debug and configuration
RGB_MATRIX_ENABLE = yes   # RGB Matrix
UNICODEMAP_ENABLE = no    # Enables UNICODE MAP. Map is self maintained in keymap.c
UNICODE_ENABLE 	  = yes   # Simple UNICODE enable. Requires WinCompose on Windows
LTO_ENABLE		  = yes   # Reduce firmware binary size
