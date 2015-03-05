CROSS_COMPILE	:= aarch64-linux-gnu-
build_dir       := $(CURDIR)/build-hikey
output_dir	:= $(HOME)/aarch64

.PHONY: have-crosscompiler
have-crosscompiler:
	@echo -n "Check that $(CROSS_COMPILE)gcc is available..."
	@which $(CROSS_COMPILE)gcc > /dev/null ; \
	if [ ! $$? -eq 0 ] ; then \
	   echo "ERROR: cross-compiler $(CROSS_COMPILE)gcc not in PATH=$$PATH!" ; \
	   echo "ABORTING." ; \
	   exit 1 ; \
	else \
	   echo "OK" ;\
	fi

build: have-crosscompiler FORCE
	rm -rf $(build_dir)
	@mkdir -p $(build_dir)
	$(MAKE) O=$(build_dir) CROSS_COMPILE=$(CROSS_COMPILE) distclean
	$(MAKE) O=$(build_dir) CROSS_COMPILE=$(CROSS_COMPILE) hikey_aemv8a_config
	$(MAKE) O=$(build_dir) CROSS_COMPILE=$(CROSS_COMPILE)
	cp $(build_dir)/u-boot.bin $(output_dir)/u-boot-hikey.bin

menuconfig:
	$(MAKE) O=$(build_dir) CROSS_COMPILE=$(CROSS_COMPILE) menuconfig

clean:
	$(MAKE) O=$(build_dir) clean
	rm -rf $(build_dir)

FORCE:
