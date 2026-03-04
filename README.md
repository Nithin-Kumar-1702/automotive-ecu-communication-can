# automotive-ecu-communication-can
Automotive ECU Communication Framework using CAN Protocol with LPC2129

🚗 Automotive ECU Communication Framework Using CAN Protocol
📌 Overview

This project implements an Automotive ECU Communication System using the CAN (Controller Area Network) protocol. The system enables real-time, reliable communication between multiple ECUs over a two-wire bus without a host computer.

The implementation is done using the LPC2129 microcontroller and MCP2551 CAN transceiver.

🎯 Problem Statement

Modern vehicles contain multiple ECUs. Traditional point-to-point wiring:

Increases complexity

Increases cost

Reduces reliability

Makes real-time communication difficult

A standardized communication system like CAN is required.

🎯 Objective

Implement CAN protocol for ECU communication

Simulate real-time data exchange between two ECUs

Reduce wiring complexity using two-wire CAN bus

Demonstrate interrupt-driven CAN communication

🏗️ System Architecture

2 × LPC2129 boards (acting as ECUs)

CAN1 peripheral used

Acceptance filter configured for specific IDs

Interrupt-driven CAN message handling

LEDs used as output indicators

Switches and potentiometer used as inputs

🔧 Hardware Used

LPC2129 Microcontroller (2 Boards)

MCP2551 CAN Transceiver

LEDs

Switches

Potentiometer

Power Supply

💻 Software Used

Keil uVision IDE

Flash Magic

Serial Debug Terminal

⚙️ Working Principle

Switch input is read by transmitting ECU.

CAN message frame is constructed with specific ID.

Message transmitted via CAN controller.

Arbitration handled automatically by CAN hardware.

Receiving ECU interrupt triggers.

Data extracted and output action performed (LED control).

📊 Results

Successful CAN message transmission and reception

Headlight ON/OFF control

Left/Right indicators blinking

Warning LED glows when speed exceeds 80 km/h

🔬 Technical Highlights

Register-level CAN programming

Interrupt-driven communication

Acceptance filter configuration

CAN arbitration mechanism

Real-time embedded system design

📈 Future Scope

Extend to multi-node CAN network

Implement advanced error handling

Add dashboard display module

Implement CAN 2.0B extended ID

📚 References

Bosch CAN 2.0 Specification

ISO 11898 Standard

LPC2129 Datasheet

MCP2551 Datasheet
