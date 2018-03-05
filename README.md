# Introduction #
This repository contains code for the publication:
Effects of Synchronous Electrode Pulses on Neural Recruitment During Multichannel Microstimulation

It has been copied from the repository:
https://github.com/JimHokanson/matlab_NEURON

# Requirements #

1. Windows - the code has currently only been tested on Windows
2. [NEURON](https://www.neuron.yale.edu/neuron/) - tested on 7.2 and 7.3
3. Matlab - tested on versions between 2013 and 2017

The following were used for computing an initial threshold prediction. They are recommended but not required. Not using these toolboxes will increase the amount of time required to generate the figures.

4. Curve Fitting Toolbox - Matlab
5. Stats Toolbox - Matlab

# Setup #

1. Install [NEURON](https://www.neuron.yale.edu/neuron/)
2. In the base folder, copy the file **Example_Options.txt** to **options.txt** and modify the values accordingly. The "scratch_path" should point to a folder where the code can save files that are the results from simulation. After all simulations are run that folder will contain approximately 300 MB of data. The neuron_exe_path should point to nrniv.exe.
3. Run the initialization script

```matlab
%Modify path as necessary
file_path = 'G:\repos\matlab_git\Hokanson_sync_stim\matlab_code\initialize_matlab_NEURON.m';

if ~exist(file_path,'file')
    error('Specified file path does not exist, please modify value')
else
    run(file_path)
end
```

If this works, and you've setup your **options.txt** properly, then you should be able to run the following command:

```matlab
options = NEURON.user_options.getInstance;
```

4. Verify toolboxes (curve fitting and stats)

The following commands can be run to see if the curve fitting and stats toolboxes are installed. If these commands return an empty value then the toolboxes are not installed.

```matlab
%For curve fitting
which fitoptions

%For stats
which knnsearch
```

If you have the appropriate license but they are not installed you can download the Matlab installer and install the toolboxes.
https://www.mathworks.com/downloads/

**Alternatively**, the following file can be edited, uncommenting at lines 47 and 47. This will slow down the code considerably but it should run without the toolboxes.

File to edit:
NEURON.xstim.single_AP_sim.predicter.predictThresholds

This file is located at:
"/matlab_code/+NEURON/+xstim/+single_AP_sim/@predicter"

5. Compile the required mod file

```matlab
%Edit this path as necessary
mod_path = 'G:\repos\matlab_git\Hokanson_sync_stim\HOC_CODE\models\MRG_Axon\mod_files'
NEURON.s.compile(mod_path)
```

**Make sure to press return (enter button) to exit**

NEURON.s.compile is a wrapper around the mod file compiler in Neuron, and that can be used as well.

# Running the Code #

The code which should produce all figures from the paper is:

```
NEURON.reproductions.Hokanson_2013.all_final_figures
```

This file is located at:
"/matlab_code/+NEURON/+reproductions/@Hokanson_2013"

Intermediate results are saved to disk. Execution can be canceled at any time and the code will resume as close to the last simulation as possible. 

# Problems #

Feel free to post an issue on GitHub or send me an email.

