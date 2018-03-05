function initialize_matlab_NEURON
%initialize  Initializes the NEURON toolbox
%
%

%{
e.g.:
file_path = 'G:\repos\matlab_git\Hokanson_sync_stim\matlab_code\initialize_matlab_NEURON.m';
if ~exist(file_path,'file')
    error('Specified file path does not exist, please modify value')
else
    run(file_path)
end
%}

%Since this script exists, we can't test whether or not
%this folder is on the path (permanently)
%
%Thus we'll always add it ..
%
%We could try and and find it on the path but we'll skip that for now ...

%Adding path
%---------------------------------
temp = which('initialize_matlab_NEURON');

root_path = fileparts(temp);

addpath(root_path)

%Call to init
%---------------------------------
NEURON.s.init_system;

end