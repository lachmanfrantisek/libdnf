#!/usr/bin/python3

import sys
import time

from libdnf_cli.progressbar import *

mbar = MultiProgressBar();
print(dir(mbar))

bar1 = DownloadProgressBar(1000000000, "abc.rpm89012345678901234567890")
print(dir(bar1))
mbar.add_bar(bar1)

# This is important step after calling add_bar() because it prevents double-free after calling mbar.add_bar().
# mbar becomes owner of bar1 and frees it in its destructor.
bar1.this.disown()

bar1.start()

while not bar1.is_finished():
    bar1.add_ticks(19134565)
    mbar._print()
    time.sleep(0.12)

bar1.set_state(ProgressBarState_WARNING)
mbar._print()

print()
