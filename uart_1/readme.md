
```
$dmesg
...
[18085.407899] usb 2-1.1: new full-speed USB device number 5 using ehci-pci
[18085.496375] usb 2-1.1: New USB device found, idVendor=0483, idProduct=374b
[18085.496385] usb 2-1.1: New USB device strings: Mfr=1, Product=2, SerialNumber=3
[18085.496391] usb 2-1.1: Product: STM32 STLink
[18085.496395] usb 2-1.1: Manufacturer: STMicroelectronics
[18085.496399] usb 2-1.1: SerialNumber: 0667FF545454885087211519
[18085.552799] usb-storage 2-1.1:1.1: USB Mass Storage device detected
[18085.553149] scsi host7: usb-storage 2-1.1:1.1
[18085.553662] cdc_acm 2-1.1:1.2: ttyACM0: USB ACM device
[18086.554488] scsi 7:0:0:0: Direct-Access     MBED     microcontroller  1.0  PQ: 0 ANSI: 2
[18086.556575] sd 7:0:0:0: Attached scsi generic sg1 type 0
[18086.556983] sd 7:0:0:0: [sdb] 1056 512-byte logical blocks: (540 kB/528 KiB)
[18086.557733] sd 7:0:0:0: [sdb] Write Protect is off
[18086.557746] sd 7:0:0:0: [sdb] Mode Sense: 03 00 00 00
[18086.558465] sd 7:0:0:0: [sdb] No Caching mode page found
[18086.558477] sd 7:0:0:0: [sdb] Assuming drive cache: write through
[18086.572037]  sdb:
[18086.574867] sd 7:0:0:0: [sdb] Attached SCSI removable disk
...
```
