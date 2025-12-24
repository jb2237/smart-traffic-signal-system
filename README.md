# Smart Traffic Signal Management System 

A smart traffic signal optimization system that uses
Data Structures and Algorithms (DSA) implemented in C,
integrated with a Flask backend and a web interface.
( No real-time sensor or camera integration)
##  Project Objective

To optimize traffic signal timings dynamically based on:
- Traffic density in each lane
- Emergency vehicle priority
- Priority order of lanes is done with green time allocation
  
The system decides:
- Which lane should get priority
- How much green time should be allocated

##  Core Concepts Used

- **Queues**: To represent vehicles waiting in each lane
- **Priority Logic**: Emergency vehicles get highest priority
- **Greedy Selection**: Lane with highest traffic is prioritized

##  Emergency Handling

- If an emergency vehicle is present in a lane,
  that lane is given **top priority** regardless of traffic count.
- Only one emergency is handled per signal cycle  
  
## Tech Stack
- C (DSA implementation)
- Python (Flask)
- HTML, CSS, JavaScript

## How to Run
1. Compile C code
   gcc *.c -o traffic
2. Run Flask server
   python app.py
3. Open browser
   http://127.0.0.1:5000

## Project Type
DSA + System Design + Web-Based Simulation
