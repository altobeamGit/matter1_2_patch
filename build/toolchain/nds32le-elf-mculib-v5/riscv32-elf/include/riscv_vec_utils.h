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
#ifndef __RISCV_VEC_UTILS_H__
#define __RISCV_VEC_UTILS_H__

#ifdef  __cplusplus
extern "C"
{
#endif

#include "riscv_dsp_math_types.h"
#include <riscv_vec_types.h>

/**
 * @defgroup groupUtils Utils Functions
 */
/**
 * @addtogroup groupUtils
 * @{
 */

// Convert function
/**
 * @defgroup convert Conversion Functions
 * @brief Conversion Functions
 *
 * Conversion functions convert element values in a source vector from one data type to another
 * and write the results into a destination vector. There are following data type conversions:
 *
 * @image html convert.gif ""
 *
 * These conversion functions are introduced in the subsections below.
 */
/**
 * @addtogroup convert
 * @{
 */
#if defined (__riscv_zfh)
/**
 * @brief Convert a floating-point vector to f16.
 * @param[in]       src  pointer of the input vector
 * @param[out]      dst  pointer of the output vector
 * @param[in]       size number of elements in a vector
 * @return none.
 *
 * @b Note:
 *
 * This function is only supported by the toolchain with the HW FPU support. Also, you need to apply option “-mzfh” both in compiling flags and linking flags for applications that use this function. For details about the linking option“-mzfh”.
 */
void riscv_vec_convert_f32_f16(float32_t *src, float16_t *dst, uint32_t size);
#endif

/**
 * @brief Converts values from f32 to q15
 * @param[in]       src  pointer of the input vector
 * @param[out]      dst  pointer of the output vector
 * @param[in]       size number of elements in a vector
 * @return none.
 *
 * @b Note:
 *
 * The results will be saturated to the Q15 range [0x8000, 0x7FFF].
 */
void riscv_vec_convert_f32_q15(float32_t *src, q15_t *dst, uint32_t size);

/**
 * @brief Converts values from f32 to q31
 * @param[in]       src  pointer of the input vector
 * @param[out]      dst  pointer of the output vector
 * @param[in]       size number of elements in a vector
 * @return none.
 *
 * @b Note:
 *
 * The results will be saturated to the Q31 range [0x80000000, 0x7FFFFFFF].
 */
void riscv_vec_convert_f32_q31(float32_t *src, q31_t *dst, uint32_t size);

/**
 * @brief Convert a floating-point vector to Q7.
 * @param[in]       src  pointer of the input vector
 * @param[out]      dst  pointer of the output vector
 * @param[in]       size number of elements in a vector
 * @return none.
 *
 * @b Note:
 *
 * The results will be saturated to the Q7 range [0x80, 0x7F].
 */
void riscv_vec_convert_f32_q7(float32_t *src, q7_t *dst, uint32_t size);

#if defined (__riscv_zfh)
/**
 * @brief Convert a Q15 vector to f16.
 * @param[in]       src  pointer of the input vector
 * @param[out]      dst  pointer of the output vector
 * @param[in]       size number of elements in a vector
 * @return none.
 *
 * @b Note:
 *
 * This function is only supported by the toolchain with the HW FPU support. Also, you need to apply option “-mzfh” both in compiling flags and linking flags for applications that use this function. For details about the linking option“-mzfh”.
 */
void riscv_vec_convert_q15_f16(q15_t *src, float16_t *dst, uint32_t size);
#endif

/**
 * @brief Convert a Q15 vector to f32.
 * @param[in]       src  pointer of the input vector
 * @param[out]      dst  pointer of the output vector
 * @param[in]       size number of elements in a vector
 * @return none.
 */
void riscv_vec_convert_q15_f32(q15_t *src, float32_t *dst, uint32_t size);

/**
 * @brief Convert a Q15 vector to Q31.
 * @param[in]       src  pointer of the input vector
 * @param[out]      dst  pointer of the output vector
 * @param[in]       size number of elements in a vector
 * @return none.
 */
void riscv_vec_convert_q15_q31(q15_t *src, q31_t *dst, uint32_t size);

/**
 * @brief Convert a Q15 vector to Q7.
 * @param[in]       src  pointer of the input vector
 * @param[out]      dst  pointer of the output vector
 * @param[in]       size number of elements in a vector
 * @return none.
 */
void riscv_vec_convert_q15_q7(q15_t *src, q7_t *dst, uint32_t size);

/**
 * @brief Convert a Q31 vector to f32.
 * @param[in]       src  pointer of the input vector
 * @param[out]      dst  pointer of the output vector
 * @param[in]       size number of elements in a vector
 * @return none.
 */
void riscv_vec_convert_q31_f32(q31_t *src, float32_t *dst, uint32_t size);

/**
 * @brief Convert a Q31 vector to Q15.
 * @param[in]       src  pointer of the input vector
 * @param[out]      dst  pointer of the output vector
 * @param[in]       size number of elements in a vector
 * @return none.
 */
void riscv_vec_convert_q31_q15(q31_t *src, q15_t *dst, uint32_t size);

/**
 * @brief Convert a Q31 vector to Q7.
 * @param[in]       src  pointer of the input vector
 * @param[out]      dst  pointer of the output vector
 * @param[in]       size number of elements in a vector
 * @return none.
 */
void riscv_vec_convert_q31_q7(q31_t *src, q7_t *dst, uint32_t size);

/**
 * @brief Convert a Q7 vector to f32.
 * @param[in]       src  pointer of the input vector
 * @param[out]      dst  pointer of the output vector
 * @param[in]       size number of elements in a vector
 * @return none.
 */
void riscv_vec_convert_q7_f32(q7_t *src, float32_t *dst, uint32_t size);

/**
 * @brief Convert a Q7 vector to Q15.
 * @param[in]       src  pointer of the input vector
 * @param[out]      dst  pointer of the output vector
 * @param[in]       size number of elements in a vector
 * @return none.
 */
void riscv_vec_convert_q7_q15(q7_t *src, q15_t *dst, uint32_t size);

/**
 * @brief Convert a Q7 vector to Q31.
 * @param[in]       src  pointer of the input vector
 * @param[out]      dst  pointer of the output vector
 * @param[in]       size number of elements in a vector
 * @return none.
 */
void riscv_vec_convert_q7_q31(q7_t *src, q31_t *dst, uint32_t size);

#if defined (__riscv_zfh)
/**
 * @brief Convert a f16 vector to f32.
 * @param[in]       src  pointer of the input vector
 * @param[out]      dst  pointer of the output vector
 * @param[in]       size number of elements in a vector
 * @return none.
 *
 * @b Note:
 *
 * This function is only supported by the toolchain with the HW FPU support. Also, you need to apply option “-mzfh” both in compiling flags and linking flags for applications that use this function. For details about the linking option“-mzfh”.
 */
void riscv_vec_convert_f16_f32(float16_t *src, float32_t *dst, uint32_t size);

/**
 * @brief Convert a f16 vector to q15.
 * @param[in]       src  pointer of the input vector
 * @param[out]      dst  pointer of the output vector
 * @param[in]       size number of elements in a vector
 * @return none.
 *
 * @b Note:
 *
 * This function is only supported by the toolchain with the HW FPU support. Also, you need to apply option “-mzfh” both in compiling flags and linking flags for applications that use this function. For details about the linking option“-mzfh”.
 */
void riscv_vec_convert_f16_q15(float16_t *src, q15_t *dst, uint32_t size);
#endif
/** @} convert */

/**
 * @defgroup exp Vector Exponential Functions
 * @brief Vector Exponential Functions
 *
 * Vector exponential functions compute the exponential values from elements of a source vector and write them one-by-one into a destination vector.
 *
 * Andes vector library supports exponential function for the following data types: single- and half-precsion floating-point data types. These functions are introduced in the subsections below.
 */

/**
 * @addtogroup exp
 * @{
 */
/**
 * @brief Vector exponential function for f32
 * @param[in]       src  pointer of the input vector
 * @param[out]      dst  pointer of the output vector
 * @param[in]       size number of elements in a vector
 * @return none.
 */
void riscv_vec_exp_f32(float32_t *src, float32_t *dst, uint32_t size);

#if defined (__riscv_zfh)
/**
 * @brief Vector exponential function for f16
 * @param[in]       src  pointer of the input vector
 * @param[out]      dst  pointer of the output vector
 * @param[in]       size number of elements in a vector
 * @return none.
 */
void riscv_vec_exp_f16(float16_t *src, float16_t *dst, uint32_t size);
#endif
/** @} exp */

/**
 * @defgroup sigmoid Vector Sigmoid Functions
 * @brief Vector Sigmoid Functions
 *
 * Vector sigmoid functions compute the sigmoid values from elements of a source vector and write them one-by-one into a destination vector.
 *
 * Andes vector library supports sigmoid function for the following data types: single- and half-precsion floating-point data types. These functions are introduced in the subsections below.
 */

/**
 * @addtogroup sigmoid
 * @{
 */
/**
 * @brief Vector sigmoid function for f32
 * @param[in]       src  pointer of the input vector
 * @param[out]      dst  pointer of the output vector
 * @param[in]       size number of elements in a vector
 * @return none.
 */
void riscv_vec_sigmoid_f32(float32_t *src, float32_t *dst, uint32_t size);

#if defined (__riscv_zfh)
/**
 * @brief Vector sigmoid function for f16
 * @param[in]       src  pointer of the input vector
 * @param[out]      dst  pointer of the output vector
 * @param[in]       size number of elements in a vector
 * @return none.
 */
void riscv_vec_sigmoid_f16(float16_t *src, float16_t *dst, uint32_t size);
#endif
/** @} */

/**
 * @defgroup log Vector Natural Logarithmic Functions
 * @brief Vector Natural Logarithmic Functions
 *
 * Vector natural logarithmic functions compute the natural logarithmic values from elements of a source vector and write them one-by-one into a destination vector. The input value must large than zero.
 *
 * Andes vector library supports natural logarithmic function for the following data types: single- and half-precsion floating-point data types. These functions are introduced in the subsections below.
 */

/**
 * @addtogroup log
 * @{
 */
/**
 * @brief Vector natural logarithmic function for f32
 * @param[in]       src  pointer of the input vector
 * @param[out]      dst  pointer of the output vector
 * @param[in]       size number of elements in a vector
 * @return none.
 */
void riscv_vec_log_f32(float32_t *src, float32_t *dst, uint32_t size);

#if defined (__riscv_zfh)
/**
 * @brief Vector natural logarithmic function for f16
 * @param[in]       src  pointer of the input vector
 * @param[out]      dst  pointer of the output vector
 * @param[in]       size number of elements in a vector
 * @return none.
 */
void riscv_vec_log_f16(float16_t *src, float16_t *dst, uint32_t size);
#endif
/** @} log */

/**
 * @defgroup sine Vector Sine Functions
 * @brief Vector Sine Functions
 *
 * Vector sine functions compute the cosine values from elements of a source vector and write them one-by-one into a destination vector. The input values of these functions are in radians and there is no limitination for the input range.
 *
 * Andes vector library supports sine function for the following data types: single- and half-precsion floating-point data types. These functions are introduced in the subsections below.
 */

/**
 * @addtogroup sine
 * @{
 */
/**
 * @brief Vector sine function for f32
 * @param[in]       src  pointer of the input vector
 * @param[out]      dst  pointer of the output vector
 * @param[in]       size number of elements in a vector
 * @return none.
 */
void riscv_vec_sin_f32(float32_t *src, float32_t *dst, uint32_t size);

#if defined (__riscv_zfh)
/**
 * @brief Vector sine function for f16
 * @param[in]       src  pointer of the input vector
 * @param[out]      dst  pointer of the output vector
 * @param[in]       size number of elements in a vector
 * @return none.
 */
void riscv_vec_sin_f16(float16_t *src, float16_t *dst, uint32_t size);
#endif
/** @} sine */

/**
 * @defgroup cosine Vector Cosine Functions
 * @brief Vector Cosine Functions
 *
 * Vector cosine functions compute the cosine values from elements of a source vector and write them one-by-one into a destination vector. The input values of these functions are in radians and there is no limitination for the input range.
 *
 * Andes vector library supports cosine function for the following data types: single- and half-precsion floating-point data types. These functions are introduced in the subsections below.
 */

/**
 * @addtogroup cosine
 * @{
 */
/**
 * @brief Vector cosine function for f32
 * @param[in]       src  pointer of the input vector
 * @param[out]      dst  pointer of the output vector
 * @param[in]       size number of elements in a vector
 * @return none.
 */
void riscv_vec_cos_f32(float32_t *src, float32_t *dst, uint32_t size);

#if defined (__riscv_zfh)
/**
 * @brief Vector cosine function for f16
 * @param[in]       src  pointer of the input vector
 * @param[out]      dst  pointer of the output vector
 * @param[in]       size number of elements in a vector
 * @return none.
 */
void riscv_vec_cos_f16(float16_t *src, float16_t *dst, uint32_t size);
#endif
/** @} cosine */

/** @} groupUtils */

#ifdef  __cplusplus
}
#endif

#endif
