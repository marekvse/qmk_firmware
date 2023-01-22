# Adding the Layer Lock feature: https://getreuer.info/posts/keyboards/layer-lock/index.html
SRC += features/layer_lock.c

# Enables Link Time Optimization (LTO) when compiling the keyboard. This makes the process take longer,
# but it can significantly reduce the compiled size (and since the firmware is small, the added time is not noticeable).
LTO_ENABLE = no

# Audio control and System control
EXTRAKEY_ENABLE = yes

# Mouse keys enabling
MOUSEKEY_ENABLE = yes

# DOC: https://docs.qmk.fm/#/feature_encoders
ENCODER_ENABLE = yes
# ENCODER_MAP_ENABLE = yes
# OLED_DRIVER_ENABLE = no
# WPM_ENABLE = no

# Enable keyboard underlight functionality
RGBLIGHT_ENABLE = yes

# COMBO_ENABLE = yes

# DOC: https://thomasbaart.nl/2018/12/20/qmk-basics-leader-key/ and https://docs.qmk.fm/#/feature_leader_key
# Enable leader key functionality
LEADER_ENABLE = yes

# DOC: https://docs.qmk.fm/#/feature_dynamic_macros
# Dynamic macros
#DYNAMIC_MACRO_ENABLE = yes

# Enable programmable buttons: https://docs.qmk.fm/#/feature_programmable_button
PROGRAMMABLE_BUTTON_ENABLE = yes

# DOC: https://qmk.github.io/qmk_mkdocs/master/en/feature_unicode/
# Enable unicode OR unicode map
# UNICODE_ENABLE = yes
UNICODEMAP_ENABLE = yes
