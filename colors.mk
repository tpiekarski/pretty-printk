#
# pretty-printk::Colors Makefile Include
# <https://github.com/tpiekarski/pretty-printk>
# ---
# Copyright 2020 Thomas Piekarski <t.piekarski@deloquencia.de>
#
# This file is part of pretty-printk - a pretty way to print to 
# the Linux Kernel Ring Buffer
# 
# pretty-printk is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.
# 
# pretty-printk is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with pretty-printk. If not, see <https://www.gnu.org/licenses/>.
# 

#
# Pass colors=1 to enable colorized output (make colors=1).
#

colors = 0

ifeq ($(colors), 1)
	COLORS = -DPP_COLORS
endif
