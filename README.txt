Homework 

Task #1 - CPU Info   The task for this challenge is to read the linux cpu
information from "/proc/cpuinfo" and display it using QML.  The solution
needs to run on a standard linux system (e.g. ubuntu) and uses Qt C++ to read
the system information and QtQuick to display the result.  The information 
can be displayed as simple as text element or in a more advanced version as a
list of cpu entries. If you use other system then Linux/Qt/QtQuick please
justify your decision. 

The task should take less than 1hr to complete.


Solution:

Due to the fact I did not already have current Linux/Qt/C++ build environment
this took longer than expected.  I had to resolve several issues updating my
Ubuntu VM, also a few problems with the Qt packages. 

Method 1:

This is a complete cheat. as I think the assignment wants to demonstrate the
interaction between C++ objects and the declarative JavaScript objects.  This
method seeks to do it all in QML.  JavaScript has no true file I/O
capabilities, but it does have an XMLHttpRequest object that can be used to
read a local file via the file protocol.  So in this case we could access the
/proc/cpuinfo file as follows:

   var xhr = new XMLHttpRequest;
   xhr.open(“GET”, “file:///proc/cpuinfo”)

Then in the state changed handler set the text attribute of the Text widget to
the fetched file text.  Most likely inside a <PRE></PRE> tag to use the already
formatted text.  A crude example of this might look like this:


Method 2:

Create the QML engine in C++ then obtain a reference to the declarative Text
object.  Read the /proc/cpuinfo file, and then write to the Text object text
attribute.  This would demonstrate some level C++/QML interaction, but probably
not what is intended for the target sandboxed environment.


Method 3:

Probably what makes the most sense is to export a C++ CpuInfo object that the
QML could access and read the files contents via a text attribute.  This would
be the safest approach that would maintain the QML sandbox.  For this I’ll
assume there could be multiple CPUs, though my VM only has one fake CPU in the
/proc/cpuinfo file.  The example will provide a pair of Next/Prev buttons to
cycle through details of each CPU in the cpuinfo file.  Assuming its possible
to split the text on some separator strings.

