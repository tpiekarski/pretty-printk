# pretty-printk

## Overview

Debugging the Linux Kernel in a way most developers are familiar with is challenging. Setting breakpoints,
stepping through lines of code and watching out for the last important variable to change their value is hard.
Sometimes just printing values to the Kernel Ring Buffer can be a better and especially faster approach to
debug some code. But while having almost output the hundredths message it felt dull.

When developing for the Web it is quite common to pretty such output and I was wondering why not to take my
chances and pretty the *printk-ing* inside the Kernel. The goal is to ease on the hand the process of printing
inside the code and on the other one it should increase readability when running dmesg.

## Concept

### Features

- Basic features
  - Metadata to every call of printk (like module name, function name and current line)
  - Shortcut printk and severity with *alias* macros like `pp_debug(), pp_info(), pp_error()`
  - Establish a convenient switch for debug messages
  - Prettifier printing of variables i.e. in a ASCII-based table including the variable name and its data
  - Create a simple macro for *walking* through code to find the lines which do not work - a Walker :)
  - Output surroundings (like some basic data around a function or something)
  - Shortcut output of conditions and their result
- Features for testing and building
  - Establish a test (probably by comparing pre-processed include files with a reference) pipeline
  - Establish a build pipeline for different major Kernel versions
  - Establish a build pipeline for different architectures
- Advanced and optional features
  - Integrated and more convenient throttling for printing to avoid flooding ring buffer
  - Colorize output with short little Macros, like red(), green(), blue()
  - Macro for generate little banners
  - Provide a accompanying Kernel Module to illustrate usage
