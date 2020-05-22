# pretty-printk

[![Build Status](https://travis-ci.org/tpiekarski/pretty-printk.svg?branch=master)](https://travis-ci.org/tpiekarski/pretty-printk)

[Overview](#overview) / [Usage](#usage) / [Features](#features) / [License](#license) / [Links](#links)

## [Overview](#overview)

Debugging the Linux Kernel in a way most developers are familiar with is challenging. Setting breakpoints, stepping
through code and watching for the last important variable to change is hard. Sometimes just printing values to the
Kernel Ring Buffer can be a better and especially faster approach to debugging. After having print almost the
hundredths message with printk it started to feel dull and pointed me to tinker with its output.

When developing for the Web it is quite common to pretty such output and I was wondering why not to take my chances
and pretty the *printk-ing* inside the Kernel. The goal is to ease on the hand the process of printing and on the
other one it should increase readability when running dmesg.

## [Usage](#usage-testing-playing)

```c
#include "pretty_printk.h"

  // [...]

  pp_warn("Shortcut for severity level and flushing '\\n' character");

  // Extended Metadata (function, filename and line number)
  // pp_debug will only print when PP_DEBUG is defined
  // ---
  pp_debug("Extended metadata while printk-ing with debug=1 or PP_DEBUG");

  // Dumping multiple variables with valid type specifiers
  // i: integer, c: character, s: character array (string)
  // ---
  pp_dump("ics", 10, 'a', "some char array");

  // Walking through code
  // ---
  pp_walker();

  // Color Output
  // pp_<color> will only colorize when either PP_COLORS is defined
  // ---
  pp_info("Colorize dmesg output with colors=1 or PP_COLORS");
  pp_info("Example colors: %s, %s, %s... and a few more.", pp_red("red"),
  pp_green("green"), pp_blue("blue"));

  // Shortcut-ed output of condition for tracing not-yet-understood logic
  // ---
  int x_pos = 16;
  int x = 64;

  if (x_pos <= x) {
    pp_true("x_pos <= x");
  } else {
    pp_false("x_pos <= x");

    goto out;
  }

   // [...]
```

```sh
[ 12.300004] pp_demo_module: Shortcut for severity level and flushing '\n' character
[ 12.300006] pp_demo_module (pretty_printk_demo_init @ pretty_printk_demo.c, 61): Extended metadata while printk-ing with debug=1 or PP_DEBUG
[ 12.300010] pp_demo_module: Dumping data
[ 12.300011]  1. 10
[ 12.300012]  2. a
[ 12.300013]  3. some char array
[ 12.300015] pp_demo_module (pretty_printk_demo_init @ pretty_printk_demo.c, 70): It worked up to this line
[ 12.300017] pp_demo_module: Colorize dmesg output with colors=1 or PP_COLORS
[ 12.300018] pp_demo_module: Example colors: red, green, blue... and a few more. Yes, colors are in the output, but not in this README :)
[ 12.300019] pp_demo_module (pretty_printk_demo_init @ pretty_printk_demo.c, 85): x_pos <= x is true
```

For testing, debugging and looking at the features the repository provides a demo module **pp_demo_module** to illustrate
the different features. For building just call ```make``` and insert/remove the module in the common tools. Inside the
[init function](https://github.com/tpiekarski/pretty-printk/blob/master/pretty_printk_demo.c#L36) all features
are demonstrated.

## [Features](#features)

Feature|Issue|Merge Commit|Status
---|---|---|---
Metadata when printk-ing| [#3](https://github.com/tpiekarski/pretty-printk/issues/3) | [7fcb473](https://github.com/tpiekarski/pretty-printk/commit/7fcb4734ef52453069d364074a28a5c6273242f6) | done
Severity shortcuts| [#4](https://github.com/tpiekarski/pretty-printk/issues/4) | [3dfc02d](https://github.com/tpiekarski/pretty-printk/commit/3dfc02d468fdc9c401f3b24c3c3b9a15b3043bce) | done
Switch for debugging| [#5](https://github.com/tpiekarski/pretty-printk/issues/5) | [62be4d5](https://github.com/tpiekarski/pretty-printk/commit/62be4d5c13a6e5bb1de8cc8e2a8fc95c28b7cf53) | done
Pretty print of multiple variables| [#6](https://github.com/tpiekarski/pretty-printk/issues/6) | [e11d951](https://github.com/tpiekarski/pretty-printk/commit/e11d951551ff51835290e3465936acfade182025) | done
Walking Macro| [#7](https://github.com/tpiekarski/pretty-printk/issues/7) | [ab52416](https://github.com/tpiekarski/pretty-printk/commit/ab5241608e3c6915424e9311a4b499a843b20166) | done
Shortcut for discovering conditional expressions | [#8](https://github.com/tpiekarski/pretty-printk/issues/8) | [f35b3ec](https://github.com/tpiekarski/pretty-printk/commit/f35b3ecc198e4afcce8891d2052f293e5a4ce34e) | done
Generic testing pipeline with Travis CI | [#9](https://github.com/tpiekarski/pretty-printk/issues/9) | [5b459c7](https://github.com/tpiekarski/pretty-printk/commit/5b459c7db35563bf5f931c9322eb8a22fc1172f2) | done
Testing pipeline for different major Kernel versions | [#10](https://github.com/tpiekarski/pretty-printk/issues/10) | - | todo
Testing pipeline for different architectures | [#11](https://github.com/tpiekarski/pretty-printk/issues/11) | - | todo
Convenient throttling of printk | [#13](https://github.com/tpiekarski/pretty-printk/issues/13) | - | todo
Colorize output | [#14](https://github.com/tpiekarski/pretty-printk/issues/14) | - | todo

## [License](#license)

pretty-printk is free software: you can redistribute it and/or modify it under the terms of the GNU General Public
License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later
version.

pretty-printk is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with pretty-printk.
If not, see [<https://www.gnu.org/licenses/>](https://www.gnu.org/licenses/).

## [Links](#links)

- FLOZz' MISC, [Colors and formatting (ANSI/VT100 Control sequences)](https://misc.flogisoft.com/bash/tip_colors_and_formatting)
- GNU, GCC, [The C Preprocessor](https://gcc.gnu.org/onlinedocs/cpp/index.html#SEC_Contents)
- Stack Overflow, [\_\_FILE\_\_ macro shows full path](https://stackoverflow.com/questions/8487986/file-macro-shows-full-path)
- Stack Overflow, [How to avoid quotes in shortcut-ed printk...](https://stackoverflow.com/questions/61747599/how-to-avoid-quotes-in-shortcut-ed-printk-macros-inside-linux-kernel-mod)
