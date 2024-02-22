/* Operating system specific defines to be used when targeting
   GCC for KolibriOS
   Copyright (C) 1997-2023 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

#undef DEFAULT_ABI
#define DEFAULT_ABI MS_ABI

/* By default, target has a 80387, uses IEEE compatible arithmetic,
   and returns float values in the 387.  */
#undef TARGET_SUBTARGET_DEFAULT
#define TARGET_SUBTARGET_DEFAULT \
	(MASK_80387 | MASK_IEEE_FP | MASK_FLOAT_RETURNS)

/* See i386/crtdll.h for an alternative definition. _INTEGRAL_MAX_BITS
   is for compatibility with native compiler.  */
#define EXTRA_OS_CPP_BUILTINS()					\
  do								\
    {								\
      builtin_define ("__KOS__");			   	\
      builtin_define ("_KOLIBRI");				\
      builtin_define ("KOLIBRI");				\
      builtin_define_std ("KOLIBRIOS");				\
      builtin_define_with_int_value ("_INTEGRAL_MAX_BITS",	\
				     TYPE_PRECISION (intmax_type_node));\
    }				\
  while (0)

#undef LIBGCC_SPEC
#define LIBGCC_SPEC "-lgcc"

/* For KolibriOS applications always include lc.dll */
#undef LIB_SPEC
#define LIB_SPEC "-lc.dll"

#define LINK_SPEC "%{mwindows:--subsystem windows} \
  %{mconsole:--subsystem console} \
  %{shared: %{mdll: %eshared and mdll are not compatible}} \
  %{shared: --shared} %{mdll: --dll} \
  %{shared|mdll: -Tkos-pedll.lds -s --entry _DllStartup --image-base=0 -ldll} \
  %{!shared: %{!mdll: -Bstatic -s -Tkos-app-dyn.lds --image-base=0 --file-alignment=16 --section-alignment=16 }} "

#undef REAL_LIBGCC_SPEC
#define REAL_LIBGCC_SPEC LIBGCC_SPEC

/* Stub! Start file not used. */
#undef STARTFILE_SPEC
#define STARTFILE_SPEC ""

/* Stub! End file not used. */
#undef ENDFILE_SPEC
#define ENDFILE_SPEC ""

/* Running objcopy for KolibriOS applications */
#undef POST_LINK_SPEC
#define POST_LINK_SPEC "%{!shared: %{!mdll: i586-kos-mingw32-objcopy -Obinary %{o*:%*} %{!o*:a.exe} }}"

/* Native header directory */
#undef NATIVE_SYSTEM_HEADER_DIR
#define NATIVE_SYSTEM_HEADER_DIR "/include"

/* Don't use ".exe" suffix by default */
#undef TARGET_EXECUTABLE_SUFFIX
#define TARGET_EXECUTABLE_SUFFIX ""

/* Define as short unsigned for compatibility */
#undef WINT_TYPE
#define WINT_TYPE "short unsigned int"

/* Stub! "-pthread" is not supported for KolibriOS. */
#undef GOMP_SELF_SPECS
#define GOMP_SELF_SPECS ""
#undef GTM_SELF_SPECS
#define GTM_SELF_SPECS ""

#define HAVE_ENABLE_EXECUTE_STACK
