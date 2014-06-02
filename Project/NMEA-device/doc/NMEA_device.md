Ell-i hackathon
===============

	During the Ell-i bare metal hackathon me and my brother designed and implemented a device for easily connecting several NMEA devices to a PC by an Ethernet connection using an STM20 ARM microcontroller.

	NMEA (National Marine Electronics Association) have standardised a protocol for communication between maritime devices, the NMEA 0183. This protocol is used by devices such as GPS recievers, wind velocity meters, sonars, echo sounders, and many other devices. These devices would usually be connected to the navigational system onboard which uses the information to plot it on a map or communicating it to the user in some other way. 

The idea
--------

	The idea in its purest form is to have a RESTful server connected to a network and several NMEA devices connected to that server. This way a client can send a request for some of the available data on the server and the server would respond with the most recent data. The server would constantly parse the NMEA data and save it into some memory while waiting for a connection to be made. When a request is made the server would serialize the requested data and send it to the client over some lightweight protocol, eg. CoAP. We chose this project due to the subject of the hackathon being "bare metal" and due to popularity of the "internet of things".

The result
----------
	We didn't have a lot of time, and the STM20 platform was new to both of us, so we didn't finish the project, but we did make some parts work. The finished device was reading the NMEA input from the GPS using the hardware UART driver, parsing and serializing the coordinate data , and outputting it trough another UART channel. The output UART channel was being read using a BusPirate general purpose serial interface. We also did extensive testing of all the parsing and serializing functions.

The process
-----------
	Getting a working development environment with the requied toolchain and libraries was the biggest obstacle of the the whole project. It took us the whole first day to get the microcontroller programming going smoothly. The whole process is documented in "". During this time we had written and tested a lot of the parsing functions on a PC, and proven them to be correct.
	We did find quite a lot of libraries for the STM20F407 microcontroller, mainly we used the standard peripheral driver libraries that had an interface to control the UART. 

The future
----------

	The STM20 has four UART drivers 
