/*
 *
 *    Copyright (c) 2020 Project CHIP Authors
 *    Copyright (c) 2018 Nest Labs, Inc.
 *    All rights reserved.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

/**
 *    @file
 *          Defines platform-specific event types and data for the
 *          CHIP Device Layer on the ATBM platform.
 */

#pragma once

#include <platform/CHIPDeviceEvent.h>

namespace chip {
namespace DeviceLayer {

namespace DeviceEventType {

/**
 * Enumerates platform-specific event types that are visible to the application.
 */
enum
{
    kATBMSystemEvent = kRange_PublicPlatformSpecific,
};

} // namespace DeviceEventType

/**
 * Represents platform-specific event information for the ATBM platform.
 */
struct ChipDevicePlatformEvent final
{
    union
    {
        struct
        {
            int32_t Id;
            union
            {
                //ip_event_t EthGotIp;
                //ip_event_got_ip_t IpGotIp;
                //ip_event_got_ip6_t IpGotIp6;
                //wifi_event_sta_scan_done_t WiFiStaScanDone;
                //wifi_event_sta_connected_t WiFiStaConnected;
                //wifi_event_sta_disconnected_t WiFiStaDisconnected;
                //wifi_event_sta_authmode_change_t WiFiStaAuthModeChange;
                int32_t event;
            } Data;
        } ATBMSystemEvent;
    };
};

} // namespace DeviceLayer
} // namespace chip
