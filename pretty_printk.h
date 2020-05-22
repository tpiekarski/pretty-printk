/*
 * pretty-printk::Macro collection
 * <https://github.com/tpiekarski/pretty-printk>
 * ---
 * Copyright 2020 Thomas Piekarski <t.piekarski@deloquencia.de>
 *
 * This file is part of pretty-printk - a pretty way to print to 
 * the Linux Kernel Ring Buffer
 * 
 * pretty-printk is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 * 
 * pretty-printk is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with pretty-printk. If not, see <https://www.gnu.org/licenses/>.
 * 
 */

#ifndef _LINUX_PRETTY_PRINTK_H
#define _LINUX_PRETTY_PRINTK_H

#include <linux/kern_levels.h>
#include <linux/printk.h>

void pp_dump(char *types, ...);

#undef _pp
#undef pp_emerg
#undef pp_alert
#undef pp_crit
#undef pp_err
#undef pp_warn
#undef pp_note
#undef pp_info

#define _pp(severity, format, args...)                                         \
	printk(severity "%s: " format "\n", THIS_MODULE->name, ##args)

#define pp_emerg(args...) _pp(KERN_EMERG, args)
#define pp_alert(args...) _pp(KERN_ALERT, args)
#define pp_crit(args...) _pp(KERN_CRIT, args)
#define pp_err(args...) _pp(KERN_ERR, args)
#define pp_warn(args...) _pp(KERN_WARNING, args)
#define pp_note(args...) _pp(KERN_NOTICE, args)
#define pp_info(args...) _pp(KERN_INFO, args)

#undef pp_debug
#undef pp_walker
#undef pp_true
#undef pp_false

#ifdef PP_DEBUG

#undef __FILENAME__
#undef _pp_debug
#undef _pp_condition

#define __FILENAME__                                                           \
	(strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#define _pp_debug(format, args...)                                             \
	printk(KERN_DEBUG "%s (%s @ %s, %i): " format "\n", THIS_MODULE->name, \
	       __FUNCTION__, __FILENAME__, __LINE__, ##args)
#define _pp_condition(condition, result)                                       \
	printk(KERN_DEBUG "%s (%s @ %s, %i): %s is %s\n", THIS_MODULE->name,   \
	       __FUNCTION__, __FILENAME__, __LINE__, condition, result)

#define pp_debug(args...) _pp_debug(args)
#define pp_walker() _pp_debug("It worked up to this line")
#define pp_true(condition) _pp_condition(condition, "true")
#define pp_false(condition) _pp_condition(condition, "false")

#else
#define pp_debug(...) // no debug output
#define pp_walker() // not walking code
#define pp_true(...) // no debug output
#define pp_false(...) // no debug output
#endif

#undef pp_black
#undef pp_blue_light
#undef pp_blue
#undef pp_cyan_light
#undef pp_cyan
#undef pp_gray_light
#undef pp_gray
#undef pp_green_light
#undef pp_green
#undef pp_magenta_light
#undef pp_magenta
#undef pp_red_light
#undef pp_red
#undef pp_white
#undef pp_yellow_light
#undef pp_yellow

#ifdef PP_COLORS
#define pp_black(arg) "\e[30m" arg "\e[0m"
#define pp_blue_light(arg) "\e[94m" arg "\e[0m"
#define pp_blue(arg) "\e[34m" arg "\e[0m"
#define pp_cyan_light(arg) "\e[96m" arg "\e[0m"
#define pp_cyan(arg) "\e[36m" arg "\e[0m"
#define pp_gray_light(arg) "\e[37m" arg "\e[0m"
#define pp_gray(arg) "\e[90m" arg "\e[0m"
#define pp_green_light(arg) "\e[92m" arg "\e[0m"
#define pp_green(arg) "\e[32m" arg "\e[0m"
#define pp_magenta_light(arg) "\e[95m" arg "\e[0m"
#define pp_magenta(arg) "\e[35m" arg "\e[0m"
#define pp_red_light(arg) "\e[91m" arg "\e[0m"
#define pp_red(arg) "\e[31m" arg "\e[0m"
#define pp_white(arg) "\e[97m" arg "\e[0m"
#define pp_yellow_light(arg) "\e[93m" arg "\e[0m"
#define pp_yellow(arg) "\e[33m" arg "\e[0m"
#else
#define pp_black(arg) arg
#define pp_blue_light(arg) arg
#define pp_blue(arg) arg
#define pp_cyan_light(arg) arg
#define pp_cyan(arg) arg
#define pp_gray_light(arg) arg
#define pp_gray(arg) arg
#define pp_green_light(arg) arg
#define pp_green(arg) arg
#define pp_magenta_light(arg) arg
#define pp_magenta(arg) arg
#define pp_red_light(arg) arg
#define pp_red(arg) arg
#define pp_white(arg) arg
#define pp_yellow_light(arg) arg
#define pp_yellow(arg) arg
#endif

#endif
