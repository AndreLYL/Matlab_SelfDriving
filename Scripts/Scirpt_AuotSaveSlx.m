function Scirpt_AuotSaveSlx
    try     % ��ȡworkspace��[AutoSaveFlag]����
        AutoSaveFlag = evalin('base', 'AutoSaveFlag'); 
    catch     % ���û��[AutoSaveFlag]����,�򴴽�һ����д�뵽workspace
        AutoSaveFlag = 0;
        assignin('base', 'AutoSaveFlag', AutoSaveFlag); 
    end
    
    if AutoSaveFlag == 0    % ��һ������
        t = timer('ExecutionMode',...
                  'fixedRate',...
                  'Period',120,...
                  'TimerFcn',...
                  @AutoSave_Callback);
       
        disp('�Զ������Ѵ�');
        start(t);
        AutoSaveFlag = 1;
        assignin('base', 'AutoSaveFlag', AutoSaveFlag);  % workspace����1
    else
        t = timerfindall;  
        AutoSaveFlag = 0;
        assignin('base', 'AutoSaveFlag', AutoSaveFlag); % workspace����0
        stop(t);
        delete(t);    
        disp('�Զ������ѹر�');       
    end
    
    function AutoSave_Callback(~,~)
        evalin('base', 'save_system');
        disp(['ģ���ѱ���----',...
                char(datetime('now', 'Format','yyyy-MM-dd HH:mm:ss ZZZ'))]);
    end
end