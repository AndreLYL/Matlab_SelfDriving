classdef TestCaseGen
    
    properties
        modelName;
        testCaseDoc;
        testHarness;      
    end
    
    methods
        function obj = TestCaseGen(model, doc, harness)
            %UNTITLED ��������ʵ��
            %   �˴���ʾ��ϸ˵��
            obj.modelName = model;
            obj.testCaseDoc = doc;
            obj.testHarness = harness;
        end
        
        function outputArg = method1(obj,inputArg)
            %METHOD1 �˴���ʾ�йش˷�����ժҪ
            %   �˴���ʾ��ϸ˵��
            outputArg = obj.Property1 + inputArg;
        end
    end
end

