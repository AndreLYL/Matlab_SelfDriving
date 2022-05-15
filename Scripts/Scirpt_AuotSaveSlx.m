function Scirpt_AuotSaveSlx
    try     % 提取workspace的[AutoSaveFlag]变量
        AutoSaveFlag = evalin('base', 'AutoSaveFlag'); 
    catch     % 如果没有[AutoSaveFlag]变量,则创建一个，写入到workspace
        AutoSaveFlag = 0;
        assignin('base', 'AutoSaveFlag', AutoSaveFlag); 
    end
    
    if AutoSaveFlag == 0    % 第一次运行
        t = timer('ExecutionMode',...
                  'fixedRate',...
                  'Period',120,...
                  'TimerFcn',...
                  @AutoSave_Callback);
       
        disp('自动保存已打开');
        start(t);
        AutoSaveFlag = 1;
        assignin('base', 'AutoSaveFlag', AutoSaveFlag);  % workspace中置1
    else
        t = timerfindall;  
        AutoSaveFlag = 0;
        assignin('base', 'AutoSaveFlag', AutoSaveFlag); % workspace中置0
        stop(t);
        delete(t);    
        disp('自动保存已关闭');       
    end
    
    function AutoSave_Callback(~,~)
        evalin('base', 'save_system');
        disp(['模型已保存----',...
                char(datetime('now', 'Format','yyyy-MM-dd HH:mm:ss ZZZ'))]);
    end
end