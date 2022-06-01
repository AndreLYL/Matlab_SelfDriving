classdef MatlabFile
    %MatlabFile: File operation relavant
    
    properties
        Property1
    end
    
    methods
        function obj = MatlabFile(inputArg1,inputArg2)
            %UNTITLED2 构造此类的实例
            %   此处显示详细说明
            obj.Property1 = inputArg1 + inputArg2;
        end
        
        function outputArg = PlatformJudge(obj,inputArg)
            if ismac
                % Code to run on Mac platform
            elseif isunix
                % Code to run on Linux platform
            elseif ispc
                % Code to run on Windows platform
            else
                disp('Platform not supported')
            end
        end
    end
end

