/*
 * MOD Convolution Loader
 * Copyright (C) 2022-2023 Filipe Coelho <falktx@falktx.com>
 *
 * Permission to use, copy, modify, and/or distribute this software for any purpose with
 * or without fee is hereby granted, provided that the above copyright notice and this
 * permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD
 * TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN
 * NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER
 * IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#pragma once

#define DISTRHO_PLUGIN_BRAND "MOD"

#define DISTRHO_PLUGIN_HAS_UI          0
#define DISTRHO_PLUGIN_IS_RT_SAFE      0
#define DISTRHO_PLUGIN_WANT_PROGRAMS   0
#define DISTRHO_PLUGIN_WANT_STATE      1
#define DISTRHO_PLUGIN_WANT_FULL_STATE 0

#ifdef CONVOLUTION_REVERB
#define DISTRHO_PLUGIN_NUM_INPUTS   2
#define DISTRHO_PLUGIN_NUM_OUTPUTS  2
#define DISTRHO_PLUGIN_NAME         "Convolution Loader"
#define DISTRHO_PLUGIN_LABEL        "ConvolutionLoader"
#define DISTRHO_PLUGIN_URI          "https://mod.audio/plugins/ConvolutionLoader"
#define DISTRHO_PLUGIN_LV2_CATEGORY "lv2:ReverbPlugin"
#else
#define DISTRHO_PLUGIN_NUM_INPUTS   1
#define DISTRHO_PLUGIN_NUM_OUTPUTS  1
#define DISTRHO_PLUGIN_NAME         "Cabinet Loader"
#define DISTRHO_PLUGIN_LABEL        "CabinetLoader"
#define DISTRHO_PLUGIN_URI          "https://mod.audio/plugins/CabinetLoader"
#define DISTRHO_PLUGIN_LV2_CATEGORY "lv2:SimulatorPlugin"
#endif

enum Parameters {
   #ifdef CONVOLUTION_REVERB
    kParameterDryLevel,
    kParameterWetLevel,
    kParameterHighPassFilter,
    kParameterTrails,
    kParameterBypass,
    kParameterBuffered,
   #else
    kParameterWetLevel,
    kParameterBypass,
   #endif
    kParameterCount
};

enum Programs {
    kProgramCount
};

enum States {
    kStateFile,
    kStateCount
};

static constexpr const struct {
    float min, def, max;
} kParameterRanges[kParameterCount] = {
   #ifdef CONVOLUTION_REVERB
    { -60.f, 0.f, 0.f },
    { -60.f, -30.f, 0.f },
    { 0.f, 0.f, 500.f },
    { 0.f, 1.f, 1.f },
    { 0.f, 0.f, 1.f },
   #else
    { -60.f, -12.f, 0.f },
   #endif
    { 0.f, 0.f, 1.f }
};
