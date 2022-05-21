classdef TestCaseGen
    
    properties
        modelName;
        testCaseDoc;
        testHarness;      
    end
    
    methods
        function obj = TestCaseGen(model, doc, harness)
            %UNTITLED 构造此类的实例
            %   此处显示详细说明
            obj.modelName = model;
            obj.testCaseDoc = doc;
            obj.testHarness = harness;
        end
        
        function outputArg = method1(obj,inputArg)
            %METHOD1 此处显示有关此方法的摘要
            %   此处显示详细说明
            outputArg = obj.Property1 + inputArg;
        end
    end
end

