classdef TestHarnessGen
    %TestHarnessGen 此处显示有关此类的摘要
    % Author;andre  此处显示详细说明
    
    properties
        testDoc = [];
        testModel = [];
        testHarness = [];
        testDirArch = [];
    end
    
    methods
        function obj = TestHarnessGen(~)
            %UNTITLED3 构造此类的实例
            obj.testDoc = 'TestDocument.xlsx';
        end
        %%
        function res = ReadTestDoc(obj)
            %ReadTestDoc Read Test
            %   此处显示详细说明
            if(~isempty(obj.testDoc))
                res.testInfo = readtable(obj.testDoc)
                res.errCode = []
            else
                res.testInfo = [];
                res.errCode = 'EmptyTestDoc';
                return
            end
        end
    end
end

