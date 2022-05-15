% 找到子系统的句柄
aa = find_system(bdroot,'FindAll','on','SearchDepth','1','BlockType','SubSystem');
% 返回子系统的名称
bb = get_param(aa,'Name');
% 拼接子系统路径
cc = [bdroot,'/',bb];
% 找出外部输入端口
dd = find_system(bdroot,'FindAll','on','SearchDepth','1','BlockType','Inport');
% 找出外部输出端口
ee = find_system(bdroot,'FindAll','on','SearchDepth','1','BlockType','Outport');
% 找出子系统输入端口
ff = find_system(cc,'FindAll','on','SearchDepth','1','BlockType','Inport');
% 找出子系统输出端口
gg = find_system(cc,'FindAll','on','SearchDepth','1','BlockType','Outport');
% 输入端口连接
for k = 1:length(ff)%子系统循环在外
    for i = 1:length(dd)%外部端口循环在内
        if (get_param(dd(i),'Name') == get_param(ff(k),'Name'))
            hh = get_param(dd(i),'Name');
            add_line(bdroot,[hh,'/1'],[bb,'/',num2str(k)]);
        end
    end
end
%输出端口连接
for y = 1:length(gg)%子系统循环在外
    for x = 1:length(ee)%外部端口循环在内
        if (get_param(ee(x),'Name') == get_param(gg(y),'Name'))
            ii = get_param(ee(x),'Name');
            add_line(bdroot,[bb,'/',num2str(y)],[ii,'/1']);
        end
    end
end
% 信号线平直
aaa = get_param(cc,'PortConnectivity');
for k=1:length(aaa)
    bbb = aaa(k).Position;
    if(~isempty(aaa(k).SrcBlock))
        set_param(aaa(k).SrcBlock,'Position',[bbb(1)-60,bbb(2)-5,bbb(1)-40,bbb(2)+5])
    end
    
    if(~isempty(aaa(k).DstBlock))
        set_param(aaa(k).DstBlock,'Position',[bbb(1)+40,bbb(2)-5,bbb(1)+60,bbb(2)+5])
    end
end
% author：flieck
% date  : 2020/09/07