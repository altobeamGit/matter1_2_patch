/******************************************************************************
 * Copyright (C) 2010-2018 Arm Limited or its affiliates. All rights reserved.*
 * Copyright (C) 2018-2021 Andes Technology Corporation. All rights reserved. *
 *                                                                            *
 * SPDX-License-Identifier: Apache-2.0                                        *
 *                                                                            *
 * Licensed under the Apache License, Version 2.0 (the License); you may      *
 * not use this file except in compliance with the License.                   *
 * You may obtain a copy of the License at                                    *
 *                                                                            *
 * www.apache.org/licenses/LICENSE-2.0                                        *
 *                                                                            *
 * Unless required by applicable law or agreed to in writing, software        *
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT    *
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.           *
 * See the License for the specific language governing permissions and        *
 * limitations under the License.                                             *
 ******************************************************************************/
#ifndef __RISCV_VEC_IMAGE_H__
#define __RISCV_VEC_IMAGE_H__

/** @file*/

#ifdef  __cplusplus
extern "C"
{
#endif

#include "riscv_dsp_math_types.h"
#include <riscv_vec_types.h>

/**
 * @defgroup groupImage Image Functions
 */

/**
 * @addtogroup groupImage
 * @{
 */

/**
 * @defgroup ImageResize Image Resize Functions
 *
 * @brief The function resizes images using the bilinear interpolation algorithm.
 *
 */

 /**
  * @addtogroup ImageResize
  * @{
  */

/**
 * @brief Image resize U8 function
 *
 * @param[out] dst pointer of the output vector
 * @param[in] dst_width number of width in the output vector
 * @param[in] dst_height number of height in the output vector
 * @param[in] src pointer of the input vector
 * @param[in] src_width number of width in the input vector
 * @param[in] src_height number of height in the input vector
 * @param[in] src_stride stride of the input vector
 *
 * @b Example
 *     <pre>
 *      \#define src_width   2
 *      \#define src_height  2
 *      \#define dst_width   4
 *      \#define dst_height  4
 *      \#define src_stride  0
 *
 *      u8_t src[4 * src_width * src_height] = {…};
 *      u8_t dst[4 * dst_width * dst_height];
 *      riscv_vec_img_resize_bilinear_rgba_u8 (dst, dst_width, dst_height, src, src_width, src_height, src_stride);
 *     </pre>
 */
void riscv_vec_img_resize_bilinear_rgba_u8(u8_t* dst,
                                      u32_t dst_width,
                                      u32_t dst_height,
                                      u8_t* src,
                                      u32_t src_width,
                                      u32_t src_height,
                                      u32_t src_stride);
/** @} */

/** @} */

#ifdef  __cplusplus
}
#endif
#endif
