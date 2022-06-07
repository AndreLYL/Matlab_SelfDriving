classdef TestCaseGen
    
    properties
        modelName;
        testCaseDoc;
        testHarness;      
    end
    
    methods
        function obj = TestCaseGen(model, doc, harness)
            % TestCaseGen class constructor
            obj.modelName = model;
            obj.testCaseDoc = doc;
            obj.testHarness = harness;
        end
        %%
        function [fullPath, tableContent, errCode] = GetTestDoc(~)
            [fileName, pathName] = uigetfile({'*.xlsx'},'File Selector');
            if strcmp(fileName(end-4:end), '.xlsx')
                fullPath = fullfile(pathName, fileName);
                tableContent = readtable(fullPath, "Sheet",1);
                errCode = 0;    %No Error
            else
                tableContent = [];
                errCode = 1;    %Please select .xlsx File
            end
        end
        
        %% listbox example
        function selectlistbox(~)
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

        end
    end
end

