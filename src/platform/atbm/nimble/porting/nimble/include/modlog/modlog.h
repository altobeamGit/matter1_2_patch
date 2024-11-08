/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#ifndef H_MODLOG_
#define H_MODLOG_

#include <stdint.h>
#include "log/log.h"

extern void modlog_dummy(uint8_t level, const char *msg, ...);


#define MODLOG_LEVEL_ERROR    0
#define MODLOG_LEVEL_WARING   1
#define MODLOG_LEVEL_INFO     2
#define MODLOG_LEVEL_LOG      3
#define MODLOG_LEVEL_RAW      4
#define MODLOG_LEVEL_CRITICAL 5

#define DEFAULT_DEBUG_LEVEL  MODLOG_LEVEL_INFO

#define MODLOG_DEBUG(ml_mod_, ml_msg_, ...) \
    if(DEFAULT_DEBUG_LEVEL>=MODLOG_LEVEL_LOG) iot_printf( (ml_msg_), ##__VA_ARGS__)

#define MODLOG_INFO(ml_mod_, ml_msg_, ...) \
   if(DEFAULT_DEBUG_LEVEL>=MODLOG_LEVEL_INFO) iot_printf( (ml_msg_), ##__VA_ARGS__)

#define MODLOG_WARN(ml_mod_, ml_msg_, ...) \
   if(DEFAULT_DEBUG_LEVEL>=MODLOG_LEVEL_WARING) iot_printf((ml_msg_), ##__VA_ARGS__)

#define MODLOG_ERROR(ml_mod_, ml_msg_, ...) \
   if(DEFAULT_DEBUG_LEVEL>=MODLOG_LEVEL_ERROR) iot_printf( (ml_msg_), ##__VA_ARGS__)

#define MODLOG_RAW(ml_mod_, ml_msg_, ...) \
    if(DEFAULT_DEBUG_LEVEL>=MODLOG_LEVEL_RAW) iot_printf( (ml_msg_), ##__VA_ARGS__)

#define MODLOG_CRITICAL(ml_mod_, ml_msg_, ...) \
    if(DEFAULT_DEBUG_LEVEL>=MODLOG_LEVEL_CRITICAL) iot_printf( (ml_msg_), ##__VA_ARGS__)

#define MODLOG(ml_lvl_, ml_mod_, ...) \
    MODLOG_ ## ml_lvl_((ml_mod_), __VA_ARGS__)

#define MODLOG_DFLT(ml_lvl_, ...) \
    MODLOG(ml_lvl_, LOG_MODULE_DEFAULT, __VA_ARGS__)

#endif
