# Test Commit for Replication
obj-m += simple_char_device_driver.o
KDIR = /lib/modules/$(shell uname -r)/build
all :
	$(MAKE) -C $(KDIR) M=$(PWD) modules
clean :
	$(MAKE) -C $(KDIR) M=$(PWD) clean