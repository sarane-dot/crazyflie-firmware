/**
 * ,---------,       ____  _ __
 * |  ,-^-,  |      / __ )(_) /_______________ _____  ___
 * | (  O  ) |     / __  / / __/ ___/ ___/ __ `/_  / / _ \
 * | / ,--´  |    / /_/ / / /_/ /__/ /  / /_/ / / /_/  __/
 *    +------`   /_____/_/\__/\___/_/   \__,_/ /___/\___/
 *
 * Crazyflie control firmware
 *
 * Copyright (C) 2022 Bitcraze AB
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, in version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 *
 * platform_defaults_sitl.h - platform specific default values for the sitl platform
 *
 * SITL-tuned PID gains (2026-09-15):
 *
 *  LAYER          KP      KI      KD     Notes
 *  ─────────────────────────────────────────────────────────────────
 *  Roll  rate    100.0   400.0    2.5   Reduced from 125/500 – less aggression
 *  Pitch rate    100.0   400.0    2.5   Same as roll
 *  Yaw   rate     50.0    16.7    0.0   Slightly softer yaw
 *
 *  Roll  angle     4.0     2.0    0.0   Higher KP for snappier levelling
 *  Pitch angle     4.0     2.0    0.0   Same as roll
 *  Yaw   angle     3.0     1.0    0.35  Unchanged
 *
 *  Pos X           2.0     0.0    0.5   Added KD to damp XY position oscillation
 *  Pos Y           2.0     0.0    0.5   Same
 *  Pos Z           2.0     0.3    0.3   Reduced KI (was 0.5), added KD
 *
 *  Vel X          20.0     0.5    0.5   Reduced KP (was 25), small KD
 *  Vel Y          20.0     0.5    0.5   Same
 *  Vel Z          15.0     5.0    1.5   KEY FIX: was 25/15/0 – much less bounce
 */

#pragma once

#ifndef __INCLUDED_FROM_PLATFORM_DEFAULTS__
    #pragma GCC error "Do not include this file directly, include platform_defaults.h instead."
#endif

// Defines for default values in the cf2 platform

// Default values for battery limits
#define DEFAULT_BAT_LOW_VOLTAGE                   3.2f
#define DEFAULT_BAT_CRITICAL_LOW_VOLTAGE          3.0f
#define DEFAULT_BAT_LOW_DURATION_TO_TRIGGER_SEC   5

// Default value for system shutdown in minutes after radio silence.
// Requires kbuild config ENABLE_AUTO_SHUTDOWN to be activated.
#define DEFAULT_SYSTEM_SHUTDOWN_TIMEOUT_MIN       5

#undef PID_ROLL_RATE_KP
#define PID_ROLL_RATE_KP  100.0
#undef PID_ROLL_RATE_KI
#define PID_ROLL_RATE_KI  400.0
#undef PID_ROLL_RATE_KD
#define PID_ROLL_RATE_KD  2.5
#undef PID_ROLL_RATE_KFF
#define PID_ROLL_RATE_KFF 0.0
#undef PID_ROLL_RATE_INTEGRATION_LIMIT
#define PID_ROLL_RATE_INTEGRATION_LIMIT    33.3

#undef PID_PITCH_RATE_KP
#define PID_PITCH_RATE_KP  100.0
#undef PID_PITCH_RATE_KI
#define PID_PITCH_RATE_KI  400.0
#undef PID_PITCH_RATE_KD
#define PID_PITCH_RATE_KD  2.5
#undef PID_PITCH_RATE_KFF
#define PID_PITCH_RATE_KFF 0.0
#undef PID_PITCH_RATE_INTEGRATION_LIMIT
#define PID_PITCH_RATE_INTEGRATION_LIMIT   33.3

#undef PID_YAW_RATE_KP
#define PID_YAW_RATE_KP  50.0
#undef PID_YAW_RATE_KI
#define PID_YAW_RATE_KI  16.7
#undef PID_YAW_RATE_KD
#define PID_YAW_RATE_KD  0.0
#undef PID_YAW_RATE_KFF
#define PID_YAW_RATE_KFF 0.0
#undef PID_YAW_RATE_INTEGRATION_LIMIT
#define PID_YAW_RATE_INTEGRATION_LIMIT     166.7

// ─── LAYER 2 – Attitude Angle ────────────────────────────────────────────────
// KP raised slightly (3→4) for faster levelling response.
// KI reduced to prevent integrator windup during aggressive manoeuvres.
#undef PID_ROLL_KP
#define PID_ROLL_KP  6.0
#undef PID_ROLL_KI
#define PID_ROLL_KI  2.0
#undef PID_ROLL_KD
#define PID_ROLL_KD  0.0
#undef PID_ROLL_KFF
#define PID_ROLL_KFF 0.0
#undef PID_ROLL_INTEGRATION_LIMIT
#define PID_ROLL_INTEGRATION_LIMIT    20.0

#undef PID_PITCH_KP
#define PID_PITCH_KP  6.0
#undef PID_PITCH_KI
#define PID_PITCH_KI  2.0
#undef PID_PITCH_KD
#define PID_PITCH_KD  0.0
#undef PID_PITCH_KFF
#define PID_PITCH_KFF 0.0
#undef PID_PITCH_INTEGRATION_LIMIT
#define PID_PITCH_INTEGRATION_LIMIT   20.0

#undef PID_YAW_KP
#define PID_YAW_KP  3.0
#undef PID_YAW_KI
#define PID_YAW_KI  1.0
#undef PID_YAW_KD
#define PID_YAW_KD  0.35
#undef PID_YAW_KFF
#define PID_YAW_KFF 0.0
#undef PID_YAW_INTEGRATION_LIMIT
#define PID_YAW_INTEGRATION_LIMIT     360.0

// ─── LAYER 3 – Velocity ──────────────────────────────────────────────────────
// XY: KP reduced 25→20 (less lateral overshoot). Removed buggy SITL KD!
#undef PID_VEL_X_KP
#define PID_VEL_X_KP  25.0f
#undef PID_VEL_X_KI
#define PID_VEL_X_KI  1.0f
#undef PID_VEL_X_KD
#define PID_VEL_X_KD  0.1f
#undef PID_VEL_X_KFF
#define PID_VEL_X_KFF 0.0f

#undef PID_VEL_Y_KP
#define PID_VEL_Y_KP  25.0f
#undef PID_VEL_Y_KI
#define PID_VEL_Y_KI  1.0f
#undef PID_VEL_Y_KD
#define PID_VEL_Y_KD  0.1f
#undef PID_VEL_Y_KFF
#define PID_VEL_Y_KFF 0.0f

#undef PID_VEL_Z_KP
#define PID_VEL_Z_KP  25.0f
#undef PID_VEL_Z_KI
#define PID_VEL_Z_KI  10.0f
#undef PID_VEL_Z_KD
#define PID_VEL_Z_KD  0.5f
#undef PID_VEL_Z_KFF
#define PID_VEL_Z_KFF 0.0f

// Barometric hold (not used in SITL with Kalman, kept for completeness)
#undef PID_VEL_Z_KP_BARO_Z_HOLD
#define PID_VEL_Z_KP_BARO_Z_HOLD 3.0f
#undef PID_VEL_Z_KI_BARO_Z_HOLD
#define PID_VEL_Z_KI_BARO_Z_HOLD 1.0f
#undef PID_VEL_Z_KD_BARO_Z_HOLD
#define PID_VEL_Z_KD_BARO_Z_HOLD 1.5f
#undef PID_VEL_Z_KFF_BARO_Z_HOLD
#define PID_VEL_Z_KFF_BARO_Z_HOLD 0.0f

// Velocity → attitude output limits and thrust baseline
#undef PID_VEL_ROLL_MAX
#define PID_VEL_ROLL_MAX  20.0f
#undef PID_VEL_PITCH_MAX
#define PID_VEL_PITCH_MAX 20.0f
#undef PID_VEL_THRUST_BASE
#define PID_VEL_THRUST_BASE              36000.0f
#undef PID_VEL_THRUST_BASE_BARO_Z_HOLD
#define PID_VEL_THRUST_BASE_BARO_Z_HOLD 38000.0f
#undef PID_VEL_THRUST_MIN
#define PID_VEL_THRUST_MIN               20000.0f

// ─── LAYER 4 – Position (outermost) ─────────────────────────────────────────
// Added KD to both XY and Z to damp overshoot when approaching waypoints.
// KI on Z reduced 0.5→0.3 to prevent altitude windup during hover.
#undef PID_POS_X_KP
#define PID_POS_X_KP  2.0f
#undef PID_POS_X_KI
#define PID_POS_X_KI  0.0f
#undef PID_POS_X_KD
#define PID_POS_X_KD  0.1f
#undef PID_POS_X_KFF
#define PID_POS_X_KFF 0.0f

#undef PID_POS_Y_KP
#define PID_POS_Y_KP  2.0f
#undef PID_POS_Y_KI
#define PID_POS_Y_KI  0.0f
#undef PID_POS_Y_KD
#define PID_POS_Y_KD  0.1f
#undef PID_POS_Y_KFF
#define PID_POS_Y_KFF 0.0f

#undef PID_POS_Z_KP
#define PID_POS_Z_KP  2.0f
#undef PID_POS_Z_KI
#define PID_POS_Z_KI  0.5f
#undef PID_POS_Z_KD
#define PID_POS_Z_KD  0.2f
#undef PID_POS_Z_KFF
#define PID_POS_Z_KFF 0.0f

// Position → velocity output caps
#undef PID_POS_VEL_X_MAX
#define PID_POS_VEL_X_MAX 1.0f
#undef PID_POS_VEL_Y_MAX
#define PID_POS_VEL_Y_MAX 1.0f
#undef PID_POS_VEL_Z_MAX
#define PID_POS_VEL_Z_MAX 1.0f
