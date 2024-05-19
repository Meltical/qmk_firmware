LTO_ENABLE = yes

MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = yes
TAP_DANCE_ENABLE = no
CAPS_WORD_ENABLE = yes
COMBO_ENABLE = yes
QMK_SETTINGS = yes
KEY_OVERRIDE_ENABLE = yes

# Trackpad
POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = cirque_pinnacle_i2c
CIRQUE_PINNACLE_DIAMETER_MM = 40
CIRQUE_PINNACLE_POSITION_MODE = CIRQUE_PINNACLE_RELATIVE_MODE

# Unused features
OLED_ENABLE = no
RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MUSIC_ENABLE = no

SRC += features/swapper.c
SRC += features/achordion.c

ifeq ($(OS),WIN)
	# Default is windows
else
    ifeq ($(OS),MAC)
        OPT_DEFS += -DMAC=TRUE
    else
        $(error "Must select OS")
    endif
endif