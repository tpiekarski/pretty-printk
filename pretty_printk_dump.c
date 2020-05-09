/*
 * pretty-printk::Variadic dumping
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

#include "pretty_printk.h"
#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

void pp_dump(enum PP_DUMP_STYLE style, char *types, ...)
{
	switch (style) {
	case LIST:
		pp_info("List style");

		// todo: implement list style output

		break;

	case TABLE:
		pp_info("Table style");

		// todo: implement table style output

		break;

	case RAW:
	default:
		pp_info("Raw (default) style");

		// todo: implement raw style

		break;
	}
}
