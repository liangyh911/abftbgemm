// Auto-generated file. Do not edit!
//   Template: src/qs8-dwconv/multipass-scalar.c.in
//   Generator: tools/xngen
//
// Copyright 2023 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include <xnnpack/dwconv.h>
#include <xnnpack/math.h>
#include <xnnpack/unaligned.h>


void xnn_qs8_dwconv_minmax_fp32_ukernel_8f8m9l1c1s1r__scalar_imagic(
    size_t channels,
    size_t output_width,
    const int8_t** input,
    const void* weights,
    int8_t* output,
    intptr_t input_stride,
    size_t output_increment,
    size_t input_offset,
    const int8_t* zero,
    size_t kernel_size,
    int32_t* buffer,
    const union xnn_qs8_conv_minmax_params params[restrict XNN_MIN_ELEMENTS(1)])
{
  assert(channels != 0);
  assert(output_width != 0);
  assert(kernel_size > 8);

  const float vscale = params->fp32_scalar_imagic.scale;
  const float vmagic_bias = params->fp32_scalar_imagic.magic_bias;
  const int32_t vmagic_min = params->fp32_scalar_imagic.magic_min;
  const int32_t vmagic_max = params->fp32_scalar_imagic.magic_max;
  const int32_t vmagic_bias_less_zero_point = params->fp32_scalar_imagic.magic_bias_less_zero_point;
  do {
    const void* w = weights;

    // First pass to process 8 inputs.
    {
      int32_t* b = buffer;
      const int8_t* i0 = input[0];
      assert(i0 != NULL);
      if XNN_UNPREDICTABLE(i0 != zero) {
        i0 = (const int8_t*) ((uintptr_t) i0 + input_offset);
      }
      const int8_t* i1 = input[1];
      assert(i1 != NULL);
      if XNN_UNPREDICTABLE(i1 != zero) {
        i1 = (const int8_t*) ((uintptr_t) i1 + input_offset);
      }
      const int8_t* i2 = input[2];
      assert(i2 != NULL);
      if XNN_UNPREDICTABLE(i2 != zero) {
        i2 = (const int8_t*) ((uintptr_t) i2 + input_offset);
      }
      const int8_t* i3 = input[3];
      assert(i3 != NULL);
      if XNN_UNPREDICTABLE(i3 != zero) {
        i3 = (const int8_t*) ((uintptr_t) i3 + input_offset);
      }
      const int8_t* i4 = input[4];
      assert(i4 != NULL);
      if XNN_UNPREDICTABLE(i4 != zero) {
        i4 = (const int8_t*) ((uintptr_t) i4 + input_offset);
      }
      const int8_t* i5 = input[5];
      assert(i5 != NULL);
      if XNN_UNPREDICTABLE(i5 != zero) {
        i5 = (const int8_t*) ((uintptr_t) i5 + input_offset);
      }
      const int8_t* i6 = input[6];
      assert(i6 != NULL);
      if XNN_UNPREDICTABLE(i6 != zero) {
        i6 = (const int8_t*) ((uintptr_t) i6 + input_offset);
      }
      const int8_t* i7 = input[7];
      assert(i7 != NULL);
      if XNN_UNPREDICTABLE(i7 != zero) {
        i7 = (const int8_t*) ((uintptr_t) i7 + input_offset);
      }
      input += 8;

      size_t c = channels;
      do {
        int32_t vacc = unaligned_load_s32(w);
        const int32_t vi0 = (int32_t) *i0++;
        const int32_t vk0 = ((const int8_t*) ((uintptr_t) w + sizeof(int32_t)))[0];
        vacc += vi0 * vk0;
        const int32_t vi1 = (int32_t) *i1++;
        const int32_t vk1 = ((const int8_t*) ((uintptr_t) w + sizeof(int32_t)))[1];
        vacc += vi1 * vk1;
        const int32_t vi2 = (int32_t) *i2++;
        const int32_t vk2 = ((const int8_t*) ((uintptr_t) w + sizeof(int32_t)))[2];
        vacc += vi2 * vk2;
        const int32_t vi3 = (int32_t) *i3++;
        const int32_t vk3 = ((const int8_t*) ((uintptr_t) w + sizeof(int32_t)))[3];
        vacc += vi3 * vk3;
        const int32_t vi4 = (int32_t) *i4++;
        const int32_t vk4 = ((const int8_t*) ((uintptr_t) w + sizeof(int32_t)))[4];
        vacc += vi4 * vk4;
        const int32_t vi5 = (int32_t) *i5++;
        const int32_t vk5 = ((const int8_t*) ((uintptr_t) w + sizeof(int32_t)))[5];
        vacc += vi5 * vk5;
        const int32_t vi6 = (int32_t) *i6++;
        const int32_t vk6 = ((const int8_t*) ((uintptr_t) w + sizeof(int32_t)))[6];
        vacc += vi6 * vk6;
        const int32_t vi7 = (int32_t) *i7++;
        const int32_t vk7 = ((const int8_t*) ((uintptr_t) w + sizeof(int32_t)))[7];
        vacc += vi7 * vk7;

        w = (const void*) ((uintptr_t) w + sizeof(int32_t) + 8 * sizeof(int8_t));
        *b++ = vacc;
      } while (--c != 0);
    }

    // Middle pass to process 8 inputs in each iteration.
    for (size_t ks = kernel_size - 8; ks > 9; ks -= 8) {
      int32_t* b = buffer;
      const int8_t* i0 = input[0];
      assert(i0 != NULL);
      if XNN_UNPREDICTABLE(i0 != zero) {
        i0 = (const int8_t*) ((uintptr_t) i0 + input_offset);
      }
      const int8_t* i1 = input[1];
      assert(i1 != NULL);
      if XNN_UNPREDICTABLE(i1 != zero) {
        i1 = (const int8_t*) ((uintptr_t) i1 + input_offset);
      }
      const int8_t* i2 = input[2];
      assert(i2 != NULL);
      if XNN_UNPREDICTABLE(i2 != zero) {
        i2 = (const int8_t*) ((uintptr_t) i2 + input_offset);
      }
      const int8_t* i3 = input[3];
      assert(i3 != NULL);
      if XNN_UNPREDICTABLE(i3 != zero) {
        i3 = (const int8_t*) ((uintptr_t) i3 + input_offset);
      }
      const int8_t* i4 = input[4];
      assert(i4 != NULL);
      if XNN_UNPREDICTABLE(i4 != zero) {
        i4 = (const int8_t*) ((uintptr_t) i4 + input_offset);
      }
      const int8_t* i5 = input[5];
      assert(i5 != NULL);
      if XNN_UNPREDICTABLE(i5 != zero) {
        i5 = (const int8_t*) ((uintptr_t) i5 + input_offset);
      }
      const int8_t* i6 = input[6];
      assert(i6 != NULL);
      if XNN_UNPREDICTABLE(i6 != zero) {
        i6 = (const int8_t*) ((uintptr_t) i6 + input_offset);
      }
      const int8_t* i7 = input[7];
      assert(i7 != NULL);
      if XNN_UNPREDICTABLE(i7 != zero) {
        i7 = (const int8_t*) ((uintptr_t) i7 + input_offset);
      }
      input += 8;

      size_t c = channels;
      do {
        int32_t vacc = *b;
        const int32_t vi0 = (int32_t) *i0++;
        const int32_t vk0 = ((const int8_t*) w)[0];
        vacc += vi0 * vk0;
        const int32_t vi1 = (int32_t) *i1++;
        const int32_t vk1 = ((const int8_t*) w)[1];
        vacc += vi1 * vk1;
        const int32_t vi2 = (int32_t) *i2++;
        const int32_t vk2 = ((const int8_t*) w)[2];
        vacc += vi2 * vk2;
        const int32_t vi3 = (int32_t) *i3++;
        const int32_t vk3 = ((const int8_t*) w)[3];
        vacc += vi3 * vk3;
        const int32_t vi4 = (int32_t) *i4++;
        const int32_t vk4 = ((const int8_t*) w)[4];
        vacc += vi4 * vk4;
        const int32_t vi5 = (int32_t) *i5++;
        const int32_t vk5 = ((const int8_t*) w)[5];
        vacc += vi5 * vk5;
        const int32_t vi6 = (int32_t) *i6++;
        const int32_t vk6 = ((const int8_t*) w)[6];
        vacc += vi6 * vk6;
        const int32_t vi7 = (int32_t) *i7++;
        const int32_t vk7 = ((const int8_t*) w)[7];
        vacc += vi7 * vk7;

        w = (const void*) ((uintptr_t) w + 8 * sizeof(int8_t));
        *b++ = vacc;
      } while (--c != 0);
    }

    // Last pass to process up to 9 inputs.
    {
      const int32_t* b = buffer;
      const int8_t* i0 = input[0];
      assert(i0 != NULL);
      if XNN_UNPREDICTABLE(i0 != zero) {
        i0 = (const int8_t*) ((uintptr_t) i0 + input_offset);
      }
      const int8_t* i1 = input[1];
      assert(i1 != NULL);
      if XNN_UNPREDICTABLE(i1 != zero) {
        i1 = (const int8_t*) ((uintptr_t) i1 + input_offset);
      }
      const int8_t* i2 = input[2];
      assert(i2 != NULL);
      if XNN_UNPREDICTABLE(i2 != zero) {
        i2 = (const int8_t*) ((uintptr_t) i2 + input_offset);
      }
      const int8_t* i3 = input[3];
      assert(i3 != NULL);
      if XNN_UNPREDICTABLE(i3 != zero) {
        i3 = (const int8_t*) ((uintptr_t) i3 + input_offset);
      }
      const int8_t* i4 = input[4];
      assert(i4 != NULL);
      if XNN_UNPREDICTABLE(i4 != zero) {
        i4 = (const int8_t*) ((uintptr_t) i4 + input_offset);
      }
      const int8_t* i5 = input[5];
      assert(i5 != NULL);
      if XNN_UNPREDICTABLE(i5 != zero) {
        i5 = (const int8_t*) ((uintptr_t) i5 + input_offset);
      }
      const int8_t* i6 = input[6];
      assert(i6 != NULL);
      if XNN_UNPREDICTABLE(i6 != zero) {
        i6 = (const int8_t*) ((uintptr_t) i6 + input_offset);
      }
      const int8_t* i7 = input[7];
      assert(i7 != NULL);
      if XNN_UNPREDICTABLE(i7 != zero) {
        i7 = (const int8_t*) ((uintptr_t) i7 + input_offset);
      }
      const int8_t* i8 = input[8];
      assert(i8 != NULL);
      if XNN_UNPREDICTABLE(i8 != zero) {
        i8 = (const int8_t*) ((uintptr_t) i8 + input_offset);
      }

      size_t c = channels;
      do {
        int32_t vacc = unaligned_load_s32(b++);
        const int32_t vi0 = (int32_t) *i0++;
        const int32_t vk0 = ((const int8_t*) w)[0];
        vacc += vi0 * vk0;
        const int32_t vi1 = (int32_t) *i1++;
        const int32_t vk1 = ((const int8_t*) w)[1];
        vacc += vi1 * vk1;
        const int32_t vi2 = (int32_t) *i2++;
        const int32_t vk2 = ((const int8_t*) w)[2];
        vacc += vi2 * vk2;
        const int32_t vi3 = (int32_t) *i3++;
        const int32_t vk3 = ((const int8_t*) w)[3];
        vacc += vi3 * vk3;
        const int32_t vi4 = (int32_t) *i4++;
        const int32_t vk4 = ((const int8_t*) w)[4];
        vacc += vi4 * vk4;
        const int32_t vi5 = (int32_t) *i5++;
        const int32_t vk5 = ((const int8_t*) w)[5];
        vacc += vi5 * vk5;
        const int32_t vi6 = (int32_t) *i6++;
        const int32_t vk6 = ((const int8_t*) w)[6];
        vacc += vi6 * vk6;
        const int32_t vi7 = (int32_t) *i7++;
        const int32_t vk7 = ((const int8_t*) w)[7];
        vacc += vi7 * vk7;
        const int32_t vi8 = (int32_t) *i8++;
        const int32_t vk8 = ((const int8_t*) w)[8];
        vacc += vi8 * vk8;

        w = (const void*) ((uintptr_t) w + 9 * sizeof(int8_t));

        float vfpacc = (float) vacc * vscale;

        vfpacc += vmagic_bias;
        int32_t vout = (int32_t) float_as_uint32(vfpacc);
        vout = math_max_s32(vout, vmagic_min);
        vout = math_min_s32(vout, vmagic_max);
        vout -= vmagic_bias_less_zero_point;

        *output++ = (int8_t) vout;
      } while (--c != 0);
    }

    input = (const int8_t**) ((uintptr_t) input + input_stride);
    output = (int8_t*) ((uintptr_t) output + output_increment);
  } while (--output_width != 0);
}
