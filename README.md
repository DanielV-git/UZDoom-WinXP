# Welcome to UZDoom-WinXP!

## UZDoom-WinXP is for old gaming machines with Windows XP. Such as mine, which will stay forever on XP. Trying to backport every Win6+ implementation used in main repository of UZDoom.

## Runs with OpenGL under Win XP 32Bit
## Runs with OpenGL or Vulkan under Win7 32Bit

You can disable graphical loading screen by adding "-nostartup" for classic look and feel with printouts.


**Copyrights:**
* Copyright 1993-1996 id Software
* Copyright 1999-2016 Marisa Heit
* Copyright 2002-2016 Christoph Oelckers
* Copyright 2017-2025 GZDoom Maintainers and Contributors
* Copyright 2025-2026 UZDoom Maintainers and Contributors
* Copyright (c) 2026 DanielV


### Source code licensed under the GPL v3
##### https://www.gnu.org/licenses/quick-guide-gplv3.en.html
---

## How to build UZDoom for Win XP

- Visual Studio Community 2017 v15.9
- v14.16 v141_xp toolset
- WinSDK 7.1A
- CMAKE 4.3.0
- Settings:
- - C++ Language: /permissive
  - C++ Language: ISO C++ 17
  - C++ preprocessor defines: BUILD_TARGET_WXP32, CLASSIC_BOOT_CONSOLE
- UZDoom 5 onwards:
- put additional VS2019 string operators in VS-Folder on C:\Progs (included in fix folder)
- replace abseil with abseil-cpp-20230125.4 (last VS2017 release)