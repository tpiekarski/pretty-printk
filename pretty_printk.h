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

void pp_dump(int dumpc, ...);

#define _pp(severity, format, args...)                                         \
	printk(severity "%s: " #format "\n", THIS_MODULE->name, ##args)

#define pp_emerg(args...) _pp(KERN_EMERG, args)
#define pp_alert(args...) _pp(KERN_ALERT, args)
#define pp_crit(args...) _pp(KERN_CRIT, args)
#define pp_err(args...) _pp(KERN_ERR, args)
#define pp_warn(args...) _pp(KERN_WARNING, args)
#define pp_note(args...) _pp(KERN_NOTICE, args)
#define pp_info(args...) _pp(KERN_INFO, args)

#undef _pp_debug
#undef pp_debug

#ifdef PP_DEBUG
#define __FILENAME__                                                           \
	(strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#define _pp_debug(format, args...)                                             \
	printk(KERN_DEBUG "%s (%s @ %s, %i): " #format "\n",                   \
	       THIS_MODULE->name, __FUNCTION__, __FILENAME__, __LINE__,        \
	       ##args)

#define pp_debug(args...) _pp_debug(args)
#define pp_walker() _pp_debug("It worked up to this line")
#else
#define pp_debug(...) // no debug output
#define pp_walker() // not walking code
#endif

#endif
