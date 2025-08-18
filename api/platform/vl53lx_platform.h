
/*
* Copyright (c) 2017, STMicroelectronics - All Rights Reserved
*
* This file is part of VL53LX Core and is dual licensed,
* either 'STMicroelectronics
* Proprietary license'
* or 'BSD 3-clause "New" or "Revised" License' , at your option.
*
********************************************************************************
*
* 'STMicroelectronics Proprietary license'
*
********************************************************************************
*
* License terms: STMicroelectronics Proprietary in accordance with licensing
* terms at www.st.com/sla0081
*
* STMicroelectronics confidential
* Reproduction and Communication of this document is strictly prohibited unless
* specifically authorized in writing by STMicroelectronics.
*
*
********************************************************************************
*
* Alternatively, VL53LX Core may be distributed under the terms of
* 'BSD 3-clause "New" or "Revised" License', in which case the following
* provisions apply instead of the ones mentioned above :
*
********************************************************************************
*
* License terms: BSD 3-clause "New" or "Revised" License.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
* 1. Redistributions of source code must retain the above copyright notice, this
* list of conditions and the following disclaimer.
*
* 2. Redistributions in binary form must reproduce the above copyright notice,
* this list of conditions and the following disclaimer in the documentation
* and/or other materials provided with the distribution.
*
* 3. Neither the name of the copyright holder nor the names of its contributors
* may be used to endorse or promote products derived from this software
* without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*
********************************************************************************
*
*/

#ifndef _VL53LX_PLATFORM_H_
#define _VL53LX_PLATFORM_H_

#include "vl53lx_ll_def.h"
#include "vl53lx_platform_log.h"

#define VL53LX_IPP_API
#include "vl53lx_platform_user_data.h"

#ifdef __cplusplus
extern "C"
{
#endif


void VL53LX_set_i2c(void *read_func, void *write_func);

VL53LX_Error VL53LX_CommsInitialise(
	VL53LX_DEV pdev,
	uint8_t       comms_type,
	uint16_t      comms_speed_khz);

VL53LX_Error VL53LX_CommsClose(
	VL53LX_DEV pdev);

VL53LX_Error VL53LX_WriteMulti(
		VL53LX_DEV pdev,
		uint16_t      index,
		uint8_t      *pdata,
		uint32_t      count);

VL53LX_Error VL53LX_ReadMulti(
		VL53LX_DEV pdev,
		uint16_t      index,
		uint8_t      *pdata,
		uint32_t      count);

VL53LX_Error VL53LX_WrByte(
		VL53LX_DEV pdev,
		uint16_t      index,
		uint8_t       VL53LX_PRM_00005);

VL53LX_Error VL53LX_WrWord(
		VL53LX_DEV pdev,
		uint16_t      index,
		uint16_t      VL53LX_PRM_00005);

VL53LX_Error VL53LX_WrDWord(
		VL53LX_DEV pdev,
		uint16_t      index,
		uint32_t      VL53LX_PRM_00005);

VL53LX_Error VL53LX_RdByte(
		VL53LX_DEV pdev,
		uint16_t      index,
		uint8_t      *pdata);

VL53LX_Error VL53LX_RdWord(
		VL53LX_DEV pdev,
		uint16_t      index,
		uint16_t     *pdata);

VL53LX_Error VL53LX_RdDWord(
		VL53LX_DEV pdev,
		uint16_t      index,
		uint32_t     *pdata);

VL53LX_Error VL53LX_WaitUs(
		VL53LX_DEV pdev,
		int32_t       wait_us);

VL53LX_Error VL53LX_WaitMs(
		VL53LX_DEV pdev,
		int32_t       wait_ms);

VL53LX_Error VL53LX_GetTimerFrequency(int32_t *ptimer_freq_hz);

VL53LX_Error VL53LX_GetTimerValue(int32_t *ptimer_count);

VL53LX_Error VL53LX_GpioSetMode(uint8_t pin, uint8_t mode);

VL53LX_Error VL53LX_GpioSetValue(uint8_t pin, uint8_t value);

VL53LX_Error VL53LX_GpioGetValue(uint8_t pin, uint8_t *pvalue);

VL53LX_Error VL53LX_GpioXshutdown(uint8_t value);

VL53LX_Error VL53LX_GpioCommsSelect(uint8_t value);

VL53LX_Error VL53LX_GpioPowerEnable(uint8_t value);

VL53LX_Error  VL53LX_GpioInterruptEnable(void (*function)(void), uint8_t edge_type);

VL53LX_Error  VL53LX_GpioInterruptDisable(void);

VL53LX_Error VL53LX_GetTickCount(
	uint32_t *ptime_ms);

VL53LX_Error VL53LX_WaitValueMaskEx(
		VL53LX_DEV pdev,
		uint32_t      timeout_ms,
		uint16_t      index,
		uint8_t       value,
		uint8_t       mask,
		uint32_t      poll_delay_ms);

#ifdef __cplusplus
}
#endif

#endif