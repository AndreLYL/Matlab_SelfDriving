% �ҵ���ϵͳ�ľ��
aa = find_system(bdroot,'FindAll','on','SearchDepth','1','BlockType','SubSystem');
% ������ϵͳ������
bb = get_param(aa,'Name');
% ƴ����ϵͳ·��
cc = [bdroot,'/',bb];
% �ҳ��ⲿ����˿�
dd = find_system(bdroot,'FindAll','on','SearchDepth','1','BlockType','Inport');
% �ҳ��ⲿ����˿�
ee = find_system(bdroot,'FindAll','on','SearchDepth','1','BlockType','Outport');
% �ҳ���ϵͳ����˿�
ff = find_system(cc,'FindAll','on','SearchDepth','1','BlockType','Inport');
% �ҳ���ϵͳ����˿�
gg = find_system(cc,'FindAll','on','SearchDepth','1','BlockType','Outport');
% ����˿�����
for k = 1:length(ff)%��ϵͳѭ������
    for i = 1:length(dd)%�ⲿ�˿�ѭ������
        if (get_param(dd(i),'Name') == get_param(ff(k),'Name'))
            hh = get_param(dd(i),'Name');
            add_line(bdroot,[hh,'/1'],[bb,'/',num2str(k)]);
        end
    end
end
%����˿�����
for y = 1:length(gg)%��ϵͳѭ������
    for x = 1:length(ee)%�ⲿ�˿�ѭ������
        if (get_param(ee(x),'Name') == get_param(gg(y),'Name'))
            ii = get_param(ee(x),'Name');
            add_line(bdroot,[bb,'/',num2str(y)],[ii,'/1']);
        end
    end
end
% �ź���ƽֱ
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
% author��flieck
% date  : 2020/09/07