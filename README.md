DSP filters in C
----

> Note: this repo is a port of my C++ filters to C. The C++ repo is
located [here](https://github.com/dimtass/DSP-Cpp-filters)

This repo contains some DSP biquad filters used in audio. I've extracted those
filters from the `Designing Audio Effect Plug-Ins in C++: With Digital Audio Signal Processing Theory`
book that you can find [here](https://www.amazon.com/Designing-Audio-Effect-Plug-Ins-Processing/dp/0240825152).

Not all those filters are tested, but I think that the high-pass filters don't work
very well.

This is the formula I'm using for the [digital biquad filter](https://en.wikipedia.org/wiki/Digital_biquad_filter)
in the source code:
```
y(n) = a0*x(n) + a1*x(n-1) + a2*x(n-2) - b*y(n-1) + b2*y(n-2)
```

The list of the filters is the following:

First order all-pass filter (fo_apf)
First order high-pass filter (fo_hpf)
First order low-pass filter (fo_lpf)
First order high-shelving filter (fo_shelving_high)
First order low-shelving filter (fo_shelving_low)
Second order all-pass filter (so_apf)
Second order band-pass filter (so_bpf)
Second order band-stop filter (so_bsf)
Second order Butterworth band-pass filter (so_butterworth_bpf)
Second order Butterworth band-stop filter (so_butterworth_bsf)
Second order Butterworth high-pass filter (so_butterworth_hpf)
Second order Butterworth low-pass filter (so_butterworth_lpf)
Second order high-pass filter (so_hpf)
Second order Linkwitz-Riley high-pass filter (so_linkwitz_riley_hpf)
Second order Linkwitz-Riley low-pass filter (so_linkwitz_riley_lpf)
Second order Low-pass filter (so_lpf)
Second order parametric/peaking boost filter with constant-Q (so_parametric_cq_boost)
Second order parametric/peaking cut filter with constant-Q (so_parametric_cq_cut)
Second order parametric/peaking filter with non-constant-Q (so_parametric_ncq)

## Usage:
The filters can be used in your C code in the part where the audio sample is about to be processed.
You need to include the filter_common.h and the calculate the coefficients with the `xxx_calculate_coeffs()`
function, where `xxx` the name of the unit file. Then in the sample processing function run the `xxx_filter()`
function with the current sample as a parameter.

There's a real example on how to use this lib in this repo [here](https://bitbucket.org/dimtass/stm32f303-adc-dac-dsp/src/master/).
In this repo I'm using an STM32F303CC (black pill). There is an ADC
that captures the input signal and then using DMA is storing the value
to the SRAM and then the filter function is applied on the sample and
then the result is ouput to the DAC channel.