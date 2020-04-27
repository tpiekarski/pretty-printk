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

// todo: print a lot of things in (more or less) pretty way

#define _LINUX_PP_MESSAGE "This is a demo module for pretty printk-ing"

// todo: How to pass severity into this?
/* 
#define _pp_emerg(format, ...)                                                  \
	printk(KERN_EMERG "%s: " #format "\n", THIS_MODULE->name, ##__VA_ARGS__)
*/

#define pp_emerg(args...) printk(KERN_EMERG args)
#define pp_alert(args...) printk(KERN_ALERT args)
#define pp_crit(args...) printk(KERN_CRIT args)
#define pp_err(args...) printk(KERN_ERR args)
#define pp_warn(args...) printk(KERN_WARNING args)
#define pp_note(args...) printk(KERN_NOTICE args)
#define pp_info(args...) printk(KERN_INFO args)
#define pp_debug(args...) printk(KERN_DEBUG args)

#endif
