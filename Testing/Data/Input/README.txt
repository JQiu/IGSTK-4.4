
This README.txt file provides a brief description of the nature of the files
available in the Testing/Data/Input directory.


------------------------------------------------------------------------------
aurora_stream_03_30_2005_1.txt:

Acquired by Hee-Su Kim at the ISIS center at Georgetown University on March 30 2005. 

It contains the log of the data stream between the program WinPolarisSample.exe
(from NDI) and an Aurora tracker.

------------------------------------------------------------------------------
aurora_stream_03_30_2005_2.txt

Acquired by Hee-Su Kim at the ISIS center at Georgetown University on March 30 2005.

It contains the log of the data stream between a custom program and an Aurora
tracker.  The exchange is tagged using the strings "sent" and "recv" in order
to make clear the direction of the dataflow. The entries are also numbered with
a format %04d in order to make clear the association between the string sent
and the string received.

------------------------------------------------------------------------------
polaris_stream_03_31_2005_1.txt

Acquired by Hee-Su Kim at the ISIS center at Georgetown University on March 31 2005.

It contains the log of the data stream between a custom program and a Polaris
tracker.  The exchange is tagged using the strings "sent" and "recv" in order
to make clear the direction of the dataflow. The entries are also numbered with
a format %04d in order to make clear the association between the string sent
and the string received. End of lines are using ^M symbols.


------------------------------------------------------------------------------
polaris_stream_03_31_2005_2.txt

Acquired by Hee-Su Kim at the ISIS center at Georgetown University on March 31 2005.

It contains the log of the data stream between a custom program and a Polaris
tracker.  The exchange is tagged using the strings "sent" and "recv" in order
to make clear the direction of the dataflow. The entries are also numbered with
a format %04d in order to make clear the association between the string sent
and the string received. End of lines are using ^M symbols.


------------------------------------------------------------------------------
polaris_stream_07_13_2005.txt

Acquired by Hee-Su Kim at the ISIS center at Georgetown University on July 13 2005.

It contains the log of the data stream between a igstk::AuroraTrackerTest 
and a Polaris tracker.  
The exchange is tagged using the strings "sent" and "recv" in order
to make clear the direction of the dataflow. The entries are also numbered with
a format %04d in order to make clear the association between the string sent
and the string received. End of lines are using ^M symbols.



------------------------------------------------------------------------------
polaris_stream_07_27_2005.bin

Acquired by Hee-Su Kim at the ISIS center at Georgetown University on July 27 2005.

It contains the log of the data stream between a igstk::AuroraTrackerTest 
and a Polaris tracker.  
The exchange is tagged using the strings "command" and "receive" in order
to make clear the direction of the dataflow. The entries are also numbered 
in order to make clear the association between the string sent
and the string received. This is in David's format (look at the WIKI page).

------------------------------------------------------------------------------
polaris_stream_08_17_2005.bin

Acquired by David Gobbi at the Robarts Research Institute on Aug 17 2005.

It contains the log of the data stream between igstkNDICommandInterpreterTest
and a Polaris tracker.  

------------------------------------------------------------------------------
polaris_passive_pointer_1.rom

This is a custom ROM file created for one of the passive Medtronic tools
using NDI's rom creation software.  It is used as a dummy rom file by
igstkNDICommandInterpreterTest so that passive strays can be tracked.

------------------------------------------------------------------------------
polaris_stream_08_18_2005.bin

Acquired by David Gobbi at the Robarts Research Institute on Aug 18 2005.

It contains the log of the data stream between igstkNDICommandInterpreterTest
and a Polaris tracker.   Compared to polaris_stream_08_17_2005.bin, it
increases coverage by adding more commands and incorporating a passive tool
rom file.

------------------------------------------------------------------------------
polaris_stream_08_29_2005.bin

Acquired by David Gobbi at the Robarts Research Institute on Aug 29 2005.

It contains the log of the data stream between igstkNDICommandInterpreterTest
and a Polaris tracker.   Compared to polaris_stream_08_18_2005.bin, it 
increases coverage by adding more commands, by including some environmental
infrared (a bright light shining on the POLARIS), and the unplugging of one
of the active tools halfway through.

------------------------------------------------------------------------------
polaris_stream_08_31_2005.bin

Acquired by David Gobbi at the Robarts Research Institute on Aug 31 2005.

It contains the log of the data stream between igstkNDICommandInterpreterTest
and a Polaris tracker.   Compared to polaris_stream_08_29_2005.bin, it 
contains some extra PHINF commands with options specific to wired tools.

------------------------------------------------------------------------------
polaris_stream_08_31_2005_NDICommandInterpreter.bin

Acquired by Hee-Su Kim at the ISIS center at Georgetown University on July 27 2005.

It contains the log of the data stream between a igstkNDICommandInterpreterTest 
and a Polaris tracker. This file includes BX-commands and responses.
The exchange is tagged using the strings "command" and "receive" in order
to make clear the direction of the dataflow. The entries are also numbered 
in order to make clear the association between the string sent
and the string received. This is in David's format (look at the WIKI page).

------------------------------------------------------------------------------
polaris_stream_NDICommandInterpreterStress.bin

Constructed from polaris_stream_08_31_2005.bin, with additions and changes
inserted to provide coverage for some exceptional situations.  The following
changes were done:
- IRCHK returns environmental infrared coords for both cameras
- line 64 contains garbage data (which should be caught by CRC check)
- line 65 is missing a char (should be caught by CRC check)
- line 66 is missing a newline (should be caught by CRC check)
- line 67 is missing carriage return (should result in simulated timeout)

------------------------------------------------------------------------------
aurora_stream_09_28_2005.txt

Acquired by Hee-Su Kim at the ISIS center at Georgetown University on Sep 28 2005.

It contains the log of the data stream between a igstkAuroraTrackerTest 
and a Aurora tracker.   Compared to polaris_stream_07_27_2005.txt, it
contains requests and responses for loading a SROM file.

------------------------------------------------------------------------------
5D.ROM

Acquired by James Zhang at the ISIS center at Georgetown University on Sep 28 2005.

It's a SROM file for Aurora tracker tools.
------------------------------------------------------------------------------
