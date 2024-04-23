# PULSAR

PUmped Liquid System for Student and Amateur Rocketry, PULSAR is a team at Purdue University designing, building, and testing a cryogenically compatible electronic feed system for small rockets.

## Description

Our first project, the PikaPump, is a test pump sized from Purdue Space Program Liquid's Crater Maker Special rocket.  It contains all the documentation, CAD files, mechanical drawings, DAQ and motor controller code, ANSYS CFD files, and CFturbo files. It should be noted that the novel magnetic coupler device the team tested was unable to hit our rpm target, so the pump did not meet the pressure rise and flowrate requirements; however, hopefully this repository can help others by reducing the amount of research and setup required. Feel free to use any information below for non-commercial projects, including hobbiest and educational ones.

## Getting Started

### Dependencies

* Must have CFturbo to run .cft files.
* To access CFD files, download 7zip 
* Must have ANSYS Workbench, CFX, and CFDPost to view the CFD.
* To access the DAQ and motor controller file, use the arduino IDE. 

### Dowloading

* Download the files as a zip file, then unzip them.
* The CAD is available in OnShape: https://cad.onshape.com/documents/3ee609e6bb3bc94de198d5cf/w/ba28e37b976e589be2fad60c/e/f99038d5f3ab1b5ac4c240aa 
* To open the CFD files, select all six of them in the 7zip application, and then unzip them. They will become one ANSYS folder, with which you can view the CFD.
* If you are trying to use our DAQ and motor controller code, ensure that you calibrate your pressure transducers appropriately if you are trying to use our code, even if you are using the same hardware as us.

### Safety

* Liquid rocketry is dangerous. Please only design and manufacture your own electric pumps if you have experienced mentors.
* Never get close to high-speed machinery. Anything rotating at several thousand RPMs can kill you.
* If you are using this with fuels, ensure that your clearances are significant enough to negate the potential for a spark. PULSAR did no testing with fuel or oxidizer because we could not verify the safety of the system, so do not trust that our work is safe.

## PikaPump Recommendations
What part of the project you can feel confident using in your own work.

* CFturbo was very helpful in understanding the conceptual design of the pump. They also have good YouTube tutorials. We are confident that we did the CFturbo portion of the project well.
* ANSYS CFX helped us establish a pump curve close to what we would expect from experimental data. We are confident that our simulations there are accurate and setup properly, feel free to use our boundary conditions for your own projects.
* The CAD, manufacturing drawings, and actual manufactured parts should not be used to design your own pump. We made a number of critical errors that are outlined in our Final Design Review Report. Please read this report before attempting to start your own pump project.
* The testing and instrumentation system can be used for your own pump projects, we have no reason to believe any of it was incorrect.
* There are a few other people who have done similar projects and had equal or slightly more success than us using different methodologies, check them out too: https://web.cecs.pdx.edu/~gerry/class/ME493/projects/2017/PSAS_electric_feed.html and https://www.sjoneil.com/electric-pump-1

## Authors

Contributors names and contact info

ex. Thomas Neidlein  
ex. wulf1237@gmail.com

ex. John Clark
ex. jjclark12@yahoo.com

ex. Max Cohen
ex. mjcohen19@gmail.com

ex. Lamya Bhat
ex. Blamya002@gmail.com

ex. Fredric Gouronc
ex. fredricgouronc@gmail.com

ex. James Beeman
ex. jay.b33man@gmail.com

## License

This project is licensed under the MIT License - see the LICENSE.md file for details

## Acknowledgments
Thank you to Purdue University's Mechanical Engineering department for providing mentorship and funding for this design project.
Thank you to Purdue Space Program for their engineering advice.

