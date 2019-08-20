# FPGA-RX-TX-Arduino
This is a simple project to connect a Spartin 6 FPGA to the arduino or ATmega328p. 

I've added all of my modules for the FPGA to get it to talk to the ATmega328p's Rx pin from pin P127 of the Spartin 6.
The code for setting up the pin out is in the Tx.ucf file. I also added a check pin for testing different signals with my oscilloscope. 
The system is set up in a way that the interrupt handler on the ATmega328p triggers when a new message is being resieved. Alternativly, on the stop bit of the data out of the FPGA,
the FPGA loads in new data to the Tx module to transmit to the ATmega328p.

Since this method works decently well and only requires ground and Rx to be hooked up, I tested the set up with my TFT touch screen for the arduino that takes up every pin except Rx,Tx, and A5. 
Thus, this method is a good option if you don't have avalible pins to work with in your project. 

NOTE: I commented out all of my TFT code, but left it as an example for instructional purposes. 

The other benifit to this set up is that you could control 8 ATmega328p's with just 8 pins which offers a really low pin count. Of course other options like SPI and I2C are even better for this if you have the pins available. 
