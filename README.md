## NLRED queue disc implementation in the Linux Kernel

This repository hosts the implementation of the Nonlinear Random Early Detection (NLRED) an active queue management queue discipline within the Linux Kernel. The NLRED active queue management serves as a queuing discipline, offering an alternative to RED (Random Early Detection). The code of Random Early Detectaion(RED) presented here has been adapted from Linux Kernel linux-6.5 but it is available from linux-2.2 onwards.

## Steps to patch the NLRED qdisc in the Linux Kernel.

# Prerequisites:-
  Install the nest[here](https://nest.nitk.ac.in/docs/v0.4.3/user/install.html) for testing:
  NeST is a python3 package aiding researchers and beginners alike in emulating         real-world networks.
  
  ## Collect enough no(min 60) of samples of RED for comparison between RED and NLRED
1. visit nest which you downloaded:-
   ```bash
   cd nest/examples/qdiscs/
   ```
2. Run examples red-point-to-point
   ```bash
     sudo python3 red-point-to-point.py
   ```

## NonLinear RED Implementation in Linux Kernel:-

1. Update System and Install Necessary Pacakage.
   ```bash
   sudo apt-get update
   sudo apt-get dist-upgrade
   sudo apt-get install git fakeroot build-essential ncurses-dev xz-    utils libssl-    dev bc flex libelf-dev bison
   ```

2. Check the linux header present in system.
   Sample input.
   ```bash
   cd /usr/src
   ```
3. Obtain Kernel Source Code and Headers[here](https://github.com/torvalds/linux/tags):
   <br/>
   in my case kernel header is(6.5.x) and kernel is(linux-6.5)

   Download the same source version with header version.
   ```bash
   $ cd ~/Desktop
   $ sudo apt-get source linux
   $ sudo apt-get install linux-headers-$(uname -r)
   ```
4.  KERNEL_VERSION is the kernel version, e.g., "6.5" in my case.
   ```bash
   ## IN MY CASE LINUX HEADER
  
   linux-headers-6.5.0-28-generic  
   linux-hwe-6.5-headers-6.5.0-28
   ```

5. Set Permissions of Source Code Directory:
   ```bash
    $ sudo chmod 777 ~/Desktop/linux-<KERNEL_VERSION> -R
   ```

6. Edit pkt_sched.h
   <br/>
   Edit file '<KERNEL_VERSION>/net/sched/sch_red.h'
   e.g: Edit file 'cd /linux-6.5/net/sched/sch_red.h'
   <br/>
   Make Following Changes here:-
   ```bash
   #include\net\red.h

   #line 6:   #include <linux/math.h>
   #line 248: p->max_P = max_P + (max_P >> 1); /* max_p = 1.5 * max_p  */
   #line 391: return !((mult_frac((qavg - p->qth_min) >> p->Wlog, (qavg - p->qth_min)    >> p->Wlog, p->max_P)) * v->qcount < v->qR);
   ```
6. Let the '~Home/linux~<KERNEL_VERSION>/net/sched/sch_red.c' file as it is.

7. Edit Makefile<br/>
   Edit file ‘~/Home/linux-<KERNEL_VERSION>/net/sched/Makefile’ and add the following    line below the line that reads ‘CONFIG_NET_SCH_RED’.
   ```bash
   obj-m	+= sch_red.o
   ```
   This modification ensures that sch_red is built as a loadable kernel module.
   
9. push the sch.red
   ```bash
    sudo rmmod sch_red
    sudo insmod sch_red.ko
    ```
  
10. Compile and install kernel modules in net/sched
   ```bash
   sudo make -C /lib/modules/$(uname -r)/build M=$(pwd) modules
   sudo make -C /lib/modules/$(uname -r)/build M=$(pwd) modules_install
   depmod -a
   ```
  This sequence compiles and builds the kernel modules in net/sched directory. It       also generates a module dependency file.

11. Done!!

## Collections of Nonlinear RED sample

1. visit nest which you downloaded:-
   ```bash
   cd nest/examples/qdiscs/
   ```
2. Run examples red-point-to-point
   ```bash
     sudo python3 red-point-to-point.py
   ```
3. Collect enough no(min 60) of samples for comparison of performance between RED and NLRED


## Comparison between RED and NLRED:
  NLRED was shown to outperform RED. NLRED is less sensitive to parameter setting. it has more predictable average queue size and can achieve a higher throughput. Performance gain of NLRED encourage the router to operate over a range of queue size according to traffic load instead of fixed one. 
