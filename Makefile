#
# pretty-printk::Makefile
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

SELF_DIR := $(dir $(lastword $(MAKEFILE_LIST)))
include $(SELF_DIR)/debug.mk

BUILD=/lib/modules/$(shell uname -r)/build
SHELL:=/bin/bash
ccflags-y := -I$(SELF_DIR) -std=gnu99 -Wall -Wno-declaration-after-statement $(DEBUG_FLAGS)

pp_demo_module-objs :=  pretty_printk_dump.o pretty_printk_demo.o
obj-m := pp_demo_module.o

all: license clean demo

clean:
	$(MAKE) -C $(BUILD) M=$(PWD) clean

demo:
	$(MAKE) -C $(BUILD) M=$(PWD) modules

license:
	@echo -e " pretty-printk::Makefile\n\n \
	pretty-printk is free software: you can redistribute it and/or modify\n \
	it under the terms of the GNU General Public License as published by\n \
	the Free Software Foundation, either version 3 of the License, or\n \
	(at your option) any later version.\n\n \
	pretty-printk is distributed in the hope that it will be useful,\n \
	but WITHOUT ANY WARRANTY; without even the implied warranty of\n \
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n \
	GNU General Public License for more details.\n\n \
	You should have received a copy of the GNU General Public License\n \
	along with pretty-printk.  If not, see <https://www.gnu.org/licenses/>.\n"

test:
	$(eval module=pp_demo_module)
	$(MAKE) license demo debug=$(debug)
	@sudo dmesg -C
	@sudo insmod $(module).ko
	@sudo dmesg
	@sudo rmmod $(module)
	$(MAKE) clean
	
	@echo ">> Test target with debug=$(debug) has run successfully."
