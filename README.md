# pretty-printk

[Overview](#overview) / [Usage, Testing and Playing](#usage-testing-playing) / [Features](#features) / [License](#license)

## [Overview](#overview)

Debugging the Linux Kernel in a way most developers are familiar with is challenging. Setting breakpoints,
stepping through lines of code and watching out for the last important variable to change their value is hard.
Sometimes just printing values to the Kernel Ring Buffer can be a better and especially faster approach to
debug some code. But while having almost output the hundredths message it felt dull.

When developing for the Web it is quite common to pretty such output and I was wondering why not to take my
chances and pretty the *printk-ing* inside the Kernel. The goal is to ease on the hand the process of printing
inside the code and on the other one it should increase readability when running dmesg.

## [Usage, Testing and Playing](#usage-testing-playing)

```c
#include "pretty_printk.h"

// [...]

// todo: show different features

// [...]

```

For testing, playing and looking at the features the repository provides a demo module *pretty_printk_demo* to
illustrate the different features. For building just call ```make``` and use the common way to insert/remove 
modules.

## [Features](#features)

- Basic features
  - Metadata to every call of printk (like module name, function name and current line)
  - Shortcut printk and severity with *alias* macros like `pp_debug(), pp_info(), pp_error()`
  - Establish a convenient switch for debug messages
  - Prettifier printing of variables i.e. in a ASCII-based table including the variable name and its data
  - Create a simple macro for *walking* through code to find the lines which do not work - a Walker :)
  - Shortcut output of conditions and their result
- Integration features
  - Snippets for a few major editors like emacs, vim and Visual Studio Code
- Features for testing and building
  - Establish a test (probably by comparing pre-processed include files with a reference) pipeline
  - Establish a build pipeline for different major Kernel versions
  - Establish a build pipeline for different architectures
- Advanced and optional features
  - Output surroundings (like some basic data around a function or something)
  - Integrated a convenient throttling for printing to avoid flooding ring buffer
  - Colorize output with short little Macros, like red(), green(), blue()
  - Macro for generate little banners
  - Provide a accompanying Kernel Module to illustrate usage

## [License](#license)

pretty-printk is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

pretty-printk is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with pretty-printk. If not, see [<https://www.gnu.org/licenses/>](https://www.gnu.org/licenses/).
