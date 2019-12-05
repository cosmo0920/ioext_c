/* ioext */
/* Licensed under the Apache License, Version 2.0 (the "License"); */
/* you may not use this file except in compliance with the License. */
/* You may obtain a copy of the License at */
/*     http://www.apache.org/licenses/LICENSE-2.0 */
/* Unless required by applicable law or agreed to in writing, software */
/* distributed under the License is distributed on an "AS IS" BASIS, */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. */
/* See the License for the specific language governing permissions and */
/* limitations under the License. */

#ifndef _IOEXT_H_
#define _IOEXT_H_

#include <ruby.h>
#include <ruby/encoding.h>

#ifdef __GNUC__
#include <w32api.h>
#define MINIMUM_WINDOWS_VERSION WindowsVista
#else                                  /* __GNUC__ */
#define MINIMUM_WINDOWS_VERSION 0x0600 /* Vista */
#endif                                 /* __GNUC__ */

#ifdef _WIN32_WINNT
#undef _WIN32_WINNT
#endif /* WIN32_WINNT */
#define _WIN32_WINNT MINIMUM_WINDOWS_VERSION

#include <stdio.h>

VALUE rb_cIOExt;

#endif // _IOEXT_H
