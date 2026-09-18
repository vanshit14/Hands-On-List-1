#include <stdio.h>
#include <unistd.h>

int main()
{
    // Run forever
    while (1)
    {
        // Sleep for 1 second so that
        // the process does not consume 100% CPU
        sleep(1);
    }

    return 0;
}


// cat status
// Name:   a.out
// Umask:  0022
// State:  S (sleeping)
// Tgid:   1190
// Ngid:   0
// Pid:    1190
// PPid:   329
// TracerPid:      0
// Uid:    1000    1000    1000    1000
// Gid:    1000    1000    1000    1000
// FDSize: 256
// Groups: 4 24 27 30 46 100 1000
// NStgid: 1190
// NSpid:  1190
// NSpgid: 1190
// NSsid:  329
// Kthread:        0
// VmPeak:     2660 kB
// VmSize:     2636 kB
// VmLck:         0 kB
// VmPin:         0 kB
// VmHWM:      1556 kB
// VmRSS:      1556 kB
// RssAnon:              92 kB
// RssFile:            1464 kB
// RssShmem:              0 kB
// VmData:       92 kB
// VmStk:       132 kB
// VmExe:         4 kB
// VmLib:      1828 kB
// VmPTE:        40 kB
// VmSwap:        0 kB
// HugetlbPages:          0 kB
// CoreDumping:    0
// THP_enabled:    1
// untag_mask:     0xffffffffffffffff
// Threads:        1
// SigQ:   1/30573
// SigPnd: 0000000000000000
// ShdPnd: 0000000000000000
// SigBlk: 0000000000000000
// SigIgn: 0000000000000000
// SigCgt: 0000000000000000
// CapInh: 0000000000000000
// CapPrm: 0000000000000000
// CapEff: 0000000000000000
// CapBnd: 000001ffffffffff
// CapAmb: 0000000000000000
// NoNewPrivs:     0
// Seccomp:        0
// Seccomp_filters:        0
// Speculation_Store_Bypass:       thread vulnerable
// SpeculationIndirectBranch:      conditional enabled
// Cpus_allowed:   3fff
// Cpus_allowed_list:      0-13
// Mems_allowed:   00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000001
// Mems_allowed_list:      0
// voluntary_ctxt_switches:        139
// nonvoluntary_ctxt_switches:     0