codeGenFolderName = "Code_Generation";
cacheFolderName = "Simulink_Cache";

currPrj = currentProject;
prjPath = currPrj.RootFolder;

codeGenFolderPath = fullfile(prjPath, codeGenFolderName);
cacheFolderPath = fullfile(prjPath, cacheFolderName);

if ~strcmp(currPrj.SimulinkCodeGenFolder, codeGenFolderPath)
    currPrj.SimulinkCodeGenFolder = codeGenFolderPath
end

if ~strcmp(currPrj.SimulinkCacheFolder, cacheFolderPath)
    currPrj.SimulinkCacheFolder = cacheFolderPath
end



