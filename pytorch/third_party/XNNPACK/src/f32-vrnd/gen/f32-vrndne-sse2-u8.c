// Auto-generated file. Do not edit!
//   Template: src/f32-vrnd/vrndne-sse2.c.in
//   Generator: tools/xngen
//
// Copyright 2020 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include <emmintrin.h>

#include <xnnpack/common.h>
#include <xnnpack/math.h>
#include <xnnpack/vunary.h>


void xnn_f32_vrndne_ukernel__sse2_u8(
    size_t batch,
    const float* input,
    float* output,
    const union xnn_f32_rnd_params params[restrict XNN_MIN_ELEMENTS(1)]) XNN_OOB_READS
{
  assert(batch != 0);
  assert(batch % sizeof(float) == 0);
  assert(input != NULL);
  assert(output != NULL);

  const __m128i vmagic = _mm_load_si128((const __m128i*) params->sse2.sign_mask);
  for (; batch >= 8 * sizeof(float); batch -= 8 * sizeof(float)) {
    const __m128 vx0123 = _mm_loadu_ps(input);
    const __m128 vx4567 = _mm_loadu_ps(input + 4);
    input += 8;

    const __m128i vintx0123 = _mm_cvtps_epi32(vx0123);
    const __m128i vintx4567 = _mm_cvtps_epi32(vx4567);

    const __m128 vrndmask0123 = _mm_castsi128_ps(_mm_or_si128(vmagic, _mm_cmpeq_epi32(vintx0123, vmagic)));
    const __m128 vrndmask4567 = _mm_castsi128_ps(_mm_or_si128(vmagic, _mm_cmpeq_epi32(vintx4567, vmagic)));

    const __m128 vrndx0123 = _mm_cvtepi32_ps(vintx0123);
    const __m128 vrndx4567 = _mm_cvtepi32_ps(vintx4567);

    const __m128 vy0123 = _mm_or_ps(_mm_and_ps(vx0123, vrndmask0123), _mm_andnot_ps(vrndmask0123, vrndx0123));
    const __m128 vy4567 = _mm_or_ps(_mm_and_ps(vx4567, vrndmask4567), _mm_andnot_ps(vrndmask4567, vrndx4567));

    _mm_storeu_ps(output, vy0123);
    _mm_storeu_ps(output + 4, vy4567);
    output += 8;
  }
  for (; batch >= 4 * sizeof(float); batch -= 4 * sizeof(float)) {
    const __m128 vx = _mm_loadu_ps(input);
    input += 4;

    const __m128i vintx = _mm_cvtps_epi32(vx);
    const __m128 vrndmask = _mm_castsi128_ps(_mm_or_si128(vmagic, _mm_cmpeq_epi32(vintx, vmagic)));
    const __m128 vrndx = _mm_cvtepi32_ps(vintx);
    const __m128 vy = _mm_or_ps(_mm_and_ps(vx, vrndmask), _mm_andnot_ps(vrndmask, vrndx));

    _mm_storeu_ps(output, vy);
    output += 4;
  }
  if XNN_UNLIKELY(batch != 0) {
    const __m128 vx = _mm_loadu_ps(input);
    const __m128i vintx = _mm_cvtps_epi32(vx);
    const __m128 vrndmask = _mm_castsi128_ps(_mm_or_si128(vmagic, _mm_cmpeq_epi32(vintx, vmagic)));
    const __m128 vrndx = _mm_cvtepi32_ps(vintx);
    __m128 vy = _mm_or_ps(_mm_and_ps(vx, vrndmask), _mm_andnot_ps(vrndmask, vrndx));
    if (batch & (2 * sizeof(float))) {
      _mm_storel_pi((__m64*) output, vy);
      vy = _mm_movehl_ps(vy, vy);
      output += 2;
    }
    if (batch & (1 * sizeof(float))) {
      _mm_store_ss(output, vy);
    }
  }
}
