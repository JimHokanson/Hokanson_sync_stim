# Introduction #
This repository contains code for the publication:
Effects of Synchronous Electrode Pulses on Neural Recruitment During Multichannel Microstimulation

It has been copied from the repository:
https://github.com/JimHokanson/matlab_NEURON

# Requirements #

1. Windows - the code currently only works on Windows, although this is largely due NEURON "mod" files having been compiled for Windows
2. [NEURON](https://www.neuron.yale.edu/neuron/)
3. Matlab - tested on versions between 2013 and 2017
4. Curve Fitting Toolbox - Matlab

# Setup #

1. Install [NEURON](https://www.neuron.yale.edu/neuron/)
2. In the base folder, copy the file **Example_Options.txt** to **options.txt** and modify the values accordingly. The "scratch_path" should point to a folder where the code can save files that are the results from simulation. After all simulations are run that folder will contain approximately 300 MBs of data. The neuron_exe_path should point to nrniv.exe.
3. Run the initialization script 'initialize_matlab_NEURON.m'. I put this in my startup.m script. Example: run('C:\repos\matlab_git\Hokanson_sync_stim\matlab_code\initialize_matlab_NEURON.m')

# Running the Code #

