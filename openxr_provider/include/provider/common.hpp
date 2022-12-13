/* Copyright 2021, 2022, 2023 Rune Berg (GitHub: https://github.com/1runeberg, Twitter: https://twitter.com/1runeberg, YouTube: https://www.youtube.com/@1RuneBerg)
 *
 *  SPDX-License-Identifier: MIT
 *
 *  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
 *
 *  1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
 *
 *  2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 *  3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this
 *     software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 *  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS
 *  BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 *  GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
 *  DAMAGE.
 *
 */

#pragma once

#include <filesystem>
#include <fstream>
#include <iostream>
#include <memory>

#include "assert.h"
#include "data_types.hpp"
#include "log.hpp"

// Generated by cmake by populating project_config.h.in
#include "project_config.h"

namespace oxr
{
#define OXR_MAKE_VERSION32( major, minor, patch ) ( ( ( major ) << 22 ) | ( ( minor ) << 12 ) | ( patch ) )
#define OXR_VERSION_MAJOR32( version ) ( ( uint32_t )( version ) >> 22 )
#define OXR_VERSION_MINOR32( version ) ( ( ( uint32_t )( version ) >> 12 ) & 0x3ff )
#define OXR_VERSION_PATCH32( version ) ( ( uint32_t )( version )&0xfff )

#define XR_ENUM_STRINGIFY( sEnum, val )                                                                                                                                                                \
	case sEnum:                                                                                                                                                                                        \
		return #sEnum;
#define XR_ENUM_TYPE_STRINGIFY( xrEnumType )                                                                                                                                                           \
	constexpr const char *XrEnumToString( xrEnumType eNum )                                                                                                                                            \
	{                                                                                                                                                                                                  \
		switch ( eNum )                                                                                                                                                                                \
		{                                                                                                                                                                                              \
			XR_LIST_ENUM_##xrEnumType( XR_ENUM_STRINGIFY ) default : return "Unknown Enum. Define in openxr_reflection.h";                                                                             \
		}                                                                                                                                                                                              \
	}

	XR_ENUM_TYPE_STRINGIFY( XrResult );
	XR_ENUM_TYPE_STRINGIFY( XrViewConfigurationType );
	XR_ENUM_TYPE_STRINGIFY( XrSessionState );
	XR_ENUM_TYPE_STRINGIFY( XrReferenceSpaceType );

#define INIT_PFN(instance, pfn) xrGetInstanceProcAddr(instance, #pfn, (PFN_xrVoidFunction*)(&pfn));
} // namespace oxr
