# MCU name
MCU = RP2040
BOARD = GENERIC_RP_RP2040

# Bootloader selection
BOOTLOADER = rp2040

# Ignore some warnings during the build, likely to be fixed before RP2040 PR is merged
ALLOW_WARNINGS = yes

# LTO must be disabled for RP2040 builds
LTO_ENABLE = no

# PIO serial/WS2812 drivers must be used on RP2040
SERIAL_DRIVER = vendor
WS2812_DRIVER = vendor

# Audio currently doesn't work with the RP2040
AUDIO_ENABLE = no

# convert to rp2040 pinout. if you use the kb2040 comment this line and uncomment the second line
#CONVERT_TO = promicro_rp2040
CONVERT_TO = kb2040

# Haptic Feedback
HAPTIC_ENABLE = yes
HAPTIC_DRIVER += SOLENOID
EXTRAKEY_ENABLE = yes
MOUSEKEY_ENABLE = yes
ENCODER_ENABLE = yes
NKRO_ENABLE = yes