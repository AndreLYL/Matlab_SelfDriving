% codeGenFolderName = "Code_Generation";
% cacheFolderName = "Simulink_Cache";
% 
% currPrj = currentProject;
% prjPath = currPrj.RootFolder;
% 
% codeGenFolderPath = fullfile(prjPath, codeGenFolderName);
% cacheFolderPath = fullfile(prjPath, cacheFolderName);
% 
% if ~strcmp(currPrj.SimulinkCodeGenFolder, codeGenFolderPath)
%     currPrj.SimulinkCodeGenFolder = codeGenFolderPath
% end
% 
% if ~strcmp(currPrj.SimulinkCacheFolder, cacheFolderPath)
%     currPrj.SimulinkCacheFolder = cacheFolderPath
% end

fig = uifigure('Position',[100 100 350 275]);

% Create text area
txt = uitextarea(fig,...
    'Position',[125 90 100 22],...
    'Value','First');

% Create list box
lbox = uilistbox(fig,...
    'Position',[125 120 100 78],...
    'Items',{'First','Second','Third'},... 
    'ValueChangedFcn', @updateEditField); 

% ValueChangedFcn callback
function updateEditField(src,event) 
    txt.Value = src.Value;
end

