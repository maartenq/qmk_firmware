// keyboards/splitkb/kyria/keymaps/maartenq/config.h

#pragma once

/* Tap-Hold Configuration */

/* Determines what is a tap and what is a hold. After holding a key for */
/* the TAPPING_TERM value in milleseconds, a key tab has become a hold. */
#undef TAPPING_TERM
#define TAPPING_TERM 240

/* Enable rapid switch from tap to hold, disables double tap hold auto-repeat. */
#define TAPPING_FORCE_HOLD

/* Makes tap and hold keys (like Layer Tap) work better for fast typists, or */
/* for high TAPPING_TERM settings. */
#define PERMISSIVE_HOLD

/* Holding and releasing a dual function key without pressing another key will
result in nothing happening. With retro tapping enabled, releasing the key
without pressing another will send the original keycode even if it is outside
the tapping term. */
#define RETRO_TAPPING

/* Mouse Configuration */
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY 5

#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 16

#undef MOUSEKEY_MOVE_DELTA
#define MOUSEKEY_MOVE_DELTA 1

#undef MOUSEKEY_INITIAL_SPEED
#define MOUSEKEY_INITIAL_SPEED 1

#undef MOUSEKEY_DECELERATED_SPEED
#define MOUSEKEY_DECELERATED_SPEED 12

#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 22

#undef USB_SUSPEND_WAKEUP_DELAY
#define USB_SUSPEND_WAKEUP_DELAY 0

#undef MOUSEKEY_WHEEL_INTERVAL
#define MOUSEKEY_WHEEL_INTERVAL 83

#undef MOUSEKEY_WHEEL_INTERVAL
#define MOUSEKEY_WHEEL_INTERVAL 83

#undef MOUSEKEY_WHEEL_MAX_SPEED
#define MOUSEKEY_WHEEL_MAX_SPEED 3
