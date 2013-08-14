build recovery                  : make -j8 recovery

build recoveryimage             : make -j8 recoveryimage

build bootable/recovery/updater : make -j8 updater 

make update package             : make -j8 otapackage

make package                    : pack -c sun4i -p crane -b evb
