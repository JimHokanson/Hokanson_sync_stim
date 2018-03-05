%{
NEURON.reproductions.Hokanson_2013.all_final_figures
%}

%{

1. Make sure that options.txt has been created in the root folder
%--------------------------------------------------------------------------
(same directory as "Example_Options.txt")

Example values:
scratch_path = C:\D\neuron temp path
neuron_exe_path = C:\nrn72\bin\nrniv.exe 


2. Run the initialization script 'initialize_matlab_NEURON'
%--------------------------------------------------------------------------

e.g.: 

%Modify path as necessary
file_path = 'G:\repos\matlab_git\Hokanson_sync_stim\matlab_code\initialize_matlab_NEURON.m';

if ~exist(file_path,'file')
    error('Specified file path does not exist, please modify value')
else
    run(file_path)
end


3. When the options and paths are setup propertly, running the following 
command should work:
%--------------------------------------------------------------------------

options = NEURON.user_options.getInstance;


Verify available toolboxes
%--------------------------------------------------------------------------
%Toolboxes
%- Curve Fitting Toolbox
%- Stats Toolbox

%??? Better method

%Run these, they shouldn't be empty if the toolboxes are present:

which fitoptions  %curve fitting
which knnsearch   %stats

%If not present download the appropriate Matlab installer
%and then install the appropriate toolboxes
https://www.mathworks.com/downloads/

%Alternatively, uncomment lines 46 & 47 in the following function
%to bypass these toolboxes. This will greatly increase the time it takes
%to run the code.

%   NEURON.xstim.single_AP_sim.predicter.predictThresholds


5. Compile code after modifying the mod_path:
%--------------------------------------------------------------------------

** This only needs to be done once **

mod_path = 'G:\repos\matlab_git\Hokanson_sync_stim\HOC_CODE\models\MRG_Axon\mod_files'
NEURON.s.compile(mod_path)

** Make sure to press the "enter" button to exit **



6. Run this code via:
%--------------------------------------------------------------------------
NEURON.reproductions.Hokanson_2013.all_final_figures()

%}

%Figure 1 - extracellular stimulation
NEURON.reproductions.Hokanson_2013.example_figure_1

%Figure 2 - example response - DONE
NEURON.reproductions.Hokanson_2013.figure_vr_walkthrough
%201 - Figure 2 A,B,D,&E
%202 - Figure 2 C&F
%204 - Figure 2 G-J

%Figure 3 - Result of random neuron placement - DONE
NEURON.reproductions.Hokanson_2013.figure_populationResponseVariability
%30 - Figure 3

%Figure 4 - fiber diameter - DONE
NEURON.reproductions.Hokanson_2013.figure2
%40 - Figure 4

%Figure 5 - stimulus width - DONE
NEURON.reproductions.Hokanson_2013.figure3
%50 - Figure 5

%Figure 6 - electrode configuration - DONE
%This one takes a really long time, about 1 week
NEURON.reproductions.Hokanson_2013.figure1
%60 - Figure 6

%Figure 7 - resistivity sensitivity
NEURON.reproductions.Hokanson_2013.figure7 %Ran
%70 - Figure 7

%Discussion - not plotted
NEURON.reproductions.Hokanson_2013.BrannerTest

%What are these for?????
% NEURON.reproductions.Hokanson_2013.figure0 %in progress
% NEURON.reproductions.Hokanson_2013.figure3_new