currPathHandle = get_param(gcs, 'Handle');
subSysHandle = find_system(gcs,'FindAll','on','SearchDepth','1','BlockType','SubSystem');
parentInHandle = find_system(gcs,'FindAll','on','SearchDepth','1','BlockType','Inport');
parentOutHandle = find_system(gcs,'FindAll','on','SearchDepth','1','BlockType','Outport');
parentInName = get_param(parentInHandle, 'Name')
% if(iscell(get_param(parentInHandle, 'Name')))
%     a = cell2mat(get_param(parentInHandle, 'Name'))
% else
%     a = get_param(parentInHandle, 'Name')
% end
if length(parentInHandle) > 1
    parentIn = [get_param(parentInHandle, 'Port') get_param(parentInHandle, 'Name') get_param(parentInHandle, 'PortHandles')]
elseif length(parentInHandle) == 1
    parentIn = [mat2cell(get_param(parentInHandle, 'Port')) mat2cell(get_param(parentInHandle, 'Name')) mat2cell(get_param(parentInHandle, 'PortHandles'))]
else
    disp("Warn: No Inport Found")
    parentIn = []
end

if length(parentOutHandle) > 1
    parentOut = [get_param(parentOutHandle, 'Port') get_param(parentOutHandle, 'Name') get_param(parentOutHandle, 'PortHandles')]  
elseif length(parentInHandle) == 1
    parentOut = [mat2cell(get_param(parentOutHandle, 'Port')) mat2cell(get_param(parentOutHandle, 'Name')) mat2cell(get_param(parentOutHandle, 'PortHandles'))]  
else
    disp("Warn: No Outport Found")
    parentOut = []
end
% parentOutName = get_param(parentOutHandle, 'Name')
% parentOut = [get_param(parentOutHandle, 'Port') get_param(parentOutHandle, 'Name') get_param(parentOutHandle, 'PortHandles')]  

%思路：首先根据Inport/Outport的Connectivity判断是否是没连接的端口,然后根据子系统的Port Name判断是否可以连接

for i = 1:length(subSysHandle)
    if subSysHandle(i) == currPathHandle
        disp('aaaa')
        continue
    end
    childInHandle = find_system(subSysHandle(i),'FindAll','on','SearchDepth','1','BlockType','Inport');
    childOutHandle = find_system(subSysHandle(i),'FindAll','on','SearchDepth','1','BlockType','Outport');
    childIn = [get_param(childInHandle, 'Port') get_param(childInHandle, 'Name') get_param(childInHandle, 'PortHandles')]
    for j = 1:length(childIn)
        for k = 1:length(parentIn)
            if(strcmp(cell2mat(childIn(j, 2)), cell2mat(parentIn(k, 2))))
                disp('Found')
                lineStartPos = get(cell2mat(parentIn(k, 3)).Outport).Position
                lineEndPos = get_param(get(subSysHandle(i)).PortHandles.Inport(j), 'Position')
                linePos = [lineStartPos; lineEndPos]
                add_line(gcs,cell2mat(parentIn(k, 3)).Outport, get(subSysHandle(i)).PortHandles.Inport(j),'autorouting','on')
            end
        end
    end
  
end
