// Auto-generated file. Do not edit!
//   Template: src/x32-packw/scalar.c.in
//   Generator: tools/xngen
//
// Copyright 2023 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.


#include <assert.h>
#include <stddef.h>
#include <stdint.h>

#include <xnnpack/math.h>
#include <xnnpack/packw.h>



void xnn_x32_packw_gemm_goi_ukernel_x8__scalar_float_u4(
  size_t g,
  size_t nc,
  size_t kc,
  size_t nr,
  size_t kr,
  size_t sr,
  const uint32_t* weights,
  const uint32_t* bias,
  const void* scale,
  uint32_t* packed_weights,
  size_t extra_bytes,
  const void* params)
{
  assert(g != 0);
  assert(nc != 0);
  assert(kc != 0);
  assert(nr == 8);
  assert(kr == 1);
  assert(sr == 1);
  assert(weights != NULL);
  assert(packed_weights != NULL);

  float* out = (float*) packed_weights;
  const float* b = (const float*) bias;

  do {
    // NC main loop multiple of 8
    const float* w0 = (const float*) weights;
    size_t n = nc;
    for (;n >= 8; n -= 8) {
      if XNN_LIKELY(b != NULL) {
        out[0] = b[0];
        out[1] = b[1];
        out[2] = b[2];
        out[3] = b[3];
        out[4] = b[4];
        out[5] = b[5];
        out[6] = b[6];
        out[7] = b[7];
        b += 8;
      } else {
        out[0] = 0;
        out[1] = 0;
        out[2] = 0;
        out[3] = 0;
        out[4] = 0;
        out[5] = 0;
        out[6] = 0;
        out[7] = 0;
      }
      out += 8;

      const float* w1 = w0 + kc;
      const float* w2 = w1 + kc;
      const float* w3 = w2 + kc;
      const float* w4 = w3 + kc;
      const float* w5 = w4 + kc;
      const float* w6 = w5 + kc;
      const float* w7 = w6 + kc;

      // KC main loop multiple of 8x4
      size_t k = kc;
      for (; k >= 4; k -= 4) {
        const float v00 = w0[0];
        const float v01 = w0[1];
        const float v02 = w0[2];
        const float v03 = w0[3];
        w0 += 4;
        const float v10 = w1[0];
        const float v11 = w1[1];
        const float v12 = w1[2];
        const float v13 = w1[3];
        w1 += 4;
        const float v20 = w2[0];
        const float v21 = w2[1];
        const float v22 = w2[2];
        const float v23 = w2[3];
        w2 += 4;
        const float v30 = w3[0];
        const float v31 = w3[1];
        const float v32 = w3[2];
        const float v33 = w3[3];
        w3 += 4;
        const float v40 = w4[0];
        const float v41 = w4[1];
        const float v42 = w4[2];
        const float v43 = w4[3];
        w4 += 4;
        const float v50 = w5[0];
        const float v51 = w5[1];
        const float v52 = w5[2];
        const float v53 = w5[3];
        w5 += 4;
        const float v60 = w6[0];
        const float v61 = w6[1];
        const float v62 = w6[2];
        const float v63 = w6[3];
        w6 += 4;
        const float v70 = w7[0];
        const float v71 = w7[1];
        const float v72 = w7[2];
        const float v73 = w7[3];
        w7 += 4;
        out[0] = v00;
        out[1] = v10;
        out[2] = v20;
        out[3] = v30;
        out[4] = v40;
        out[5] = v50;
        out[6] = v60;
        out[7] = v70;
        out[8] = v01;
        out[9] = v11;
        out[10] = v21;
        out[11] = v31;
        out[12] = v41;
        out[13] = v51;
        out[14] = v61;
        out[15] = v71;
        out[16] = v02;
        out[17] = v12;
        out[18] = v22;
        out[19] = v32;
        out[20] = v42;
        out[21] = v52;
        out[22] = v62;
        out[23] = v72;
        out[24] = v03;
        out[25] = v13;
        out[26] = v23;
        out[27] = v33;
        out[28] = v43;
        out[29] = v53;
        out[30] = v63;
        out[31] = v73;
        out += 32;
      }

      // KC remainder
      for (; k != 0; --k) {
        const float v0 = *w0++;
        out[0] = v0;
        const float v1 = *w1++;
        out[1] = v1;
        const float v2 = *w2++;
        out[2] = v2;
        const float v3 = *w3++;
        out[3] = v3;
        const float v4 = *w4++;
        out[4] = v4;
        const float v5 = *w5++;
        out[5] = v5;
        const float v6 = *w6++;
        out[6] = v6;
        const float v7 = *w7++;
        out[7] = v7;
        out += 8;
      }
      out = (float*) ((uintptr_t) out + extra_bytes);
      w0 = w7;
    }

    // NC remainder (1..7)
    if XNN_UNLIKELY(n != 0) {
      if XNN_LIKELY(b != NULL) {
        size_t nb = n;
        do {
          *out++ = *b++;
        } while (--nb != 0);
      } else {
        size_t nb = n;
        do {
          *out++ = 0;
        } while (--nb != 0);
      }
      out += (8 - n);

      // NR remainder has less than 8 rows so last row is not loaded
      const float* w1 = w0 + kc;
      if XNN_UNPREDICTABLE(n < 2) {
        w1 = w0;
      }
      const float* w2 = w1 + kc;
      if XNN_UNPREDICTABLE(n <= 2) {
        w2 = w1;
      }
      const float* w3 = w2 + kc;
      if XNN_UNPREDICTABLE(n < 4) {
        w3 = w2;
      }
      const float* w4 = w3 + kc;
      if XNN_UNPREDICTABLE(n <= 4) {
        w4 = w3;
      }
      const float* w5 = w4 + kc;
      if XNN_UNPREDICTABLE(n < 6) {
        w5 = w4;
      }
      const float* w6 = w5 + kc;
      if XNN_UNPREDICTABLE(n <= 6) {
        w6 = w5;
      }

      // KC main loop multiple of 8x4
      size_t k = kc;
      for (; k >= 4; k -= 4) {
        const float v00 = w0[0];
        const float v01 = w0[1];
        const float v02 = w0[2];
        const float v03 = w0[3];
        w0 += 4;
        const float v10 = w1[0];
        const float v11 = w1[1];
        const float v12 = w1[2];
        const float v13 = w1[3];
        w1 += 4;
        const float v20 = w2[0];
        const float v21 = w2[1];
        const float v22 = w2[2];
        const float v23 = w2[3];
        w2 += 4;
        const float v30 = w3[0];
        const float v31 = w3[1];
        const float v32 = w3[2];
        const float v33 = w3[3];
        w3 += 4;
        const float v40 = w4[0];
        const float v41 = w4[1];
        const float v42 = w4[2];
        const float v43 = w4[3];
        w4 += 4;
        const float v50 = w5[0];
        const float v51 = w5[1];
        const float v52 = w5[2];
        const float v53 = w5[3];
        w5 += 4;
        const float v60 = w6[0];
        const float v61 = w6[1];
        const float v62 = w6[2];
        const float v63 = w6[3];
        w6 += 4;
        out[0] = v00;
        out[1] = v10;
        out[2] = v20;
        out[3] = v30;
        out[4] = v40;
        out[5] = v50;
        out[6] = v60;
        out[8] = v01;
        out[9] = v11;
        out[10] = v21;
        out[11] = v31;
        out[12] = v41;
        out[13] = v51;
        out[14] = v61;
        out[16] = v02;
        out[17] = v12;
        out[18] = v22;
        out[19] = v32;
        out[20] = v42;
        out[21] = v52;
        out[22] = v62;
        out[24] = v03;
        out[25] = v13;
        out[26] = v23;
        out[27] = v33;
        out[28] = v43;
        out[29] = v53;
        out[30] = v63;
        out += 32;
      }

      // KC remainder of 1..3
      for (; k != 0; --k) {
        const float v0 = *w0++;
        out[0] = v0;
        const float v1 = *w1++;
        out[1] = v1;
        const float v2 = *w2++;
        out[2] = v2;
        const float v3 = *w3++;
        out[3] = v3;
        const float v4 = *w4++;
        out[4] = v4;
        const float v5 = *w5++;
        out[5] = v5;
        const float v6 = *w6++;
        out[6] = v6;
        out += 8;
      }
      out = (float*) ((uintptr_t) out + extra_bytes);
    }
    weights += nc * kc;
  } while (--g != 0);
}
