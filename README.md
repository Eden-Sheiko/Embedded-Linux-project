# Overview

This project consists of two parts:

1. Design and implementation of a system using an STM32 microcontroller and a BBG (BeagleBone Green)
2. Creation of a TCP server on a PC that supports multiple clients from the system in Part 1

# Part 1: STM32 and BBG
- The STM32 functions as a GPS module, sending GPS coordinates and a unique ID to the BBG via UART protocol.
- The BBG, when triggered by a button press, transmits the data to a server using the Ethernet protocol.

# Part 2: TCP Server
- The TCP server on a PC receives GPS coordinates, unique IDs, and start/end messages from multiple clients.
- The data is stored in shared memory and the server calculates the elapsed time between start/end messages.
- The server uses GPS coordinates to determine pricing based on city and elapsed time.
- A process is implemented to update the data in a file every 10 seconds.

# Requirements
- A PC with an operating system that supports TCP server implementation
- BBG board
- STM32 microcontroller
- Ethernet connection for data transmission

# Getting Started
- Clone the repository to your local machine using `git clone https://github.com/Eden-Sheiko/Embedded-Linux-Project.git`
- Install the necessary software and hardware as specified in the Requirements section
- Follow the instructions in the readme.md file for each part of the project to set up and run the system.

# Contributions
This project is open to contributions. Please submit pull requests or issues on the GitHub repository if you wish to contribute.
