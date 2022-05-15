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
    
parentOutName = get_param(parentOutHandle, 'Name')


for i = 1:length(subSysHandle)
    if subSysHandle(i) == currPathHandle
        disp('aaaa')
        continue
    end
    childInHandle = find_system(subSysHandle(i),'FindAll','on','SearchDepth','1','BlockType','Inport');
    childOutHandle = find_system(subSysHandle(i),'FindAll','on','SearchDepth','1','BlockType','Outport');
    childInName = get_param(childInHandle, 'Name');
    childOutName = get_param(childOutHandle, 'Name');
    
%     for j = 1:length(childInHandle)
%         parentIndex = find(strcmp(parentInName, childInName(j)))
%         if ~isempty(parentIndex)
%             disp('bbb')
%             add_line(gcs,get(parentInHandle(parentIndex)).PortConnectivity.Position,'Scope1/1','autorouting','on')
%         end    
%     end
end


