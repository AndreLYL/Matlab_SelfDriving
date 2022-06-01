classdef TestHarnessGen
    %TestHarnessGen �˴���ʾ�йش����ժҪ
    % Author;andre  �˴���ʾ��ϸ˵��
    
    properties
        testDoc = [];
        testModel = [];
        testHarness = [];
        testDirArch = [];
    end
    
    methods
        function obj = TestHarnessGen(~)
            %UNTITLED3 ��������ʵ��
            obj.testDoc = 'TestDocument.xlsx';
        end
        %%
        function res = ReadTestDoc(obj)
            %ReadTestDoc Read Test
            %   �˴���ʾ��ϸ˵��
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

