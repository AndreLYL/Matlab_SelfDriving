function Fields = DrawRasterMap(rows,cols,startsub,endsub,obssub)
%DRAWRASTERMAO ��������ϰ����դ��ͼ,����һ���������ݣ������ʽ������ ���� ������� �յ������� �ϰ������У���
                                                       % �������:��ֵ����դ�����

% ����դ���ͼȫ�򣬲���ʼ���հ�����
field = ones(rows, cols); %��ʼ���հ����� ��ֵȫΪ1,��ֵ���ڱ�ʾCmap����ɫ(��ΪCmap��������ֻ�ܴ�1��ʼ)

% ��ʼ���Ŀ���
start = startsub;                       % ����λ��
goal = endsub;                          % �յ��λ��
field(start(1),start(2)) = 4;           % ������������ֵ,��ֵ���ڱ�ʾCmap����ɫ
field(goal(1),goal(2)) = 5;             % �յ����������ֵ,��ֵ���ڱ�ʾCmap����ɫ

% �ϰ�������
obs = obssub;
field(obs(:,1),obs(:,2)) = 2;       %�ϰ������������ֵ,��ֵ���ڱ�ʾCmap����ɫ

% ObsR = obssub(:,1);ObsC = obssub(:,2);
% obs = sub2ind([rows,cols],ObsR,ObsC);
% field(obs) = 2;                         % �ϰ������������ֵ,��ֵ���ڱ�ʾCmap����ɫ

% ��������ֵΪ��ֵ����դ�����
Fields = field;

%���������դ��ͼ ���Բ鿴���� help image
cmap = [1 1 1; ...       % 1-��ɫ-�յ�
        0 0 0; ...       % 2-��ɫ-��̬�ϰ�
        1 0 0; ...       % 3-��ɫ-��̬�ϰ�
        1 1 0;...        % 4-��ɫ-��ʼ�� 
        1 0 1;...        % 5-Ʒ��-Ŀ���
        0 1 0; ...       % 6-��ɫ-��Ŀ���Ĺ滮·��   
        0 1 1; ...       % 7-��ɫ-��̬�滮��·��
        0 0 1];          % 8-��ɫ

% ������ɫMAPͼ
colormap(cmap);


% ����ͼ��
image(1.5,1.5,field);
grid on;
set(gca,'gridline','-','gridcolor','k','linewidth',2,'GridAlpha',0.5);
set(gca,'xtick',1:cols+1,'ytick',1:rows+1);
set(gca, 'XAxisLocation','top')
axis image;

end
