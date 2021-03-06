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
	// External macros for shortcutting severity levels
	// ---
	pp_emerg("Emergency severity");
	pp_crit("Critical severity");
	pp_err("Error severity");
	pp_warn("Warning severity");
	pp_note("Notice severity");
	pp_info("Information severity");

	// Appending multiple arguments
	// ---
	pp_emerg("Emergency, checking arguments, %s and %i", "AAA", 11);
	pp_crit("Critical, checking arguments, %s and %i", "BBB", 22);
	pp_err("Error, checking arguments, %s and %i", "CCC", 33);
	pp_warn("Warning, checking arguments, %s and %i", "DDD", 44);
	pp_note("Notice, checking arguments, %s and %i", "EEE", 55);
	pp_info("Information, checking arguments, %s and %i", "FFF", 66);

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

	return 0;

out:
	pp_debug("This should not have happened... :(");

	return 1;
}
module_init(pretty_printk_demo_init);

static void __exit pretty_printk_demo_exit(void)
{
	// nothing todo when exiting
}
module_exit(pretty_printk_demo_exit);
