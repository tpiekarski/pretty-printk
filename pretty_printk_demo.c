/*
 * pretty-printk::pretty-printk-demo
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

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

#include "pretty_printk.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Thomas Piekarski");
MODULE_DESCRIPTION("Sample module for pretty printk-ing");
MODULE_VERSION("0.1");

static int __init pretty_printk_demo_init(void)
{
	// Internal macro
	_pp(KERN_INFO, "Internal Pre-processing Macro...");

	// External macros
	pp_emerg("Emergency severity");
	pp_crit("Critical severity");
	pp_err("Error severity");
	pp_warn("Warning severity");
	pp_note("Notice severity");
	pp_info("Information severity");
	pp_debug("Debugging severity");

	return 0;
}
module_init(pretty_printk_demo_init);

static void __exit pretty_printk_demo_exit(void)
{
	// nothing todo when exiting
}
module_exit(pretty_printk_demo_exit);
